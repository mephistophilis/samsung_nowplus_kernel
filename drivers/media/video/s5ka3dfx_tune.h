#ifndef CAMIF_REG_CONFIG_H_
#define CAMIF_REG_CONFIG_H_

/* If you wanna use the reg_val configuration file on board, set this value to 1 */
#define IS_USE_REGISTER_CONFIGURE_FILE_LSI 0

#if (IS_USE_REGISTER_CONFIGURE_FILE_LSI)

static int s5ka3dfx_make_table(void);

enum
{
    REG_INIT_VGA_SECTION,
    REG_INIT_VGA_VT_SECTION,  
    REG_WB_AUTO_SECTION,
    REG_WB_DAYLIGHT_SECTION,
    REG_WB_CLOUDY_SECTION,
    REG_WB_INCANDESCENT_SECTION,
    REG_WB_FLUORESCENT_SECTION,
    REG_EV_SECTION,
    REG_EV_VT_SECTION,
    REG_EFFECT_NONE_SECTION,
    REG_EFFECT_GRAY_SECTION,
    REG_EFFECT_RED_SECTION,    
    REG_EFFECT_SEPIA_SECTION,
    REG_EFFECT_GREEN_SECTION,
    REG_EFFECT_AQUA_SECTION,
    REG_EFFECT_NEGATIVE_SECTION,
    REG_FLIP_NONE_SECTION,
    REG_FLIP_WATER_SECTION,
    REG_FLIP_MIRROR_SECTION,
    REG_FLIP_WATER_MIRROR_SECTION,
    REG_PRETTY_NONE_SECTION,
    REG_PRETTY_LEVEL1_SECTION,
    REG_PRETTY_LEVEL2_SECTION,
    REG_PRETTY_LEVEL3_SECTION,   
    REG_PRETTY_VT_NONE_SECTION,
    REG_PRETTY_VT_LEVEL1_SECTION,
    REG_PRETTY_VT_LEVEL2_SECTION,
    REG_PRETTY_VT_LEVEL3_SECTION,
    REG_FPS_7_SECTION,
    REG_FPS_10_SECTION,
    REG_FPS_12_SECTION,    
    REG_FPS_15_SECTION,    
};

/****************************************************************************/
/*     sensor                                                               */
/*--------------------------------------------------------------------------*/
#define CAMIF_CONFIGURE_FILE_LSI                "/sdcard/reg_val_s5ka3dfx.txt"

#define CAMIF_SET_SENSOR_VGA_INIT               "[[CAMIF_INIT_VGA_INIT]]"
#define CAMIF_SET_SENSOR_VGA_VT_INIT            "[[CAMIF_INIT_VGA_VT_INIT]]"
#define CAMIF_SET_SENSOR_WB_AUTO                "[[CAMIF_WB_AUTO]]"
#define CAMIF_SET_SENSOR_WB_DAYLIGHT            "[[CAMIF_WB_DAYLIGHT]]"
#define CAMIF_SET_SENSOR_WB_CLOUDY              "[[CAMIF_WB_CLOUDY]]"
#define CAMIF_SET_SENSOR_WB_INCANDESCENT        "[[CAMIF_WB_INCANDESCENT]]"
#define CAMIF_SET_SENSOR_WB_FLUORESCENT         "[[CAMIF_WB_FLUORESCENT]]"
#define CAMIF_SET_SENSOR_EV                     "[[CAMIF_EV]]"
#define CAMIF_SET_SENSOR_EV_VT                  "[[CAMIF_EV_VT]]"
#define CAMIF_SET_SENSOR_EFFECT_NONE            "[[CAMIF_EFFECT_NONE]]"
#define CAMIF_SET_SENSOR_EFFECT_GRAY            "[[CAMIF_EFFECT_GRAY]]"
#define CAMIF_SET_SENSOR_EFFECT_RED             "[[CAMIF_EFFECT_RED]]"
#define CAMIF_SET_SENSOR_EFFECT_SEPIA           "[[CAMIF_EFFECT_SEPIA]]"
#define CAMIF_SET_SENSOR_EFFECT_GREEN           "[[CAMIF_EFFECT_GREEN]]"
#define CAMIF_SET_SENSOR_EFFECT_AQUA            "[[CAMIF_EFFECT_AQUA]]"
#define CAMIF_SET_SENSOR_EFFECT_NEGATIVE        "[[CAMIF_EFFECT_NEGATIVE]]"
#define CAMIF_SET_SENSOR_FLIP_NONE              "[[CAMIF_FLIP_NONE]]"
#define CAMIF_SET_SENSOR_FLIP_WATER             "[[CAMIF_FLIP_WATER]]"
#define CAMIF_SET_SENSOR_FLIP_MIRROR            "[[CAMIF_FLIP_MIRROR]]"
#define CAMIF_SET_SENSOR_FLIP_WATER_MIRROR      "[[CAMIF_FLIP_WATER_MIRROR]]"
#define CAMIF_SET_SENSOR_PRETTY_NONE            "[[CAMIF_FLIP_PRETTY_NONE]]"
#define CAMIF_SET_SENSOR_PRETTY_LEVEL1          "[[CAMIF_FLIP_PRETTY_LEVEL1]]"
#define CAMIF_SET_SENSOR_PRETTY_LEVEL2          "[[CAMIF_FLIP_PRETTY_LEVEL2]]"
#define CAMIF_SET_SENSOR_PRETTY_LEVEL3          "[[CAMIF_FLIP_PRETTY_LEVEL3]]"
#define CAMIF_SET_SENSOR_PRETTY_VT_NONE         "[[CAMIF_FLIP_PRETTY_VT_NONE]]"
#define CAMIF_SET_SENSOR_PRETTY_VT_LEVEL1       "[[CAMIF_FLIP_PRETTY_VT_LEVEL1]]"
#define CAMIF_SET_SENSOR_PRETTY_VT_LEVEL2       "[[CAMIF_FLIP_PRETTY_VT_LEVEL2]]"
#define CAMIF_SET_SENSOR_PRETTY_VT_LEVEL3       "[[CAMIF_FLIP_PRETTY_VT_LEVEL3]]"
#define CAMIF_SET_SENSOR_FPS7                   "[[CAMIF_FPS_7]]"
#define CAMIF_SET_SENSOR_FPS10                  "[[CAMIF_FPS_10]]"
#define CAMIF_SET_SENSOR_FPS12                  "[[CAMIF_FPS_12]]"
#define CAMIF_SET_SENSOR_FPS15                  "[[CAMIF_FPS_15]]"



