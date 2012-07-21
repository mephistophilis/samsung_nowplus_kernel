/*
 *  drivers/usb/otg/fsa9480_i2c.c
 *
 * Copyright (C) 2009 Samsung Electronics Co. Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
*/

#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/i2c.h>
#include <linux/gpio.h>
#include <asm/irq.h>
#include <linux/delay.h>
#include <linux/wakelock.h>
#include <plat/gpio.h>
#include <plat/hardware.h>
#include <plat/mux.h>
#include "fsa9480_i2c.h"


#define FSA9480UCX 0x4A

#define _ATTACH 1
#define _DETTACH 0

#define USB_DISCONNECT_WAIT_TIMEOUT	(5*HZ)

static u8 MicroUSBStatus = _DETTACH;
static u8 MicroJigUSBOnStatus = _DETTACH;
static u8 MicroJigUSBOffStatus = _DETTACH;
static u8 MicroJigUARTOnStatus = _DETTACH;
static u8 MicroJigUARTOffStatus = _DETTACH;
u8 MicroTAstatus = _DETTACH;

static u8 fsa9480_device1 = 0;
static u8 fsa9480_device2 = 0;

static struct i2c_client *fsa9480_i2c_client;
static struct i2c_device_id *fsa9480_i2c_device_id;
struct i2c_driver fsa9480_i2c_driver;

static DECLARE_WAIT_QUEUE_HEAD(usb_detect_waitq);
static DECLARE_WAIT_QUEUE_HEAD(usb_disconnect_waitq);
static struct workqueue_struct *fsa9480_workqueue;
static struct work_struct fsa9480_work;

struct wake_lock fsa9480_wake_lock;

static int microusb_usbpath = -1;

#if 0 // SASKEN - TODO Enable when CONFIG_PM is enabled
#ifndef FEATURE_FTM_SLEEP
#define FEATURE_FTM_SLEEP
#endif
#endif

#ifdef FEATURE_FTM_SLEEP
#ifdef CONFIG_ARCH_OMAP34XX
extern unsigned short wakeup_timer_seconds;
#endif
extern unsigned char ftm_sleep;
extern void (*ftm_enable_usb_sw)(int mode);
static void _ftm_enable_usb_sw(int mode);
#endif

FSA9480_DEV_TY1_TYPE fsa9480_get_dev_typ1(void)
{
	return fsa9480_device1;
}


u8 fsa948080_get_jig_status(void)
{
	if(MicroJigUSBOnStatus | MicroJigUSBOffStatus | MicroJigUARTOnStatus | MicroJigUARTOffStatus)
		return 1;
	else
		return 0;
}


u8 fsa9480_get_usb_status(void)
{
	if( MicroUSBStatus | MicroJigUSBOnStatus | MicroJigUSBOffStatus )
		return 1;
	else
		return 0;
}


u8 fsa9480_get_ta_status(void)
{
	if(MicroTAstatus)
		return 1;
	else
		return 0;
}


static int fsa9480_read(struct i2c_client *client, u8 reg, u8 *data)
{
	int ret;
	u8 buf[1];
	struct i2c_msg msg[2];

	buf[0] = reg;

	msg[0].addr = client->addr;
	msg[0].flags = 0;
	msg[0].len = 1;
	msg[0].buf = buf;

	msg[1].addr = client->addr;
	msg[1].flags = I2C_M_RD;
	msg[1].len = 1;
	msg[1].buf = buf;

	ret = i2c_transfer(client->adapter, msg, 2);
	if (ret != 2) 
		return -EIO;

	*data = buf[0];
	
	return 0;
}


static int fsa9480_write(struct i2c_client *client, u8 reg, u8 data)
{
	int ret;
	u8 buf[2];
	struct i2c_msg msg[1];

	buf[0] = reg;
	buf[1] = data;

	msg[0].addr = client->addr;
	msg[0].flags = 0;
	msg[0].len = 2;
	msg[0].buf = buf;

	ret = i2c_transfer(client->adapter, msg, 1);
	if (ret != 1) 
		return -EIO;

	return 0;
}


