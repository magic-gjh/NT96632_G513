
#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "UIPlayObj.h"
#include "UIFlowWndPlay.h"
#include "UIFlowWndPlayFuncs.h"
#include "UIFlowWndPlayThumb.h"
#include "UIMenuSetupSettings.h"
#include "UISystemStatusSettings.h"
#include "Audio.h"
#include "JpgEnc.h"
#include "Exif.h"
#include "PlaybackTsk.h"
//#include "UIFlowWndPlayIcons.h"
#include "Utility.h"
#include "SysCfg.h"
#include "MediaPlayApi.h"

extern UINT32 g_ui32UIFlowWndPlayShowState;

/*
    DSCMode/Flash/EV Icon/Image size/WB/image quality/sharpness
    DZoom/Battery/Histogram/Protect/Date/Time
*/

void FlowPB_IconDrawDSCMode(void)
{
    UINT32 uiFlag;

    if (UIPlay_GetData(PLAY_CURRMODE) ==PLAYMODE_AVI)
    {
        uiFlag = ICON_FILE_VIDEO;
    }
    else
    {
        uiFlag = ICON_MODE_PLAYBACK;
    }

    UxStatic_SetData(&UIFlowWndPlay_StaticICN_DSCModeCtrl,STATIC_VALUE,uiFlag);
    UxCtrl_SetShow(&UIFlowWndPlay_StaticICN_DSCModeCtrl, TRUE);
}

void FlowPB_IconHideDSCMode(void)
{
    UxCtrl_SetShow(&UIFlowWndPlay_StaticICN_DSCModeCtrl, FALSE);
}

void FlowPB_IconDrawFlash(void)
{
    UINT32 uiFlag;
    PJPGHEAD_DEC_CFG pJpgInfo;

    pJpgInfo  = PB_GetCurrImageInfo();

    switch (pJpgInfo->pExifInfo->StrobeFlash)
    {
    case (StrobeFlashForceON+StrobeNoFired):
    case (StrobeFlashForceON+StrobeFired):
        uiFlag = UIFlowWndPlay_StatusICN_Flash_ICON_FLASH_ON;
        break;

    case (StrobeFlashAutoRedEye+StrobeNoFired):
    case (StrobeFlashAutoRedEye+StrobeFired):
    case (StrobeFlashForceONRedEye+StrobeNoFired):
    case (StrobeFlashForceONRedEye+StrobeFired):
        uiFlag = UIFlowWndPlay_StatusICN_Flash_ICON_FLASH_RED_EYE;
        break;

    case StrobeFlashForceOFF:
        uiFlag = UIFlowWndPlay_StatusICN_Flash_ICON_FLASH_OFF;
        break;

    case (StrobeFlashAuto+StrobeNoFired):
    case (StrobeFlashAuto+StrobeFired):
    default:
        uiFlag = UIFlowWndPlay_StatusICN_Flash_ICON_FLASH_AUTO;
        break;
    }

    UxState_SetData(&UIFlowWndPlay_StatusICN_FlashCtrl,STATE_CURITEM,uiFlag);
    UxCtrl_SetShow(&UIFlowWndPlay_StatusICN_FlashCtrl, TRUE);
}

void FlowPB_IconHideFlash(void)
{
    UxCtrl_SetShow(&UIFlowWndPlay_StatusICN_FlashCtrl, FALSE);
}

