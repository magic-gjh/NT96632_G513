/*++

Copyright (c) 2004  Novatek Microelectronics Corporation

Module Name:

    flashlight.c

Abstract:

    flashlight control

Environment:

    For nt96610

Notes:

  Copyright (c) 2005 Novatek Microelectronics Corporation.  All Rights Reserved.


Revision History:

    05/27/05: by YH Lee
--*/
#include "sensor_model.h"
#if OV5633_630
#include "top.h"
#include "OSCommon.h"

//#NT#20091022#ethanlau -begin
#define IGBT 0
//#NT#20091022#ethanlau -end
//----- Global funcs & variables define here  ------------------
UINT YPreFlash;
FLASH_STRUCT Flash_Param;

extern UINT g_Idx_n;
extern INT8 message[];

UINT32 Flash_Rg = 288;
UINT32 Flash_Bg = 256;
/**
    Flashlight charge
*/
UINT flash_Charge(void)
{
    debug_ind(("Flashlight Charging!\r\n"));

    if((SensorInfor.FP_SetFlashCharge!=NULL)&&
        (SensorInfor.FP_CheckFlashADCVlaue!=NULL))
    {

    SensorInfor.FP_SetFlashCharge(1,0);
    while(!(SensorInfor.FP_CheckFlashADCVlaue()))
    {
        sie_waitVD(10);
        debug_ind(("Wait Charge full!\r\n"));
    }
    SensorInfor.FP_SetFlashCharge(0,0);
    }
    return 0;
}

/**
    Preview pre-flash process
*/

#define TEST_BY_PATGEN   0
void flash_PreFlashFlow(void)
{

#if TEST_BY_PATGEN
    UINT YY[3];
#endif

    UINT8 flashed_buffer_ID;

    flash_Evaluate();    //Evaluate flash status according to menu setting
    if((Flash_Param.FlshEna>=Flash_Enable))
    {
        //dummy flash
        GPIOMap_TriggerFlash(ON);
        TimerDelayMs(100);
        GPIOMap_TriggerFlash(OFF);
        sie_waitVD(5);
    }

#if TEST_BY_PATGEN
    sie_PatGen(3, 0x00); //Fixed pattern
    sie_waitVD(3);
    Flash_Param.FlshEna=Flash_Enable;
#endif
#if IGBT
    if(Flash_Param.FlshEna>=Flash_Enable)
    {

        aaa_AeLock(1);    //Stop AE

        sie_waitVD(1);

        flash_PreFlashExpSet();    //Configure fixed AE setting of sensor and backend

        flash_RedEyeReduct();

        flash_ConfigPreFlash();    //Configure preflash width and delay

        flash_TriggerFlash();

        //sie_waitVD(1); //wait for PRE frame end
        pre_WaitFlagFieldEnd(); //wait for PRE frame end

        flashed_buffer_ID=ime_getPath1CurrentBufferIndex();
        //debug_err(("flash trigger bid %d\r\n",flashed_buffer_ID));


        sie_waitVD(1);

#if TEST_BY_PATGEN
        sie_PatGen(3, 0xFFF); //Fixed, value=0xFF
#endif

        sie_waitVD(1); //end of exposure VD w/ flashlight

        sie_pause();

#if TEST_BY_PATGEN
        sie_PatGen(0, 0x000); //Fixed pattern
#endif

        sie_waitVD(2);


        YPreFlash=aaa_EstimateY2(ime_getOutputPath1Add(flashed_buffer_ID, IME_CHANNEL_Y),GetIPPSizeInfor(_ImeOut1Hsize),GetIPPSizeInfor(_ImeOut1Vsize),GetIPPSizeInfor(_ImeOut1Hsize));
        //debug_err(("YPreFlash=%d\r\n",YPreFlash));

#if TEST_BY_PATGEN
        //Get all 3 ping-pong buffers luminance and compare to get the max
        YY[0]=  aaa_EstimateY2(ime_getOutputPath1Add(IME_BUFNUM_0, IME_CHANNEL_Y),GetIPPSizeInfor(_ImeOut1Hsize),GetIPPSizeInfor(_ImeOut1Vsize),GetIPPSizeInfor(_ImeOut1Hsize));
        YY[1]=  aaa_EstimateY2(ime_getOutputPath1Add(IME_BUFNUM_1, IME_CHANNEL_Y),GetIPPSizeInfor(_ImeOut1Hsize),GetIPPSizeInfor(_ImeOut1Vsize),GetIPPSizeInfor(_ImeOut1Hsize));
        YY[2]=  aaa_EstimateY2(ime_getOutputPath1Add(IME_BUFNUM_2, IME_CHANNEL_Y),GetIPPSizeInfor(_ImeOut1Hsize),GetIPPSizeInfor(_ImeOut1Vsize),GetIPPSizeInfor(_ImeOut1Hsize));
/*
        if(YY[0]>YY[1])
        {
            if(YY[0]>YY[2])
            {
                YPreFlash=YY[0];
            }
            else//(YY[0]<=YY[2])
            {
                YPreFlash=YY[2];
            }
        }
        else//(YY[0]<=YY[1])
        {
            if(YY[1]>YY[2])
            {
                YPreFlash=YY[1];
            }
            else//(YY[1]<=YY[2])
            {
                YPreFlash=YY[2];
            }
        }
*/
        debug_err(("YY %d %d %d ID:%d\r\n",YY[0],YY[1],YY[2],flashed_buffer_ID));
#endif



        //main flash AE convergence
        flash_AEConverge(YPreFlash);
    }
#endif
}