static void fsa9480_process_device(u8 dev1, u8 dev2, u8 attach)
{
	DEBUG_FSA9480("fsa9480_process_device function!!!!\n");

	if(dev1)
	{
		switch(dev1)
		{
			case FSA9480_DEV_TY1_AUD_TY1:
				DEBUG_FSA9480("Audio Type1 ");
				if(attach & FSA9480_INT1_ATTACH)
					DEBUG_FSA9480("FSA9480_DEV_TY1_AUD_TY1 --- ATTACH\n");
				else
					DEBUG_FSA9480("FSA9480_DEV_TY1_AUD_TY1 --- DETACH\n");
			break;

			case FSA9480_DEV_TY1_AUD_TY2:
				DEBUG_FSA9480("Audio Type2 ");
				DEBUG_FSA9480("\n");
			break;

			case FSA9480_DEV_TY1_USB:
			{
				DEBUG_FSA9480("USB attach or detach: %d ",attach);
				if(attach & FSA9480_INT1_ATTACH)
				{
					DEBUG_FSA9480("FSA9480_DEV_TY1_USB --- ATTACH\n");
					MicroUSBStatus = _ATTACH;
				}
				else if(attach & FSA9480_INT1_DETACH)
				{
					MicroUSBStatus = _DETTACH;
					DEBUG_FSA9480("FSA9480_DEV_TY1_USB --- DETACH\n");
					interruptible_sleep_on_timeout(&usb_disconnect_waitq, USB_DISCONNECT_WAIT_TIMEOUT);
				}

				wake_up_interruptible(&usb_detect_waitq);
				microusb_usbjig_detect();
			}
			break;

			case FSA9480_DEV_TY1_UART:
				DEBUG_FSA9480("UART ");
				DEBUG_FSA9480("\n");
			break;

			case FSA9480_DEV_TY1_CAR_KIT:
				DEBUG_FSA9480("Carkit ");
				DEBUG_FSA9480("\n");
			break;

			case FSA9480_DEV_TY1_USB_CHG:
				DEBUG_FSA9480("USB ");
				DEBUG_FSA9480("\n");
			break;

			case FSA9480_DEV_TY1_DED_CHG:
				DEBUG_FSA9480("Dedicated Charger ");
				DEBUG_FSA9480("\n");
			break;

			case FSA9480_DEV_TY1_USB_OTG:
				DEBUG_FSA9480("USB OTG ");
				DEBUG_FSA9480("\n");
			break;

			default:
				DEBUG_FSA9480("Unknown device ");
				DEBUG_FSA9480("\n");
			break;
		}

	}

	if(dev2)
	{
		switch(dev2)
		{
			case FSA9480_DEV_TY2_JIG_USB_ON:
				DEBUG_FSA9480("JIG USB ON attach or detach: %d ",attach);
				if(attach & FSA9480_INT1_ATTACH)
				{
					DEBUG_FSA9480("FSA9480_DEV_TY2_JIG_USB_ON --- ATTACH\n");
					MicroJigUSBOnStatus = _ATTACH;
				}
				else if(attach & FSA9480_INT1_DETACH)
				{
					DEBUG_FSA9480("FSA9480_DEV_TY2_JIG_USB_ON --- DETACH\n");
					MicroJigUSBOnStatus = DETACH;
					interruptible_sleep_on_timeout(&usb_disconnect_waitq, USB_DISCONNECT_WAIT_TIMEOUT);
				}

				wake_up_interruptible(&usb_detect_waitq);
				microusb_usbjig_detect();
			break;

			case FSA9480_DEV_TY2_JIG_USB_OFF:
				DEBUG_FSA9480("JIG USB OFF ");
				if(attach & FSA9480_INT1_ATTACH)
				{
					DEBUG_FSA9480("FSA9480_DEV_TY2_JIG_USB_OFF --- ATTACH\n");
					MicroJigUSBOffStatus = _ATTACH;
				}
				else if(attach & FSA9480_INT1_DETACH)
				{
					DEBUG_FSA9480("FSA9480_DEV_TY2_JIG_USB_OFF --- DETACH\n");
					MicroJigUSBOffStatus = DETACH;
					interruptible_sleep_on_timeout(&usb_disconnect_waitq, USB_DISCONNECT_WAIT_TIMEOUT);
				}

				wake_up_interruptible(&usb_detect_waitq);
				microusb_usbjig_detect();
			break;

			case FSA9480_DEV_TY2_JIG_UART_ON:
				DEBUG_FSA9480("JIG UART ON ");
				if(attach & FSA9480_INT1_ATTACH)
				{
					DEBUG_FSA9480("FSA9480_DEV_TY2_JIG_UART_ON --- ATTACH\n");
					MicroJigUARTOnStatus = _ATTACH;
				}
				else
				{
					DEBUG_FSA9480("FSA9480_DEV_TY2_JIG_UART_ON --- DETACH\n");
					MicroJigUARTOnStatus = DETACH;
				}
			break;

			case FSA9480_DEV_TY2_JIG_UART_OFF:
				DEBUG_FSA9480("JIT UART OFF ");
				if(attach & FSA9480_INT1_ATTACH)
				{
					DEBUG_FSA9480("FSA9480_DEV_TY2_JIG_UART_OFF --- ATTACH\n");
					MicroJigUARTOffStatus = _ATTACH;
				}
				else
				{
					DEBUG_FSA9480("FSA9480_DEV_TY2_JIG_UART_OFF --- DETACH\n");
					MicroJigUARTOffStatus = DETACH;
				}
			break;

			case FSA9480_DEV_TY2_PDD:
				DEBUG_FSA9480("PPD ");
				DEBUG_FSA9480("\n");
			break;

			case FSA9480_DEV_TY2_TTY:
				DEBUG_FSA9480("TTY ");
				DEBUG_FSA9480("\n");
			break;

			case FSA9480_DEV_TY2_AV:
			{
				DEBUG_FSA9480("AudioVideo ");
				if(attach & FSA9480_INT1_ATTACH)
					DEBUG_FSA9480("FSA9480_DEV_TY2_AV --- ATTACH\n");
				else
					DEBUG_FSA9480("FSA9480_DEV_TY2_AV --- DETACH\n");
			}
			break;

			default:
				DEBUG_FSA9480("Unknown device ");
				DEBUG_FSA9480("\n");
			break;
		}
	}
}