void FlowPB_IconDrawEVIcon(void)
{
    PJPGHEAD_DEC_CFG pJpgInfo;
    UINT32           uiFlag;
    char             *str;

    pJpgInfo  = PB_GetCurrImageInfo();
    str = (char *)pJpgInfo->pExifInfo->ExpBiasValue;

    if      (!strncmp(str,"-2.0",4)) uiFlag = UIFlowWndPlay_StatusICN_EV_ICON_EV_M2P0;
    else if (!strncmp(str,"-5/3",4)) uiFlag = UIFlowWndPlay_StatusICN_EV_ICON_EV_M1P6;
    else if (!strncmp(str,"-4/3",4)) uiFlag = UIFlowWndPlay_StatusICN_EV_ICON_EV_M1P3;
    else if (!strncmp(str,"-1.0",4)) uiFlag = UIFlowWndPlay_StatusICN_EV_ICON_EV_M1P0;
    else if (!strncmp(str,"-2/3",4)) uiFlag = UIFlowWndPlay_StatusICN_EV_ICON_EV_M0P6;
    else if (!strncmp(str,"-1/3",4)) uiFlag = UIFlowWndPlay_StatusICN_EV_ICON_EV_M0P3;
    else if (!strncmp(str,"+1/3",4)) uiFlag = UIFlowWndPlay_StatusICN_EV_ICON_EV_P0P3;
    else if (!strncmp(str,"+2/3",4)) uiFlag = UIFlowWndPlay_StatusICN_EV_ICON_EV_P0P6;
    else if (!strncmp(str,"+1.0",4)) uiFlag = UIFlowWndPlay_StatusICN_EV_ICON_EV_P1P0;
    else if (!strncmp(str,"+4/3",4)) uiFlag = UIFlowWndPlay_StatusICN_EV_ICON_EV_P1P3;
    else if (!strncmp(str,"+5/3",4)) uiFlag = UIFlowWndPlay_StatusICN_EV_ICON_EV_P1P6;
    else if (!strncmp(str,"+2.0",4)) uiFlag = UIFlowWndPlay_StatusICN_EV_ICON_EV_P2P0;
    else                             uiFlag = UIFlowWndPlay_StatusICN_EV_ICON_EV_P0P0;

    UxState_SetData(&UIFlowWndPlay_StatusICN_EVCtrl,STATE_CURITEM,uiFlag);
    UxCtrl_SetShow(&UIFlowWndPlay_StatusICN_EVCtrl,TRUE);
}

void FlowPB_IconHideEVIcon(void)
{
    UxCtrl_SetShow(&UIFlowWndPlay_StatusICN_EVCtrl,FALSE);
}

void FlowPB_IconDrawDCFFileID(void)
{
    static char item1_Buf[32];

    snprintf(item1_Buf,32,"%03d-%04d",PB_GetCurFileDirId(),PB_GetCurFileNameId());

    UxStatic_SetData(&UIFlowWndPlay_StaticTXT_FilenameCtrl,STATIC_VALUE,Txt_Pointer(item1_Buf));
    UxCtrl_SetShow(&UIFlowWndPlay_StaticTXT_FilenameCtrl, TRUE);
}

void FlowPB_IconHideDCFFileID(void)
{
    UxCtrl_SetShow(&UIFlowWndPlay_StaticTXT_FilenameCtrl, FALSE);
}

void FlowPB_IconDrawImageSize(void)
{
    PJPGHEAD_DEC_CFG pJpgInfo;
    static char item1_Buf[32];

//    if (UIPlay_GetData(PLAY_CURRMODE) == PLAYMODE_PRIMARY)
    if (UIPlay_GetData(PLAY_FILEFORMAT)&PLAYFMT_JPG)
    {
        pJpgInfo = PB_GetCurrImageInfo();
        switch(pJpgInfo->ori_imagewidth)
        {
        case 4000:
            snprintf(item1_Buf,32,"12M");
            break;
        case 3200:
            snprintf(item1_Buf,32,"8M");
            break;
        case 2592:
            snprintf(item1_Buf,32,"5M");
            break;
        case 2272:
            snprintf(item1_Buf,32,"4M");
            break;			
        case 2048:
            snprintf(item1_Buf,32,"3M");
            break;
        case 1280:
            snprintf(item1_Buf,32,"1.3M");
            break;			
        default:
            snprintf(item1_Buf,32,"%dx%d",pJpgInfo->ori_imagewidth,pJpgInfo->ori_imageheight);
        }
    }
    else
    {
        pJpgInfo = PB_GetCurrImageInfoBeforeDec(FALSE);
        switch(pJpgInfo->imagewidth)
        {
        case 1920:
            snprintf(item1_Buf,32,"1080PHD");
            break;
        case 1440:
            snprintf(item1_Buf,32,"1080P");
            break;
        case 1280:
            snprintf(item1_Buf,32,"720P");
            break;
        case 848:
            snprintf(item1_Buf,32,"WVGA");
            break;				
        case 720:
            snprintf(item1_Buf,32,"WVGA");
            break;			
        case 640:
            snprintf(item1_Buf,32,"VGA");
            break;
        case 320:
            snprintf(item1_Buf,32,"QVGA");
            break;
        default:
            snprintf(item1_Buf,32,"%dx%d",pJpgInfo->imagewidth,pJpgInfo->imageheight);
        }
    }

    UxStatic_SetData(&UIFlowWndPlay_StaticTXT_SizeCtrl,STATIC_VALUE,Txt_Pointer(item1_Buf));
    UxCtrl_SetShow(&UIFlowWndPlay_StaticTXT_SizeCtrl, TRUE);
}

