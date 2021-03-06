/***************************************************************************
* Copyright  Novatek Microelectronics Corp. 2008.  All rights reserved.    *
*--------------------------------------------------------------------------*
* Name: IQSetting_MI5100_630.c                                           *
* Description:     IQ setting of Alg                                      *
* Author: YH                                                           *
****************************************************************************/
#include "sensor_model.h"
#include "grph.h"
#if MI5100_630
__align(4) IPE_ISO_PARAM  IPE_ISOParam[Total_ISONum] =
{
//                  NRSel,            NStabSel,            NDtabSel,            FStabSel,            FDtabsel,                EdgeSel,                     KerSel,                EmapSel,            EStabSel
    {IPE_NRParam[ISONUM0], IPE_nrStab[ISONUM0], IPE_nrDtab[ISONUM0], IPE_fmStab[ISONUM0], IPE_fmDtab[ISONUM0], IPE_EdgeParam[ISONUM0], IPE_edgeKernelDiv[ISONUM0], IPE_emap16tab[ISONUM0], IPE_emStab[ISONUM0]},
    {IPE_NRParam[ISONUM1], IPE_nrStab[ISONUM1], IPE_nrDtab[ISONUM1], IPE_fmStab[ISONUM1], IPE_fmDtab[ISONUM1], IPE_EdgeParam[ISONUM1], IPE_edgeKernelDiv[ISONUM1], IPE_emap16tab[ISONUM1], IPE_emStab[ISONUM1]},
    {IPE_NRParam[ISONUM2], IPE_nrStab[ISONUM2], IPE_nrDtab[ISONUM2], IPE_fmStab[ISONUM2], IPE_fmDtab[ISONUM2], IPE_EdgeParam[ISONUM2], IPE_edgeKernelDiv[ISONUM2], IPE_emap16tab[ISONUM2], IPE_emStab[ISONUM2]},
    {IPE_NRParam[ISONUM3], IPE_nrStab[ISONUM3], IPE_nrDtab[ISONUM3], IPE_fmStab[ISONUM3], IPE_fmDtab[ISONUM3], IPE_EdgeParam[ISONUM3], IPE_edgeKernelDiv[ISONUM3], IPE_emap16tab[ISONUM3], IPE_emStab[ISONUM3]},
    {IPE_NRParam[ISONUM4], IPE_nrStab[ISONUM4], IPE_nrDtab[ISONUM4], IPE_fmStab[ISONUM4], IPE_fmDtab[ISONUM4], IPE_EdgeParam[ISONUM4], IPE_edgeKernelDiv[ISONUM4], IPE_emap16tab[ISONUM4], IPE_emStab[ISONUM4]}, //capture_ISO1
    {IPE_NRParam[ISONUM5], IPE_nrStab[ISONUM5], IPE_nrDtab[ISONUM5], IPE_fmStab[ISONUM5], IPE_fmDtab[ISONUM5], IPE_EdgeParam[ISONUM5], IPE_edgeKernelDiv[ISONUM5], IPE_emap16tab[ISONUM5], IPE_emStab[ISONUM5]}, //capture_ISO2
    {IPE_NRParam[ISONUM6], IPE_nrStab[ISONUM6], IPE_nrDtab[ISONUM6], IPE_fmStab[ISONUM6], IPE_fmDtab[ISONUM6], IPE_EdgeParam[ISONUM6], IPE_edgeKernelDiv[ISONUM6], IPE_emap16tab[ISONUM6], IPE_emStab[ISONUM6]}  //capture_ISO3
};

