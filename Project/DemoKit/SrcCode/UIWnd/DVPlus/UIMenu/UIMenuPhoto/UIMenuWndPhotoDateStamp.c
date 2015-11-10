//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIMenuWndPhotoDateStampRes.c"
#include "UIMenuWndPhotoDateStamp.h"
#include "UIMenuWndPhotoStill.h"
#include "UIPhotoObj.h"
#include "UISystemObj.h"
#include "KeyScanTsk.h"

//---------------------UIMenuWndPhotoDateStampCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndPhotoDateStamp)
CTRL_LIST_ITEM(UIMenuWndPhotoDateStamp_Panel)
CTRL_LIST_END

//----------------------UIMenuWndPhotoDateStampCtrl Event---------------------------
INT32 UIMenuWndPhotoDateStamp_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoDateStamp_OnClose(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndPhotoDateStamp)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIMenuWndPhotoDateStamp_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIMenuWndPhotoDateStamp_OnClose)
EVENT_END

INT32 UIMenuWndPhotoDateStamp_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UxMenu_SetData(&UIMenuWndPhotoDateStamp_MenuCtrl,MNU_CURITM,Get_DateImprintIndex());
    /* Set key press/release/continue mask */
    Ux_FlushEvent();
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_PRESS, FLGKEY_KEY_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_RELEASE, FLGKEY_KEY_REL_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_CONTINUE, FLGKEY_KEY_CONT_MASK_DEFAULT);
    Ux_RedrawAllWind();
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoDateStamp_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    /* Reset key press/release/continue mask to default */
    Ux_FlushEvent();
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_PRESS, FLGKEY_KEY_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_RELEASE, FLGKEY_KEY_REL_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_CONTINUE, FLGKEY_KEY_CONT_MASK_DEFAULT);
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
//---------------------UIMenuWndPhotoDateStamp_PanelCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndPhotoDateStamp_Panel)
CTRL_LIST_ITEM(UIMenuWndPhotoDateStamp_Menu)
CTRL_LIST_END

//----------------------UIMenuWndPhotoDateStamp_PanelCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndPhotoDateStamp_Panel)
EVENT_END

//----------------------UIMenuWndPhotoDateStamp_MenuCtrl Event---------------------------
INT32 UIMenuWndPhotoDateStamp_Menu_OnKeyUp(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoDateStamp_Menu_OnKeyDown(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoDateStamp_Menu_OnKeyLeft(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoDateStamp_Menu_OnKeyEnter(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoDateStamp_Menu_OnKeyMenu(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoDateStamp_Menu_OnKeyMode(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndPhotoDateStamp_Menu)
EVENT_ITEM(NVTEVT_KEY_UP,UIMenuWndPhotoDateStamp_Menu_OnKeyUp)
EVENT_ITEM(NVTEVT_KEY_DOWN,UIMenuWndPhotoDateStamp_Menu_OnKeyDown)
EVENT_ITEM(NVTEVT_KEY_LEFT,UIMenuWndPhotoDateStamp_Menu_OnKeyLeft)
EVENT_ITEM(NVTEVT_KEY_ENTER,UIMenuWndPhotoDateStamp_Menu_OnKeyEnter)
EVENT_ITEM(NVTEVT_KEY_MENU,UIMenuWndPhotoDateStamp_Menu_OnKeyMenu)
EVENT_ITEM(NVTEVT_KEY_MODE,UIMenuWndPhotoDateStamp_Menu_OnKeyMode)
EVENT_END

INT32 UIMenuWndPhotoDateStamp_Menu_OnKeyUp(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(pCtrl,NVTEVT_PREVIOUS_ITEM,0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoDateStamp_Menu_OnKeyDown(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(pCtrl,NVTEVT_NEXT_ITEM,0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoDateStamp_Menu_OnKeyLeft(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_CloseWindow(&UIMenuWndPhotoDateStampCtrl,0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoDateStamp_Menu_OnKeyEnter(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    INT32   value;
    value = UxMenu_GetData(pCtrl,MNU_CURITM);
    Ux_SendEvent(&UIPhotoObjCtrl,NVTEVT_EXE_DATEIMPRINT,1,value);
    Ux_CloseWindow(&UIMenuWndPhotoDateStampCtrl,0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoDateStamp_Menu_OnKeyMenu(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_CloseWindow(&UIMenuWndPhotoStillCtrl,0); // close photo still menu
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoDateStamp_Menu_OnKeyMode(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(&UISystemObjCtrl,NVTEVT_FORCETO_LIVEVIEW_MODE,0);
    return NVTEVT_CONSUME;
}