void FlowPB_IconHideImageSize(void)
{
    UxCtrl_SetShow(&UIFlowWndPlay_StaticTXT_SizeCtrl, FALSE);
}

void FlowPB_IconDrawWB(void)
{
    PJPGHEAD_DEC_CFG pJpgInfo;
    UINT32        uiFlag;

    pJpgInfo  = PB_GetCurrImageInfo();

    switch (pJpgInfo->pExifInfo->WhiteBalance)
    {
    case AutoWhite:
    case ManualWhite:
        //Todo: implement all kind of manual white
    default:
        uiFlag = UIFlowWndPlay_StatusICN_WB_ICON_WB_AUTO;
        break;
    }

    UxState_SetData(&UIFlowWndPlay_StatusICN_WBCtrl,STATE_CURITEM,uiFlag);
    UxCtrl_SetShow(&UIFlowWndPlay_StatusICN_WBCtrl, TRUE);
}

void FlowPB_IconHideWB(void)
{
    UxCtrl_SetShow(&UIFlowWndPlay_StatusICN_WBCtrl, FALSE);
}

void FlowPB_IconDrawImageQuality(void)
{
    PJPGHEAD_DEC_CFG pJpgInfo;
    UINT32 uiFlag;

    pJpgInfo  = PB_GetCurrImageInfo();

    switch(pJpgInfo->pExifInfo->JPGQuality)
    {
    //case Quality_SuperHigh:
        //Rev
        //break;
    case Quality_High:
        uiFlag = UIFlowWndPlay_StatusICN_Quality_ICON_QUALITY_FINE;
        break;
    case Quality_Economy:
        uiFlag = UIFlowWndPlay_StatusICN_Quality_ICON_QUALITY_NORMAL;
        break;
    case Quality_Undefine:
    default:
        uiFlag = UIFlowWndPlay_StatusICN_Quality_ICON_QUALITY_BASIC;
        break;
    }

    UxState_SetData(&UIFlowWndPlay_StatusICN_QualityCtrl,STATE_CURITEM,uiFlag);
    UxCtrl_SetShow(&UIFlowWndPlay_StatusICN_QualityCtrl, TRUE);
}

void FlowPB_IconHideImageQuality(void)
{
    UxCtrl_SetShow(&UIFlowWndPlay_StatusICN_QualityCtrl, FALSE);
}

void FlowPB_IconDrawSharpness(void)
{
    PJPGHEAD_DEC_CFG pJpgInfo;
    UINT32  uiFlag;

    pJpgInfo  = PB_GetCurrImageInfo();

    debug_err(("### chris: sharp=%d\r\n", pJpgInfo->pExifInfo->Sharpness));

    switch(pJpgInfo->pExifInfo->Sharpness)
    {
    case HARD_SHARPNESS:
        uiFlag = UIFlowWndPlay_StatusICN_Sharpness_ICON_SHARPNESS_HIGH;
        break;
    case NORMAL_SHARPNESS:
        uiFlag = UIFlowWndPlay_StatusICN_Sharpness_ICON_SHARPNESS_MED;
        break;
    case SOFT_SHARPNESS:
    default:
        uiFlag = UIFlowWndPlay_StatusICN_Sharpness_ICON_SHARPNESS_LOW;
        break;
    }

    UxState_SetData(&UIFlowWndPlay_StatusICN_SharpnessCtrl,STATE_CURITEM,uiFlag);
    UxCtrl_SetShow(&UIFlowWndPlay_StatusICN_SharpnessCtrl, TRUE);
}

void FlowPB_IconHideSharpness(void)
{
    UxCtrl_SetShow(&UIFlowWndPlay_StatusICN_SharpnessCtrl, FALSE);
}

void FlowPB_IconDrawStorage(void)
{
    switch(GetCardStatus())
    {
    case CARD_REMOVED:
        UxState_SetData(&UIFlowWndPlay_StatusICN_StorageCtrl,STATE_CURITEM,UIFlowWndPlay_StatusICN_Storage_ICON_INTERNAL_FLASH);
        break;
    default:
        UxState_SetData(&UIFlowWndPlay_StatusICN_StorageCtrl,STATE_CURITEM,UIFlowWndPlay_StatusICN_Storage_ICON_SD_CARD);
        break;
    }

    UxCtrl_SetShow(&UIFlowWndPlay_StatusICN_StorageCtrl, TRUE);
}