/* Section Entry Num */
#define CAMIF_SECTION_INIT_VGA_MAX              1200
#define CAMIF_SECTION_INIT_VGA_VT_MAX           1200
#define CAMIF_SECTION_WB_AUTO_MAX               50
#define CAMIF_SECTION_WB_DAYLIGHT_MAX           50
#define CAMIF_SECTION_WB_CLOUDY_MAX             50
#define CAMIF_SECTION_WB_INCANDESCENT_MAX       50
#define CAMIF_SECTION_WB_FLUORESCENT_MAX        50
#define CAMIF_SECTION_EV_MAX                    50
#define CAMIF_SECTION_EV_VT_MAX                 50
#define CAMIF_SECTION_EFFECT_NONE_MAX           50
#define CAMIF_SECTION_EFFECT_GRAY_MAX           50
#define CAMIF_SECTION_EFFECT_RED_MAX            50
#define CAMIF_SECTION_EFFECT_SEPIA_MAX          50
#define CAMIF_SECTION_EFFECT_GREEN_MAX          50
#define CAMIF_SECTION_EFFECT_AQUA_MAX           50
#define CAMIF_SECTION_EFFECT_NEGATIVE_MAX       50
#define CAMIF_SECTION_FLIP_NONE_MAX             50
#define CAMIF_SECTION_FLIP_WATER_MAX            50
#define CAMIF_SECTION_FLIP_MIRROR_MAX           50
#define CAMIF_SECTION_FLIP_WATER_MIRROR_MAX     50
#define CAMIF_SECTION_PRETTY_NONE_MAX           500
#define CAMIF_SECTION_PRETTY_LEVEL1_MAX         500
#define CAMIF_SECTION_PRETTY_LEVEL2_MAX         500
#define CAMIF_SECTION_PRETTY_LEVEL3_MAX         500
#define CAMIF_SECTION_PRETTY_VT_NONE_MAX        500
#define CAMIF_SECTION_PRETTY_VT_LEVEL1_MAX      500
#define CAMIF_SECTION_PRETTY_VT_LEVEL2_MAX      500
#define CAMIF_SECTION_PRETTY_VT_LEVEL3_MAX      500
#define CAMIF_SECTION_FPS_7_MAX                 500
#define CAMIF_SECTION_FPS_10_MAX                500
#define CAMIF_SECTION_FPS_12_MAX                500
#define CAMIF_SECTION_FPS_15_MAX                500


/* Section Table */
u32 reg_init_vga_table                          [CAMIF_SECTION_INIT_VGA_MAX];
u32 reg_init_vga_vt_table                       [CAMIF_SECTION_INIT_VGA_VT_MAX];
u32 reg_wb_auto_table                           [CAMIF_SECTION_WB_AUTO_MAX];
u32 reg_wb_daylight_table                       [CAMIF_SECTION_WB_DAYLIGHT_MAX];
u32 reg_wb_cloudy_table                         [CAMIF_SECTION_WB_CLOUDY_MAX];
u32 reg_wb_incandescent_table                   [CAMIF_SECTION_WB_INCANDESCENT_MAX];
u32 reg_wb_fluorescent_table                    [CAMIF_SECTION_WB_FLUORESCENT_MAX];
u32 reg_ev_table                                [CAMIF_SECTION_EV_MAX];
u32 reg_ev_vt_table                             [CAMIF_SECTION_EV_VT_MAX];
u32 reg_effect_none_table                       [CAMIF_SECTION_EFFECT_NONE_MAX];
u32 reg_effect_gray_table                       [CAMIF_SECTION_EFFECT_GRAY_MAX];
u32 reg_effect_red_table                        [CAMIF_SECTION_EFFECT_RED_MAX];
u32 reg_effect_sepia_table                      [CAMIF_SECTION_EFFECT_SEPIA_MAX];
u32 reg_effect_green_table                      [CAMIF_SECTION_EFFECT_GREEN_MAX];
u32 reg_effect_aqua_table                       [CAMIF_SECTION_EFFECT_AQUA_MAX];
u32 reg_effect_negative_table                   [CAMIF_SECTION_EFFECT_NEGATIVE_MAX];
u32 reg_flip_none_table                         [CAMIF_SECTION_FLIP_NONE_MAX];
u32 reg_flip_water_table                        [CAMIF_SECTION_FLIP_WATER_MAX];
u32 reg_flip_mirror_table                       [CAMIF_SECTION_FLIP_MIRROR_MAX];
u32 reg_flip_water_mirror_table                 [CAMIF_SECTION_FLIP_WATER_MIRROR_MAX];
u32 reg_pretty_none_table                       [CAMIF_SECTION_PRETTY_NONE_MAX];
u32 reg_pretty_level1_table                     [CAMIF_SECTION_PRETTY_LEVEL1_MAX];
u32 reg_pretty_level2_table                     [CAMIF_SECTION_PRETTY_LEVEL2_MAX];
u32 reg_pretty_level3_table                     [CAMIF_SECTION_PRETTY_LEVEL3_MAX];
u32 reg_pretty_vt_none_table                    [CAMIF_SECTION_PRETTY_VT_NONE_MAX];
u32 reg_pretty_vt_level1_table                  [CAMIF_SECTION_PRETTY_VT_LEVEL1_MAX];
u32 reg_pretty_vt_level2_table                  [CAMIF_SECTION_PRETTY_VT_LEVEL2_MAX];
u32 reg_pretty_vt_level3_table                  [CAMIF_SECTION_PRETTY_VT_LEVEL3_MAX];
u32 reg_fps_7_table                             [CAMIF_SECTION_FPS_7_MAX];
u32 reg_fps_10_table                            [CAMIF_SECTION_FPS_10_MAX];
u32 reg_fps_12_table                            [CAMIF_SECTION_FPS_12_MAX];
u32 reg_fps_15_table                            [CAMIF_SECTION_FPS_15_MAX];

#else