static void fsa9480_read_int_register(struct work_struct *work)
{
	u8 interrupt1 , interrupt2, device1, device2, temp;

	DEBUG_FSA9480("fsa9480_read_int_register function!!!!\n");

	fsa9480_read(fsa9480_i2c_client, REGISTER_INTERRUPT1, &interrupt1);

	mdelay(10);

	fsa9480_read(fsa9480_i2c_client, REGISTER_INTERRUPT2, &interrupt2);

	mdelay(10);

	fsa9480_read(fsa9480_i2c_client, REGISTER_DEVICETYPE1, &device1);

	mdelay(10);

	fsa9480_read(fsa9480_i2c_client, REGISTER_DEVICETYPE2, &device2);

	if(interrupt1 & FSA9480_INT1_ATTACH)
	{
		fsa9480_device1 = device1;
		fsa9480_device2 = device2;

		if(fsa9480_device1 & FSA9480_DEV_TY1_CAR_KIT)
		{
			mdelay(10);
			fsa9480_write(fsa9480_i2c_client, REGISTER_CARKITSTATUS, 0x02);

			mdelay(10);
			fsa9480_read(fsa9480_i2c_client, REGISTER_CARKITINT1, &temp);
		}
	}

	mdelay(10);

	if(microusb_usbpath > 0) // if CP USB
	{
		fsa9480_write(fsa9480_i2c_client, REGISTER_CONTROL, 0x1A);
		mdelay(10);

		fsa9480_write(fsa9480_i2c_client, REGISTER_MANUALSW1, 0x90);
		mdelay(10);

		fsa9480_write(fsa9480_i2c_client, REGISTER_MANUALSW2, 0x10);
		mdelay(10);
	}
	else
	{
		fsa9480_write(fsa9480_i2c_client, REGISTER_CONTROL, 0x1E);	 

		wake_up_interruptible(&usb_detect_waitq);

		fsa9480_process_device(fsa9480_device1, fsa9480_device2, interrupt1);
	}

	fsa9480_write(fsa9480_i2c_client, REGISTER_INTERRUPTMASK1, 0xFC);

	if(interrupt1 & FSA9480_INT1_DETACH)
	{
		fsa9480_device1 = 0;
		fsa9480_device2 = 0;
	}

	enable_irq(fsa9480_i2c_client->irq);

	wake_lock_timeout(&fsa9480_wake_lock, 3*HZ);
}


