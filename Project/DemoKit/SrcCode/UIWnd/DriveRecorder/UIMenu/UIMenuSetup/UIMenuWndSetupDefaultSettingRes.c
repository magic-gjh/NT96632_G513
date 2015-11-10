//This source code is generated by UI Designer Studio.

#ifndef UIMENUWNDSETUPDEFAULTSETTINGRES_H
#define UIMENUWNDSETUPDEFAULTSETTINGRES_H

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIDisplayUtil.h"
//------------------------------------------------------------

SHOW_MAP_BEGIN(Skin1)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin1,0,0,319,239)

SHOW_ITEM_RECT(CMD_Rectangle,Rect3,56,50,304,208,272,0,5,255,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin5Rect,0,0,215,37,0,0,255,255,0,0,0)
SHOW_MAP_BEGIN(Skin5)
SHOW_MAP_BODY(Skin5Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin5,0,0,215,37)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text7,1,5,216,35,STRID_NULL,0,0,0,0,2,1,1,256,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Normal4)
SHOW_MAP_BODY(Skin5)
SHOW_MAP_BODY(Text7)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal4,73,111,288,148)

SHOW_ITEM_IMAGE(CMD_Image,Sel_Bar_Begin10, 0, 0, 31,43, ICON_SEL_BAR_BEGIN,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_IMAGE(CMD_Image,Sel_Bar_Med11, 31, 0, 62,43, ICON_SEL_BAR_MED,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_IMAGE(CMD_Image,Sel_Bar_Med12, 63, 0, 94,43, ICON_SEL_BAR_MED,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_IMAGE(CMD_Image,Sel_Bar_Med13, 94, 0, 125,43, ICON_SEL_BAR_MED,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_IMAGE(CMD_Image,Sel_Bar_Med14, 126, 0, 157,43, ICON_SEL_BAR_MED,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_IMAGE(CMD_Image,Sel_Bar_Med15, 156, 0, 187,43, ICON_SEL_BAR_MED,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_IMAGE(CMD_Image,Sel_Bar_End16, 183, 0, 214,43, ICON_SEL_BAR_END,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin9Rect,0,0,215,37,0,0,255,255,0,0,0)
SHOW_MAP_BEGIN(Skin9)
SHOW_MAP_BODY(Skin9Rect)
SHOW_MAP_BODY(Sel_Bar_Begin10)
SHOW_MAP_BODY(Sel_Bar_Med11)
SHOW_MAP_BODY(Sel_Bar_Med12)
SHOW_MAP_BODY(Sel_Bar_Med13)
SHOW_MAP_BODY(Sel_Bar_Med14)
SHOW_MAP_BODY(Sel_Bar_Med15)
SHOW_MAP_BODY(Sel_Bar_End16)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin9,0,0,215,37)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text18,1,5,216,35,STRID_NULL,0,0,0,0,14,1,1,256,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Focused8)
SHOW_MAP_BODY(Skin9)
SHOW_MAP_BODY(Text18)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused8,73,111,288,148)

SHOW_ITEM_RECT(CMD_Rectangle,Skin20Rect,0,0,215,37,0,0,255,255,0,0,0)
SHOW_MAP_BEGIN(Skin20)
SHOW_MAP_BODY(Skin20Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin20,0,0,215,37)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text22,1,5,216,35,STRID_NULL,0,0,0,0,2,1,1,256,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Normal_Disable19)
SHOW_MAP_BODY(Skin20)
SHOW_MAP_BODY(Text22)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal_Disable19,73,111,288,148)

SHOW_ITEM_RECT(CMD_Rectangle,Skin24Rect,0,0,215,37,0,0,255,255,0,0,0)
SHOW_MAP_BEGIN(Skin24)
SHOW_MAP_BODY(Skin24Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin24,0,0,215,37)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text26,1,5,216,35,STRID_NULL,0,0,0,0,2,1,1,256,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Focused_Disable23)
SHOW_MAP_BODY(Skin24)
SHOW_MAP_BODY(Text26)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused_Disable23,73,111,288,148)

SHOW_ITEM_RECT(CMD_Rectangle,Skin28Rect,0,0,215,37,0,0,255,255,0,0,0)
SHOW_MAP_BEGIN(Skin28)
SHOW_MAP_BODY(Skin28Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin28,0,0,215,37)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text30,1,5,216,35,STRID_NULL,0,0,0,0,2,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Pressed27)
SHOW_MAP_BODY(Skin28)
SHOW_MAP_BODY(Text30)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Pressed27,73,111,288,148)

CREATE_LIST_ITEM_DATA(STRID_CANCEL31,STRID_CANCEL,ICONID_NULL,STATUS_ENABLE) 
CREATE_LIST_ITEM_DATA(STRID_OK32,STRID_OK,ICONID_NULL,STATUS_ENABLE) 
SHOW_MAP_BEGIN(UIMenuWndSetupDefaultSetting_List_Text)
SHOW_MAP_BODY(Normal4)
SHOW_MAP_BODY(Focused8)
SHOW_MAP_BODY(Normal_Disable19)
SHOW_MAP_BODY(Focused_Disable23)
SHOW_MAP_BODY(Pressed27)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndSetupDefaultSetting_List_Text)
LIST_LIST_BEGIN(UIMenuWndSetupDefaultSetting_List_Text)
LIST_LIST_ITEM(STRID_CANCEL31)
LIST_LIST_ITEM(STRID_OK32)
LIST_LIST_END

CREATE_LIST_DATA(UIMenuWndSetupDefaultSetting_List_Text,0,2,MENU_LAYOUT_VERTICAL|MENU_DISABLE_SHOW|MENU_SCROLL_STOP|MENU_SCROLL_NEXT_PAGE|MENU_DISABLE_SKIP|LIST_DRAW_IMAGE,NVTEVT_NULL)

CREATE_LIST_CTRL(UIMenuWndSetupDefaultSetting_List_Text,UIMenuWndSetupDefaultSetting_List_Text,0,73,111,288,148)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin34Rect,0,0,235,51,0,0,255,255,0,0,0)
SHOW_MAP_BEGIN(Skin34)
SHOW_MAP_BODY(Skin34Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin34,0,0,235,51)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text36,6,5,229,47,STRID_NULL,0,0,0,0,2,1,1,256,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Normal33)
SHOW_MAP_BODY(Skin34)
SHOW_MAP_BODY(Text36)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal33,63,58,298,109)

SHOW_MAP_BEGIN(UIMenuWndSetupDefaultSetting_Static_Text)
SHOW_MAP_BODY(Normal33)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndSetupDefaultSetting_Static_Text)
CREATE_STATIC_DATA(UIMenuWndSetupDefaultSetting_Static_Text,STRID_RESET_WARNING)
CREATE_STATIC_CTRL(UIMenuWndSetupDefaultSetting_Static_Text,0,63,58,298,109)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(UIMenuWndSetupDefaultSetting)
SHOW_MAP_BODY(Skin1)
SHOW_MAP_BODY(Rect3)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndSetupDefaultSetting)
DECLARE_CTRL_LIST(UIMenuWndSetupDefaultSetting)
CREATE_CTRL(UIMenuWndSetupDefaultSetting,UIMenuWndSetupDefaultSetting,CTRL_WND,NULL,0 ,0,0,319,239)
#endif