/************** Init Setting ******************/
/* Modified to SEHF Variable */
static const u32 reg_init_vga_table[] = 
{
  0xef02,
  0x13a0,  //OB sel(R reference)
  0x2353,  //tx_width
  0x2624,  //clp level
  0x2c05,  //s1s
  0x0500,  //s1s end value
  0x0358,  //s1R end value       -------------------- Pclk Inversion [3]  0x58 or 0x50
  0x240a,  //cds //1a
  0x0b82,  //Analog Offset
  0x1eb7,  //Global gain
  0x5605,  //ADLC
  0x2896,  //CFPN
  0x673c,  //or 3Ch, or 38h //to reduce HN at low lux
  0x4B5d,  // Pclk PAD current 8mA
  0xef03,
  0x50d2,  //MCLK //e6
  0x0f31,  //ADD vblank value
  0xef03,  //FPs setting
  0x5F03,  //NT Cintr Max
  0x6002,  //PAL Cintr Max
  0x610F,  //NT shutter Max (FrameAE mode)
  0x620C,  //PAL shutter Max (FrameAE mode)
  0x6301,  //NT Vblank
  0x64E7,
  0x6501,  //PAL Vblank
  0x66E7,
  0x6d5e,  //AGC Min for suppress B
  0x6e90,  //Dgain Min(Temporary. Don't move)
  0x6f90,  //Dgain Max(Temporary. Don't move)
  0x4c00,  //Hblank of 50Hz. 50Hz Default value is not 9Eh.
  0x4d9e,
  0xef03,
  0x0007,  //AE ON [0], AWB ON [1] //87 : 50Hz Fixed mode, 07 : 60Hz Fixed mode
  0x0180,  //AE target (Temporary. Don't move)
  0x027f,  //AE th. (Temporary. Don't move)
  0x2b41,  //Auto E-shutter enable
  0x3100,  //N.L. BT(Brightness)
  0x3208,  //L.L. BT(Brightness)
  0x3380,  //N.L. CT(Contrast)
  0x3479,  //L.L. CT(Contrast)
  0x3638,  //40 //3b  //38  //N.L. ST(saturation)
  0x372d,  //L.L. ST(saturation)
  0x6a00,  //BPR start point
  0x7b05,  //H.L. BPR
  0x3805,  //N.L. BPR
  0x3903,  //L.L. BPR
  0x2d12,  //1a  //18  //08  //N.L. NR gain
  0x2e2a,  //20  //N.L. NR edge
  0x2f2d,  //30 //L.L. NR gain
  0x30ff,  //L.L. NR edge
  0x7c02,  //06 //13  //0b  //06  //H.L. NR gain
  0x7d20,  //20  //H.L. NR edge
  0x7e0c,  //10 //0c  //M.L. NR gain
  0x7f50,  //M.L. NR edge
  0x2802,  //sharpness ON
  0x29ac,  //93 //N.L sharpness gain
  0x2a00,  //L.L sharpness gain
  0x1300,  //AWB Outdoor Cintr limit
  0x14a0,
  0x1a5b,  //Outdoor Rgain Max
  0x1b5a,  //5b //5d  //60  //59  //Outdoor Rgain Min
  0x1c78,  //Outdoor Bgain Max
  0x1d50,  //4d  //Outdoor Bgain Min
  0x1e65,  //6a  //Indoor Rgain Max
  0x1f44,  //Indoor Rgain Min
  0x2078,  //Indoor Bgain Max
  0x2142,  //50  //Indoor Bgain Min
  0x3a13,  //[7:4]AWB speed, [3:0] AWB threshold
  0x3b3D,  //37  //3a  //3C AWB skip BRT <= same value with AE target<3. 01>
  0x3c00,  //AWB skip Gain
  0x3d18,  //AWB skip AVG
  0x2380,  //AWB window select
  0x150b,  //AWB CNT
  0x16d2,
  0x1764,
  0x1878,
  
  0X1183,
  
  0xef00,  // X-shading
  0xde00,
  0xdf1F,
  0xe000,
  0xe137,
  0xe208,
  0xe342,
  0xe400,
  0xe512,
  0xe69E,
  0xe900,
  0xe701,
  0xe813,
  0xe901,
  0xe701,
  0xe806,
  0xe902,
  0xe700,
  0xe8EF,
  0xe903,
  0xe700,
  0xe8E0,
  0xe904,
  0xe700,
  0xe8C3,
  0xe905,
  0xe700,
  0xe8AB,
  0xe906,
  0xe700,
  0xe891,
  0xe907,
  0xe700,
  0xe8BD,
  0xe908,
  0xe700,
  0xe8AB,
  0xe909,
  0xe700,
  0xe89A,
  0xe90A,
  0xe700,
  0xe88F,
  0xe90B,
  0xe700,
  0xe878,
  0xe90C,
  0xe700,
  0xe869,
  0xe90D,
  0xe700,
  0xe855,
  0xe90E,
  0xe700,
  0xe84C,
  0xe90F,
  0xe700,
  0xe84D,
  0xe910,
  0xe700,
  0xe843,
  0xe911,
  0xe700,
  0xe839,
  0xe912,
  0xe700,
  0xe826,
  0xe913,
  0xe700,
  0xe81E,
  0xe914,
  0xe700,
  0xe80D,
  0xe915,
  0xe707,
  0xe8D8,
  0xe916,
  0xe707,
  0xe8D8,
  0xe917,
  0xe707,
  0xe8E1,
  0xe918,
  0xe707,
  0xe8DC,
  0xe919,
  0xe707,
  0xe8D3,
  0xe91A,
  0xe707,
  0xe8CB,
  0xe91B,
  0xe707,
  0xe8BE,
  0xe91C,
  0xe707,
  0xe862,
  0xe91D,
  0xe707,
  0xe866,
  0xe91E,
  0xe707,
  0xe871,
  0xe91F,
  0xe707,
  0xe880,
  0xe920,
  0xe707,
  0xe875,
  0xe921,
  0xe707,
  0xe867,
  0xe922,
  0xe707,
  0xe885,
  0xe940,
  
  0xd108,  //YC order [3]YC [2]RB
  0xdd03,  //X shade ON
  0x2317,  //GrGb
  0x2417,
  0x2517,
  0x2718,
  0x2960,
  0x2a22,
  0x2f01,  //INTP_COEF_sharpness
  0x3601,  //shading ON(R, G, B)
  0x37ba,  //c3  //c2  //ca  //c2  //bd  //4  //af  //bc  //b3  //84 //81 R Gain
  0x389b,  //a7  //70
  0x398e,  //96  //c  //83  //82  //57
  0x3a00,
  0x3bf0,  //dc  //d7 //C8 //f0
  0x3c01,
  0x3d40,  //a  //36 //2C //54
  0xb902,  //sharpness ON(HW initial)
  0xbbb0,  //HPF for sharpness
  0xbc18,
  0xbd30,
  0xbf38,  //sharpness Core
  0xc188,
  0xc811,  //YC delay
  0xeb81,  //ECs ON
  0xed05,  //ECs th.
  0xb100,  //AWB window
  0xb262,
  0xb300,
  0xb400,
  0xb501,
  0xb6a3,
  0xb702,
  0xb880,
  0x7700,  //HUE
  0x7810,  //25,
  0xef00,
  0x9340,  //AWB Map
  0x9480,
  0x95c0,
  0x96c0,
  0x9720,
  0x9820,
  0x9930,
  0xA000,
  0xA100,
  0xA21c,
  0xA316,
  0xA403,
  0xA507,
  0xA600,
  0xef00,
  0xadd0,  //AWB up data
  0xaf10,  //AWB dn data
  0xef00,
  0x424b,  //Rgain (start point of AWB)
  0x446a,  //Bgain (start point of AWB)
  0x5700,  //AE Min skip
  0xef03,
  0x013D,  //37  //3C AE target
  0x0205,  //AE threshold
  0x0320,  //AE step
  0x0467,  //AGC Max of LowLux
  0x061c,  //AGC Max of HL
  0x0701,  //AE win_A weight
  0x0803,  //AE win_B weight
  0x0b01,  //cintc max high
  0x5110,   //CHIP_DBG
  0x5200,
  0x5300,
  0x5400,
  0x5522,
  0x5601,
  0x5761,
  0x5825,
  0x67cf,   //AE speed
  0x6917,   //AE ROW FLAG
  0xef00,
  0x5800,  //AE window(무선 center weight)
  0x5900,
  0x5a02,
  0x5b73,
  0x5c00,
  0x5d00,
  0x5e01,
  0x5fe0,
  0x6000,
  0x61AE,
  0x6201,
  0x63bB,
  0x6400,
  0x657E,
  0x6601,
  0x678E,
  0xef00,  //Flicker setting
  0x6a01,  //080331 Flicker H sIZE High
  0x6be0,  //080331 Flicker H sIZE low
  0x6c05,  //04 //080331 Flicker WINDOW V0xIZE
  0x6d00,  //080331 Flicker V sIZE sTART H
  0x6e0e,  //080331 Flicker V sIZE sTART L
  0x6f00,  //080331 Flicker H sIZE sTART H
  0x7010,  //080331 Flicker H sIZE sTART L
  0xef03,
  0x2224,  //flicker 0xen0xitivity H/L
  0x3e23,
  0x3f23,
  0x4000,
  0x4109,  //60hz light - 50hz 0xetting threshold
  0x4a09,  //50hz light - 60hz 0xetting thresxhold
  0x4b04,
  0x5b20,  //detection haunting protection count
  0x5d35,
  0x5e13,
  0x780f,
  0xef00, //CCM
  0x4c79,
  0x4dbe,
  0x4e08,
  0x4f9c,
  0x507a,
  0x519e,
  0x528f,
  0x53bb,
  0x548a,
  0xef03,
  0x6e40,  //Dgain Min
  0x6f6a,  //Dgain Max
  0x7001, 
  0xef00,
  0x4800,
  0x4900,
  0x4A03,
  0x4801,
  0x4900,
  0x4A08,
  0x4802,
  0x4900,
  0x4A31,
  0x4803,
  0x4900,
  0x4A96,
  0x4804,
  0x4901,
  0x4A24,
  0x4805,
  0x4901,
  0x4AB4,
  0x4806,
  0x4902,
  0x4A23,
  0x4807,
  0x4902,
  0x4A72,
  0x4808,
  0x4902,
  0x4ABE,
  0x4809,
  0x4902,
  0x4AFA,
  0x480A,
  0x4903,
  0x4A27,
  0x480B,
  0x4903,
  0x4A55,
  0x480C,
  0x4903,
  0x4A81,
  0x480D,
  0x4903,
  0x4AA2,
  0x480E,
  0x4903,
  0x4ABC,
  0x480F,
  0x4903,
  0x4AD4,
  0x4810,
  0x4903,
  0x4AE8,
  0x4811,
  0x4903,
  0x4AF4,
  0x4812,
  0x4903,
  0x4AFF,
  
  0x4820,
  0x4900,
  0x4A03,
  0x4821,
  0x4900,
  0x4A08,
  0x4822,
  0x4900,
  0x4A31,
  0x4823,
  0x4900,
  0x4A96,
  0x4824,
  0x4901,
  0x4A24,
  0x4825,
  0x4901,
  0x4AB4,
  0x4826,
  0x4902,
  0x4A23,
  0x4827,
  0x4902,
  0x4A72,
  0x4828,
  0x4902,
  0x4ABE,
  0x4829,
  0x4902,
  0x4AFA,
  0x482A,
  0x4903,
  0x4A27,
  0x482B,
  0x4903,
  0x4A55,
  0x482C,
  0x4903,
  0x4A81,
  0x482D,
  0x4903,
  0x4AA2,
  0x482E,
  0x4903,
  0x4ABC,
  0x482F,
  0x4903,
  0x4AD4,
  0x4830,
  0x4903,
  0x4AE8,
  0x4831,
  0x4903,
  0x4AF4,
  0x4832,
  0x4903,
  0x4AFF,
  
  0x4840,
  0x4900,
  0x4A03,
  0x4841,
  0x4900,
  0x4A08,
  0x4842,
  0x4900,
  0x4A31,
  0x4843,
  0x4900,
  0x4A96,
  0x4844,
  0x4901,
  0x4A24,
  0x4845,
  0x4901,
  0x4AB4,
  0x4846,
  0x4902,
  0x4A23,
  0x4847,
  0x4902,
  0x4A72,
  0x4848,
  0x4902,
  0x4ABE,
  0x4849,
  0x4902,
  0x4AFA,
  0x484A,
  0x4903,
  0x4A27,
  0x484B,
  0x4903,
  0x4A55,
  0x484C,
  0x4903,
  0x4A81,
  0x484D,
  0x4903,
  0x4AA2,
  0x484E,
  0x4903,
  0x4ABC,
  0x484F,
  0x4903,
  0x4AD4,
  0x4850,
  0x4903,
  0x4AE8,
  0x4851,
  0x4903,
  0x4AF4,
  0x4852,
  0x4903,
  0x4AFF,
  
  0xef00, // RGB Shading 70%
  0x3601,
  0x3780,
  0x3873,
  0x3975,
  0x3a00,
  0x3bf0,
  0x3c01,
  0x3d40,
};