__align(4) STR_IPE_NOVANR2_PARA IPE_NRParam[Total_ISONum][16]=
{
//   RBW, GW, GBAL, OUTL, OutlRbw, OutlGw, Honly, Nsndir, Nsvsb, NsGain, Nsmar, Lpfw, Sumsel, Dthr,         Nthr[4]
    {12,    8,    0,    0,       0,      0,     0,      0,     2,     64,     8,    5,      0,   96, { 24,  18,  18,  24}},     //ISONUM0
    {24,   16,    0,    1,       4,      4,     0,      0,     6,     64,    12,    5,      0,   96, { 32,  24,  24,  32}},     //ISONUM1
    {36,   24,    0,    1,       8,      8,     0,      0,    10,     64,    16,    5,      0,   96, { 48,  32,  32,  48}},     //ISONUM2
    {48,   32,    0,    1,      12,     12,     0,      0,    20,     64,    20,    5,      0,   96, { 64,  48,  48,  64}},   //ISONUM3
    
    {16,   16,    0,    0,       0,      0,     0,      0,     2,     64,    18,    7,      0,   86, { 24,  18,  18,  24}},     //capture_ISO1
    {32,   32,    0,    1,      16,     16,     0,      0,    15,     64,    48,    5,      0,   60, { 64,  48,  48,  64}},     //capture_ISO2
    {60,   60,    0,    1,      32,     32,     0,      0,    15,     64,    80,    3,      0,   60, { 90,  76,  76,  90}}      //capture_ISO3
};
__align(4) STR_IPE_EDGE_ENHMAP_PARA IPE_EdgeParam[Total_ISONum][5]=
{
//  Enh, EthrA, EthrB, EtabA, EtabB
    //{  120,      16,    256,         3,        3},  //ISONUM0
    {  100,       4,    256,         1,        3},  //ISONUM0
//    {  120,       4,    256,         1,        3},  //ISONUM0
    {   90,       8,    256,         3,        4},  //ISONUM1
//    {  100,       8,    256,         3,        4},  //ISONUM1
    {   80,      16,    256,         4,        5},  //ISONUM2
//    {   70,      16,    256,         4,        5},  //ISONUM2
    {   70,      30,    256,         4,        5},  //ISONUM3
//    {   70,      30,    256,         4,        5},  //ISONUM3
    {  100,      30,    624,         2,        3},  //capture_ISO1
    {   80,      30,    624,         2,        3},  //capture_ISO2
    {   70,      30,    624,         4,        4},  //capture_ISO3
};

//#NT#2009/12/02#Jarkko Chang -begin
__align(4) UINT32 Sharpness[Total_ISONum][Max_Sharp+1] = {
//    _IMGSharp_P1,_IMGSharp_Normal,_IMGSharp_N1
    {   300,        100,             25}, //ISONUM0
    {   210,         70,             17}, //ISONUM1
    {   180,         60,             15}, //ISONUM2
    {   150,         50,             12}, //ISONUM3
    {   300,        100,             25}, //Capture_ISO1
    {   240,         80,             20}, //Capture_ISO2
    {   210,         70,             15}  //Capture_ISO3
};
//#NT#2009/12/02#Jarkko Chang -end

__align(4) STR_IPE_EDGE_KER_PARA IPE_AFedgeKernelDiv[11]=
    { 12, 8, 2, 0, -6, 0, 0, -4, -1, 5, 1};

