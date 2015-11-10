//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIMenuWndMovieVideoRes.c"
#include "UIMenuWndMovieVideo.h"
#include "UIMenuWndSetup.h"
#include "UIMenuWndMovieResolution.h"
#include "UIMenuWndMovieCyclicRec.h"
#include "UIMenuWndMovieFlashRec.h"
#include "UIMenuWndMovieGolfRec.h"
#include "UIMenuWndMovieMotionDetect.h"
#include "UIMenuWndMovieDateStamp.h"
#include "UIMenuWndMovieAudioSet.h"
//#include "UIMenuWndMovieGodBless.h"
#include "UIMenuWndMovieGsensor.h"
#include "UIMenuWndMovieEV.h"
#include "UIMenuWndMovieWB.h"

#include "UISystemObj.h"
#include "Debug.h"
#include "KeyScanTsk.h"
//---------------------UIMenuWndMovieVideoCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndMovieVideo)
CTRL_LIST_ITEM(UIMenuWndMovieVideo_Panel)
CTRL_LIST_ITEM(UIMenuWndMovieVideo_Title_Panel)
CTRL_LIST_ITEM(UIMenuWndMovieVideo_End_Panel)
CTRL_LIST_ITEM(UIMenuWndMovieVideo_Video_Menu)
CTRL_LIST_END

