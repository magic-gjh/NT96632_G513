//This source code is generated by UI Designer Studio.

#ifndef UIMENUWNDSETUPDELAYPOWEROFFRES_H
#define UIMENUWNDSETUPDELAYPOWEROFFRES_H

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIDisplayUtil.h"
//------------------------------------------------------------

SHOW_MAP_BEGIN(Skin1)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin1,0,0,319,239)

SHOW_ITEM_RECT(CMD_Rectangle,Rect4,0,0,248,158,272,0,5,255,0,0,0)
SHOW_MAP_BEGIN(Skin2)
SHOW_MAP_BODY(Rect4)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin2,0,0,248,158)

SHOW_ITEM_RECT(CMD_Rectangle,Skin6Rect,0,0,215,37,0,0,255,255,0,0,0)
SHOW_MAP_BEGIN(Skin6)
SHOW_MAP_BODY(Skin6Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin6,0,0,215,37)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text8,0,0,215,37,STRID_NULL,0,0,0,0,2,1,1,256,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Normal5)
SHOW_MAP_BODY(Skin6)
SHOW_MAP_BODY(Text8)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal5,72,55,287,92)

SHOW_ITEM_IMAGE(CMD_Image,Sel_Bar_Begin11, 0, 0, 31,37, ICON_SEL_BAR_BEGIN,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_IMAGE(CMD_Image,Sel_Bar_Med12, 31, 0, 62,37, ICON_SEL_BAR_MED,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_IMAGE(CMD_Image,Sel_Bar_Med13, 63, 0, 94,37, ICON_SEL_BAR_MED,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_IMAGE(CMD_Image,Sel_Bar_Med14, 94, 0, 125,37, ICON_SEL_BAR_MED,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_IMAGE(CMD_Image,Sel_Bar_Med15, 126, 0, 157,37, ICON_SEL_BAR_MED,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_IMAGE(CMD_Image,Sel_Bar_Med16, 156, 0, 187,37, ICON_SEL_BAR_MED,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_IMAGE(CMD_Image,Sel_Bar_End17, 183, 0, 214,37, ICON_SEL_BAR_END,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin10Rect,0,0,215,37,0,0,255,255,0,0,0)
SHOW_MAP_BEGIN(Skin10)
SHOW_MAP_BODY(Skin10Rect)
SHOW_MAP_BODY(Sel_Bar_Begin11)
SHOW_MAP_BODY(Sel_Bar_Med12)
SHOW_MAP_BODY(Sel_Bar_Med13)
SHOW_MAP_BODY(Sel_Bar_Med14)
SHOW_MAP_BODY(Sel_Bar_Med15)
SHOW_MAP_BODY(Sel_Bar_Med16)
SHOW_MAP_BODY(Sel_Bar_End17)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin10,0,0,215,37)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text19,0,0,215,37,STRID_NULL,0,0,0,0,14,1,1,256,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Focused9)
SHOW_MAP_BODY(Skin10)
SHOW_MAP_BODY(Text19)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused9,72,55,287,92)

SHOW_ITEM_RECT(CMD_Rectangle,Skin21Rect,0,0,215,37,0,0,255,255,0,0,0)
SHOW_MAP_BEGIN(Skin21)
SHOW_MAP_BODY(Skin21Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin21,0,0,215,37)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text23,1,5,216,35,STRID_NULL,0,0,0,0,2,1,1,256,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Normal_Disable20)
SHOW_MAP_BODY(Skin21)
SHOW_MAP_BODY(Text23)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal_Disable20,72,55,287,92)

SHOW_ITEM_RECT(CMD_Rectangle,Skin25Rect,0,0,215,37,0,0,255,255,0,0,0)
SHOW_MAP_BEGIN(Skin25)
SHOW_MAP_BODY(Skin25Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin25,0,0,215,37)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text27,1,5,216,35,STRID_NULL,0,0,0,0,2,1,1,256,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Focused_Disable24)
SHOW_MAP_BODY(Skin25)
SHOW_MAP_BODY(Text27)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused_Disable24,72,55,287,92)