__align(4) STR_IPE_EDGE_KER_PARA IPE_edgeKernelDiv[Total_ISONum][11]=
{
#if 1
    { 12, 8, 2, 0, -6, 0, 0, -4, -1, 3, 1}, //ISONUM0
    { 12, 8, 2, 0, -6, 0, 0, -4, -1, 3, 1}, //ISONUM1
    { 12, 8, 2, 0, -6, 0, 0, -4, -1, 3, 1}, //ISONUM2
#else
    {  8, 1,-1, 1, -1, 1,-1, -1, -1, 2, 1}, //ISONUM0
    {  8, 1,-1, 1, -1, 1,-1, -1, -1, 2, 1}, //ISONUM1
    {  8, 1,-1, 1, -1, 1,-1, -1, -1, 2, 1}, //ISONUM2
#endif    
    { 12, 8, 2, 0, -6, 0, 0, -4, -1, 3, 1}, //ISONUM3
    { 12, 8, 2, 0, -6, 0, 0, -4, -1, 3, 1}, //capture_ISO1
    { 12, 8, 2, 0, -6, 0, 0, -4, -1, 3, 1}, //capture_ISO2
    { 12, 8, 2, 0, -6, 0, 0, -4, -1, 3, 1}  //capture_ISO3
};

 __align(4) UINT8 IPE_nrStab[Total_ISONum][16]=
{
    {255,255,240,224,192,160,128,96,64,32,16,8,0,0,0,0},            //ISONUM0
    {255,255,255,240,224,192,160,128,96,64,32,16,8,0,0,0},          //ISONUM1
    {255,255,255,240,224,192,160,128,96,64,32,16,8,0,0,0},          //ISONUM2
    {255,255,255,255,240,224,192,160,128,96,64,32,16,8,0,0},          //ISONUM3
    {255,255,240,224,192,160,128,96,64,32,16,8,0,0,0,0},            //Capture_ISO1
    {255,255,255,240,224,192,160,128,96,64,32,16,8,0,0,0},          //Capture_ISO2
    {255,255,255,255,240,224,192,160,128,96,64,32,16,8,0,0}           //Capture_ISO3
};
 __align(4) UINT8 IPE_nrDtab[Total_ISONum][16]=
{
    {255,240,224,192,160,128,112,96,80,64,48,32,16,8,4,0},          //ISONUM0
    {255,255,255,240,224,192,160,128,96,64,32,16,8,0,0,0},          //ISONUM1
    {255,255,255,240,224,192,160,128,96,64,32,16,8,0,0,0},          //ISONUM2
    {255,255,255,255,240,224,192,160,128,96,64,32,16,8,0,0},          //ISONUM3
    {255,240,224,192,160,128,112,96,80,64,48,32,16,8,4,0},          //Captrure_ISO1
    {255,255,255,240,224,192,160,128,96,64,32,16,8,0,0,0},          //Captrure_ISO2
    {255,255,255,255,240,224,192,160,128,96,64,32,16,8,0,0}           //Captrure_ISO3
};
 __align(4) UINT8 IPE_fmStab[Total_ISONum][16]=
{
    {154,110,64,32,16,8,4,2,0,0,0,0,0,0,0,0},      //ISONUM0
    {255,184,128,64,32,16,8,4,2,0,0,0,0,0,0,0},      //ISONUM1
    {255,255,184,128,64,32,16,8,4,2,0,0,0,0,0,0},      //ISONUM2
    {255,255,240,213,155,90,52,28,13,6,3,0,0,0,0,0}, //ISONUM3
    
    {255,97,0,0,0,0,0,0,0,0,0,0,0,0,0,0},               //Capture_ISO1
    {180,154,110,64,32,16,8,4,2,0,0,0,0,0,0,0},      //Capture_ISO2
    {180,154,110,64,32,16,8,4,2,0,0,0,0,0,0,0}       //Capture_ISO3
};
 __align(4) UINT8 IPE_fmDtab[Total_ISONum][16]=
{
    {128,96,64,32,16,8,4,2,0,0,0,0,0,0,0,0},          //ISONUM0
    {128,96,64,32,16,8,4,2,0,0,0,0,0,0,0,0},    //ISONUM1
    {128,96,64,32,16,8,4,2,0,0,0,0,0,0,0,0},    //ISONUM2
    {128,96,64,32,16,8,4,2,0,0,0,0,0,0,0,0},    //ISONUM3
    
    {255,90,26,0,0,0,0,0,0,0,0,0,0,0,0,0},          //Capture_ISO1
    {128,96,64,32,16,8,4,2,0,0,0,0,0,0,0,0},    //Capture_ISO2
    {128,96,64,32,16,8,4,2,0,0,0,0,0,0,0,0}     //Capture_ISO3
};
 __align(4) UINT8 IPE_emap16tab[Total_ISONum][16]=
{
    //{12,24,36,56,96,146,200,255,255,200,146,96,56,36,24,12},     //ISONUM0
    {20,36,56,64,96,146,200,255,255,200,146,96,56,36,24,12},     //ISONUM0    
    //{12,24,36,56,96,146,200,255,236,200,146,96,56,36,24,12},     //ISONUM1
    {20,36,56,64,96,146,200,255,255,200,146,96,56,36,24,12},     //ISONUM1
    {12,24,36,56,96,146,200,255,210,160,120,80,56,36,24,12},     //ISONUM2
    {12,24,36,56,96,146,200,255,210,160,120,80,56,36,24,12},     //ISONUM3
    {12,24,36,56,96,146,200,255,255,228,196,160,128,96,64,32},   //Capture_ISO1
    {12,24,36,56,96,146,200,255,255,228,196,160,128,96,64,32},   //Capture_ISO2
    {12,24,36,56,96,146,200,255,255,228,196,160,128,96,64,32}    //Capture_ISO3
};
  __align(4) UINT8 IPE_emStab[Total_ISONum][16]=
 {
 #if 0
     {64,64,64,64,64,68,72,76,80,84,88,92,96,100,104,108}, //ISONUM0
     {64,64,64,64,64,68,72,76,80,84,88,92,96,100,104,108}, //ISONUM1
     {64,64,64,64,64,68,72,76,80,84,88,92,96,100,104,108}, //ISONUM2
     {64,64,64,64,64,68,72,76,80,84,88,92,96,100,104,108}, //ISONUM3
#endif     
     {30,40,50,60,64,68,72,76,80,76,72,68,64,60,50,40}, //ISONUM0
     {30,40,50,60,64,68,72,76,80,76,72,68,64,60,50,40}, //ISONUM1
//     {30,40,50,60,64,68,72,76,80,84,88,92,96,100,104,108}, //ISONUM0
  //   {30,40,50,60,64,68,72,76,80,84,88,92,96,100,104,108}, //ISONUM1
     {20,30,40,50,60,68,72,76,80,84,88,92,96,100,104,108}, //ISONUM2
     {10,20,30,40,50,60,70,76,80,84,88,92,96,100,104,108}, //ISONUM3

     {64,64,64,64,64,68,72,76,80,84,88,92,96,100,104,108}, //Capture_ISO1
     {64,64,64,64,64,68,72,76,80,84,88,92,96,100,104,108}, //Capture_ISO2
     {64,64,64,64,64,68,72,76,80,84,88,92,96,100,104,108}  //Capture_ISO3
 };