static irqreturn_t fsa9480_interrupt(int irq, void *ptr)
{
	wake_lock_timeout(&fsa9480_wake_lock, 3*HZ);

	disable_irq_nosync(irq);

	queue_work(fsa9480_workqueue, &fsa9480_work);

	return IRQ_HANDLED;
}


static void fsa9480_interrupt_init(int irq, void *dev_id)
{
#define FSA9480_IRQ_FLAGS (IRQF_DISABLED | IRQF_SHARED)

	set_irq_type(irq, IRQ_TYPE_LEVEL_LOW/*IRQ_TYPE_EDGE_FALLING*/);

	if (request_irq(irq, fsa9480_interrupt, FSA9480_IRQ_FLAGS, "FSA9480 Detected", dev_id))
	{
		DEBUG_FSA9480("[FSA9480]fail to register IRQ[%d] for FSA9480 USB Switch \n", irq);
	}

	enable_irq_wake(irq); // keep wakeup attr in sleep state
}


static void fsa9480_init(void)
{
	u8 data = 0;

	fsa9480_read(fsa9480_i2c_client, REGISTER_DEVICEID, &data);

	mdelay(10);

	fsa9480_write(fsa9480_i2c_client, REGISTER_CONTROL, 0x1E);

	mdelay(10);

	// Unmask attach/detach interrupt
	fsa9480_write(fsa9480_i2c_client, REGISTER_INTERRUPTMASK1, 0xFC);
	fsa9480_write(fsa9480_i2c_client, REGISTER_INTERRUPTMASK2, 0xFF);

	mdelay(10);

	// Mask CARKIT all interrupt
	fsa9480_write(fsa9480_i2c_client, REGISTER_CARKITMASK1, 0xFF);
	fsa9480_write(fsa9480_i2c_client, REGISTER_CARKITMASK2, 0xFF);

	mdelay(10);

	fsa9480_read(fsa9480_i2c_client, REGISTER_DEVICETYPE1, &fsa9480_device1);

	mdelay(10);

	fsa9480_read(fsa9480_i2c_client, REGISTER_DEVICETYPE2, &fsa9480_device2);
}


static int fsa9480_modify(struct i2c_client *client, u8 reg, u8 data, u8 mask)
{
   u8 original_value, modified_value;

   fsa9480_read(client, reg, &original_value);

   mdelay(10);
   
   DEBUG_FSA9480("[FSA9480] %s Original value is 0x%02x\n ",__func__, original_value);
   
   modified_value = ((original_value&~mask) | data);
   
   DEBUG_FSA9480("[FSA9480] %s modified value is 0x%02x\n ",__func__, modified_value);
   
   fsa9480_write(client, reg, modified_value);

   mdelay(10);

   return 0;
}


void fsa9480_init_status(void)
{
	u8 pData;

	fsa9480_modify(fsa9480_i2c_client, REGISTER_CONTROL, ~INT_MASK, INT_MASK);

	fsa9480_read(fsa9480_i2c_client, 0x13, &pData);
}


static int fsa9480_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	int ret = 0;

	init_waitqueue_head(&usb_detect_waitq);
	init_waitqueue_head(&usb_disconnect_waitq);
	INIT_WORK(&fsa9480_work, fsa9480_read_int_register);
	fsa9480_workqueue = create_singlethread_workqueue("fsa9480_wq");

	fsa9480_i2c_client = client;
	fsa9480_i2c_device_id = id;

	wake_lock_init(&fsa9480_wake_lock, WAKE_LOCK_SUSPEND, "FSA9480");

	fsa9480_init_status();

	fsa9480_init();

	//fsa9480_interrupt_init(client->irq, (void*)id);

