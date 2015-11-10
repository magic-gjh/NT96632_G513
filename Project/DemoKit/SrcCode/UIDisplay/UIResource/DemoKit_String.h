/*//////////////////////////////////////////////////////////////////////////////

 ---------- Document Info ---------------

        Author : Anonymous
       Created : 16:07:28, Apr  7 2010
 Last modified : 16:07:28, Apr  7 2010
   Making tool : UI Designer Studio
   File format : C language header file

 ----------- Object Info ----------------

         Class : STRING_TABLE
          Name : DemoKit_String

*///////////////////////////////////////////////////////////////////////////////

#ifndef _DEMOKIT_STRING_H_
#define _DEMOKIT_STRING_H_
// STRING_TABLE count
#define DEMOKIT_STRING_LANG_NUM    10

// STRING_TABLE
extern const
unsigned char gDemoKit_String_EN[];

extern const
unsigned char gDemoKit_String_FR[];

extern const
unsigned char gDemoKit_String_DE[];

extern const
unsigned char gDemoKit_String_ES[];

extern const
unsigned char gDemoKit_String_IT[];

extern const
unsigned char gDemoKit_String_PO[];

extern const
unsigned char gDemoKit_String_SC[];

extern const
unsigned char gDemoKit_String_JP[];

extern const
unsigned char gDemoKit_String_TC[];

extern const
unsigned char gDemoKit_String_RU[];