__align(4) UINT CHR_Param[5][28];
/*
__align(4) UINT CHR_Param[5][28] ={

    {0, 0, 0, LPF_LENGTH12, LPF_LENGTH4, LPF_LENGTH4, LPF_LENGTH0, LPF_LENGTH0, LPF_LENGTH0, 0x1FEFF, AVG_NORM16, 0, CHR_OUT_NORMAL,
     0, 63, 127, 3, CHR_EDGDET_SHFN0, CHR_EDGDET_OUT_ORI, 16, 0, 63, 127, 3, 3, CHR_EDGENH_OUT_DISABLE, 1, 1},
    {0, 0, 0, LPF_LENGTH16, LPF_LENGTH6, LPF_LENGTH6, LPF_LENGTH2, LPF_LENGTH0, LPF_LENGTH0, 0x1FEFF, AVG_NORM16, 0, CHR_OUT_NORMAL,
     0, 63, 127, 3, CHR_EDGDET_SHFN0, CHR_EDGDET_OUT_ORI, 16, 0, 63, 127, 3, 3, CHR_EDGENH_OUT_DISABLE, 1, 1},
    {0, 0, 0, LPF_LENGTH16, LPF_LENGTH6, LPF_LENGTH6, LPF_LENGTH2, LPF_LENGTH0, LPF_LENGTH0, 0x1FEFF, AVG_NORM16, 6, CHR_OUT_NORMAL,
     0, 63, 127, 3, CHR_EDGDET_SHFN0, CHR_EDGDET_OUT_ORI, 16, 0, 63, 127, 3, 3, CHR_EDGENH_OUT_DISABLE, 1, 1},
    {0, 0, 0, LPF_LENGTH16, LPF_LENGTH6, LPF_LENGTH6, LPF_LENGTH2, LPF_LENGTH0, LPF_LENGTH0, 0x1FEFF, AVG_NORM16, 7, CHR_OUT_AVG,
     0, 63, 127, 3, CHR_EDGDET_SHFN0, CHR_EDGDET_OUT_ORI, 16, 0, 63, 127, 3, 3, CHR_EDGENH_OUT_DISABLE, 1, 2},
    {0, 0, 0, LPF_LENGTH16, LPF_LENGTH6, LPF_LENGTH6, LPF_LENGTH2, LPF_LENGTH0, LPF_LENGTH0, 0x1FEFF, AVG_NORM16, 7, CHR_OUT_AVG,
     0, 63, 127, 3, CHR_EDGDET_SHFN0, CHR_EDGDET_OUT_ORI, 16, 0, 63, 127, 3, 3, CHR_EDGENH_OUT_DISABLE, 1, 3},
};
*/
__align(4)INT16 Indenity_CC[9] = {
    0x004C, 0x0096, 0x001D,
    0x07D5, 0x07AB, 0x0080,
    0x0080, 0x0795, 0x07EB
};