void FlowPB_IconHideStorage(void)
{
    UxCtrl_SetShow(&UIFlowWndPlay_StatusICN_StorageCtrl, FALSE);
}

void FlowPB_IconDrawBattery(void)
{
    UINT32 uiFlag;

    switch(GetBatteryLevel())
    {
    case BATTERY_LOW:
        uiFlag= UIFlowWndPlay_StatusICN_Battery_ICON_BATTERY_LOW;
        break;
    case BATTERY_EMPTY:
        uiFlag= UIFlowWndPlay_StatusICN_Battery_ICON_BATTERY_EMPTY;
        break;
    case BATTERY_FULL:
        uiFlag= UIFlowWndPlay_StatusICN_Battery_ICON_BATTERY_FULL;
        break;
    case BATTERY_MED:
        uiFlag= UIFlowWndPlay_StatusICN_Battery_ICON_BATTERY_MED;
        break;
    default:
        uiFlag= UIFlowWndPlay_StatusICN_Battery_ICON_BATTERY_EMPTY;
        break;
    }

    UxState_SetData(&UIFlowWndPlay_StatusICN_BatteryCtrl,STATE_CURITEM,uiFlag);
    UxCtrl_SetShow(&UIFlowWndPlay_StatusICN_BatteryCtrl, FALSE);
}

void FlowPB_IconHideBattery(void)
{
    UxCtrl_SetShow(&UIFlowWndPlay_StatusICN_BatteryCtrl, FALSE);
}

void FlowPB_IconDrawHistogram(void)
{
    UxCtrl_SetShow(&UIFlowWndPlay_HistoCtrl, TRUE);
}

void FlowPB_IconHideHistogram(void)
{
    UxCtrl_SetShow(&UIFlowWndPlay_HistoCtrl, FALSE);
}

void FlowPB_IconDrawFileLock(void)
{
    if (UIPlay_GetData(PLAY_LOCKSTATUS))
    {
        UxCtrl_SetShow(&UIFlowWndPlay_StaticICN_ProtectCtrl, TRUE);
    }
    else
    {
        UxCtrl_SetShow(&UIFlowWndPlay_StaticICN_ProtectCtrl, FALSE);
    }
}

void FlowPB_IconHideFileLock(void)
{
    UxCtrl_SetShow(&UIFlowWndPlay_StaticICN_ProtectCtrl, FALSE);
}

void FlowPB_IconDrawPrint(void)
{
    if (UIPlay_GetData(PLAY_DPOFQTY))
    {
        UxCtrl_SetShow(&UIFlowWndPlay_StaticICN_PrintCtrl, TRUE);
    }
    else
    {
        UxCtrl_SetShow(&UIFlowWndPlay_StaticICN_PrintCtrl, FALSE);
    }
}

void FlowPB_IconHidePrint(void)
{
    UxCtrl_SetShow(&UIFlowWndPlay_StaticICN_PrintCtrl, FALSE);
}

void FlowPB_IconDrawDate(void)
{
    UINT    Date[3];
    UINT    uiFileFormat,uiPBCurrMode;
    static char item1_Buf[32];

    switch(UIPlay_GetData(PLAY_CURRMODE))
    {
    case PLAYMODE_ASF:
    case PLAYMODE_AVI:
        uiFileFormat = FST_FMT_AVI;
        break;
    case PLAYMODE_MOVMJPG:
        uiFileFormat = FST_FMT_MOV;
        break;
    case PLAYMODE_WAV:
        uiFileFormat = FST_FMT_WAV;
        break;
    default:
        uiFileFormat = FST_FMT_JPG;
    }

    FilesysWaitCmdFinish(FST_TIME_INFINITE);
    FilesysGetFileTime2(PB_GetCurFileDirId(), PB_GetCurFileNameId(), uiFileFormat, FST_TIMEMODE_MODIFY_DATE, &Date[0], &Date[1], &Date[2]);

    Date[0] %= 100;
    if (Date[0] > 50)  Date[0] = 50;
    if (Date[1] > 12)  Date[0] = 12;
    if (Date[2] > 31)  Date[0] = 31;

    snprintf(item1_Buf,20,"%02d/%02d/%02d",Date[0],Date[1],Date[2]);

    UxStatic_SetData(&UIFlowWndPlay_StaticTXT_DateCtrl,STATIC_VALUE,Txt_Pointer(item1_Buf));
    UxCtrl_SetShow(&UIFlowWndPlay_StaticTXT_DateCtrl, TRUE);
}

