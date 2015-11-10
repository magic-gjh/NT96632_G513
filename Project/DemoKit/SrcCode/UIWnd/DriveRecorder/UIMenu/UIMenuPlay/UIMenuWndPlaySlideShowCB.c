//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIMenuWndPlaySlideShowCBRes.c"
#include "UIMenuWndPlaySlideShowCB.h"
//#NT#2009/09/14#Chris Chung -begin
#include "UIMenuWndPlayback.h"
#include "UIFlowWndPlay.h"
#include "UIPlayObj.h"
#include "UIFlowWndPlayFuncs.h"
#include "UIMenuWndPlaySlideShow.h"
#include "UISystemObj.h"
#include "KeyScanTsk.h"
//#NT#2009/09/14#Chris Chung -end

//---------------------UIMenuWndPlaySlideShowCBCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndPlaySlideShowCB)
CTRL_LIST_END

//----------------------UIMenuWndPlaySlideShowCBCtrl Event---------------------------
INT32 UIMenuWndPlaySlideShowCB_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlaySlideShowCB_OnClose(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlaySlideShowCB_OnKeyEnter(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlaySlideShowCB_OnSlideKeep(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlaySlideShowCB_OnKeyShutter2(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlaySlideShowCB_OnKeyMenu(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlaySlideShowCB_OnKeyMode(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndPlaySlideShowCB)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIMenuWndPlaySlideShowCB_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIMenuWndPlaySlideShowCB_OnClose)
EVENT_ITEM(NVTEVT_KEY_ENTER,UIMenuWndPlaySlideShowCB_OnKeyEnter)
EVENT_ITEM(NVTEVT_CB_SLIDE_KEEP,UIMenuWndPlaySlideShowCB_OnSlideKeep)
EVENT_ITEM(NVTEVT_KEY_SHUTTER2,UIMenuWndPlaySlideShowCB_OnKeyShutter2)
EVENT_ITEM(NVTEVT_KEY_MENU,UIMenuWndPlaySlideShowCB_OnKeyMenu)
EVENT_ITEM(NVTEVT_KEY_MODE,UIMenuWndPlaySlideShowCB_OnKeyMode)
EVENT_END

INT32 UIMenuWndPlaySlideShowCB_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    //#NT#2009/09/14#Chris Chung -begin
    UINT32 uiSlideInterval;

    if (paramNum == 1)
    {
        uiSlideInterval = paramArray[0];
    }
    else
    {
        uiSlideInterval = 2000; // default slide show time interval is 2sec
    }

    UIPlay_SetData(PLAY_SLIDERTIME,uiSlideInterval);
    KeyScan_EnableAutoPoweroff(FALSE);
    Ux_SendEvent(&UIPlayObjCtrl,NVTEVT_SLIDEINIT,1,&FlowPB_SliderCBFunc);

    /* Set key press/release/continue mask */
    Ux_FlushEvent();
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_PRESS, FLGKEY_KEY_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_RELEASE, FLGKEY_KEY_REL_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_CONTINUE, FLGKEY_KEY_CONT_MASK_DEFAULT);
    //#NT#2009/09/14#Chris Chung -end
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlaySlideShowCB_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    KeyScan_EnableAutoPoweroff(TRUE);
    //#NT#2009/09/14#Chris Chung -begin
    /* Reset key press/release/continue mask to default */
    Ux_FlushEvent();
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_PRESS, FLGKEY_KEY_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_RELEASE, FLGKEY_KEY_REL_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_CONTINUE, FLGKEY_KEY_CONT_MASK_DEFAULT);
    //#NT#2009/09/14#Chris Chung -end
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlaySlideShowCB_OnKeyEnter(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    VControl *pCloseWnd = NULL;

    //#NT#2009/09/03#Chris Chung -begin
    Ux_SendEvent(&UIPlayObjCtrl,NVTEVT_SLIDESTOP,0);
    KeyScan_EnableAutoPoweroff(TRUE);
    //Ux_CloseWindow(&UIMenuWndPlaySlideShowCtrl,0);
    //#NT#2009/09/03#Chris Chung -end
    /* Close all the window upper than root */
    Ux_GeWindowByIndex(&pCloseWnd, UX_2NDLAYER_WND_IDX);
    if(pCloseWnd)
    {
        Ux_CloseWindow(pCloseWnd, 0);
    }
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlaySlideShowCB_OnSlideKeep(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    //#NT#2009/08/03#Chris Chung -begin
    Ux_SendEvent(&UIPlayObjCtrl,NVTEVT_SLIDEKEEP,0);
    //#NT#2009/08/03#Chris Chung -end
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlaySlideShowCB_OnKeyShutter2(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlaySlideShowCB_OnKeyMenu(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlaySlideShowCB_OnKeyMode(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    //#NT#2009/09/14#Chris Chung -begin
    Ux_SendEvent(&UISystemObjCtrl,NVTEVT_FORCETO_LIVEVIEW_MODE,0);
    //#NT#2009/09/14#Chris Chung -end
    return NVTEVT_CONSUME;
}