//----------------------UIMenuWndMovieVideoCtrl Event---------------------------
INT32 UIMenuWndMovieVideo_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndMovieVideo_OnClose(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndMovieVideo_OnChildClose(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndMovieVideo_OnKeyLeft(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndMovieVideo_OnKeyRight(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndMovieVideo_OnKeyMenu(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndMovieVideo_OnKeyDown(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndMovieVideo_OnKeyMode(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndMovieVideo)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIMenuWndMovieVideo_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIMenuWndMovieVideo_OnClose)
EVENT_ITEM(NVTEVT_CHILD_CLOSE,UIMenuWndMovieVideo_OnChildClose)
EVENT_ITEM(NVTEVT_KEY_LEFT,UIMenuWndMovieVideo_OnKeyLeft)
EVENT_ITEM(NVTEVT_KEY_RIGHT,UIMenuWndMovieVideo_OnKeyRight)
EVENT_ITEM(NVTEVT_KEY_MENU,UIMenuWndMovieVideo_OnKeyMenu)
EVENT_ITEM(NVTEVT_KEY_DOWN,UIMenuWndMovieVideo_OnKeyDown)
EVENT_ITEM(NVTEVT_KEY_MODE,UIMenuWndMovieVideo_OnKeyMode)
EVENT_END

//------------------------------------------------------------
static BOOL bUIMenuWndMovieVideo_Video_MenuCtrl_rx_event = FALSE;
static UINT8 BottomBar_Buf[20];
INT32 UIMenuWndMovieVideo_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    INT32 item,page,total_page;

    UxMenu_SetItemData(&UIMenuWndMovieVideo_Video_MenuCtrl,item,MNUITM_STATUS,(STATUS_DISABLE));
    UxState_SetData(&UIMenuWndMovieVideo_Title_Mode_StatusCtrl,STATE_CURITEM,UIMenuWndMovieVideo_Title_Mode_Status_STRID_VIDEO);

    UxMenu_SetData(&UIMenuWndMovieVideo_Video_MenuCtrl,MNU_CURITM,0);

    item = UxMenu_GetData(&UIMenuWndMovieVideo_Video_MenuCtrl,MNU_CURITM);
    page = UxMenu_GetData(&UIMenuWndMovieVideo_Video_MenuCtrl,MNU_PAGEITEM);
    item = (item / page) + 1;
    total_page = (UIMenuWndMovieVideo_Video_Menu_MAX / page)+(((UIMenuWndMovieVideo_Video_Menu_MAX % page) == 0)? 0:1);
    sprintf((char *)BottomBar_Buf,"%d/%d",item,total_page);
    UxStatic_SetData(&UIMenuWndMovieVideo_PageNum_StaticCtrl,STATIC_VALUE,Txt_Pointer(BottomBar_Buf));

    for(item = UIMenuWndMovieVideo_Video_Menu_STRID_RESOLUTION;item < UIMenuWndMovieVideo_Video_Menu_MAX;item++)
    {
        UxMenu_SetItemData(&UIMenuWndMovieVideo_Video_MenuCtrl,item,MNUITM_STATUS,(STATUS_DISABLE));
    }



    UxCtrl_SetShow(&UIMenuWndMovieVideo_Dir_PanelCtrl,TRUE);
    //UxCtrl_SetShow(&UIMenuWndMovieVideo_Dir2_PanelCtrl,FALSE);
    //UxCtrl_SetShow(&UIMenuWndMovieVideo_Dir3_PanelCtrl,FALSE);
    bUIMenuWndMovieVideo_Video_MenuCtrl_rx_event = FALSE;

    /* Set key press/release/continue mask */
    Ux_FlushEvent();
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_PRESS, FLGKEY_KEY_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_RELEASE, FLGKEY_KEY_REL_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_CONTINUE, FLGKEY_KEY_CONT_MASK_DEFAULT);

    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndMovieVideo_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    /* Reset key press/release/continue mask to default */
    Ux_FlushEvent();
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_PRESS, FLGKEY_KEY_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_RELEASE, FLGKEY_KEY_REL_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_CONTINUE, FLGKEY_KEY_CONT_MASK_DEFAULT);
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndMovieVideo_OnChildClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    INT32 item;
    if (paramNum > 0)
    {
        if(*paramArray == 0x123)
        {
            Ux_PostEvent(NVTEVT_KEY_MENU, 0, 0);
//            Ux_DefaultEvent(pCtrl,NVTEVT_CHILD_CLOSE,0);
//            return NVTEVT_CONSUME;
        }
    }
    UxState_SetData(&UIMenuWndMovieVideo_Title_Mode_StatusCtrl,STATE_CURITEM,UIMenuWndMovieVideo_Title_Mode_Status_STRID_VIDEO);

    if(bUIMenuWndMovieVideo_Video_MenuCtrl_rx_event == FALSE)
    {
        //UxCtrl_SetShow(&UIMenuWndMovieVideo_Dir_PanelCtrl,TRUE);
        //UxCtrl_SetShow(&UIMenuWndMovieVideo_Dir2_PanelCtrl,FALSE);
        //UxCtrl_SetShow(&UIMenuWndMovieVideo_Dir3_PanelCtrl,FALSE);
    }
    else
    {
        //UxCtrl_SetShow(&UIMenuWndMovieVideo_Dir_PanelCtrl,FALSE);
        //UxCtrl_SetShow(&UIMenuWndMovieVideo_Dir2_PanelCtrl,TRUE);
        //UxCtrl_SetShow(&UIMenuWndMovieVideo_Dir3_PanelCtrl,FALSE);
    }

    if(bUIMenuWndMovieVideo_Video_MenuCtrl_rx_event == TRUE)
    {
        UxCtrl_SetShow(&UIMenuWndMovieVideo_Video_MenuCtrl,TRUE);
    }
    Ux_DefaultEvent(pCtrl,NVTEVT_CHILD_CLOSE,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndMovieVideo_OnKeyLeft(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    if(bUIMenuWndMovieVideo_Video_MenuCtrl_rx_event == FALSE)
    {
        Ux_OpenWindow(&UIMenuWndSetupCtrl,0);
        return NVTEVT_CONSUME;
    }
    return NVTEVT_PASS;
}
INT32 UIMenuWndMovieVideo_OnKeyRight(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    if(bUIMenuWndMovieVideo_Video_MenuCtrl_rx_event == FALSE)
    {
        Ux_OpenWindow(&UIMenuWndSetupCtrl,0);
        return NVTEVT_CONSUME;
    }
    return NVTEVT_PASS;
}
INT32 UIMenuWndMovieVideo_OnKeyMenu(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    //Ux_CloseWindow(pCtrl,0);
     Ux_OpenWindow(&UIMenuWndSetupCtrl,0);
    //Ux_DefaultEvent(pCtrl,NVTEVT_KEY_MENU,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndMovieVideo_OnKeyDown(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    INT32 item,page,total_page;
    if(bUIMenuWndMovieVideo_Video_MenuCtrl_rx_event == FALSE)
    {
        bUIMenuWndMovieVideo_Video_MenuCtrl_rx_event = TRUE;
        for(item = UIMenuWndMovieVideo_Video_Menu_STRID_RESOLUTION;item < UIMenuWndMovieVideo_Video_Menu_MAX;item++)
        {
            UxMenu_SetItemData(&UIMenuWndMovieVideo_Video_MenuCtrl,item,MNUITM_STATUS,(STATUS_ENABLE));
        }
        item = UxMenu_GetData(&UIMenuWndMovieVideo_Video_MenuCtrl,MNU_CURITM);
        page = UxMenu_GetData(&UIMenuWndMovieVideo_Video_MenuCtrl,MNU_PAGEITEM);

        debug_ind(("UIMenuWndSetup_OnKeyDown item = %d, page = %d\n\r",item, page));
        item = (item / page)+1;
        total_page = (UIMenuWndMovieVideo_Video_Menu_MAX / page)+(((UIMenuWndMovieVideo_Video_Menu_MAX % page) == 0)? 0:1);
        sprintf((char *)BottomBar_Buf,"%d/%d",item,total_page);
        debug_ind(("%s\n\r",BottomBar_Buf));
        UxStatic_SetData(&UIMenuWndMovieVideo_PageNum_StaticCtrl,STATIC_VALUE,Txt_Pointer(BottomBar_Buf));

        //UxCtrl_SetShow(&UIMenuWndMovieVideo_Dir_PanelCtrl,FALSE);
        //UxCtrl_SetShow(&UIMenuWndMovieVideo_Dir2_PanelCtrl,TRUE);
        //UxCtrl_SetShow(&UIMenuWndMovieVideo_Dir3_PanelCtrl,FALSE);
        return NVTEVT_CONSUME;
    }
    return NVTEVT_PASS;
}
INT32 UIMenuWndMovieVideo_OnKeyMode(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(&UISystemObjCtrl,NVTEVT_FORCETO_LIVEVIEW_MODE,0);
    return NVTEVT_CONSUME;
}
//---------------------UIMenuWndMovieVideo_PanelCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndMovieVideo_Panel)
CTRL_LIST_END

//----------------------UIMenuWndMovieVideo_PanelCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndMovieVideo_Panel)
EVENT_END

//---------------------UIMenuWndMovieVideo_Title_PanelCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndMovieVideo_Title_Panel)
CTRL_LIST_ITEM(UIMenuWndMovieVideo_Title_Mode_Status)
CTRL_LIST_END

//----------------------UIMenuWndMovieVideo_Title_PanelCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndMovieVideo_Title_Panel)
EVENT_END

//----------------------UIMenuWndMovieVideo_Title_Mode_StatusCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndMovieVideo_Title_Mode_Status)
EVENT_END

//---------------------UIMenuWndMovieVideo_End_PanelCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndMovieVideo_End_Panel)
CTRL_LIST_ITEM(UIMenuWndMovieVideo_Return_Static)
CTRL_LIST_ITEM(UIMenuWndMovieVideo_Dir_Panel)
CTRL_LIST_ITEM(UIMenuWndMovieVideo_PageNum_Static)
CTRL_LIST_END

//----------------------UIMenuWndMovieVideo_End_PanelCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndMovieVideo_End_Panel)
EVENT_END

//----------------------UIMenuWndMovieVideo_Return_StaticCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndMovieVideo_Return_Static)
EVENT_END

//---------------------UIMenuWndMovieVideo_Dir_PanelCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndMovieVideo_Dir_Panel)
CTRL_LIST_END

//----------------------UIMenuWndMovieVideo_Dir_PanelCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndMovieVideo_Dir_Panel)
EVENT_END

//----------------------UIMenuWndMovieVideo_PageNum_StaticCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndMovieVideo_PageNum_Static)
EVENT_END

//----------------------UIMenuWndMovieVideo_Video_MenuCtrl Event---------------------------
INT32 UIMenuWndMovieVideo_Video_Menu_OnKeyUp(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndMovieVideo_Video_Menu_OnKeyDown(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndMovieVideo_Video_Menu_OnKeyLeft(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndMovieVideo_Video_Menu_OnKeyRight(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndMovieVideo_Video_Menu_OnKeyEnter(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndMovieVideo_Video_Menu)
EVENT_ITEM(NVTEVT_KEY_UP,UIMenuWndMovieVideo_Video_Menu_OnKeyUp)
EVENT_ITEM(NVTEVT_KEY_DOWN,UIMenuWndMovieVideo_Video_Menu_OnKeyDown)
EVENT_ITEM(NVTEVT_KEY_LEFT,UIMenuWndMovieVideo_Video_Menu_OnKeyLeft)
EVENT_ITEM(NVTEVT_KEY_RIGHT,UIMenuWndMovieVideo_Video_Menu_OnKeyRight)
EVENT_ITEM(NVTEVT_KEY_ENTER,UIMenuWndMovieVideo_Video_Menu_OnKeyEnter)
EVENT_END

INT32 UIMenuWndMovieVideo_Video_Menu_OnKeyUp(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    INT32   item;
    INT32   page,total_page;
    if(bUIMenuWndMovieVideo_Video_MenuCtrl_rx_event == TRUE)
    {
        item = UxMenu_GetData(pCtrl,MNU_CURITM);
        page = UxMenu_GetData(pCtrl,MNU_PAGEITEM);
        if(item == (UIMenuWndMovieVideo_Video_Menu_MAX - 1))
        {
            item = 0;
            item = (item/ page) + 1;
        }
        else
            item = ((item+1) / page) + 1;
        total_page = (UIMenuWndMovieVideo_Video_Menu_MAX / page)+(((UIMenuWndMovieVideo_Video_Menu_MAX % page) == 0)? 0:1);
        debug_ind(("UIMenuWndSetup_Setup_Menu_OnKeyDown item = %d, page = %d\n\r",item, page));

        sprintf((char *)BottomBar_Buf,"%d/%d",item,total_page);
        UxStatic_SetData(&UIMenuWndMovieVideo_PageNum_StaticCtrl,STATIC_VALUE,Txt_Pointer(BottomBar_Buf));

        Ux_SendEvent(pCtrl,NVTEVT_PREVIOUS_ITEM,0);
    }
    //Ux_SendEvent(pCtrl,NVTEVT_PREVIOUS_ITEM,0);
    return NVTEVT_CONSUME;


#if 0
    bUIMenuWndMovieVideo_Video_MenuCtrl_rx_event = TRUE;
    UxMenu_SetItemData(&UIMenuWndMovieVideo_Video_MenuCtrl,UIMenuWndMovieVideo_Video_Menu_STRID_RESOLUTION,MNUITM_STATUS,(STATUS_ENABLE | STATUS_FOCUS_BIT));
    UxCtrl_SetShow(&UIMenuWndMovieVideo_Dir_PanelCtrl,FALSE);
    UxCtrl_SetShow(&UIMenuWndMovieVideo_Dir2_PanelCtrl,TRUE);
    UxCtrl_SetShow(&UIMenuWndMovieVideo_Dir3_PanelCtrl,FALSE);

    Ux_SendEvent(pCtrl,NVTEVT_PREVIOUS_ITEM,0);
    return NVTEVT_CONSUME;
#endif
}
INT32 UIMenuWndMovieVideo_Video_Menu_OnKeyDown(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    INT32   item;
    INT32   page,total_page;
    if(bUIMenuWndMovieVideo_Video_MenuCtrl_rx_event == TRUE)
    {
        item = UxMenu_GetData(pCtrl,MNU_CURITM);
        page = UxMenu_GetData(pCtrl,MNU_PAGEITEM);
        if(item == 0)
        {
            item = UIMenuWndMovieVideo_Video_Menu_MAX - 1;
            item = (item/ page) + 1;
        }
        else
            item = ((item-1) / page) + 1;
        total_page = (UIMenuWndMovieVideo_Video_Menu_MAX / page)+(((UIMenuWndMovieVideo_Video_Menu_MAX % page) == 0)? 0:1);
        debug_ind(("UIMenuWndSetup_Setup_Menu_OnKeyUp item = %d, page = %d\n\r",item, page));

        sprintf((char *)BottomBar_Buf,"%d/%d",item,total_page);
        UxStatic_SetData(&UIMenuWndMovieVideo_PageNum_StaticCtrl,STATIC_VALUE,Txt_Pointer(BottomBar_Buf));

        Ux_SendEvent(pCtrl,NVTEVT_NEXT_ITEM,0);
    }
    //Ux_SendEvent(pCtrl,NVTEVT_NEXT_ITEM,0);
    #if 0
    if(bUIMenuWndMovieVideo_Video_MenuCtrl_rx_event == TRUE)
    {
        Ux_SendEvent(pCtrl,NVTEVT_NEXT_ITEM,0);
    }
    #endif
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndMovieVideo_Video_Menu_OnKeyLeft(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    INT32   item,page,total_page;
    if(bUIMenuWndMovieVideo_Video_MenuCtrl_rx_event == TRUE)
    {
        for(item = UIMenuWndMovieVideo_Video_Menu_STRID_RESOLUTION;item < UIMenuWndMovieVideo_Video_Menu_MAX;item++)
        {
            UxMenu_SetItemData(&UIMenuWndMovieVideo_Video_MenuCtrl,item,MNUITM_STATUS,(STATUS_DISABLE | STATUS_NORMAL_BIT));
        }
        UxMenu_SetData(pCtrl,MNU_CURITM,UIMenuWndMovieVideo_Video_Menu_STRID_RESOLUTION);

        item = UxMenu_GetData(pCtrl,MNU_CURITM);
        page = UxMenu_GetData(pCtrl,MNU_PAGEITEM);
        item = (item / page)+1;
        total_page = (UIMenuWndMovieVideo_Video_Menu_MAX / page)+(((UIMenuWndMovieVideo_Video_Menu_MAX % page) == 0)? 0:1);
        debug_ind(("UIMenuWndMovieVideo_Video_Menu_OnKeyLeft item = %d, page = %d\n\r",item, page));
        sprintf((char *)BottomBar_Buf,"%d/%d",item,total_page);
        debug_ind(("%s\n\r",BottomBar_Buf));
        UxStatic_SetData(&UIMenuWndMovieVideo_PageNum_StaticCtrl,STATIC_VALUE,Txt_Pointer(BottomBar_Buf));

        //UxCtrl_SetShow(&UIMenuWndMovieVideo_Dir_PanelCtrl,TRUE);
        //UxCtrl_SetShow(&UIMenuWndMovieVideo_Dir2_PanelCtrl,FALSE);
        //UxCtrl_SetShow(&UIMenuWndMovieVideo_Dir3_PanelCtrl,FALSE);
    }
    bUIMenuWndMovieVideo_Video_MenuCtrl_rx_event = FALSE;
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndMovieVideo_Video_Menu_OnKeyRight(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    INT32 item;
    if(bUIMenuWndMovieVideo_Video_MenuCtrl_rx_event == TRUE)
    {
        item = UxMenu_GetData(pCtrl,MNU_CURITM);
        UxState_SetData(&UIMenuWndMovieVideo_Title_Mode_StatusCtrl,STATE_CURITEM,(UIMenuWndMovieVideo_Title_Mode_Status_STRID_VIDEO + item + 1));
        UxCtrl_SetDirty(&UIMenuWndMovieVideo_Title_Mode_StatusCtrl, TRUE);

//        UxState_SetData(&UIMenuWndMovieVideo_Title_Mode_StatusCtrl,STATE_CURITEM,UIMenuWndMovieVideo_Title_Mode_Status_STRID_RESOLUTION);

//        UxCtrl_SetDirty(&UIMenuWndMovieVideo_Title_Mode_StatusCtrl, TRUE);
        //UxCtrl_SetShow(&UIMenuWndMovieVideo_Dir_PanelCtrl,FALSE);
        //UxCtrl_SetShow(&UIMenuWndMovieVideo_Dir2_PanelCtrl,FALSE);
        //UxCtrl_SetShow(&UIMenuWndMovieVideo_Dir3_PanelCtrl,TRUE);
        debug_err(("UIMenuWndMovieVideo_Video_Menu_OnKeyRight,item=%d\n\r",item));
        Ux_Redraw();

        switch (item)
        {
        case UIMenuWndMovieVideo_Video_Menu_STRID_RESOLUTION:
            Ux_OpenWindow(&UIMenuWndMovieResCtrl,0);
            break;
        case UIMenuWndMovieVideo_Video_Menu_STRID_CYCLIC_REC:
            Ux_OpenWindow(&UIMenuWndMovieCyclicRecCtrl,0);
            break;
        case UIMenuWndMovieVideo_Video_Menu_STRID_MOTION_DET:
            Ux_OpenWindow(&UIMenuWndMovieMotionDetCtrl,0);
            break;
        case UIMenuWndMovieVideo_Video_Menu_STRID_RECORD_AUDIO:
            Ux_OpenWindow(&UIMenuWndMovieAudioSetCtrl,0);
            break;
        //case UIMenuWndMovieVideo_Video_Menu_STRID_GOD_BLESS:
            //Ux_OpenWindow(&UIMenuWndMovieGodBlessCtrl,0);
            //break;
        case UIMenuWndMovieVideo_Video_Menu_STRID_DATE_STAMP:
            Ux_OpenWindow(&UIMenuWndMovieDateStampCtrl,0);
            break;

        case UIMenuWndMovieVideo_Video_Menu_STRID_EV:
            Ux_OpenWindow(&UIMenuWndMovieEVCtrl,0);
            break;
			
        case UIMenuWndMovieVideo_Video_Menu_STRID_WB:
            Ux_OpenWindow(&UIMenuWndMovieWBCtrl,0);
            break;

	  case UIMenuWndMovieVideo_Video_Menu_STRID_GSENSOR_SENSITIVITY:
	  	Ux_OpenWindow(&UIMenuWndMovieGsensorCtrl,0);
		break;
		
        }

    }
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndMovieVideo_Video_Menu_OnKeyEnter(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return UIMenuWndMovieVideo_Video_Menu_OnKeyRight(pCtrl, paramNum, paramArray); // the same behavior as RIGHT key
}
