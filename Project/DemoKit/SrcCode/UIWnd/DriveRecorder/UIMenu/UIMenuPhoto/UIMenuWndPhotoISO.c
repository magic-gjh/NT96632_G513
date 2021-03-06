//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIMenuWndPhotoISORes.c"
#include "UIMenuWndPhotoISO.h"
#include "UIMenuWndPhotoStill.h"
#include "UIPhotoObj.h"
#include "UISystemObj.h"
#include "KeyScanTsk.h"
//---------------------UIMenuWndPhotoISOCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndPhotoISO)
CTRL_LIST_ITEM(UIMenuWndPhotoISO_Panel)
CTRL_LIST_END

//----------------------UIMenuWndPhotoISOCtrl Event---------------------------
INT32 UIMenuWndPhotoISO_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoISO_OnClose(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndPhotoISO)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIMenuWndPhotoISO_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIMenuWndPhotoISO_OnClose)
EVENT_END

INT32 UIMenuWndPhotoISO_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UxMenu_SetData(&UIMenuWndPhotoISO_MenuCtrl,MNU_CURITM,Get_ISOIndex());
    /* Set key press/release/continue mask */
    Ux_FlushEvent();
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_PRESS, FLGKEY_KEY_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_RELEASE, FLGKEY_KEY_REL_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_CONTINUE, FLGKEY_KEY_CONT_MASK_DEFAULT);
    Ux_RedrawAllWind();
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoISO_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    /* Reset key press/release/continue mask to default */
    Ux_FlushEvent();
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_PRESS, FLGKEY_KEY_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_RELEASE, FLGKEY_KEY_REL_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_CONTINUE, FLGKEY_KEY_CONT_MASK_DEFAULT);
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
//---------------------UIMenuWndPhotoISO_PanelCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndPhotoISO_Panel)
CTRL_LIST_ITEM(UIMenuWndPhotoISO_Menu)
CTRL_LIST_END

//----------------------UIMenuWndPhotoISO_PanelCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndPhotoISO_Panel)
EVENT_END

//----------------------UIMenuWndPhotoISO_MenuCtrl Event---------------------------
INT32 UIMenuWndPhotoISO_Menu_OnKeyUp(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoISO_Menu_OnKeyDown(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoISO_Menu_OnKeyLeft(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoISO_Menu_OnKeyEnter(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoISO_Menu_OnKeyMenu(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoISO_Menu_OnKeyMode(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndPhotoISO_Menu)
EVENT_ITEM(NVTEVT_KEY_UP,UIMenuWndPhotoISO_Menu_OnKeyUp)
EVENT_ITEM(NVTEVT_KEY_DOWN,UIMenuWndPhotoISO_Menu_OnKeyDown)
EVENT_ITEM(NVTEVT_KEY_LEFT,UIMenuWndPhotoISO_Menu_OnKeyLeft)
EVENT_ITEM(NVTEVT_KEY_ENTER,UIMenuWndPhotoISO_Menu_OnKeyEnter)
EVENT_ITEM(NVTEVT_KEY_MENU,UIMenuWndPhotoISO_Menu_OnKeyMenu)
EVENT_ITEM(NVTEVT_KEY_MODE,UIMenuWndPhotoISO_Menu_OnKeyMode)
EVENT_END

INT32 UIMenuWndPhotoISO_Menu_OnKeyUp(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(pCtrl,NVTEVT_PREVIOUS_ITEM,0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoISO_Menu_OnKeyDown(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(pCtrl,NVTEVT_NEXT_ITEM,0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoISO_Menu_OnKeyLeft(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_CloseWindow(&UIMenuWndPhotoISOCtrl,0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoISO_Menu_OnKeyEnter(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    INT32   value;
    value = UxMenu_GetData(pCtrl,MNU_CURITM);
    Ux_SendEvent(&UIPhotoObjCtrl,NVTEVT_EXE_ISO,1,value);
    Ux_CloseWindow(&UIMenuWndPhotoISOCtrl,0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoISO_Menu_OnKeyMenu(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_CloseWindow(&UIMenuWndPhotoStillCtrl,0); // close photo still menu
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoISO_Menu_OnKeyMode(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(&UISystemObjCtrl,NVTEVT_FORCETO_LIVEVIEW_MODE,0);
    return NVTEVT_CONSUME;
}
