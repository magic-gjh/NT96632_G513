
#----------------------------------------------------------------------
# set the library name here
#----------------------------------------------------------------------
PRJ_NAME = Sensor_OV9710_630

#----------------------------------------------------------------------
# add/delete source files here
#----------------------------------------------------------------------
SRC = \
	ae_OV9710_630.c \
	awb_OV9710_630.c \
	flashlight_OV9710_630.c \
	dzoom_OV9710_630.c \
	IQSetting_OV9710_630.c \
	SensorSys_OV9710_630.c \
	isr_OV9710_630.c \
	OV9710_630.c \
	SensorFlowFunc_OV9710_630.c \
	../IPPManager.c \
	../sen_cmd.c \
	../ImageAlgInfor.c \
	../sen_common.c \
	../Cal_Api.c \
	../IPPBuffer.c \
	../DataStamp.c \
	../AlbumShot.c \
	../cap_common.c \
	../CoupleShot.c \
	../PreShot.c \
	../prv_common.c \
	../Alg_IPLMode.c\
	../dis_common.c\
	../sen_snr.c\

ASM =

#----------------------------------------------------------------------
# set the include directory here
#----------------------------------------------------------------------
INC_DIR = .. \
	../../../../../Include \

#----------------------------------------------------------------------
# set the image output directory here
#----------------------------------------------------------------------
IMG_BASE_DIR = ../../../..

#----------------------------------------------------------------------
# add additional C and assembly flags here
#----------------------------------------------------------------------
CFLAGS_D = -Otime -DPanasonic_10M_630=0 -DA1040_630=0 -DMI1030_630=0 -DMI5100_630=0 -DOV5653_630=0 -DOV9710_630=1 -DOV5633_630=0
ASMFLAGS_D =

CFLAGS_R = -Otime -DPanasonic_10M_630=0 -DA1040_630=0 -DMI1030_630=0 -DMI5100_630=0 -DOV5653_630=0 -DOV9710_630=1 -DOV5633_630=0
ASMFLAGS_R =

#----------------------------------------------------------------------
# include common parts of the makefile
#----------------------------------------------------------------------
MAKE_COMMON_DIR = ../../../../../MakeCommon
include $(MAKE_COMMON_DIR)/OutputLib.txt


