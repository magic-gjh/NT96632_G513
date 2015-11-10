//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIMenuWndPrint_PrintDPOFRes.c"
#include "UIMenuWndPrint_PrintDPOF.h"
//-------------------------------------------------------------------------------------------------
#include "UIPrintObj.h"
#include "UIMenuPrintSettings.h"
#include "UIFlowWndPrint.h"
#include "UIMenuWndPrint.h"
#include "UIMenuWndPrint_Confirm.h"
//-------------------------------------------------------------------------------------------------
void UIMenuWndPrint_PrintDPOF_Menu_Confirm(VControl *pCtrl)
{
    switch(UxMenu_GetData(pCtrl,MNU_CURITM))
    {
        case UIMenuWndPrint_PrintDPOF_Menu_Menu_STRID_DPOF:
        {
            Ux_OpenWindow(&UIMenuWndPrint_ConfirmCtrl, 1,UIMenuWndPrint_Confirm_STATE_CONFIRM_DPOF);
            break;
        }

        case UIMenuWndPrint_PrintDPOF_Menu_Menu_STRID_DPOF_RESTART:
        {
            Ux_OpenWindow(&UIMenuWndPrint_ConfirmCtrl, 1,UIMenuWndPrint_Confirm_STATE_CONFIRM_DPOF_CONTINUE);
            break;
        }

        case UIMenuWndPrint_PrintDPOF_Menu_Menu_STRID_RETURN:
        {
            Ux_CloseWindow(&UIMenuWndPrint_PrintDPOFCtrl, 0);
            break;
        }

        default:
        {
            break;
        }
    }

    Ux_Redraw();
}
//---------------------UIMenuWndPrint_PrintDPOFCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndPrint_PrintDPOF)
CTRL_LIST_ITEM(UIMenuWndPrint_PrintDPOF_Content_Panel)
CTRL_LIST_ITEM(UIMenuWndPrint_PrintDPOF_Title_Panel)
CTRL_LIST_ITEM(UIMenuWndPrint_PrintDPOF_End_Panel)
CTRL_LIST_ITEM(UIMenuWndPrint_PrintDPOF_Menu_Menu)
CTRL_LIST_END