void FlowPB_IconHideDate(void)
{
    UxCtrl_SetShow(&UIFlowWndPlay_StaticTXT_DateCtrl, FALSE);
}

void FlowPB_IconDrawTime(void)
{
    UINT  Time[3];
    UINT  uiFileFormat,uiPBCurrMode;
    static char item1_Buf[32];

    switch(UIPlay_GetData(PLAY_CURRMODE))
    {
    case PLAYMODE_ASF:
    case PLAYMODE_AVI:
        uiFileFormat = FST_FMT_AVI;
        break;
    case PLAYMODE_MOVMJPG:
        uiFileFormat = FST_FMT_MOV;
        break;
    case PLAYMODE_WAV:
        uiFileFormat = FST_FMT_WAV;
        break;
    default:
        uiFileFormat = FST_FMT_JPG;
    }

    FilesysWaitCmdFinish(FST_TIME_INFINITE);
    FilesysGetFileTime2(PB_GetCurFileDirId(), PB_GetCurFileNameId(), uiFileFormat, FST_TIMEMODE_MODIFY_TIME, &Time[0], &Time[1], &Time[2]);

    if (Time[0]>23)   Time[0]=0;
    if (Time[1]>59)   Time[1]=0;

    snprintf(item1_Buf,20,"%02d:%02d",Time[0],Time[1]);

    UxStatic_SetData(&UIFlowWndPlay_StaticTXT_TimeCtrl,STATIC_VALUE,Txt_Pointer(item1_Buf));
    UxCtrl_SetShow(&UIFlowWndPlay_StaticTXT_TimeCtrl, TRUE);
}

void FlowPB_IconHideTime(void)
{
    UxCtrl_SetShow(&UIFlowWndPlay_StaticTXT_TimeCtrl, FALSE);
}

void FlowPB_IconDrawThumbSeq(void)
{
    static char item1_Buf[32];
    UINT16  *pThumbSeqID;

    pThumbSeqID = PB_GetAllThumbSeqIdArray();

    snprintf(item1_Buf,32,"%d/%d",*(pThumbSeqID + PB_GetCurFileIndex() - 1),PB_GetCurrFileSysInfo(PLAYFILEINFO_FILENUMS));

    UxStatic_SetData(&UIFlowWndPlayThumb_ThumbIDCtrl,STATIC_VALUE,Txt_Pointer(item1_Buf));
    UxCtrl_SetShow(&UIFlowWndPlayThumb_ThumbIDCtrl, TRUE);
}

void FlowPB_IconHideThumbSeq(void)
{
    UxCtrl_SetShow(&UIFlowWndPlayThumb_ThumbIDCtrl, FALSE);
}

void FlowPB_IconDrawMovPlay(void)
{
    if(g_PlbData.State == PLB_ST_PLAY_MOV)
    {
        UxState_SetData(&UIFlowWndPlay_StatusICN_MovPlayCtrl,STATE_CURITEM,UIFlowWndPlay_StatusICN_MovPlay_ICON_OK_PAUSE);
    }
    else
    {
        UxState_SetData(&UIFlowWndPlay_StatusICN_MovPlayCtrl,STATE_CURITEM,UIFlowWndPlay_StatusICN_MovPlay_ICON_OK_PLAY);
    }
    UxCtrl_SetShow(&UIFlowWndPlay_StatusICN_MovPlayCtrl, TRUE);
}

void FlowPB_IconHideMovPlay(void)
{
    UxCtrl_SetShow(&UIFlowWndPlay_StatusICN_MovPlayCtrl, FALSE);
}

void FlowPB_IconDrawMovStop(void)
{
    UxCtrl_SetShow(&UIFlowWndPlay_StatusICN_MovStopCtrl, TRUE);
}

void FlowPB_IconHideMovStop(void)
{
    UxCtrl_SetShow(&UIFlowWndPlay_StatusICN_MovStopCtrl, FALSE);
}

void FlowPB_IconDrawMovBwd(void)
{
    UxCtrl_SetShow(&UIFlowWndPlay_StatusICN_MovBwdCtrl, TRUE);
}

void FlowPB_IconHideMovBwd(void)
{
    UxCtrl_SetShow(&UIFlowWndPlay_StatusICN_MovBwdCtrl, FALSE);
}

void FlowPB_IconDrawMovFwd(void)
{
    UxCtrl_SetShow(&UIFlowWndPlay_StatusICN_MovFwdCtrl, TRUE);
}

