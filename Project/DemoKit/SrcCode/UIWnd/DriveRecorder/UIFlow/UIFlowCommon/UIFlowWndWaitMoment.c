//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIFlowWndWaitMomentRes.c"
#include "UIFlowWndWaitMoment.h"
#include "KeyScanTsk.h"
#include "UIBackgroundObj.h"

//-----------------------------------------------------------------------------
// UIFlowWndWaitMoment User Variable & Function Declarations
//-----------------------------------------------------------------------------
static UINT32 g_uiWaitMomentMsg     = 0;
static UINT32 g_uiAniTimerID        = NULL_TIMER;

#define FUNNEL_TIME_PERIOD          500

//-----------------------------------------------------------------------------
// UIFlowWndWaitMoment ToolGen
//-----------------------------------------------------------------------------
//---------------------UIFlowWndWaitMoment Control List---------------------------
CTRL_LIST_BEGIN(UIFlowWndWaitMoment)
CTRL_LIST_ITEM(UIFlowWndWaitMoment_StatusTXT_Msg)
CTRL_LIST_END

//----------------------UIFlowWndWaitMoment Event---------------------------
INT32 UIFlowWndWaitMoment_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndWaitMoment_OnClose(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndWaitMoment_OnTimer(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndWaitMoment_OnBackgroundDone(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIFlowWndWaitMoment)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIFlowWndWaitMoment_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIFlowWndWaitMoment_OnClose)
EVENT_ITEM(NVTEVT_TIMER,UIFlowWndWaitMoment_OnTimer)
EVENT_ITEM(NVTEVT_BACKGROUND_DONE,UIFlowWndWaitMoment_OnBackgroundDone)
EVENT_END

INT32 UIFlowWndWaitMoment_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    debug_ind(("UIFlowWndWaitMoment: OnOpen\r\n"));

    if(paramNum > 0)
    {
        g_uiWaitMomentMsg = paramArray[0];
        debug_ind(("UIFlowWndWaitMoment: Msg = 0x%x\r\n", g_uiWaitMomentMsg));
    }
    UxState_SetData(&UIFlowWndWaitMoment_StatusTXT_MsgCtrl,STATE_CURITEM,g_uiWaitMomentMsg);
    UxCtrl_SetShow(&UIFlowWndWaitMoment_StatusTXT_MsgCtrl,TRUE);

    #if 0
    /* Start animation icon timer */
    if(g_uiAniTimerID == NULL_TIMER)
    {
        g_uiAniTimerID = KeyScan_startTimer(FUNNEL_TIME_PERIOD, NVTEVT_FUNNEL_TIMER, CONTINUE);
    }
    #endif

    /* Set key press/release/continue mask */
    Ux_FlushEvent();
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_PRESS, FLGKEY_KEY_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_RELEASE, FLGKEY_KEY_REL_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_CONTINUE, FLGKEY_KEY_CONT_MASK_DEFAULT);

    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndWaitMoment_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    debug_ind(("UIFlowWndWaitMoment: OnClose\r\n"));

    #if 0
    /* Stop animation icon timer if exists */
    if(g_uiAniTimerID != NULL_TIMER)
    {
        KeyScan_stopTimer(&g_uiAniTimerID);
    }
    #endif

    /* Reset key press/release/continue mask to default */
    Ux_FlushEvent();
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_PRESS, FLGKEY_KEY_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_RELEASE, FLGKEY_KEY_REL_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_CONTINUE, FLGKEY_KEY_CONT_MASK_DEFAULT);

    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndWaitMoment_OnTimer(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    NVTEVT event;

    event = paramArray[0];
    debug_ind(("UIFlowWndWaitMoment OnTimer event = 0x%x\r\n", event));
    //Rsvd
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndWaitMoment_OnBackgroundDone(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    NVTEVT event;
    UINT32 uiReturn;
    UIBKW_STATUS status;

    event = paramArray[ONDONE_PARAM_INDEX_CMD];
    status = paramArray[ONDONE_PARAM_INDEX_RET];
    debug_ind(("UIFlowWndWaitMoment OnBackgroundDone event = 0x%x, status=%d\r\n", event, status));

    switch(event)
    {
        case NVTEVT_BKW_COPY2CARD:
        {
            switch(status)
            {
            case UIBKW_STA_OK:
                uiReturn = NVTRET_COPY2CARD;
                break;
            case UIBKW_STA_CARDFULL:
                uiReturn = NVTRET_COPY2CARDFULL;
            }
            //Rsvd
            break;
        }

        case NVTEVT_BKW_DELALL:
        {
            uiReturn = NVTRET_DELETEALL;
            //Rsvd
            break;
        }

        case NVTEVT_BKW_DELONE:
        {
            uiReturn = NVTRET_DELETEONE;
            //Rsvd
            break;
        }

        case NVTEVT_BKW_FORMAT:
        case NVTEVT_BKW_FORMATCARD:
        case NVTEVT_BKW_FORMATNAND:
        {
            uiReturn = NVTRET_FORMAT;
            //Rsvd
            break;
        }

        case NVTEVT_BKW_PROTECTALL:
        case NVTEVT_BKW_UNPROTECTALL:
        {
            uiReturn = NVTRET_PROTECT;
            //Rsvd
            break;
        }

        default:
            uiReturn = NVTRET_ERROR;
            debug_err(("UIFlowWndWaitMoment OnBackgroundDone: Unknown event 0x%x\r\n", event));
            break;
    }

    /* Close waitmoment window */
    #if 0
    if(g_uiAniTimerID != NULL_TIMER)
    {
        KeyScan_stopTimer(&g_uiAniTimerID);
    }
    #endif
    Ux_CloseWindow(pCtrl, 2, NVTRET_WAITMOMENT, uiReturn);

    return NVTEVT_CONSUME;
}
//----------------------UIFlowWndWaitMoment_StatusTXT_Msg Event---------------------------
EVENT_BEGIN(UIFlowWndWaitMoment_StatusTXT_Msg)
EVENT_END

//-----------------------------------------------------------------------------
// UIFlowWndWaitMoment User Functions
//-----------------------------------------------------------------------------

