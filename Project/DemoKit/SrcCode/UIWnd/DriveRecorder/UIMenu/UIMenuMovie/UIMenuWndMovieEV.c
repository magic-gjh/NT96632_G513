//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIMenuWndMovieEVRes.c"
#include "UIMenuWndMovieEV.h"
#include "UIPhotoObj.h"
#include "UISystemObj.h"
#include "KeyScanTsk.h"
//---------------------UIMenuWndMovieEVCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndMovieEV)
CTRL_LIST_ITEM(UIMenuWndMovieEV_Panel)
CTRL_LIST_END

//----------------------UIMenuWndMovieEVCtrl Event---------------------------
INT32 UIMenuWndMovieEV_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndMovieEV_OnClose(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndMovieEV)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIMenuWndMovieEV_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIMenuWndMovieEV_OnClose)
EVENT_END

INT32 UIMenuWndMovieEV_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UxMenu_SetData(&UIMenuWndMovieEV_MenuCtrl,MNU_CURITM,Get_EVIndex());
    /* Set key press/release/continue mask */
    Ux_FlushEvent();
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_PRESS, FLGKEY_KEY_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_RELEASE, FLGKEY_KEY_REL_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_CONTINUE, FLGKEY_KEY_CONT_MASK_DEFAULT);
    Ux_RedrawAllWind();
	
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndMovieEV_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_FlushEvent();
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_PRESS, FLGKEY_KEY_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_RELEASE, FLGKEY_KEY_REL_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_CONTINUE, FLGKEY_KEY_CONT_MASK_DEFAULT);
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
//---------------------UIMenuWndMovieEV_PanelCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndMovieEV_Panel)
CTRL_LIST_ITEM(UIMenuWndMovieEV_Menu)
CTRL_LIST_END

//----------------------UIMenuWndMovieEV_PanelCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndMovieEV_Panel)
EVENT_END

//----------------------UIMenuWndMovieEV_MenuCtrl Event---------------------------
INT32 UIMenuWndMovieEV_Menu_OnKeyUp(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndMovieEV_Menu_OnKeyDown(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndMovieEV_Menu_OnKeyLeft(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndMovieEV_Menu_OnKeyEnter(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndMovieEV_Menu_OnKeyMenu(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndMovieEV_Menu_OnKeyMode(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndMovieEV_Menu)
EVENT_ITEM(NVTEVT_KEY_UP,UIMenuWndMovieEV_Menu_OnKeyUp)
EVENT_ITEM(NVTEVT_KEY_DOWN,UIMenuWndMovieEV_Menu_OnKeyDown)
EVENT_ITEM(NVTEVT_KEY_LEFT,UIMenuWndMovieEV_Menu_OnKeyLeft)
EVENT_ITEM(NVTEVT_KEY_ENTER,UIMenuWndMovieEV_Menu_OnKeyEnter)
EVENT_ITEM(NVTEVT_KEY_MENU,UIMenuWndMovieEV_Menu_OnKeyMenu)
EVENT_ITEM(NVTEVT_KEY_MODE,UIMenuWndMovieEV_Menu_OnKeyMode)
EVENT_END

INT32 UIMenuWndMovieEV_Menu_OnKeyUp(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(pCtrl,NVTEVT_PREVIOUS_ITEM,0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndMovieEV_Menu_OnKeyDown(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(pCtrl,NVTEVT_NEXT_ITEM,0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndMovieEV_Menu_OnKeyLeft(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndMovieEV_Menu_OnKeyEnter(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    INT32   value;
    value = UxMenu_GetData(pCtrl,MNU_CURITM);
    Ux_SendEvent(&UIPhotoObjCtrl,NVTEVT_EXE_EV,1,value);
    Ux_CloseWindow(&UIMenuWndMovieEVCtrl,0);
	
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndMovieEV_Menu_OnKeyMenu(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_CloseWindow(&UIMenuWndMovieEVCtrl,0); // close photo still menu
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndMovieEV_Menu_OnKeyMode(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(&UISystemObjCtrl,NVTEVT_FORCETO_LIVEVIEW_MODE,0);
    return NVTEVT_CONSUME;
}
