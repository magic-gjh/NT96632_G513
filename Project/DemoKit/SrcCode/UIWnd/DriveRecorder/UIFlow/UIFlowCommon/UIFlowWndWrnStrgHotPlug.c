//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIFlowWndWrnStrgHotPlugRes.c"
#include "UIFlowWndWrnStrgHotPlug.h"
#include "UISystemObj.h"
#include "KeyScanTsk.h"

//-----------------------------------------------------------------------------
// UIFlowWndWrnStrgHotPlug User Variable & Function Declarations
//-----------------------------------------------------------------------------
static BOOL g_bStrgHotPlugReady     = FALSE;
static UINT32 g_uiCheckTimerCnt     = 0;
static UINT32 g_uiCheckTimerID      = NULL_TIMER;

#define STRG_READY_CHK_PERIOD       500
#define USER_WAIT_MIN_TIME          2000
#define USER_WAIT_MIN_CNT           (USER_WAIT_MIN_TIME/STRG_READY_CHK_PERIOD)

//-----------------------------------------------------------------------------
// UIFlowWndWrnStrgHotPlug ToolGen
//-----------------------------------------------------------------------------
//---------------------UIFlowWndWrnStrgHotPlug Control List---------------------------
CTRL_LIST_BEGIN(UIFlowWndWrnStrgHotPlug)
CTRL_LIST_ITEM(UIFlowWndWrnStrgHotPlug_StatusTXT_Msg)
CTRL_LIST_END

//----------------------UIFlowWndWrnStrgHotPlug Event---------------------------
INT32 UIFlowWndWrnStrgHotPlug_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndWrnStrgHotPlug_OnClose(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndWrnStrgHotPlug_OnRedraw(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndWrnStrgHotPlug_OnStorageChange(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndWrnStrgHotPlug_OnTimer(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIFlowWndWrnStrgHotPlug)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIFlowWndWrnStrgHotPlug_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIFlowWndWrnStrgHotPlug_OnClose)
EVENT_ITEM(NVTEVT_REDRAW,UIFlowWndWrnStrgHotPlug_OnRedraw)
EVENT_ITEM(NVTEVT_STORAGE_CHANGE,UIFlowWndWrnStrgHotPlug_OnStorageChange)
EVENT_ITEM(NVTEVT_TIMER,UIFlowWndWrnStrgHotPlug_OnTimer)
EVENT_END

INT32 UIFlowWndWrnStrgHotPlug_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uiMsg = 0;
    debug_ind(("UIFlowWndWrnStrgHotPlug: OnOpen\r\n"));

    g_bStrgHotPlugReady = FALSE;
    g_uiCheckTimerCnt = 0;

    uiMsg = (GetCardStatus() == CARD_REMOVED)? UIFlowWndWrnStrgHotPlug_StatusTXT_Msg_STRID_TOINTERNAL : UIFlowWndWrnStrgHotPlug_StatusTXT_Msg_STRID_TOSD;
    UxState_SetData(&UIFlowWndWrnStrgHotPlug_StatusTXT_MsgCtrl,STATE_CURITEM,uiMsg);
    UxCtrl_SetShow(&UIFlowWndWrnStrgHotPlug_StatusTXT_MsgCtrl,TRUE);

    /* Start storage hot plug/unplug ready check timer */
    if(g_uiCheckTimerID == NULL_TIMER)
    {
        g_uiCheckTimerID = KeyScan_startTimer(STRG_READY_CHK_PERIOD, NVTEVT_STRG_CHK_TIMER, CONTINUE);
    }

    /* Set key press/release/continue mask */
    Ux_FlushEvent();
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_PRESS, FLGKEY_KEY_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_RELEASE, FLGKEY_KEY_REL_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_CONTINUE, FLGKEY_KEY_CONT_MASK_DEFAULT);

    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndWrnStrgHotPlug_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    debug_ind(("UIFlowWndWrnStrgHotPlug: OnClose\r\n"));

    /* Stop storage hot plug/unplug ready check timer if exists */
    if(g_uiCheckTimerID != NULL_TIMER)
    {
        KeyScan_stopTimer(&g_uiCheckTimerID);
    }

    /* Reset key press/release/continue mask to default */
    Ux_FlushEvent();
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_PRESS, FLGKEY_KEY_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_RELEASE, FLGKEY_KEY_REL_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_CONTINUE, FLGKEY_KEY_CONT_MASK_DEFAULT);

    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndWrnStrgHotPlug_OnRedraw(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    /* For handling redraw evt posted from other tasks */
    Ux_DefaultEvent(pCtrl,NVTEVT_REDRAW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndWrnStrgHotPlug_OnStorageChange(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    BOOL bCurrCardRemoved = (GetCardStatus() == CARD_REMOVED)? TRUE : FALSE;
    debug_err(("UIFlowWndWrnStrgHotPlug: OnStorageChange - %s\r\n", (bCurrCardRemoved)? "MEM" : "Card"));

    g_bStrgHotPlugReady = TRUE;

    return NVTEVT_CONSUME;
}
INT32 UIFlowWndWrnStrgHotPlug_OnTimer(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    NVTEVT event;

    event = paramArray[0];
    debug_ind(("UIFlowWndWrnStrgHotPlug OnTimer event = 0x%x\r\n", event));

    switch(event)
    {
        case NVTEVT_STRG_CHK_TIMER:
            g_uiCheckTimerCnt ++;
            debug_err(("UIFlowWndWrnStrgHotPlug g_uiCheckTimerCnt = %ld\r\n", g_uiCheckTimerCnt));

            if((g_bStrgHotPlugReady == TRUE) && (g_uiCheckTimerCnt >= USER_WAIT_MIN_CNT))
            {
                if(g_uiCheckTimerID != NULL_TIMER)
                {
                    KeyScan_stopTimer(&g_uiCheckTimerID);
                }

                /* Utilize mode change (to current mode) to re-init current mode and ui window */
                Ux_SendEvent(&UISystemObjCtrl,NVTEVT_CHANGE_DSCMODE,1,DSCMODE_CHGTO_CURR);
            }
            break;

        default:
            debug_err(("UIFlowWndWrnStrgHotPlug OnTimer: Unknown event 0x%x\r\n", event));
            break;
    }

    return NVTEVT_CONSUME;
}
//----------------------UIFlowWndWrnStrgHotPlug_StatusTXT_Msg Event---------------------------
EVENT_BEGIN(UIFlowWndWrnStrgHotPlug_StatusTXT_Msg)
EVENT_END

//-----------------------------------------------------------------------------
// UIFlowWndWrnStrgHotPlug User Functions
//-----------------------------------------------------------------------------