static const u32 reg_init_vga_vt_table[] = 
{
  0xef02,
  0x13a0,
  0x2353,
  0x2624,
  0x2c05,
  0x0500,
  0x0358,
  0x240a,
  0x0b81,
  0x1eb7,
  0x5605,
  0x2896,
  0x673c,
  0x4B5E,
  0xef03,
  0x50d2,
  0x0f31,
  0xef03,
  0x5F0f,
  0x600c,
  0x610f,
  0x620c,
  0x6305,
  0x6443,
  0x6505,
  0x6643,
  0x6d08,
  0x6e90,
  0x6f90,
  0x4c00,
  0x4d9e,
  0xef03,
  0x0007,
  0x0180,
  0x027f,
  0x2b41,
  
  0x3109, //05 NEO :: Normal Light Brightness Gain
  0x321e, //1a 12 //16 //14 //12 :: Low Light Brightness Gain
  
  0x3380, //NEO :: Normal Light Contrast Gain
  0x3479, //NEO :: Low Light Contrast Gain
  
  0x3634, //38 NEO :: Normal Light Saturation Gain
  0x3724, //2e 2b NEO :: Low Light Saturation Gain
  
  0x6a00,
  0x7b05,
  0x3805,
  0x3903,
  0x2d08,
  0x2e2c,
  0x2f35,  //4a
  0x30ff,
  0x7c06,
  0x7d2a,
  0x7e0c,
  0x7f2a,
  0x2802,
  0x298f,
  0x2a00,
  0x1300,
  0x14a0,
  0x1943,
  0x1a6a,
  0x1b5f,
  0x1c65,
  0x1d4e,
  0x1e6a,
  0x1f42,
  0x2090,
  0x214e,
  0x3a13,
  0x3b3e,
  0x3c00,
  0x3d18,
  0x2380,
  0x150b,
  
  0x16d2,
  0x1764,
  0x1878,
  
  0x1181,  //R-target
  0x1281,
  
  0xef00,
  0XDE00,
  0XDF1F,
  0XE000,
  0XE137,
  0XE208,
  0XE342,
  0XE400,
  0XE512,
  0XE69E,
  0XE900,
  0XE700,
  0XE881,
  0XE901,
  0XE700,
  0XE88B,
  0XE902,
  0XE700,
  0XE88A,
  0XE903,
  0XE700,
  0XE87D,
  0XE904,
  0XE700,
  0XE89B,
  0XE905,
  0XE700,
  0XE8A0,
  0XE906,
  0XE700,
  0XE8C2,
  0XE907,
  0XE700,
  0XE82E,
  0XE908,
  0XE700,
  0XE83C,
  0XE909,
  0XE700,
  0XE83E,
  0XE90A,
  0XE700,
  0XE82A,
  0XE90B,
  0XE700,
  0XE846,
  0XE90C,
  0XE700,
  0XE855,
  0XE90D,
  0XE700,
  0XE866,
  0XE90E,
  0XE707,
  0XE8E4,
  0XE90F,
  0XE707,
  0XE8EC,
  0XE910,
  0XE707,
  0XE8DF,
  0XE911,
  0XE707,
  0XE8D8,
  0XE912,
  0XE707,
  0XE8EB,
  0XE913,
  0XE707,
  0XE8EC,
  0XE914,
  0XE707,
  0XE8FD,
  0XE915,
  0XE707,
  0XE885,
  0XE916,
  0XE707,
  0XE888,
  0XE917,
  0XE707,
  0XE882,
  0XE918,
  0XE707,
  0XE876,
  0XE919,
  0XE707,
  0XE885,
  0XE91A,
  0XE707,
  0XE87C,
  0XE91B,
  0XE707,
  0XE89E,
  0XE91C,
  0XE707,
  0XE847,
  0XE91D,
  0XE707,
  0XE83B,
  0XE91E,
  0XE707,
  0XE82B,
  0XE91F,
  0XE707,
  0XE81E,
  0XE920,
  0XE707,
  0XE821,
  0XE921,
  0XE707,
  0XE827,
  0XE922,
  0XE707,
  0XE832,
  0XE940,
  0xd108,
  0xdd03,
  0x2310,
  0x2410,
  0x2510,
  0x2718,
  0x2960,
  0x2a22,
  0x2f01,
  0x3601,
  0x37ba,
  0x389b,
  0x398e,
  0x3a00,
  0x3bf5,
  0x3c01,
  0x3d36,
  0xb902,
  0xbbb0,
  0xbc18,
  0xbd30,
  0xbf38,
  0xc188,
  0xc811,
  0xeb81,
  0xed05,
  0xb100,
  0xb262,
  0xb300,
  0xb400,
  0xb501,
  0xb6a3,
  0xb702,
  0xb880,
  0x7700,
  0x7820,
  0xef00,
  0x9340,
  0x9480,
  0x95c0,
  0x96c0,
  0x9720,
  0x9820,
  0x9930,
  0xA000,
  0xA100,
  0xA21c,
  0xA316,
  0xA403,
  0xA507,
  0xA600,
  0xef00,
  0xadd0,
  0xaf10,
  0xef00,
  0x424a,
  0x4460,
  0x5700,
  0xef03,
  0x0003,
  0x013a, // NEO :: AE Target
  0x0203,
  0x0321, // NEO :: AE Step Guard (Stable Area인듯)
  0x0473, //72 //71 //73 NEO :: AE Low Light Max Gain
  0x061c,
  0x0701,
  0x0802,
  0x0b01,
  0x5110,
  
  
  0x5200,
  0x5300,
  0x5400,
  0x5522,
  0x5601,
  0x5761,
  0x5825,
  0x67cf,
  0x6917,
  0xef00,
  0x5800,
  0x5900,
  0x5a02,
  0x5b73,
  0x5c00,
  0x5d00,
  0x5e01,
  0x5fe0,
  0x6000,
  0x61b1,
  0x6201,
  0x63be,
  0x6400,
  0x6581,
  0x6601,
  0x6761,
  0xef00,
  0x6a01,
  0x6be0,
  0x6c05,
  0x6d00,
  0x6e0e,
  0x6f00,
  0x7010,
  0xef03,
  0x2224,
  0x3e23,
  0x3f23,
  0x4000,
  0x4109,
  0x4a09,
  0x4b04,
  0x5b20,
  0x5d35,
  0x5e13,
  0x780f,
  0xef00,
  0x4c79,
  0x4dbe,
  0x4e08,
  0x4f9c,
  0x507a,
  0x519e,
  0x528f,
  0x53bb,
  0x548a,
  0xef03,
  0x6e40,
  0x6f40,
  
  0xef00,  //RGB Gamma (Feburary updated version for 계조구분)
  0x4800,     //0x4800,
  0x4900,     //0x4900,
  0x4A03,     //0x4A03,
  0x4801,     //0x4801,
  0x4900,     //0x4900,
  0x4A08,     //0x4A08,
  0x4802,     //0x4802,
  0x4900,     //0x4900,
  0x4A38,     //0x4A38,
  0x4803,     //0x4803,
  0x4900,     //0x4900,
  0x4A96,     //0x4A96,
  0x4804,     //0x4804,
  0x4901,     //0x4901,
  0x4A24,     //0x4A24,
  0x4805,     //0x4805,
  0x4901,     //0x4901,
  0x4Aac,     //0x4Aac,
  0x4806,     //0x4806,
  0x4902,     //0x4902,
  0x4A18,     //0x4A18,
  0x4807,     //0x4807,
  0x4902,     //0x4902,
  0x4A6e,     //0x4A6e,
  0x4808,     //0x4808,
  0x4902,     //0x4902,
  0x4ABE,     //0x4ABE,
  0x4809,     //0x4809,
  0x4902,     //0x4902,
  0x4AFA,     //0x4AFA,
  0x480A,     //0x480A,
  0x4903,     //0x4903,
  0x4A27,     //0x4A27,
  0x480B,     //0x480B,
  0x4903,     //0x4903,
  0x4A55,     //0x4A55,
  0x480C,     //0x480C,
  0x4903,     //0x4903,
  0x4A81,     //0x4A81,
  0x480D,     //0x480D,
  0x4903,     //0x4903,
  0x4AA2,     //0x4AA2,
  0x480E,     //0x480E,
  0x4903,     //0x4903,
  0x4ABC,     //0x4ABC,
  0x480F,     //0x480F,
  0x4903,     //0x4903,
  0x4AD2,     //0x4AD2,
  0x4810,     //0x4810,
  0x4903,     //0x4903,
  0x4Ae4,     //0x4Ae4,
  0x4811,     //0x4811,
  0x4903,     //0x4903,
  0x4af0,     //0x4af0,
  0x4812,     //0x4812,
  0x4903,     //0x4903,
  0x4AFa,     //0x4AFa,
       //
  0x4820,     //0x4820,
  0x4900,     //0x4900,
  0x4A03,     //0x4A03,
  0x4821,     //0x4821,
  0x4900,     //0x4900,
  0x4A08,     //0x4A08,
  0x4822,     //0x4822,
  0x4900,     //0x4900,
  0x4A38,     //0x4A38,
  0x4823,     //0x4823,
  0x4900,     //0x4900,
  0x4A96,     //0x4A96,
  0x4824,     //0x4824,
  0x4901,     //0x4901,
  0x4A24,     //0x4A24,
  0x4825,     //0x4825,
  0x4901,     //0x4901,
  0x4Aac,     //0x4Aac,
  0x4826,     //0x4826,
  0x4902,     //0x4902,
  0x4A18,     //0x4A18,
  0x4827,     //0x4827,
  0x4902,     //0x4902,
  0x4A6e,     //0x4A6e,
  0x4828,     //0x4828,
  0x4902,     //0x4902,
  0x4ABE,     //0x4ABE,
  0x4829,     //0x4829,
  0x4902,     //0x4902,
  0x4AFA,     //0x4AFA,
  0x482A,     //0x482A,
  0x4903,     //0x4903,
  0x4A27,     //0x4A27,
  0x482B,     //0x482B,
  0x4903,     //0x4903,
  0x4A55,     //0x4A55,
  0x482C,     //0x482C,
  0x4903,     //0x4903,
  0x4A81,     //0x4A81,
  0x482D,     //0x482D,
  0x4903,     //0x4903,
  0x4AA2,     //0x4AA2,
  0x482E,     //0x482E,
  0x4903,     //0x4903,
  0x4ABC,     //0x4ABC,
  0x482F,     //0x482F,
  0x4903,     //0x4903,
  0x4AD2,     //0x4AD2,
  0x4830,     //0x4830,
  0x4903,     //0x4903,
  0x4Ae4,     //0x4Ae4,
  0x4831,     //0x4831,
  0x4903,     //0x4903,
  0x4af0,     //0x4af0,
  0x4832,     //0x4832,
  0x4903,     //0x4903,
  0x4AFa,     //0x4AFa,
       //
  0x4840,     //0x4840,
  0x4900,     //0x4900,
  0x4A04,     //0x4A03,
  0x4841,     //0x4841,
  0x4900,     //0x4900,
  0x4A0a,     //0x4A08,
  0x4842,     //0x4842,
  0x4900,     //0x4900,
  0x4A3c,     //0x4A38,
  0x4843,     //0x4843,
  0x4900,     //0x4900,
  0x4A9c,     //0x4A96,
  0x4844,     //0x4844,
  0x4901,     //0x4901,
  0x4A24,     //0x4A24,
  0x4845,     //0x4845,
  0x4901,     //0x4901,
  0x4Abe,     //0x4Aac,
  0x4846,     //0x4846,
  0x4902,     //0x4902,
  0x4A18,     //0x4A18,
  0x4847,     //0x4847,
  0x4902,     //0x4902,
  0x4A77,     //0x4A6e,
  0x4848,     //0x4848,
  0x4902,     //0x4902,
  0x4ABE,     //0x4ABE,
  0x4849,     //0x4849,
  0x4902,     //0x4902,
  0x4AFc,     //0x4AFA,
  0x484A,     //0x484A,
  0x4903,     //0x4903,
  0x4A2a,     //0x4A27,
  0x484B,     //0x484B,
  0x4903,     //0x4903,
  0x4A55,     //0x4A55,
  0x484C,     //0x484C,
  0x4903,     //0x4903,
  0x4A81,     //0x4A81,
  0x484D,     //0x484D,
  0x4903,     //0x4903,
  0x4AA2,     //0x4AA2,
  0x484E,     //0x484E,
  0x4903,     //0x4903,
  0x4ABC,     //0x4ABC,
  0x484F,     //0x484F,
  0x4903,     //0x4903,
  0x4AD2,     //0x4AD2,
  0x4850,     //0x4850,
  0x4903,     //0x4903,
  0x4Ae4,     //0x4Ae4,
  0x4851,     //0x4851,
  0x4903,     //0x4903,
  0x4af0,     //0x4af0,
  0x4852,     //0x4852,
  0x4903,     //0x4903,
  0x4AFa,     //0x4AFa,
};