void FlowPB_IconHideMovFwd(void)
{
    UxCtrl_SetShow(&UIFlowWndPlay_StatusICN_MovFwdCtrl, FALSE);
}

void FlowPB_IconDrawMovPlayTime(void)
{
    static char item1_Buf[32];
    UINT32 uiPlayTimeSecs;

    uiPlayTimeSecs = MediaPlay_GetCurrPlaySecs();

    snprintf(item1_Buf, 32, "%02d:%02d:%02d", uiPlayTimeSecs/3600, (uiPlayTimeSecs%3600)/60, (uiPlayTimeSecs%3600)%60);

    UxStatic_SetData(&UIFlowWndPlay_StaticTXT_MovPlayTimeCtrl,STATIC_VALUE,Txt_Pointer(item1_Buf));

    UxCtrl_SetShow(&UIFlowWndPlay_StaticTXT_MovPlayTimeCtrl, TRUE);
}

void FlowPB_IconHideMovPlayTime(void)
{
    UxCtrl_SetShow(&UIFlowWndPlay_StaticTXT_MovPlayTimeCtrl, FALSE);
}

void FlowPB_IconDrawMovPlaySpeed(void)
{
    static CHAR SpeedStr[8];
    BOOL bShow = TRUE;

    switch(Get_PlayMovSpeedIndex())
    {
        case PLAYMOV_SPEED_BWD_8X:
            sprintf(SpeedStr, "-8x");
            break;
        case PLAYMOV_SPEED_BWD_4X:
            sprintf(SpeedStr, "-4x");
            break;
        case PLAYMOV_SPEED_BWD_2X:
            sprintf(SpeedStr, "-2x");
            break;
        case PLAYMOV_SPEED_FWD_2X:
            sprintf(SpeedStr, "2x");
            break;
        case PLAYMOV_SPEED_FWD_4X:
            sprintf(SpeedStr, "4x");
            break;
        case PLAYMOV_SPEED_FWD_8X:
            sprintf(SpeedStr, "8x");
            break;
        case PLAYMOV_SPEED_FWD_1X:
        default:
            sprintf(SpeedStr, "1x");
            bShow = FALSE;
            break;
    }

    UxStatic_SetData(&UIFlowWndPlay_StaticTXT_SpeedCtrl,STATIC_VALUE,Txt_Pointer(SpeedStr));

    UxCtrl_SetShow(&UIFlowWndPlay_StaticTXT_SpeedCtrl, bShow);
}

void FlowPB_IconHideMovPlaySpeed(void)
{
    UxCtrl_SetShow(&UIFlowWndPlay_StaticTXT_SpeedCtrl, FALSE);
}

void FlowPB_IconDrawMovPlayVolumn(UINT32 uiVolumn)
{
    UINT32 uiFlag;

    switch(uiVolumn)
    {
    case AUDIO_VOL_MUTE:
        uiFlag= UIFlowWndPlay_StatusICN_Volumn_ICON_VOL_0;
        break;
    case AUDIO_VOL_0:
        uiFlag= UIFlowWndPlay_StatusICN_Volumn_ICON_VOL_1;
        break;
    case AUDIO_VOL_1:
        uiFlag= UIFlowWndPlay_StatusICN_Volumn_ICON_VOL_2;
        break;
    case AUDIO_VOL_2:
        uiFlag= UIFlowWndPlay_StatusICN_Volumn_ICON_VOL_3;
        break;
    case AUDIO_VOL_3:
        uiFlag= UIFlowWndPlay_StatusICN_Volumn_ICON_VOL_4;
        break;
    case AUDIO_VOL_4:
        uiFlag= UIFlowWndPlay_StatusICN_Volumn_ICON_VOL_5;
        break;
    case AUDIO_VOL_5:
        uiFlag= UIFlowWndPlay_StatusICN_Volumn_ICON_VOL_6;
        break;
    case AUDIO_VOL_6:
        uiFlag= UIFlowWndPlay_StatusICN_Volumn_ICON_VOL_7;
        break;
    case AUDIO_VOL_7:
        uiFlag= UIFlowWndPlay_StatusICN_Volumn_ICON_VOL_8;
        break;
    default:
        uiFlag= UIFlowWndPlay_StatusICN_Volumn_ICON_VOL_0;
        break;
    }

    UxState_SetData(&UIFlowWndPlay_StatusICN_VolumnCtrl,STATE_CURITEM,uiFlag);
    UxCtrl_SetShow(&UIFlowWndPlay_StatusICN_VolumnCtrl, FALSE);
}

