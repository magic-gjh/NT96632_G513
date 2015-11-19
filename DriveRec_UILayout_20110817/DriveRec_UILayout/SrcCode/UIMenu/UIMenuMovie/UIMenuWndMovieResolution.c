//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIMenuWndMovieResolutionRes.c"
#include "UIMenuWndMovieResolution.h"
//---------------------UIMenuWndMovieResCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndMovieRes)
CTRL_LIST_ITEM(UIMenuWndMovieRes_Panel)
CTRL_LIST_END

//----------------------UIMenuWndMovieResCtrl Event---------------------------
INT32 UIMenuWndMovieRes_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndMovieRes_OnClose(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndMovieRes_OnKeyLeft(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndMovieRes_OnKeyMenu(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndMovieRes_OnKeyMode(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndMovieRes)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIMenuWndMovieRes_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIMenuWndMovieRes_OnClose)
EVENT_ITEM(NVTEVT_KEY_LEFT,UIMenuWndMovieRes_OnKeyLeft)
EVENT_ITEM(NVTEVT_KEY_MENU,UIMenuWndMovieRes_OnKeyMenu)
EVENT_ITEM(NVTEVT_KEY_MODE,UIMenuWndMovieRes_OnKeyMode)
EVENT_END

INT32 UIMenuWndMovieRes_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndMovieRes_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndMovieRes_OnKeyLeft(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndMovieRes_OnKeyMenu(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndMovieRes_OnKeyMode(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return NVTEVT_CONSUME;
}
//---------------------UIMenuWndMovieRes_PanelCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndMovieRes_Panel)
CTRL_LIST_ITEM(UIMenuWndMovieRes_Menu)
CTRL_LIST_END

//----------------------UIMenuWndMovieRes_PanelCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndMovieRes_Panel)
EVENT_END

//----------------------UIMenuWndMovieRes_MenuCtrl Event---------------------------
INT32 UIMenuWndMovieRes_Menu_OnKeyUp(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndMovieRes_Menu_OnKeyDown(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndMovieRes_Menu_OnKeyEnter(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndMovieRes_Menu)
EVENT_ITEM(NVTEVT_KEY_UP,UIMenuWndMovieRes_Menu_OnKeyUp)
EVENT_ITEM(NVTEVT_KEY_DOWN,UIMenuWndMovieRes_Menu_OnKeyDown)
EVENT_ITEM(NVTEVT_KEY_ENTER,UIMenuWndMovieRes_Menu_OnKeyEnter)
EVENT_END

INT32 UIMenuWndMovieRes_Menu_OnKeyUp(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(pCtrl,NVTEVT_PREVIOUS_ITEM,0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndMovieRes_Menu_OnKeyDown(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(pCtrl,NVTEVT_NEXT_ITEM,0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndMovieRes_Menu_OnKeyEnter(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_KEY_ENTER,paramNum,paramArray);
    return NVTEVT_CONSUME;
}