#ifdef FEATURE_FTM_SLEEP
	ftm_enable_usb_sw = _ftm_enable_usb_sw;
#endif

	return ret;
}


static int __devexit fsa9480_remove(struct i2c_client *client)
{
	free_irq(client->irq, client);

	return 0;
}


static int fsa9480_resume(struct i2c_client *client)
{
#ifdef FEATURE_FTM_SLEEP
	if(ftm_sleep)
	{
#ifdef CONFIG_ARCH_OMAP34XX
		if(wakeup_timer_seconds)
#endif
		{
#ifdef CONFIG_ARCH_OMAP34XX
			wakeup_timer_seconds = 0;
#endif

			/*set Auto Swithing mode */
			fsa9480_write(fsa9480_i2c_client, REGISTER_CONTROL, 0x1E);
		}
	}
#endif

	return 0;
}


static const struct i2c_device_id fsa9480_id[] = {
        { "fsa9480", 0 },
        { }
};


struct i2c_driver fsa9480_i2c_driver = {
	.driver = {
		.name = "fsa9480",
		.owner = THIS_MODULE,
	},
	.probe		= fsa9480_probe,
	.remove		= __devexit_p(fsa9480_remove),
	.resume		= fsa9480_resume,
	.id_table	= fsa9480_id,
};

void microusb_init(void)
{
#define I2C_READ_RETRY_MAX 2
	int ret = 0;
	int read_retry;
	u8 device1;
	u8 device2;
	u8 interrupt1;
	u8 interrupt2;
	u8 attach = FSA9480_INT1_ATTACH;

	for(read_retry = 0; read_retry < I2C_READ_RETRY_MAX; read_retry++) {
		device1 = 0;
		if(fsa9480_read(fsa9480_i2c_client, REGISTER_DEVICETYPE1, &device1) == 0) {
			break;
		}
	}

	for(read_retry = 0; read_retry < I2C_READ_RETRY_MAX; read_retry++) {
		device2 = 0;
		if(fsa9480_read(fsa9480_i2c_client, REGISTER_DEVICETYPE2, &device2) == 0) {
			break;
		}
	}

	if(microusb_usbpath > 0) // if CP USB
	{
		fsa9480_write(fsa9480_i2c_client, REGISTER_CONTROL, 0x1A);
		mdelay(10);

		fsa9480_write(fsa9480_i2c_client, REGISTER_MANUALSW1, 0x90);
		mdelay(10);

		fsa9480_write(fsa9480_i2c_client, REGISTER_MANUALSW2, 0x10);
		mdelay(10);
	}
	else
	{
		if(device1 && (device1 != FSA9480_DEV_TY1_DED_CHG)) {
			attach = FSA9480_INT1_ATTACH;
		}

		if(device1 == 0 && device2 == 0) {
			device1 = FSA9480_DEV_TY1_USB;
			attach = FSA9480_INT1_DETACH;
		}

		fsa9480_device1 = device1;
		fsa9480_device2 = device2;

		fsa9480_process_device(fsa9480_device1, fsa9480_device2, attach);

		fsa9480_init();
	}

	// clear interrupt
	fsa9480_read(fsa9480_i2c_client, REGISTER_INTERRUPT1, &interrupt1);
	msleep(5);

	fsa9480_read(fsa9480_i2c_client, REGISTER_INTERRUPT2, &interrupt2);
	msleep(5);

	fsa9480_interrupt_init(fsa9480_i2c_client->irq, fsa9480_i2c_device_id);
}
EXPORT_SYMBOL(microusb_init);