void FlowPB_IconHideMovPlayVolumn(void)
{
    UxCtrl_SetShow(&UIFlowWndPlay_StatusICN_VolumnCtrl, FALSE);
}

void FlowPB_UpdateIcons(BOOL bShow)
{
    if (bShow == FALSE || Get_DisplayIndex() == DISPLAY_OFF)
    {
        FlowPB_IconHideDSCMode();
        FlowPB_IconHideFlash();
        FlowPB_IconHideEVIcon();
        FlowPB_IconHideDCFFileID();
        FlowPB_IconHideImageSize();
        FlowPB_IconHideWB();
        FlowPB_IconHideImageQuality();
        FlowPB_IconHideSharpness();
        FlowPB_IconHideStorage();
        FlowPB_IconHideBattery();
        FlowPB_IconHideHistogram();
        FlowPB_IconHideFileLock();
        FlowPB_IconHidePrint();
        FlowPB_IconHideDate();
        FlowPB_IconHideTime();
        FlowPB_IconHideMovPlay();
        FlowPB_IconHideMovStop();
        FlowPB_IconHideMovPlayTime();
        FlowPB_IconHideMovPlaySpeed();
        FlowPB_IconHideMovPlayVolumn();
    }
    else
    {
        switch(Get_DisplayIndex())
        {
        case DISPLAY_ALL:
            FlowPB_IconDrawDSCMode();
            FlowPB_IconDrawEVIcon();
            FlowPB_IconDrawDCFFileID();
            FlowPB_IconDrawImageSize();
            FlowPB_IconDrawWB();
            FlowPB_IconDrawStorage();
            FlowPB_IconDrawBattery();
            FlowPB_IconDrawHistogram();
            FlowPB_IconDrawFileLock();
            FlowPB_IconDrawPrint();
            FlowPB_IconDrawDate();
            FlowPB_IconDrawTime();
            FlowPB_IconHideMovPlayTime();
            FlowPB_IconHideMovPlaySpeed();
            FlowPB_IconHideMovPlayVolumn();
            if (UIPlay_GetData(PLAY_CURRMODE) == PLAYMODE_PRIMARY)
            {
                FlowPB_IconDrawFlash();
                FlowPB_IconDrawImageQuality();
                FlowPB_IconDrawSharpness();
                FlowPB_IconHideMovPlay();
                FlowPB_IconHideMovStop();
            }
            else
            {
                FlowPB_IconHideFlash();
                FlowPB_IconHideImageQuality();
                FlowPB_IconHideSharpness();
                FlowPB_IconDrawMovPlay();
                FlowPB_IconDrawMovStop();
            }
            break;
        case DISPLAY_NORMAL:
            FlowPB_IconDrawDSCMode();
            FlowPB_IconHideFlash();
            FlowPB_IconHideEVIcon();
            FlowPB_IconDrawDCFFileID();
            FlowPB_IconDrawImageSize();
            FlowPB_IconHideWB();
            FlowPB_IconHideImageQuality();
            FlowPB_IconHideSharpness();
            FlowPB_IconHideStorage();
            FlowPB_IconDrawBattery();
            FlowPB_IconHideHistogram();
            FlowPB_IconDrawFileLock();
            FlowPB_IconDrawPrint();
            FlowPB_IconDrawDate();
            FlowPB_IconDrawTime();
            FlowPB_IconHideMovPlayTime();
            FlowPB_IconHideMovPlaySpeed();
            FlowPB_IconHideMovPlayVolumn();
            if (UIPlay_GetData(PLAY_CURRMODE) == PLAYMODE_PRIMARY)
            {
                FlowPB_IconHideMovPlay();
                FlowPB_IconHideMovStop();
                FlowPB_IconHideMovBwd();
                FlowPB_IconHideMovFwd();
            }
            else
            {
                FlowPB_IconDrawMovPlay();
                FlowPB_IconDrawMovStop();
                FlowPB_IconDrawMovBwd();
                FlowPB_IconDrawMovFwd();
            }
                FlowPB_IconHideMovBwd();
                FlowPB_IconHideMovFwd();			
            break;
        }
    }
}