static const u32 reg_resize_qcif_table[] = 
{
  0xef00,  //Resizing to 176x144
  0x7a00,
  0x8100,
  0x82b8,
  0x7f00,
  0x8098,
  0xc204, // Capture Cut V size 4
  0xc304, // Capture Cut H size 4  
  0xc600,
  0xc7b0,
  0xc400,
  0xc590,
  0x7a02,
  0x7a03,
};

static const u32 reg_resize_ivs_qcif_table[] = 
{
  0xef00, // 144X176
  0x7a00,
  0x7f00, // Destination V size
  0x80BC, // 188
  0x8100, // Destination H size
  0x82F8, // 248
  0xc206, // Capture Cut V size 6
  0xc334, // Capture Cut H size 52
  0xc400, // Capture V size
  0xc5B0, // 176
  0xc600, // Capture H size
  0xc790, // 144
  0x7a02,
  0x7a03, 
};

static const u32 reg_resize_cif_table[] = 
{
  0xef00,  //Resizing to 352x288
  0x7a00,
  0x8101,
  0x8268,
  0x7f01,
  0x8028,
  0xc204, // Capture Cut V size 4
  0xc304, // Capture Cut H size 4   
  0xc601,
  0xc760,
  0xc401,
  0xc520,
  0x7a02,
  0x7a03, 
};