/**
    flash evaluation
*/
void flash_Evaluate(void)
{
    Flash_Param.FTP = 2560;
    debug_msg("gImageAlgInfo.FlashMode = %d\r\n",gImageAlgInfo.FlashMode);
    switch(gImageAlgInfo.FlashMode)
    {
        case _IMGFlashMode_Auto:
            //#NT#20091022#ethanlau -begin
            if(AE_Param.EV_Value < Flash_Param.FTP)
            {
                debug_msg("AUTO FLASH : FLASH ON\r\n");
                Flash_Param.FlshEna = Flash_Enable;
            }
            else
                Flash_Param.FlshEna = Flash_off;
            //#NT#20091022#ethanlau -end
            break;
        case _IMGFlashMode_ForceON:
            Flash_Param.FlshEna = Flash_Enable;
            break;
        case _IMGFlashMode_AutoRedEye:
        case _IMGFlashMode_ForceONRedEye:
        case _IMGFlashMode_NightStrobe:
            Flash_Param.FlshEna = Flash_RedEye;
            break;
        case _IMGFlashMode_ForceOFF:
        default:
            Flash_Param.FlshEna = Flash_off;
            break;
    }
}

/**
    pre-flash fixed AE setting
*/
void flash_PreFlashExpSet(void)
{}

/**
    flash redeye reduction flow
*/
void flash_RedEyeReduct(void)
{}

/**
    pre-flash setting
*/
void flash_ConfigPreFlash(void)
{
    Flash_Param.DelayLines=VD_Total_Prv-10;
    Flash_Param.PreWidth=540;
    sie_ClrIntrStatus(SIE_INT_FLSH);
    sie_FlashSetting(0, Flash_Param.DelayLines, 0, Flash_Param.PreWidth);
}

/**
    main-flash setting
*/
void flash_ConfigMainFlash(void)
{
    if(Flash_Param.FlshEna>=Flash_Enable)
    {
        Flash_Param.DelayLines=GetIPPSizeInfor(_VDTotal_Captrue)-35;//-5;
        Flash_Param.MainWidth=500;
        debug_ind(("Flash_Param.DelayLines=%d\r\n",Flash_Param.DelayLines));
        sie_ClrIntrStatus(SIE_INT_FLSH);
        sie_FlashSetting(0,Flash_Param.DelayLines, 0, Flash_Param.MainWidth);
    }
}

/**
    flash trigger
*/
void flash_TriggerFlash(void)
{
    if(Flash_Param.FlshEna>=Flash_Enable)
    {
        flash_CtrlPinSelect();
        debug_msg("- flash_TriggerFlash\r\n");
        sie_FlashStart();
    }
}

/**
    flash hardware pin select
*/
void flash_CtrlPinSelect(void)
{
    pinmux_select_flctr(PINMUX_FLCTR);
}

/**
    pre-flash AE converge
*/
void flash_AEConverge(UINT Yflash)
{

}

unsigned int flash_getCurAdcVal(void)
{
    UINT AdcVal;
    if(SensorInfor.FP_CheckFlashADCVlaue != NULL)
    {
        AdcVal=SensorInfor.FP_CheckFlashADCVlaue();
    }
    else
    {
        return 0;
    }

    return AdcVal;
}
#endif