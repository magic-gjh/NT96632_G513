//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIMenuWndPlayQuickDelRes.c"
#include "UIMenuWndPlayQuickDel.h"
//#NT#2009/08/04#Chris Chung -begin
#include "UIMenuWndPlayQuickConfirmDel.h"
#include "PlaybackTsk.h"
#include "UISystemObj.h"
#include "KeyScanTsk.h"
//#NT#2009/08/04#Chris Chung -end

//---------------------UIMenuWndPlayQuickDelCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndPlayQuickDel)
CTRL_LIST_ITEM(UIMenuWndPlayQuickDel_Status)
CTRL_LIST_ITEM(UIMenuWndPlayQuickDel_Panel)
CTRL_LIST_END

//----------------------UIMenuWndPlayQuickDelCtrl Event---------------------------
INT32 UIMenuWndPlayQuickDel_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlayQuickDel_OnClose(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlayQuickDel_OnKeyMode(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndPlayQuickDel)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIMenuWndPlayQuickDel_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIMenuWndPlayQuickDel_OnClose)
EVENT_ITEM(NVTEVT_KEY_MODE,UIMenuWndPlayQuickDel_OnKeyMode)
EVENT_END

INT32 UIMenuWndPlayQuickDel_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    //#NT#2009/08/05#Chris Chung -begin
    UxMenu_SetData(&UIMenuWndPlayQuickDel_MenuCtrl, MNU_CURITM, 0);

    if(PB_GetCurrMode() == PLAYMODE_ASF ||
       PB_GetCurrMode() == PLAYMODE_AVI)
    {
        UxState_SetData(&UIMenuWndPlayQuickDel_StatusCtrl,STATE_CURITEM,UIMenuWndPlayQuickDel_Status_ICON_FILE_VIDEO);
    }
    else
    {
        UxState_SetData(&UIMenuWndPlayQuickDel_StatusCtrl,STATE_CURITEM,UIMenuWndPlayQuickDel_Status_ICON_MODE_PLAYBACK);
    }
    //#NT#2009/08/05#Chris Chung -end
    /* Set key press/release/continue mask */
    Ux_FlushEvent();
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_PRESS, FLGKEY_KEY_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_RELEASE, FLGKEY_KEY_REL_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_CONTINUE, FLGKEY_KEY_CONT_MASK_DEFAULT);
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlayQuickDel_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    /* Reset key press/release/continue mask to default */
    Ux_FlushEvent();
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_PRESS, FLGKEY_KEY_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_RELEASE, FLGKEY_KEY_REL_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_CONTINUE, FLGKEY_KEY_CONT_MASK_DEFAULT);
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlayQuickDel_OnKeyMode(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    //#NT#2009/08/04#Chris Chung -begin
    Ux_SendEvent(&UISystemObjCtrl,NVTEVT_FORCETO_LIVEVIEW_MODE,0);
    //#NT#2009/08/04#Chris Chung -end
    return NVTEVT_CONSUME;
}
//----------------------UIMenuWndPlayQuickDel_StatusCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndPlayQuickDel_Status)
EVENT_END

//---------------------UIMenuWndPlayQuickDel_PanelCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndPlayQuickDel_Panel)
CTRL_LIST_ITEM(UIMenuWndPlayQuickDel_Menu)
CTRL_LIST_END

//----------------------UIMenuWndPlayQuickDel_PanelCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndPlayQuickDel_Panel)
EVENT_END

//----------------------UIMenuWndPlayQuickDel_MenuCtrl Event---------------------------
INT32 UIMenuWndPlayQuickDel_Menu_OnKeyUp(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlayQuickDel_Menu_OnKeyDown(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlayQuickDel_Menu_OnKeyEnter(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlayQuickDel_Menu_OnKeyLeft(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPlayQuickDel_Menu_OnKeyMenu(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndPlayQuickDel_Menu)
EVENT_ITEM(NVTEVT_KEY_UP,UIMenuWndPlayQuickDel_Menu_OnKeyUp)
EVENT_ITEM(NVTEVT_KEY_DOWN,UIMenuWndPlayQuickDel_Menu_OnKeyDown)
EVENT_ITEM(NVTEVT_KEY_ENTER,UIMenuWndPlayQuickDel_Menu_OnKeyEnter)
EVENT_ITEM(NVTEVT_KEY_LEFT,UIMenuWndPlayQuickDel_Menu_OnKeyLeft)
EVENT_ITEM(NVTEVT_KEY_MENU,UIMenuWndPlayQuickDel_Menu_OnKeyMenu)
EVENT_END

INT32 UIMenuWndPlayQuickDel_Menu_OnKeyUp(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(pCtrl,NVTEVT_PREVIOUS_ITEM,0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlayQuickDel_Menu_OnKeyDown(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(pCtrl,NVTEVT_NEXT_ITEM,0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlayQuickDel_Menu_OnKeyEnter(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    //#NT#2009/06/04#Chris Chung -begin
    UINT32   curItem;

    curItem = UxMenu_GetData(pCtrl,MNU_CURITM);

    Ux_OpenWindow((VControl *)(&UIMenuWndPlayQuickConfirmDelCtrl), 1, curItem);
    //#NT#2009/06/04#Chris Chung -end
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlayQuickDel_Menu_OnKeyLeft(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    //#NT#2009/07/16#Chris Chung -begin
    Ux_CloseWindow((VControl *)(&UIMenuWndPlayQuickDelCtrl), 0);
    //#NT#2009/07/16#Chris Chung -end
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPlayQuickDel_Menu_OnKeyMenu(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    //#NT#2009/07/16#Chris Chung -begin
    Ux_CloseWindow((VControl *)(&UIMenuWndPlayQuickDelCtrl), 0);
    //#NT#2009/07/16#Chris Chung -end
    return NVTEVT_CONSUME;
}