// STRING ID
//#define name id
//#define STRID_NULL                               0x0000
#define STRID_MODE                               0x0001
#define STRID_IMGSIZE                            0x0002
#define STRID_RESOLUTION                         0x0003
#define STRID_12M                                0x0004
#define STRID_10M                                0x0005
#define STRID_9M                                 0x0006
#define STRID_8M                                 0x0007
#define STRID_7MHD                               0x0008
#define STRID_7M                                 0x0009
#define STRID_6M                                 0x000A
#define STRID_5M                                 0x000B
#define STRID_4M                                 0x000C
#define STRID_3M                                 0x000D
#define STRID_2MHD                               0x000E
#define STRID_2M                                 0x000F
#define STRID_1M                                 0x0010
#define STRID_VGA                                0x0011
#define STRID_QVGA                               0x0012
#define STRID_D1                                 0x0013
#define STRID_12MWXH                             0x0014
#define STRID_9MWXH                              0x0015
#define STRID_8MWXH                              0x0016
#define STRID_7MHDWXH                            0x0017
#define STRID_7MWXH                              0x0018
#define STRID_6MWXH                              0x0019
#define STRID_5MWXH                              0x001A
#define STRID_4MWXH                              0x001B
#define STRID_3MWXH                              0x001C
#define STRID_2MHDWXH                            0x001D
#define STRID_2MWXH                              0x001E
#define STRID_1MWXH                              0x001F
#define STRID_VGAWXH                             0x0020
#define STRID_QVGAWXH                            0x0021
#define STRID_D1WXH                              0x0022
#define STRID_COMPRESSION                        0x0023
#define STRID_QUALITY                            0x0024
#define STRID_SUPER                              0x0025
#define STRID_FINE                               0x0026
#define STRID_NORMAL                             0x0027
#define STRID_ECONOMY                            0x0028
#define STRID_WB                                 0x0029
#define STRID_AUTO                               0x002A
#define STRID_WB_DAY                             0x002B
#define STRID_WB_CLOUDY                          0x002C
#define STRID_WB_TUNGSTEN                        0x002D
#define STRID_WB_FLUORESCENT                     0x002E
#define STRID_EXPOSURE                           0x002F
#define STRID_EV                                 0x0030
#define STRID_ISO                                0x0031
#define STRID_ISO50                              0x0032
#define STRID_ISO100                             0x0033
#define STRID_ISO200                             0x0034
#define STRID_ISO400                             0x0035
#define STRID_METERING                           0x0036
#define STRID_METER_CENTER                       0x0037
#define STRID_METER_SPOT                         0x0038
#define STRID_METER_AVG                          0x0039
#define STRID_CAP_MODE                           0x003A
#define STRID_CAP_SINGLE                         0x003B
#define STRID_CAP_BURST                          0x003C
#define STRID_CAP_BURST_3                        0x003D
#define STRID_CAP_AUTO                           0x003E
#define STRID_CAP_TIMER2S                        0x003F
#define STRID_CAP_TIMER5S                        0x0040
#define STRID_CAP_TIMER10S                       0x0041
#define STRID_CAP_TIMER20S                       0x0042
#define STRID_FLASHMODE                          0x0043
#define STRID_FLASHON                            0x0044
#define STRID_FLASHOFF                           0x0045
#define STRID_FLASHAUTO                          0x0046
#define STRID_REDEYE                             0x0047
#define STRID_AV                                 0x0048
#define STRID_TV                                 0x0049
#define STRID_AVTV                               0x004A
#define STRID_AVSETTING                          0x004B
#define STRID_TVSETTING                          0x004C
#define STRID_AVTVSETTING                        0x004D
#define STRID_SCENESETTING                       0x004E
#define STRID_SCENE                              0x004F
#define STRID_LANDSCAPE                          0x0050
#define STRID_NIGHTSCENE                         0x0051
#define STRID_SPORTS                             0x0052
#define STRID_PORTRAIT                           0x0053
#define STRID_FLOWER                             0x0054
#define STRID_SMART                              0x0055
#define STRID_BACKLIGHT                          0x0056
#define STRID_COLOR                              0x0057
#define STRID_COLOR_FULL                         0x0058
#define STRID_COLOR_BW                           0x0059
#define STRID_COLOR_SEPIA                        0x005A
#define STRID_SHARPNESS                          0x005B
#define STRID_STRONG                             0x005C
#define STRID_SOFT                               0x005D
#define STRID_LOW                                0x005E
#define STRID_MED                                0x005F
#define STRID_HIGH                               0x0060
#define STRID_DATE_STAMP                         0x0061
#define STRID_DATE_TIME                          0x0062
#define STRID_DATE                               0x0063
#define STRID_TIME                               0x0064
#define STRID_Y_M_D                              0x0065
#define STRID_D_M_Y                              0x0066
#define STRID_M_D_Y                              0x0067
#define STRID_ON                                 0x0068
#define STRID_OFF                                0x0069
#define STRID_DZ                                 0x006A
#define STRID_QUICK_VIEW                         0x006B
#define STRID_SATURATION                         0x006C
#define STRID_MOVIE                              0x006D
#define STRID_FRAMERATE                          0x006E
#define STRID_30FPS                              0x006F
#define STRID_15FPS                              0x0070
#define STRID_VIDEO                              0x0071
#define STRID_AUDIO                              0x0072
#define STRID_SETUP                              0x0073
#define STRID_FREQUENCY                          0x0074
#define STRID_50HZ                               0x0075
#define STRID_60HZ                               0x0076
#define STRID_MEDIA                              0x0077
#define STRID_STORAGE                            0x0078
#define STRID_INT_FLASH                          0x0079
#define STRID_EXT_CARD                           0x007A
#define STRID_LOGO_DISPLAY                       0x007B
#define STRID_OPENING                            0x007C
#define STRID_FORMAT                             0x007D
#define STRID_OK                                 0x007E
#define STRID_CANCEL                             0x007F
#define STRID_BEEPER                             0x0080
#define STRID_BEEP_LOUD                          0x0081
#define STRID_BEEP_SOFT                          0x0082
#define STRID_LANGUAGE                           0x0083
#define STRID_LANG_EN                            0x0084
#define STRID_LANG_FR                            0x0085
#define STRID_LANG_ES                            0x0086
#define STRID_LANG_DE                            0x0087
#define STRID_LANG_IT                            0x0088
#define STRID_LANG_TC                            0x0089
#define STRID_LANG_SC                            0x008A
#define STRID_LANG_JP                            0x008B
#define STRID_LANG_PO                            0x008C
#define STRID_LANG_RUS                           0x008D
#define STRID_USB                                0x008E
#define STRID_PC_MODE                            0x008F
#define STRID_MSDC                               0x0090
#define STRID_PCC                                0x0091
#define STRID_PICTBRIDGE                         0x0092
#define STRID_USBCHARGE                          0x0093
#define STRID_TV_MODE                            0x0094
#define STRID_TV_NTSC                            0x0095
#define STRID_TV_PAL                             0x0096
#define STRID_BRIGHTNESS                         0x0097
#define STRID_AUTO_OFF                           0x0098
#define STRID_AUTO_OFF_1MIN                      0x0099
#define STRID_AUTO_OFF_2MIN                      0x009A
#define STRID_AUTO_OFF_3MIN                      0x009B
#define STRID_AUTO_OFF_5MIN                      0x009C
#define STRID_AUTO_OFF_10MIN                     0x009D
#define STRID_1MIN                               0x009E
#define STRID_2MIN                               0x009F
#define STRID_3MIN                               0x00A0
#define STRID_5MIN                               0x00A1
#define STRID_10MIN                              0x00A2
#define STRID_15MIN                              0x00A3
#define STRID_20MIN                              0x00A4
#define STRID_25MIN                              0x00A5
#define STRID_30MIN                              0x00A6
#define STRID_60MIN                              0x00A7
#define STRID_CYCLIC_REC                         0x00A8
#define STRID_FLASH_REC                          0x00A9
#define STRID_GOLF_REC                           0x00AA
#define STRID_NONE                               0x00AB
#define STRID_RESET_NUM                          0x00AC
#define STRID_DEFAULT_SETTING                    0x00AD
#define STRID_YES                                0x00AE
#define STRID_NO                                 0x00AF
#define STRID_VERSION                            0x00B0
#define STRID_PLAYBACK                           0x00B1
#define STRID_THUMBNAIL                          0x00B2
#define STRID_SET_LOGO                           0x00B3
#define STRID_ROTATE                             0x00B4
#define STRID_ROTATE_S                           0x00B5
#define STRID_ROTATE_90                          0x00B6
#define STRID_ROTATE_180                         0x00B7
#define STRID_ROTATE_270                         0x00B8
#define STRID_CROP                               0x00B9
#define STRID_CROP_S                             0x00BA
#define STRID_SLIDE_SHOW                         0x00BB
#define STRID_2SEC                               0x00BC
#define STRID_3SEC                               0x00BD
#define STRID_5SEC                               0x00BE
#define STRID_8SEC                               0x00BF
#define STRID_10SEC                              0x00C0
#define STRID_15SEC                              0x00C1
#define STRID_PROTECT                            0x00C2
#define STRID_PROTECTONE                         0x00C3
#define STRID_PROTECTALL                         0x00C4
#define STRID_LOCK                               0x00C5
#define STRID_LOCKONE                            0x00C6
#define STRID_LOCKALL                            0x00C7
#define STRID_LOCKSELECTED                       0x00C8
#define STRID_UNLOCK                             0x00C9
#define STRID_UNLOCKONE                          0x00CA
#define STRID_UNLOCKALL                          0x00CB
#define STRID_UNLOCKSELECTED                     0x00CC
#define STRID_DPOF                               0x00CD
#define STRID_ONEIMAGE                           0x00CE
#define STRID_ALL_IMAGES                         0x00CF
#define STRID_THIS_IMAGE                         0x00D0
#define STRID_THIS_VIDEO                         0x00D1
#define STRID_SELECT_IMAGES                      0x00D2
#define STRID_ALL_INDEX                          0x00D3
#define STRID_ALL                                0x00D4
#define STRID_RESETALL                           0x00D5
#define STRID_COPIES                             0x00D6
#define STRID_RETURN                             0x00D7
#define STRID_RESIZE                             0x00D8
#define STRID_QUALITYCHANGE                      0x00D9
#define STRID_COPY_TO_CARD                       0x00DA
#define STRID_COPY_FROM_CARD                     0x00DB
#define STRID_COPY                               0x00DC
#define STRID_TOSD                               0x00DD
#define STRID_TOINTERNAL                         0x00DE
#define STRID_DELETE                             0x00DF
#define STRID_DELETECURRENT                      0x00E0
#define STRID_DELETEALL                          0x00E1
#define STRID_DELETESELECTED                     0x00E2
#define STRID_DATAPROCESSED                      0x00E3
#define STRID_SELECT                             0x00E4
#define STRID_PAGE                               0x00E5
#define STRID_PRINTMODESEL                       0x00E6
#define STRID_SIZE                               0x00E7
#define STRID_STANDARD                           0x00E8
#define STRID_CONTINUE                           0x00E9
#define STRID_WITHOUT                            0x00EA
#define STRID_WITH                               0x00EB
#define STRID_NAME                               0x00EC
#define STRID_NO_IMAGE                           0x00ED
#define STRID_SET                                0x00EE
#define STRID_MEMORY_FULL                        0x00EF
#define STRID_CARD_FULL                          0x00F0
#define STRID_FOLDERFULL                         0x00F1
#define STRID_CARDERROR                          0x00F2
#define STRID_MEMORYERROR                        0x00F3
#define STRID_LENSERROR                          0x00F4
#define STRID_CARD_LOCKED                        0x00F5
#define STRID_FILE_PROTECT                       0x00F6
#define STRID_PICTUREERROR                       0x00F7
#define STRID_BATTERY_LOW                        0x00F8
#define STRID_ONEMOMENT                          0x00F9
#define STRID_NOCONNECTION                       0x00FA
#define STRID_TRANSFERRING                       0x00FB
#define STRID_CONNECTEDTOPC                      0x00FC
#define STRID_REMOVEUSBCABLE                     0x00FD
#define STRID_TOTAL                              0x00FE
#define STRID_DATE_STAMPING                      0x00FF
#define STRID_FILE_NAME                          0x0100
#define STRID_NO_OF_COPY                         0x0101
#define STRID_DEFAULT                            0x0102
#define STRID_MENU                               0x0103
#define STRID_EXIT                               0x0104
#define STRID_PLEASE_WAIT                        0x0105
#define STRID_STARTSHUTTER                       0x0106
#define STRID_STOPSHUTTER                        0x0107
#define STRID_NO_FILE                            0x0108
#define STRID_NO_CARD                            0x0109
#define STRID_NO_PHOTO                           0x010A
#define STRID_NOT_JPEG                           0x010B
#define STRID_FLASHNOTREADY                      0x010C
#define STRID_UPDATEBG                           0x010D
#define STRID_CHECKVERSION                       0x010E
#define STRID_PSTOREERR                          0x010F
#define STRID_PLAY                               0x0110
#define STRID_PAUSE                              0x0111
#define STRID_STOP                               0x0112
#define STRID_MOVE                               0x0113
#define STRID_SAVE                               0x0114
#define STRID_NEXT                               0x0115
#define STRID_CHANGE                             0x0116
#define STRID_VOLUME                             0x0117
#define STRID_STILL                              0x0118
#define STRID_BATTERY_TYPE                       0x0119
#define STRID_ALKALINE                           0x011A
#define STRID_NIMH                               0x011B
#define STRID_DELETE_WARNING                     0x011C
#define STRID_SEQUENCE_NO                        0x011D
#define STRID_RESET_WARNING                      0x011E
#define STRID_ERASE_THIS                         0x011F
#define STRID_ERASE_ALL                          0x0120
#define STRID_IMAGES                             0x0121
#define STRID_CONNECT_TO_DEVICE                  0x0122
#define STRID_DEVICE_IS_CONNECTED                0x0123
#define STRID_LINK_ERROR                         0x0124
#define STRID_USB_ERROR                          0x0125
#define STRID_DUMMY                              0x0126
#define STRID_EV_M0P3                            0x0127
#define STRID_EV_M0P6                            0x0128
#define STRID_EV_M1P0                            0x0129
#define STRID_EV_M1P3                            0x012A
#define STRID_EV_M1P6                            0x012B
#define STRID_EV_M2P0                            0x012C
#define STRID_EV_P0P0                            0x012D
#define STRID_EV_P0P3                            0x012E
#define STRID_EV_P0P6                            0x012F
#define STRID_EV_P1P0                            0x0130
#define STRID_EV_P1P3                            0x0131
#define STRID_EV_P1P6                            0x0132
#define STRID_EV_P2P0                            0x0133
#define STRID_PRINT_ALL                          0x0134
#define STRID_PRINT_INDEX                        0x0135
#define STRID_PRINT_DPOF                         0x0136
#define STRID_PRINT_SETTING                      0x0137
#define STRID_DPOF_RESTART                       0x0138
#define STRID_PRINT                              0x0139
#define STRID_START_PRINTING                     0x013A
#define STRID_PRINTING                           0x013B
#define STRID_PRINT_CANCELED                     0x013C
#define STRID_PRINT_FINISHED                     0x013D
#define STRID_OK_TO_PRINT                        0x013E
#define STRID_PAPER_SIZE                         0x013F
#define STRID_L                                  0x0140
#define STRID_2L                                 0x0141
#define STRID_POSTCARD                           0x0142
#define STRID_CARD                               0x0143
#define STRID_100X150                            0x0144
#define STRID_4X6                                0x0145
#define STRID_8X10                               0x0146
#define STRID_LETTER                             0x0147
#define STRID_11X17                              0x0148
#define STRID_A0                                 0x0149
#define STRID_A1                                 0x014A
#define STRID_A2                                 0x014B
#define STRID_A3                                 0x014C
#define STRID_A4                                 0x014D
#define STRID_A5                                 0x014E
#define STRID_A6                                 0x014F
#define STRID_A7                                 0x0150
#define STRID_A8                                 0x0151
#define STRID_A9                                 0x0152
#define STRID_B0                                 0x0153
#define STRID_B1                                 0x0154
#define STRID_B2                                 0x0155
#define STRID_B3                                 0x0156
#define STRID_B4                                 0x0157
#define STRID_B5                                 0x0158
#define STRID_B6                                 0x0159
#define STRID_B7                                 0x015A
#define STRID_B8                                 0x015B
#define STRID_B9                                 0x015C
#define STRID_L_ROLLS                            0x015D
#define STRID_2L_ROLLS                           0x015E
#define STRID_4_ROLLS                            0x015F
#define STRID_A4_ROLLS                           0x0160
#define STRID_PAPER_TYPE                         0x0161
#define STRID_PHOTO_PAPER                        0x0162
#define STRID_PLAIN_PAPER                        0x0163
#define STRID_FAST_PHOTO                         0x0164
#define STRID_FILE_TYPE                          0x0165
#define STRID_EXIF_JPEG                          0x0166
#define STRID_EXIF                               0x0167
#define STRID_JPEG                               0x0168
#define STRID_DATE_PRINT                         0x0169
#define STRID_FILENAME_PRINT                     0x016A
#define STRID_IMAGE_OPTIMIZE                     0x016B
#define STRID_LAYOUT                             0x016C
#define STRID_1UP                                0x016D
#define STRID_2UP                                0x016E
#define STRID_3UP                                0x016F
#define STRID_4UP                                0x0170
#define STRID_5UP                                0x0171
#define STRID_6UP                                0x0172
#define STRID_7UP                                0x0173
#define STRID_8UP                                0x0174
#define STRID_9UP                                0x0175
#define STRID_10UP                               0x0176
#define STRID_250UP                              0x0177
#define STRID_INDEX                              0x0178
#define STRID_1UP_BORDERLESS                     0x0179
#define STRID_FIXED_SIZE                         0x017A
#define STRID_25X325                             0x017B
#define STRID_35X5                               0x017C
#define STRID_254X178                            0x017D
#define STRID_110X74                             0x017E
#define STRID_89X55                              0x017F
#define STRID_6X8                                0x0180
#define STRID_7X10                               0x0181
#define STRID_9X13                               0x0182
#define STRID_13X18                              0x0183
#define STRID_15X21                              0x0184
#define STRID_18X24                              0x0185
#define STRID_CROPPING                           0x0186
#define STRID_PRINT_ERROR                        0x0187
#define STRID_PRINTER_DISCONNECTABLE             0x0188
#define STRID_PAPER_ERROR                        0x0189
#define STRID_PAPER_OUT                          0x018A
#define STRID_PAPER_LOAD_ERROR                   0x018B
#define STRID_PAPER_EJECT_ERROR                  0x018C
#define STRID_PAPER_MEDIA_ERROR                  0x018D
#define STRID_PAPER_JAMMED                       0x018E
#define STRID_PAPER_NEAR_EMPTY                   0x018F
#define STRID_PAPER_NOT_SUPPORT                  0x0190
#define STRID_INK_ERROR                          0x0191
#define STRID_INK_EMPTY                          0x0192
#define STRID_INK_LOW                            0x0193
#define STRID_INK_WASTE                          0x0194
#define STRID_HW_ERROR                           0x0195
#define STRID_HW_FATAL                           0x0196
#define STRID_HW_SERVICE_CALL                    0x0197
#define STRID_HW_UNAVAILABLE                     0x0198
#define STRID_HW_BUSY                            0x0199
#define STRID_HW_LEVER                           0x019A
#define STRID_HW_COVER_OPEN                      0x019B
#define STRID_HW_NO_MARKING_AGENT                0x019C
#define STRID_HW_INK_COVER_OPEN                  0x019D
#define STRID_HW_NO_INK_CARTRIDGE                0x019E
#define STRID_FILE_ERROR                         0x019F
#define STRID_FILE_PRINT_INFO                    0x01A0
#define STRID_FILE_DECODE_ERROR                  0x01A1
#define STRID_UNKNOW_ERROR                       0x01A2
#define STRID_XML_SYNTAX_ERROR                   0x01A3
#define STRID_MOTION_DET                         0x01A4
#define STRID_FACE_DET                           0x01A5
#define STRID_SMILE_DET                          0x01A6
#define STRID_ANTI_SHAKING                       0x01A7
#define STRID_NO_MOVIE                           0x01A8
#define STRID_MP3PLAY                            0x01A9
#define STRID_NO_MP3FILE                         0x01AA
#define STRID_SENSOR_ROTATE                      0x01AB
#define STRID_RECORD                             0x01AC
#define STRID_RECORD_AUDIO                       0x01AD
#define STRID_LED_SETTING                        0x01AE
#define STRID_CLUSTER_WRONG                      0x01AF
#define STRID_DELAY_POWEROFF                     0x01B0
#define STRID_SCEEN_SAVE                         0x01B1
#define STRID_GSENSOR_SENSITIVITY                0x01B2
#define STRID_YY                                 0x01B3
#define STRID_MM                                 0x01B4
#define STRID_DD                                 0x01B5

#endif //_DEMOKIT_STRING_H_