static const u32 reg_resize_ivs_cif_table[] = 
{
  0xef00, // 288X352
  0x7a00,
  0x7f01, // Destination V size
  0x8070, // 368
  0x8101, // Destination H size
  0x82E8, // 488
  0xc208, // Capture Cut V size 8
  0xc364, // Capture Cut H size 100
  0xc401, // Capture V size
  0xc560, // 352
  0xc601, // Capture H size
  0xc720, // 288
  0x7a02,
  0x7a03,  
};

static const u32 reg_resize_qvga_table[] = 
{
  0xef00,  //Resizing to 320x240
  0x7a00,
  0x8101,
  0x8248,
  0x7f00,
  0x80f8,
  0xc204, // Capture Cut V size 4
  0xc304, // Capture Cut H size 4   
  0xc601,
  0xc740,
  0xc400,
  0xc5f0,
  0x7a02,
  0x7a03,  
};

static const u32 reg_resize_ivs_qvga_table[] = 
{
  0xef00, // 240X320
  0x7a00,
  0x7f01, // Destination V size
  0x8070, // 368
  0x8101, // Destination H size
  0x82E8, // 488
  0xc218, // Capture Cut V size 24
  0xc37c, // Capture Cut H size 124
  0xc401, // Capture V size
  0xc540, // 320
  0xc600, // Capture H size
  0xc7F0, // 240
  0x7a02,
  0x7a03, 
};