// Called by switch sio driver
void mcirousb_usbpath_change(int usb_path)
{
	u8 pData;

	fsa9480_read(fsa9480_i2c_client, REGISTER_CONTROL, &pData);

	microusb_usbpath = usb_path;

	if(usb_path) { // CP USB
		if(pData != 0x1A) {
			//mdelay(10000);
			fsa9480_write(fsa9480_i2c_client, REGISTER_CONTROL, 0x1A);
			mdelay(1000);//mdelay(10000);

			fsa9480_write(fsa9480_i2c_client, REGISTER_MANUALSW1, 0x90);
			mdelay(10);

			fsa9480_write(fsa9480_i2c_client, REGISTER_MANUALSW2, 0x10);
			mdelay(10);
		}
	} else { // AP USB
		if(pData != 0x1E) {
			//mdelay(10000);
			fsa9480_write(fsa9480_i2c_client, REGISTER_CONTROL, 0x1E);
		}
	}
}
EXPORT_SYMBOL(mcirousb_usbpath_change);

void microusb_disconnect_notify(void)
{
	wake_up_interruptible(&usb_disconnect_waitq);
}
EXPORT_SYMBOL(microusb_disconnect_notify);

#ifdef CONFIG_TWL4030_USB
// Called by switch sio driver
int microusb_enable(void)
{
	int retval;

	retval = i2c_add_driver(&fsa9480_i2c_driver);
	if (retval != 0) {
		printk("[Micro-USB] can't add i2c driver");
	}

	return retval;
}
EXPORT_SYMBOL(microusb_enable);


void microusb_disable(void)
{
	i2c_del_driver(&fsa9480_i2c_driver);
}
EXPORT_SYMBOL(microusb_disable);
#endif


#if 1 // Called by charger MAX8845 driver and twl4030 usb tranceiver driver
int get_real_usbic_state(void)
{
#define I2C_READ_RETRY_MAX 2
	int ret = 0;
	int read_retry;
	u8 device1;
	u8 device2;

	interruptible_sleep_on_timeout(&usb_detect_waitq, HZ);

	for(read_retry = 0; read_retry < I2C_READ_RETRY_MAX; read_retry++)
	{
		device1 = 0;
		if(fsa9480_read(fsa9480_i2c_client, REGISTER_DEVICETYPE1, &device1) == 0)
		{
			break;
		}
	}

	for(read_retry = 0; read_retry < I2C_READ_RETRY_MAX; read_retry++)
	{
		device2 = 0;
		if(fsa9480_read(fsa9480_i2c_client, REGISTER_DEVICETYPE2, &device2) == 0)
		{
			break;
		}
	}

	DEBUG_FSA9480("real usbic state : %d, %d\n", device1, device2);

	switch(device1)
	{
		case FSA9480_DEV_TY1_USB:
		ret = MICROUSBIC_USB_CABLE;
		break;

		case FSA9480_DEV_TY1_USB_CHG:
		ret = MICROUSBIC_USB_CHARGER;
		break;

		case FSA9480_DEV_TY1_CAR_KIT:
		ret = MICROUSBIC_5W_CHARGER;
		break;

		case FSA9480_DEV_TY1_DED_CHG:
		ret = MICROUSBIC_TA_CHARGER;
		break;

		default:
		break;
	}

	if(!ret)
	{
		switch(device2)
		{
			case FSA9480_DEV_TY2_JIG_USB_ON:
			case FSA9480_DEV_TY2_JIG_USB_OFF:
			ret = MICROUSBIC_USB_CABLE;
			break;

			default:
			break;
		}
	}

	if(microusb_usbpath > 0) // if CP USB
	{
		if(ret == MICROUSBIC_USB_CABLE)
		{
			ret = MICROUSBIC_USB_CHARGER;
		}
	}

	return ret;
}
EXPORT_SYMBOL(get_real_usbic_state);
#endif

#ifdef FEATURE_FTM_SLEEP
//SEC_BSP_WONSUK_20090810 : Add the codes related SLEEP CMD in factory process
/*================================================
	When DIAG SLEEP command arrived, UART RXD, TXD port make disable
	because CP could not enter the sleep mode due to the UART floating voltage.
================================================*/