SHOW_ITEM_RECT(CMD_Rectangle,Skin29Rect,0,0,215,37,0,0,255,255,0,0,0)
SHOW_MAP_BEGIN(Skin29)
SHOW_MAP_BODY(Skin29Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin29,0,0,215,37)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text31,1,5,216,35,STRID_NULL,0,0,0,0,2,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Pressed28)
SHOW_MAP_BODY(Skin29)
SHOW_MAP_BODY(Text31)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Pressed28,72,55,287,92)

CREATE_LIST_ITEM_DATA(STRID_OFF32,STRID_OFF,ICONID_NULL,STATUS_ENABLE) 
CREATE_LIST_ITEM_DATA(STRID_15SEC33,STRID_15SEC,ICONID_NULL,STATUS_ENABLE) 
CREATE_LIST_ITEM_DATA(STRID_1MIN34,STRID_1MIN,ICONID_NULL,STATUS_ENABLE) 
CREATE_LIST_ITEM_DATA(STRID_5MIN35,STRID_5MIN,ICONID_NULL,STATUS_ENABLE) 
CREATE_LIST_ITEM_DATA(STRID_30MIN36,STRID_30MIN,ICONID_NULL,STATUS_ENABLE) 
CREATE_LIST_ITEM_DATA(STRID_60MIN37,STRID_60MIN,ICONID_NULL,STATUS_ENABLE) 
SHOW_MAP_BEGIN(UIMenuWndSetupDelayPowerOff_List_Text)
SHOW_MAP_BODY(Normal5)
SHOW_MAP_BODY(Focused9)
SHOW_MAP_BODY(Normal_Disable20)
SHOW_MAP_BODY(Focused_Disable24)
SHOW_MAP_BODY(Pressed28)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndSetupDelayPowerOff_List_Text)
LIST_LIST_BEGIN(UIMenuWndSetupDelayPowerOff_List_Text)
LIST_LIST_ITEM(STRID_OFF32)
LIST_LIST_ITEM(STRID_15SEC33)
LIST_LIST_ITEM(STRID_1MIN34)
LIST_LIST_ITEM(STRID_5MIN35)
LIST_LIST_ITEM(STRID_30MIN36)
LIST_LIST_ITEM(STRID_60MIN37)
LIST_LIST_END

CREATE_LIST_DATA(UIMenuWndSetupDelayPowerOff_List_Text,0,4,MENU_LAYOUT_VERTICAL|MENU_DISABLE_SHOW|MENU_SCROLL_CYCLE|MENU_SCROLL_NEXT_PAGE|MENU_DISABLE_NORMAL|LIST_DRAW_IMAGE,NVTEVT_NULL)

CREATE_LIST_CTRL(UIMenuWndSetupDelayPowerOff_List_Text,UIMenuWndSetupDelayPowerOff_List_Text,0,16,5,231,42)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(UIMenuWndSetupDelayPowerOff_Panel)
SHOW_MAP_BODY(Skin2)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndSetupDelayPowerOff_Panel)
DECLARE_CTRL_LIST(UIMenuWndSetupDelayPowerOff_Panel)
CREATE_CTRL(UIMenuWndSetupDelayPowerOff_Panel,UIMenuWndSetupDelayPowerOff_Panel,CTRL_WND,NULL,0 ,56,50,304,208)
SHOW_MAP_BEGIN(UIMenuWndSetupDelayPowerOff)
SHOW_MAP_BODY(Skin1)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndSetupDelayPowerOff)
DECLARE_CTRL_LIST(UIMenuWndSetupDelayPowerOff)
CREATE_CTRL(UIMenuWndSetupDelayPowerOff,UIMenuWndSetupDelayPowerOff,CTRL_WND,NULL,0 ,0,0,319,239)
#endif