static const u32 reg_resize_vga_table[] = 
{
  0xef00,  //Resizing to 640x480
  0x7a00,
  0x8102,
  0x8288,
  0x7f01,
  0x80E8,
  0xc204, // Capture Cut V size 4
  0xc304, // Capture Cut H size 4    
  0xc602,
  0xc780,
  0xc401,
  0xc5E0,
  0x7a02,
  0x7a01,
};

/************** White Balance Setting ******************/
/* Modified to SEHF Variable */
static const u32 reg_wb_auto_table[] = 
{
  0xef03,
  0x0087,  
  0xef00,  
  0x426f,  
  0x4340,  
  0x445a,  
};

static const u32 reg_wb_daylight_table[] = 
{
  0xef03,
  0x0085,  
  0xef00,  
  0x4267,  
  0x4340,  
  0x444c,    
};

static const u32 reg_wb_incandescent_table[] = 
{
  0xef03,
  0x0085,  
  0xef00,  
  0x4248,  
  0x4343,  
  0x447e,  
};

static const u32 reg_wb_fluorescent_table[] = 
{
  0xef03,
  0x0085,  
  0xef00,  
  0x425c,  
  0x4340,  
  0x446d, 
};

static const u32 reg_wb_cloudy_table[] = 
{
  0xef03,
  0x0085,  
  0xef00,  
  0x426f,  
  0x433d,  
  0x4447,    
};


/************** Exposure Value Setting ****************/
/* Modified to SEHF Variable */
static const u32 reg_ev_table[] = 
{
  0xef03, //Page 03
  
  0x31a8, //EV_0 
  0x3298, 
  0x3198, //EV_1
  0x3290,
  0x3190, //EV_2
  0x3288,
  0x3188, //EV_3
  0x3200,
  0x3100, //EV_4
  0x3208,
  0x3108, //EV_5
  0x3210,
  0x3110, //EV_6
  0x3220,
  0x3118, //EV_7
  0x3230,
  0x3128, //EV_8 
  0x3238,
  0x3130, //EV_9 
  0x3240,
  0x3138, //EV_10 
  0x3248,
};