#if 0
//orig
__align(4)INT16 Normal_CC[9] = {
0x4c,0x96,0x1d,
0x7bc,0x6cd,0x178,
0x11d,0x6f4,0x7f0
};
#elif 0 //spark_0601
__align(4)INT16 Normal_CC[9] = {
0x4c,		0x96,		0x1d,
0x7da,		0x730,		0xf7,
0xbf,		0x746,		0x7fb
};
#elif 1 //Jarkko 0608
__align(4)INT16 Normal_CC[9] = {
0x4c,0x96,0x1d,
0x7bd,0x725,0x11e,
0x119,0x6dd,0x9
};
#elif 0
//0201
__align(4)INT16 Normal_CC[9] = {
0x4c,0x96,0x1d,
0x7c3,0x72d,0x111,
0xf0,0x702,0xd
};
#else   //0527
__align(4)INT16 Normal_CC[9] = {
0x4c,0x96,0x1d,
0x7a8,0x764,0xf4,
0xf1,0x72a,0x7e6
};
#endif

__align(4)INT16 Normal_CC_Video[9] = {
0x4c,0x96,0x1d,
0x7ba,0x6ff,0x148,
0x120,0x6eb,0x7f5
};

__align(4)UINT32 GammaLUT_128Tab[130]={
#if 0   //0608_prv
   0,  16,  32,  48,  64,  87, 110, 133, 156, 177,
 199, 220, 242, 258, 275, 292, 305, 317, 330, 342,
 353, 363, 373, 383, 394, 404, 414, 423, 432, 441,
 450, 459, 469, 478, 487, 496, 506, 515, 524, 533,
 541, 549, 557, 565, 573, 581, 589, 597, 605, 613,
 622, 630, 639, 648, 656, 664, 672, 680, 688, 696,
 704, 712, 719, 725, 732, 738, 745, 752, 758, 765,
 772, 779, 785, 791, 797, 804, 810, 816, 822, 828,
 834, 840, 846, 851, 855, 860, 865, 870, 875, 880,
 885, 890, 895, 899, 903, 907, 911, 916, 920, 924,
 928, 933, 937, 940, 943, 947, 950, 953, 956, 960,
 963, 967, 971, 974, 978, 982, 985, 988, 991, 994,
 997,1000,1003,1006,1009,1013,1016,1019, 1023};
#elif 0   //0608_7
0, 20, 44, 64, 84, 104, 124, 144, 164, 184, 
204, 220, 240, 256, 272, 288, 304, 320, 332, 344, 
356, 368, 380, 388, 400, 408, 420, 428, 436, 444, 
452, 460, 468, 476, 484, 492, 500, 508, 512, 520, 
528, 536, 544, 552, 556, 564, 572, 580, 584, 592, 
600, 608, 612, 620, 628, 632, 640, 648, 652, 660, 
668, 672, 680, 684, 692, 700, 704, 712, 716, 724, 
728, 736, 740, 748, 752, 760, 764, 772, 776, 784, 
788, 792, 800, 804, 812, 816, 824, 828, 832, 840, 
844, 852, 856, 860, 868, 872, 876, 884, 888, 892, 
900, 904, 908, 916, 920, 924, 932, 936, 940, 944, 
952, 956, 960, 964, 968, 972, 976, 980, 988, 988, 
992, 996, 1000, 1004, 1008, 1012, 1016, 1020, 1023};
#elif 1 //0608_7_2
0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 
196, 212, 228, 244, 260, 276, 292, 304, 320, 332, 
348, 360, 376, 388, 404, 416, 424, 432, 440, 448, 
456, 464, 472, 480, 488, 496, 504, 512, 520, 524, 
532, 536, 544, 552, 556, 564, 572, 580, 588, 596, 
600, 608, 616, 624, 632, 636, 640, 648, 652, 660, 
668, 676, 684, 692, 696, 704, 712, 720, 724, 732, 
740, 744, 748, 752, 756, 764, 768, 772, 776, 784, 
788, 792, 800, 808, 812, 820, 824, 832, 836, 844, 
848, 852, 856, 860, 864, 872, 880, 884, 892, 896, 
900, 908, 912, 916, 924, 928, 932, 940, 944, 948, 
952, 956, 960, 964, 968, 972, 976, 980, 984, 988, 
992, 996, 1000, 1004, 1008, 1012, 1016, 1020, 1023};

#endif