void FlowPB_DrawThumbRect(BOOL bShow)
{
    switch(PB_GetCurFileIndex())
    {
    //Playback fileIndex starts from 1.
    case 1:
        UxCtrl_SetShow(&UIFlowWndPlayThumb_Panel0Ctrl,bShow);
        break;
    case 2:
        UxCtrl_SetShow(&UIFlowWndPlayThumb_Panel1Ctrl,bShow);
        break;
    case 3:
        UxCtrl_SetShow(&UIFlowWndPlayThumb_Panel2Ctrl,bShow);
        break;
    case 4:
        UxCtrl_SetShow(&UIFlowWndPlayThumb_Panel3Ctrl,bShow);
        break;
    case 5:
        UxCtrl_SetShow(&UIFlowWndPlayThumb_Panel4Ctrl,bShow);
        break;
    case 6:
        UxCtrl_SetShow(&UIFlowWndPlayThumb_Panel5Ctrl,bShow);
        break;
    case 7:
        UxCtrl_SetShow(&UIFlowWndPlayThumb_Panel6Ctrl,bShow);
        break;
    case 8:
        UxCtrl_SetShow(&UIFlowWndPlayThumb_Panel7Ctrl,bShow);
        break;
    case 9:
        UxCtrl_SetShow(&UIFlowWndPlayThumb_Panel8Ctrl,bShow);
        break;
    }
}


void FlowPB_ClearAllThumbIcon(void)
{
    UxCtrl_SetShow(&UIFlowWndPlayThumb_Panel0Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowWndPlayThumb_Panel1Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowWndPlayThumb_Panel2Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowWndPlayThumb_Panel3Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowWndPlayThumb_Panel4Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowWndPlayThumb_Panel5Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowWndPlayThumb_Panel6Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowWndPlayThumb_Panel7Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowWndPlayThumb_Panel8Ctrl,FALSE);

    UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_Protect0Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_Protect1Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_Protect2Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_Protect3Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_Protect4Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_Protect5Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_Protect6Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_Protect7Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_Protect8Ctrl,FALSE);

    UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_FileFilm0Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_FileFilm1Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_FileFilm2Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_FileFilm3Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_FileFilm4Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_FileFilm5Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_FileFilm6Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_FileFilm7Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_FileFilm8Ctrl,FALSE);

    UxCtrl_SetShow(&UIFlowWndPlayThumb_ThumbIDCtrl,FALSE);
}


void FlowPB_ShowAllThumbIcon(void)
{
    UINT32  i, loopcnts,CurrFileFormat ;
    UINT16  *pCurrFileFormat;   // Hideo@0503: variable type should be UINT16

    FlowPB_DrawThumbRect(TRUE);

    FlowPB_IconDrawThumbSeq();

    pCurrFileFormat = (UINT16*)PB_GetAllThumbFileFormatArray();
    loopcnts = PB_GetCurThumbNums();

    for (i=0; i<loopcnts; i++)
    {
        CurrFileFormat  = *pCurrFileFormat++;

        if (CurrFileFormat & PLAYFMT_READONLY)
        {
            switch(i)
            {
            case 0:
                UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_Protect0Ctrl,TRUE);
                break;
            case 1:
                UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_Protect1Ctrl,TRUE);
                break;
            case 2:
                UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_Protect2Ctrl,TRUE);
                break;
            case 3:
                UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_Protect3Ctrl,TRUE);
                break;
            case 4:
                UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_Protect4Ctrl,TRUE);
                break;
            case 5:
                UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_Protect5Ctrl,TRUE);
                break;
            case 6:
                UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_Protect6Ctrl,TRUE);
                break;
            case 7:
                UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_Protect7Ctrl,TRUE);
                break;
            case 8:
                UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_Protect8Ctrl,TRUE);
                break;
            }
        }

        if (CurrFileFormat & (PLAYFMT_AVI|PLAYFMT_ASF|PLAYFMT_MPG|PLAYFMT_MOVMJPG))
        {
            switch(i)
            {
            case 0:
                UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_FileFilm0Ctrl,TRUE);
                break;
            case 1:
                UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_FileFilm1Ctrl,TRUE);
                break;
            case 2:
                UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_FileFilm2Ctrl,TRUE);
                break;
            case 3:
                UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_FileFilm3Ctrl,TRUE);
                break;
            case 4:
                UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_FileFilm4Ctrl,TRUE);
                break;
            case 5:
                UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_FileFilm5Ctrl,TRUE);
                break;
            case 6:
                UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_FileFilm6Ctrl,TRUE);
                break;
            case 7:
                UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_FileFilm7Ctrl,TRUE);
                break;
            case 8:
                UxCtrl_SetShow(&UIFlowWndPlayThumb_StaticICN_FileFilm8Ctrl,TRUE);
                break;
            }
        }
    }
}