static const u32 reg_ev_vt_table[] =
{
  0xef03, //Page 03

  0x31a4, //EV_0 
  0x328a, 
  0x3194, //EV_1
  0x3206,
  0x3187, //EV_2
  0x320e,
  0x3101, //EV_3
  0x3216,
  0x3109, //EV_4
  0x321e,
  0x3111, //EV_5
  0x3226,
  0x3119, //EV_6
  0x322e,
  0x3121, //EV_7
  0x3236,
  0x3131, //EV_8 
  0x3246,
  0x3139, //EV_9 
  0x324e,
  0x3141, //EV_10 
  0x3256,
};


/************** Effect Setting ********************/
/* Modified to SEHF Variable */
static const u32 reg_effect_none_table[] = 
{
  0xef00,
  0xd300,
  0xd400,
  0xd501,
  0xd6a3,
};

static const u32 reg_effect_gray_table[] = 
{
  0xef00,
  0xd300,
  0xd403,
  0xd580,
  0xd680,
};

static const u32 reg_effect_sepia_table[] = 
{
  0xef00,
  0xd300,
  0xd403,
  0xd560,
  0xd68c,
};

static const u32 reg_effect_negative_table[] = 
{
  0xef00,
  0xd301,
  0xd400,
  0xd52c,
  0xd681,
};

static const u32 reg_effect_aqua_table[] = 
{
  0xef00,
  0xd300,
  0xd403,
  0xd5dc,
  0xd600,
};

static const u32 reg_effect_red_table[] = 
{
  0xef00,
  0xd300,
  0xd413,
  0xd5aa,
  0xd681,
};

static const u32 reg_effect_green_table[] = 
{
  0xef00,
  0xd300,
  0xd403,
  0xd52c,
  0xd641,
};


/************** Pretty Setting ********************/
/* Modified to SEHF Variable */
static const u32 reg_pretty_none_table[] = 
{
  0xef03,
  0x013c,
  0x2985,
  0x3479,
};

static const u32 reg_pretty_level1_table[] = 
{
  0xef03,
  0x014a,
  0x2955,
  0x3489,
};

static const u32 reg_pretty_level2_table[] = 
{
  0xef03,
  0x0158,
  0x2925,
  0x3499,
};

static const u32 reg_pretty_level3_table[] = 
{
  0xef03,
  0x0166,
  0x2900,
  0x34a9,
}; 

static const u32 reg_pretty_vt_none_table[] =
{
  0xef03,
  0x013c,
  0x2985,
  0x3479,
};

static const u32 reg_pretty_vt_level1_table[] =
{
  0xef03,
  0x014a,
  0x2955,
  0x3489,
};

static const u32 reg_pretty_vt_level2_table[] =
{
  0xef03,
  0x0158,
  0x2925,
  0x3499,
};

static const u32 reg_pretty_vt_level3_table[] =
{
  0xef03,
  0x0166,
  0x2900,
  0x34a9,
}; 


/************** Flip Setting ********************/
/* Modified to SEHF Variable */
static const u32 reg_flip_none_table[] = 
{
  0xef03,
  0x7000,
};

static const u32 reg_flip_mirror_table[] = 
{
  0xef03,
  0x7001,
};

static const u32 reg_flip_water_table[] = 
{
  0xef03,
  0x7002,
};

static const u32 reg_flip_water_mirror_table[] = 
{
  0xef03,
  0x7003,
};

static const u32 reg_fps_7_table[] = 
{
  0xEF03,
  
  0x5F03, //NT Cintr Max
  0x6002, //PAL Cintr Max
  0x6111, //NT shutter Max (Fixed mode)
  0x620E, //PAL shutter Max (Fixed mode)
  
  0x6306, //NT Vblank
  0x644B,
  0x6506, //PAL Vblank
  0x664B,
  0x4800, //NT Hblank
  0x499E,
  0x4C00, //PAL Hblank
  0x4D9E,
  0xEF03,
  0x5110,
  0x5200,
  0x5300,
  0x5400,
  0x5601,
  0x5761,
  0x5825,
  0x67CF,
};

static const u32 reg_fps_10_table[] = 
{
  0xEF03,
  
  0x5F03, //NT Cintr Max
  0x6002, //PAL Cintr Max
  0x610C, //NT shutter Max (Fixed mode)
  0x620A, //PAL shutter Max (Fixed mode)
  
  0x6303, //NT Vblank
  0x64D3,
  0x6503, //PAL Vblank
  0x66D3,
  0x4800, //NT Hblank
  0x499E,
  0x4C00, //PAL Hblank
  0x4D9E,
  0xEF03,
  0x5110,
  0x5200,
  0x5300,
  0x5400,
  0x5601,
  0x5761,
  0x5825,
  0x67CF,
};

static const u32 reg_fps_12_table[] = 
{
  0xEF03,
  
  0x5F03, //NT Cintr Max
  0x6002, //PAL Cintr Max
  0x610A, //NT shutter Max (Fixed mode)
  0x6208, //PAL shutter Max (Fixed mode)
  
  0x6302, //NT Vblank
  0x64DD,
  0x6502, //PAL Vblank
  0x66DD,
  0x4800, //NT Hblank
  0x499E,
  0x4C00, //PAL Hblank
  0x4D9E,
  0xEF03,
  0x5110,
  0x5200,
  0x5300,
  0x5400,
  0x5601,
  0x5761,
  0x5825,
  0x67CF,
};

static const u32 reg_fps_15_table[] = 
{
  0xEF03,
  
  0x5F03, //NT Cintr Max
  0x6002, //PAL Cintr Max
  0x6108, //NT shutter Max (Fixed mode)
  0x6206, //PAL shutter Max (Fixed mode)
  
  0x6301, //NT Vblank
  0x64E7,
  0x6501, //PAL Vblank
  0x66E7,
  0x4800, //NT Hblank
  0x499E,
  0x4C00, //PAL Hblank
  0x4D9E,
  0xEF03,
  0x5110,
  0x5200,
  0x5300,
  0x5400,
  0x5601,
  0x5761,
  0x5825,
  0x67CF,
};

#endif
#endif //#ifndef CAMIF_REG_CONFIG_H_
