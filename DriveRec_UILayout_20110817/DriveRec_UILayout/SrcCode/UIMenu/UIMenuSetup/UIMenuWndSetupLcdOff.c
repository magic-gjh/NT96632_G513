//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIMenuWndSetupLcdOffRes.c"
#include "UIMenuWndSetupLcdOff.h"
//---------------------UIMenuWndSetupLcdOffCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndSetupLcdOff)
CTRL_LIST_ITEM(UIMenuWndSetupLcdOff_List_Text)
CTRL_LIST_END

//----------------------UIMenuWndSetupLcdOffCtrl Event---------------------------
INT32 UIMenuWndSetupLcdOff_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndSetupLcdOff_OnClose(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndSetupLcdOff_OnKeyLeft(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndSetupLcdOff_OnKeyMenu(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndSetupLcdOff_OnKeyMode(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndSetupLcdOff)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIMenuWndSetupLcdOff_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIMenuWndSetupLcdOff_OnClose)
EVENT_ITEM(NVTEVT_KEY_LEFT,UIMenuWndSetupLcdOff_OnKeyLeft)
EVENT_ITEM(NVTEVT_KEY_MENU,UIMenuWndSetupLcdOff_OnKeyMenu)
EVENT_ITEM(NVTEVT_KEY_MODE,UIMenuWndSetupLcdOff_OnKeyMode)
EVENT_END

INT32 UIMenuWndSetupLcdOff_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndSetupLcdOff_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndSetupLcdOff_OnKeyLeft(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndSetupLcdOff_OnKeyMenu(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndSetupLcdOff_OnKeyMode(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return NVTEVT_CONSUME;
}
//----------------------UIMenuWndSetupLcdOff_List_TextCtrl Event---------------------------
INT32 UIMenuWndSetupLcdOff_List_Text_OnKeyUp(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndSetupLcdOff_List_Text_OnKeyDown(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndSetupLcdOff_List_Text_OnKeyEnter(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndSetupLcdOff_List_Text)
EVENT_ITEM(NVTEVT_KEY_UP,UIMenuWndSetupLcdOff_List_Text_OnKeyUp)
EVENT_ITEM(NVTEVT_KEY_DOWN,UIMenuWndSetupLcdOff_List_Text_OnKeyDown)
EVENT_ITEM(NVTEVT_KEY_ENTER,UIMenuWndSetupLcdOff_List_Text_OnKeyEnter)
EVENT_END

INT32 UIMenuWndSetupLcdOff_List_Text_OnKeyUp(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(pCtrl,NVTEVT_PREVIOUS_ITEM,0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndSetupLcdOff_List_Text_OnKeyDown(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(pCtrl,NVTEVT_NEXT_ITEM,0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndSetupLcdOff_List_Text_OnKeyEnter(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return NVTEVT_CONSUME;
}