__align(4)UINT32 GammaLUT_Vid_128Tab[130]={
#if 1//100608
   0,  36,  72, 108, 140, 168, 196, 220, 238, 255,
 272, 289, 306, 323, 340, 357, 374, 385, 396, 408,
 419, 430, 442, 453, 465, 474, 483, 493, 502, 511, 
 521, 530, 540, 548, 556, 564, 572, 580, 588, 596,
 604, 608, 616, 624, 632, 636, 644, 652, 656, 663,
 669, 676, 682, 689, 695, 702, 708, 714, 720, 726, 
 733, 739, 745, 751, 758, 764, 769, 775, 780, 786,
 791, 796, 802, 807, 812, 816, 821, 825, 830, 834,
 839, 843, 848, 853, 857, 862, 866, 871, 875, 880, 
 884, 888, 892, 896, 900, 904, 908, 912, 916, 920, 
 924, 928, 932, 936, 940, 944, 948, 952, 956, 960, 
 963, 967, 970, 973, 977, 980, 983, 986, 989, 993,
 996, 999,1003,1006,1010,1013,1016,1019,1023};
#endif

__align(4)UW  ChrCurveLUT[130]={
 0, 8, 16, 28, 36, 44, 52, 64, 72, 80,
88, 100, 108, 116, 124, 136, 144, 152, 160, 172,
180, 188, 196, 204, 216, 224, 232, 240, 248, 260,
268, 276, 284, 292, 300, 312, 320, 328, 336, 344,
352, 360, 368, 376, 388, 396, 404, 412, 420, 428,
436, 444, 452, 460, 468, 476, 484, 492, 496, 504,
508, 512, 512, 512, 512, 512, 512, 512, 516, 524,
532, 540, 548, 556, 564, 576, 584, 592, 600, 608,
620, 628, 636, 644, 656, 664, 672, 680, 688, 696,
708, 716, 724, 732, 740, 748, 756, 768, 776, 784,
792, 800, 808, 816, 824, 832, 840, 852, 860, 868,
876, 884, 892, 900, 908, 916, 924, 932, 940, 948,
960, 968, 976, 984, 992, 1000, 1008, 1016, 1023
};


/*
__align(4)UH PreGeoLUT[66]={
65535,65535,65534,65532,65530,65526,65522,65516,
65510,65504,65496,65488,65479,65469,65458,65446,
65434,65421,65407,65393,65377,65361,65344,65326,
65308,65289,65269,65248,65227,65205,65182,65158,
65134,65109,65083,65057,65030,65002,64973,64944,
64914,64883,64852,64820,64788,64755,64721,64686,
64651,64616,64579,64542,64505,64467,64428,64388,
64349,64308,64267,64225,64183,64141,64097,64054,64009,64009};
*/
__align(4)UH PreGeoLUT[66]={
65535,    65535,    65531,    65524,
65516,    65504,    65490,    65473,
65454,    65433,    65409,    65382,
65353,    65322,    65288,    65252,
65213,    65172,    65129,    65083,
65036,    64986,    64933,    64879,
64823,    64764,    64703,    64641,
64576,    64509,    64441,    64370,
64298,    64224,    64148,    64071,
63992,    63911,    63828,    63744,
63659,    63572,    63484,    63394,
63303,    63210,    63117,    63022,
62925,    62828,    62730,    62630,
62530,    62428,    62326,    62222,
62118,    62013,    61907,    61800,
61692,    61584,    61475,    61365, 61255, 61255};

__align(4) unsigned char Shading_Table_PreF[20] = {
      0, 10, 20, 30,
     40, 50, 60, 70,
     80, 90,100,110,
    120,130,140,150,
    160,0,0,0
};

__align(4) unsigned char Shading_Table[20] = {
      0, 5, 10,15,
     20,25, 30,35,
     40,45, 50,55,
     60,65, 70,75,
     80,0,0,0
 };

//#NT#2009/08/12#Jarkko Chang -begin
//#NT#add for vig update
__align(4) unsigned char Shading_Table_R[20] = {
    0,   7,  14,  20,
   25,  31,  35,  39,
   43,  47,  50,  54,
   60,  71,  86, 110,
  149,   0,   0,   0
 };

__align(4) unsigned char Shading_Table_G[20] = {
    0,   7,  14,  20,
   25,  31,  35,  39,
   43,  47,  50,  54,
   60,  71,  86, 110,
  149,   0,   0,   0
};

