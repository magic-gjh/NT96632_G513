//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIMenuWndPhotoResolutionRes.c"
#include "UIMenuWndPhotoResolution.h"
//---------------------UIMenuWndPhotoResCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndPhotoRes)
CTRL_LIST_ITEM(UIMenuWndPhotoRes_Panel)
CTRL_LIST_END

//----------------------UIMenuWndPhotoResCtrl Event---------------------------
INT32 UIMenuWndPhotoRes_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoRes_OnClose(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndPhotoRes)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIMenuWndPhotoRes_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIMenuWndPhotoRes_OnClose)
EVENT_END

INT32 UIMenuWndPhotoRes_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoRes_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
//---------------------UIMenuWndPhotoRes_PanelCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndPhotoRes_Panel)
CTRL_LIST_ITEM(UIMenuWndPhotoRes_Menu)
CTRL_LIST_END

//----------------------UIMenuWndPhotoRes_PanelCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndPhotoRes_Panel)
EVENT_END

//----------------------UIMenuWndPhotoRes_MenuCtrl Event---------------------------
INT32 UIMenuWndPhotoRes_Menu_OnKeyUp(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoRes_Menu_OnKeyDown(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoRes_Menu_OnKeyLeft(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoRes_Menu_OnKeyEnter(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoRes_Menu_OnKeyMenu(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoRes_Menu_OnKeyMode(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndPhotoRes_Menu)
EVENT_ITEM(NVTEVT_KEY_UP,UIMenuWndPhotoRes_Menu_OnKeyUp)
EVENT_ITEM(NVTEVT_KEY_DOWN,UIMenuWndPhotoRes_Menu_OnKeyDown)
EVENT_ITEM(NVTEVT_KEY_LEFT,UIMenuWndPhotoRes_Menu_OnKeyLeft)
EVENT_ITEM(NVTEVT_KEY_ENTER,UIMenuWndPhotoRes_Menu_OnKeyEnter)
EVENT_ITEM(NVTEVT_KEY_MENU,UIMenuWndPhotoRes_Menu_OnKeyMenu)
EVENT_ITEM(NVTEVT_KEY_MODE,UIMenuWndPhotoRes_Menu_OnKeyMode)
EVENT_END

INT32 UIMenuWndPhotoRes_Menu_OnKeyUp(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(pCtrl,NVTEVT_PREVIOUS_ITEM,0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoRes_Menu_OnKeyDown(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(pCtrl,NVTEVT_NEXT_ITEM,0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoRes_Menu_OnKeyLeft(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoRes_Menu_OnKeyEnter(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoRes_Menu_OnKeyMenu(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoRes_Menu_OnKeyMode(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return NVTEVT_CONSUME;
}