//----------------------UIMenuWndPrint_PrintDPOFCtrl Event---------------------------
INT32 UIMenuWndPrint_PrintDPOF_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPrint_PrintDPOF_OnClose(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPrint_PrintDPOF_OnPrintDpsEvent(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPrint_PrintDPOF_OnKeyMenu(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndPrint_PrintDPOF)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIMenuWndPrint_PrintDPOF_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIMenuWndPrint_PrintDPOF_OnClose)
EVENT_ITEM(NVTEVT_CB_PRINT_DPS_EVENT,UIMenuWndPrint_PrintDPOF_OnPrintDpsEvent)
EVENT_ITEM(NVTEVT_KEY_MENU,UIMenuWndPrint_PrintDPOF_OnKeyMenu)
EVENT_END

INT32 UIMenuWndPrint_PrintDPOF_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    /* Set key press/release/continue mask */
    Ux_FlushEvent();
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_PRESS, FLGKEY_KEY_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_RELEASE, FLGKEY_KEY_REL_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_CONTINUE, FLGKEY_KEY_CONT_MASK_DEFAULT);
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);

    UxMenu_SetData(&UIMenuWndPrint_PrintDPOF_Menu_MenuCtrl, MNU_CURITM, 0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPrint_PrintDPOF_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    /* Set key press/release/continue mask */
    Ux_FlushEvent();
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_PRESS, FLGKEY_KEY_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_RELEASE, FLGKEY_KEY_REL_MASK_DEFAULT);
    KeyScan_SetKeyMask(KEYSCAN_KEYMODE_CONTINUE, FLGKEY_KEY_CONT_MASK_DEFAULT);
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPrint_PrintDPOF_OnPrintDpsEvent(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    if(paramNum > 0)
    {
        switch(paramArray[0])
        {
            case DPS_EVENT_CAPABILITY_CHANGED:
            {
                Ux_CloseWindow(&UIMenuWndPrintCtrl, 1, paramArray[0]);
                break;
            }

            default:
            {
                UIPrint_ShowNotification(
                    UIMenuWndPrint_Confirm_STATE_NON_PRINTING,
                    paramArray[0]);
                break;
            }
        }
    }
    Ux_Redraw();
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPrint_PrintDPOF_OnKeyMenu(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_CloseWindow(pCtrl, 0);
    return NVTEVT_CONSUME;
}
//---------------------UIMenuWndPrint_PrintDPOF_Content_PanelCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndPrint_PrintDPOF_Content_Panel)
CTRL_LIST_END

//----------------------UIMenuWndPrint_PrintDPOF_Content_PanelCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndPrint_PrintDPOF_Content_Panel)
EVENT_END

//---------------------UIMenuWndPrint_PrintDPOF_Title_PanelCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndPrint_PrintDPOF_Title_Panel)
CTRL_LIST_ITEM(UIMenuWndPrint_PrintDPOF_Title_Text_Status)
CTRL_LIST_ITEM(UIMenuWndPrint_PrintDPOF_Title_Icon_Status)
CTRL_LIST_END

//----------------------UIMenuWndPrint_PrintDPOF_Title_PanelCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndPrint_PrintDPOF_Title_Panel)
EVENT_END

//----------------------UIMenuWndPrint_PrintDPOF_Title_Text_StatusCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndPrint_PrintDPOF_Title_Text_Status)
EVENT_END

//----------------------UIMenuWndPrint_PrintDPOF_Title_Icon_StatusCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndPrint_PrintDPOF_Title_Icon_Status)
EVENT_END

//---------------------UIMenuWndPrint_PrintDPOF_End_PanelCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndPrint_PrintDPOF_End_Panel)
CTRL_LIST_ITEM(UIMenuWndPrint_PrintDPOF_End_Dir_Panel)
CTRL_LIST_END

//----------------------UIMenuWndPrint_PrintDPOF_End_PanelCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndPrint_PrintDPOF_End_Panel)
EVENT_END

//---------------------UIMenuWndPrint_PrintDPOF_End_Dir_PanelCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndPrint_PrintDPOF_End_Dir_Panel)
CTRL_LIST_END

//----------------------UIMenuWndPrint_PrintDPOF_End_Dir_PanelCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndPrint_PrintDPOF_End_Dir_Panel)
EVENT_END

//----------------------UIMenuWndPrint_PrintDPOF_Menu_MenuCtrl Event---------------------------
INT32 UIMenuWndPrint_PrintDPOF_Menu_Menu_OnKeyUp(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPrint_PrintDPOF_Menu_Menu_OnKeyDown(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPrint_PrintDPOF_Menu_Menu_OnKeyRight(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPrint_PrintDPOF_Menu_Menu_OnKeyEnter(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPrint_PrintDPOF_Menu_Menu_OnKeyZoomin(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPrint_PrintDPOF_Menu_Menu_OnKeyZoomout(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPrint_PrintDPOF_Menu_Menu_OnKeyShutter2(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndPrint_PrintDPOF_Menu_Menu)
EVENT_ITEM(NVTEVT_KEY_UP,UIMenuWndPrint_PrintDPOF_Menu_Menu_OnKeyUp)
EVENT_ITEM(NVTEVT_KEY_DOWN,UIMenuWndPrint_PrintDPOF_Menu_Menu_OnKeyDown)
EVENT_ITEM(NVTEVT_KEY_RIGHT,UIMenuWndPrint_PrintDPOF_Menu_Menu_OnKeyRight)
EVENT_ITEM(NVTEVT_KEY_ENTER,UIMenuWndPrint_PrintDPOF_Menu_Menu_OnKeyEnter)
EVENT_ITEM(NVTEVT_KEY_ZOOMIN,UIMenuWndPrint_PrintDPOF_Menu_Menu_OnKeyZoomin)
EVENT_ITEM(NVTEVT_KEY_ZOOMOUT,UIMenuWndPrint_PrintDPOF_Menu_Menu_OnKeyZoomout)
EVENT_ITEM(NVTEVT_KEY_SHUTTER2,UIMenuWndPrint_PrintDPOF_Menu_Menu_OnKeyShutter2)
EVENT_END

INT32 UIMenuWndPrint_PrintDPOF_Menu_Menu_OnKeyUp(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    if(paramNum >0)
    {
        switch(paramArray[0])
        {
            #if (UIPRINT_KEYACT_TYPE&UIPRINT_KEYACT_PRESS)
            case NVTEVT_KEY_PRESS:
            {
                break;
            }
            #endif

            #if (UIPRINT_KEYACT_TYPE&UIPRINT_KEYACT_RELEASE)
            case NVTEVT_KEY_RELEASE:
            {
                break;
            }
            #endif

            default:
            {
                return NVTEVT_CONSUME;
            }
        }
    }

    #if (UIPRINT_KEY_UP == UIPRINT_KEYMAP_UP)
    Ux_SendEvent(pCtrl,NVTEVT_PREVIOUS_ITEM,0);
    #endif
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPrint_PrintDPOF_Menu_Menu_OnKeyDown(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    if(paramNum >0)
    {
        switch(paramArray[0])
        {
            #if (UIPRINT_KEYACT_TYPE&UIPRINT_KEYACT_PRESS)
            case NVTEVT_KEY_PRESS:
            {
                break;
            }
            #endif

            #if (UIPRINT_KEYACT_TYPE&UIPRINT_KEYACT_RELEASE)
            case NVTEVT_KEY_RELEASE:
            {
                break;
            }
            #endif

            default:
            {
                return NVTEVT_CONSUME;
            }
        }
    }

    #if (UIPRINT_KEY_DOWN == UIPRINT_KEYMAP_DOWN)
    Ux_SendEvent(pCtrl,NVTEVT_NEXT_ITEM,0);
    #endif
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPrint_PrintDPOF_Menu_Menu_OnKeyRight(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    if(paramNum >0)
    {
        switch(paramArray[0])
        {
            #if (UIPRINT_KEYACT_TYPE&UIPRINT_KEYACT_PRESS)
            case NVTEVT_KEY_PRESS:
            {
                break;
            }
            #endif

            #if (UIPRINT_KEYACT_TYPE&UIPRINT_KEYACT_RELEASE)
            case NVTEVT_KEY_RELEASE:
            {
                break;
            }
            #endif

            default:
            {
                return NVTEVT_CONSUME;
            }
        }
    }

    #if (UIPRINT_KEY_RIGHT == UIPRINT_KEYMAP_RIGHT)
    UIMenuWndPrint_PrintDPOF_Menu_Confirm(pCtrl);
    #endif
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPrint_PrintDPOF_Menu_Menu_OnKeyEnter(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    if(paramNum >0)
    {
        switch(paramArray[0])
        {
            #if (UIPRINT_KEYACT_TYPE&UIPRINT_KEYACT_PRESS)
            case NVTEVT_KEY_PRESS:
            {
                break;
            }
            #endif

            #if (UIPRINT_KEYACT_TYPE&UIPRINT_KEYACT_RELEASE)
            case NVTEVT_KEY_RELEASE:
            {
                break;
            }
            #endif

            default:
            {
                return NVTEVT_CONSUME;
            }
        }
    }

    #if (UIPRINT_KEY_ENTER == UIPRINT_KEYMAP_ENTER)
    UIMenuWndPrint_PrintDPOF_Menu_Confirm(pCtrl);
    #endif
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPrint_PrintDPOF_Menu_Menu_OnKeyZoomin(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    if(paramNum >0)
    {
        switch(paramArray[0])
        {
            #if (UIPRINT_KEYACT_TYPE&UIPRINT_KEYACT_PRESS)
            case NVTEVT_KEY_PRESS:
            {
                break;
            }
            #endif

            #if (UIPRINT_KEYACT_TYPE&UIPRINT_KEYACT_RELEASE)
            case NVTEVT_KEY_RELEASE:
            {
                break;
            }
            #endif

            default:
            {
                return NVTEVT_CONSUME;
            }
        }
    }

    #if (UIPRINT_KEY_ZOOMIN == UIPRINT_KEYMAP_UP)
    Ux_SendEvent(pCtrl,NVTEVT_PREVIOUS_ITEM,0);
    #endif
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPrint_PrintDPOF_Menu_Menu_OnKeyZoomout(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    if(paramNum >0)
    {
        switch(paramArray[0])
        {
            #if (UIPRINT_KEYACT_TYPE&UIPRINT_KEYACT_PRESS)
            case NVTEVT_KEY_PRESS:
            {
                break;
            }
            #endif

            #if (UIPRINT_KEYACT_TYPE&UIPRINT_KEYACT_RELEASE)
            case NVTEVT_KEY_RELEASE:
            {
                break;
            }
            #endif

            default:
            {
                return NVTEVT_CONSUME;
            }
        }
    }

    #if (UIPRINT_KEY_ZOOMOUT == UIPRINT_KEYMAP_DOWN)
    Ux_SendEvent(pCtrl,NVTEVT_NEXT_ITEM,0);
    #endif
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPrint_PrintDPOF_Menu_Menu_OnKeyShutter2(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    if(paramNum >0)
    {
        switch(paramArray[0])
        {
            #if (UIPRINT_KEYACT_TYPE&UIPRINT_KEYACT_PRESS)
            case NVTEVT_KEY_PRESS:
            {
                break;
            }
            #endif

            #if (UIPRINT_KEYACT_TYPE&UIPRINT_KEYACT_RELEASE)
            case NVTEVT_KEY_RELEASE:
            {
                break;
            }
            #endif

            default:
            {
                return NVTEVT_CONSUME;
            }
        }
    }

    #if (UIPRINT_KEY_SHUTTER2 == UIPRINT_KEYMAP_ENTER)
    UIMenuWndPrint_PrintDPOF_Menu_Confirm(pCtrl);
    #endif
    return NVTEVT_CONSUME;
}