__align(4) unsigned char Shading_Table_B[20] = {
    0,   7,  14,  20,
   25,  31,  35,  39,
   43,  47,  50,  54,
   60,  71,  86, 110,
  149,   0,   0,   0
};
__align(4) unsigned char Shading_Table_R_MD2[20] = {
     0,   8,  15,  21,
    27,  32,  36,  41,
    45,  49,  51,  55,
    63,  78, 105, 153, 
   206,   0,   0,   0
 };

__align(4) unsigned char Shading_Table_G_MD2[20] = {
     0,   8,  15,  21,
    27,  32,  36,  41,
    45,  49,  51,  55,
    63,  78, 105, 153, 
   206,   0,   0,   0
};

__align(4) unsigned char Shading_Table_B_MD2[20] = {
     0,   8,  15,  21,
    27,  32,  36,  41,
    45,  49,  51,  55,
    63,  78, 105, 153, 
   206,   0,   0,   0
};

__align(4) unsigned char Shading_Table_R_CAP[20] = {
     0,   8,  15,  21,
    27,  32,  36,  40,
    42,  44,  46,  48,
    54,  69,  98, 142,
   193,   0,   0,   0
 };

__align(4) unsigned char Shading_Table_G_CAP[20] = {
     0,   8,  15,  21,
    27,  32,  36,  40,
    42,  44,  46,  48,
    54,  69,  98, 142,
   193,   0,   0,   0
};

__align(4) unsigned char Shading_Table_B_CAP[20] = {
     0,   8,  15,  21,
    27,  32,  36,  40,
    42,  44,  46,  48,
    54,  69,  98, 142,
   193,   0,   0,   0
 };
//#NT#2009/08/12#Jarkko Chang -end

__align(4) unsigned char Shading_Table_Flash[20] = {
      0, 19, 39, 60,
     82,104,127,150,
    174,200,225,243,
    255,255,255,255,
    255,0,0,0
};


__align(4) unsigned char Shading_LineTable[20] = {
      0,0,0,0,
      0,0,0,0,
      0,0,0,0,
      0,0,0,0,
      0,0,0,0,
};

__align(4) IPE_COLOR_EFFECT_PARAM ColorEffectTable[Max_ImgEffect + 1] = {
    {128, 128, 128, 128, 0, 0},    //_IMGEffect_Off,
    {128, 128, 128,   0, 0, 0},    //_IMGEffect_BW,
    {108, 146, 128,   0, 0, 0},    //_IMGEffect_Sepia,
    {128, 128, 128, 128, 0, 0},    //_IMGEffect_Vivid,
    {128, 128, 128, 128, 0, 0},    //_IMGEffect_Neutral,
    {128, 128, 128, 128, 0, 0},    //_IMGEffect_LowSharping,
    {128, 128, 128, 128, 0, 0},    //_IMGEffect_Fasion1,
    {128, 128, 128, 128, 0, 0},    //_IMGEffect_Fasion2,
    {128, 128, 128, 128, 0, 0},    //_IMGEffect_CustomManual,
    {128, 128, 128, 128, 0, 0},    //_IMGEffect_Red,
    {128, 128, 128, 128, 0, 0},    //_IMGEffect_Green,
    {128, 128, 128, 128, 0, 0},    //_IMGEffect_Blue,
    {128, 128, 128, 128, 0, 0},    //_IMGEffect_Yellow,
    {128, 128, 128, 128, 0, 0},    //_IMGEffect_Purple
};

//#NT#2009/12/09#Jarkko Chang -begin

extern __align(4) IME_FILT_PARA IMECHROMAPARAM[Total_ISONum] =  {
     {IMEALG_ENABLE, IMEALG_HAVGSIZE8,31,IMEALG_DISABLE, 3,0x80},
     {IMEALG_DISABLE,IMEALG_HAVGSIZE8,31,IMEALG_DISABLE,3,0x80},
     {IMEALG_DISABLE,IMEALG_HAVGSIZE8,31,IMEALG_DISABLE,3,0x80},
     {IMEALG_DISABLE,IMEALG_HAVGSIZE8,31,IMEALG_DISABLE,3,0x80},
};
//#NT#2009/12/09#Jarkko Chang -end
#endif