/**********************************************************************
*    Name         : fsa9480_SetManualSW()
*    Description : Control FSA9480's Manual SW1 and SW2
*                        
*    Parameter   :
*                       @ valManualSw1 : the value to set SW1
*                       @ valManualSw2 : the value to set SW2
*    Return        : None
*
***********************************************************************/
void fsa9480_SetManualSW(unsigned char valManualSw1, unsigned char valManualSw2)
{
	unsigned char cont_reg, man_sw1, man_sw2;

	DEBUG_FSA9480("[FSA9480]%s \n", __func__);

	/*Set Manual switch*/
	fsa9480_write(fsa9480_i2c_client, REGISTER_MANUALSW1, valManualSw1);
	mdelay(20);

	fsa9480_write(fsa9480_i2c_client, REGISTER_MANUALSW2, valManualSw2);
	mdelay(20);

	/*when detached the cable, Control register automatically be restored.*/
	fsa9480_read(fsa9480_i2c_client, REGISTER_CONTROL, &cont_reg);
	mdelay(20);
	DEBUG_FSA9480("[FSA9480] fsa9480_SetManualSW : [Before]Control Register's value is %s\n",&cont_reg);

	/*set switching mode to MANUAL*/
	fsa9480_write(fsa9480_i2c_client, REGISTER_CONTROL, 0x1A);

	/* Read current setting value , manual sw1, manual sw2, control register.*/
	fsa9480_read(fsa9480_i2c_client, REGISTER_MANUALSW1, &man_sw1);
	mdelay(20);
	DEBUG_FSA9480("[FSA9480] fsa9480_SetManualSW : Manual SW1 Register's value is %s\n",&man_sw1);

	fsa9480_read(fsa9480_i2c_client, REGISTER_MANUALSW2, &man_sw2);
	mdelay(20);
	DEBUG_FSA9480("[FSA9480] fsa9480_SetManualSW : Manual SW2 Register's value is %s\n",&man_sw2);

	fsa9480_read(fsa9480_i2c_client, REGISTER_CONTROL, &cont_reg);
	DEBUG_FSA9480("[FSA9480] fsa9480_SetManualSW : [After]Control Register's value is %s\n",&cont_reg);
}

/**********************************************************************
*    Name         : fsa9480_SetAutoSWMode()
*    Description : Set FSA9480 with Auto Switching Mode.
*                        
*    Parameter   : None
*                       @ 
*                       @ 
*    Return        : None
*
***********************************************************************/
void fsa9480_SetAutoSWMode(void)
{
	DEBUG_FSA9480("[FSA9480]%s\n ", __func__);

	/*set Auto Swithing mode */
	fsa9480_write(fsa9480_i2c_client, REGISTER_CONTROL, 0x1E);
}

/**********************************************************************
*    Name         : fsa9480_MakeRxdLow()
*    Description : Make UART port to OPEN state.
*                        
*    Parameter   : None
*                       @ 
*                       @ 
*    Return        : None
*
***********************************************************************/
void fsa9480_MakeRxdLow(void)
{
	unsigned char hidden_reg;

	DEBUG_FSA9480("[FSA9480]%s\n ", __func__);

	fsa9480_write(fsa9480_i2c_client, HIDDEN_REGISTER_MANUAL_OVERRDES1, 0x0a); 
	mdelay(20);
	fsa9480_read(fsa9480_i2c_client, HIDDEN_REGISTER_MANUAL_OVERRDES1, &hidden_reg);
	fsa9480_SetManualSW(0x00, 0x00);
}

EXPORT_SYMBOL(fsa9480_SetManualSW);
EXPORT_SYMBOL(fsa9480_SetAutoSWMode);
EXPORT_SYMBOL(fsa9480_MakeRxdLow);

static void _ftm_enable_usb_sw(int mode)
{
#define FTM_TIMEOUT 4 // sec
	pr_info("%s: mode(%d)\n", __func__, mode);

	if (mode) {
		fsa9480_SetAutoSWMode();
	} else {
		fsa9480_MakeRxdLow();
		mdelay(10);
		fsa9480_MakeRxdLow();
#ifdef CONFIG_ARCH_OMAP34XX
		wakeup_timer_seconds = FTM_TIMEOUT;
#endif
	}
}
#endif /* FEATURE_FTM_SLEEP */

MODULE_AUTHOR("SAMSUNG ELECTRONICS CO., LTD");
MODULE_DESCRIPTION("FSA9480 MicroUSB driver");
MODULE_LICENSE("GPL");
