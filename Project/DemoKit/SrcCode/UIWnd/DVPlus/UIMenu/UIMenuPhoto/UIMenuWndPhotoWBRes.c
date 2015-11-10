//This source code is generated by UI Designer Studio.

#ifndef UIMENUWNDPHOTOWBRES_H
#define UIMENUWNDPHOTOWBRES_H

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIDisplayUtil.h"
//------------------------------------------------------------

SHOW_MAP_BEGIN(Skin1)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin1,0,0,319,239)

SHOW_ITEM_RECT(CMD_Rectangle,Rect4,0,0,293,168,272,0,5,0,0,0,0)
SHOW_MAP_BEGIN(Skin2)
SHOW_MAP_BODY(Rect4)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin2,0,0,293,168)

SHOW_MAP_BEGIN(Skin6)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin6,0,0,203,38)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text8,0,0,203,31,STRID_NULL,0,0,0,0,2,1,1,0,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Normal5)
SHOW_MAP_BODY(Skin6)
SHOW_MAP_BODY(Text8)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal5,58,48,261,86)

SHOW_ITEM_IMAGE(CMD_Image,Image11, 0, 0, 43,31, ICON_SEL_BAR_BEGIN,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image12, 32, 0, 77,30, ICON_SEL_BAR_MED,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image13, 64, 0, 107,30, ICON_SEL_BAR_MED,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image14, 96, 0, 145,29, ICON_SEL_BAR_MED,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image15, 128, 0, 176,29, ICON_SEL_BAR_MED,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image16, 149, 0, 192,29, ICON_SEL_BAR_MED,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image17, 171, 0, 205,30, ICON_SEL_BAR_END,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin10)
SHOW_MAP_BODY(Image11)
SHOW_MAP_BODY(Image12)
SHOW_MAP_BODY(Image13)
SHOW_MAP_BODY(Image14)
SHOW_MAP_BODY(Image15)
SHOW_MAP_BODY(Image16)
SHOW_MAP_BODY(Image17)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin10,0,0,203,38)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text19,0,0,203,31,STRID_NULL,0,0,0,0,14,1,1,0,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Focused9)
SHOW_MAP_BODY(Skin10)
SHOW_MAP_BODY(Text19)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused9,58,48,261,86)

SHOW_ITEM_RECT(CMD_Rectangle,Skin21Rect,0,0,203,38,0,0,98,98,0,0,0)
SHOW_MAP_BEGIN(Skin21)
SHOW_MAP_BODY(Skin21Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin21,0,0,203,38)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text23,0,0,203,31,STRID_NULL,0,0,0,0,1,1,1,256,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Normal_Disable20)
SHOW_MAP_BODY(Skin21)
SHOW_MAP_BODY(Text23)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal_Disable20,58,48,261,86)

SHOW_ITEM_RECT(CMD_Rectangle,Skin25Rect,0,0,203,38,0,0,98,98,0,0,0)
SHOW_MAP_BEGIN(Skin25)
SHOW_MAP_BODY(Skin25Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin25,0,0,203,38)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text27,0,0,203,31,STRID_NULL,0,0,0,0,1,1,1,256,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Focused_Disable24)
SHOW_MAP_BODY(Skin25)
SHOW_MAP_BODY(Text27)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused_Disable24,58,48,261,86)

SHOW_ITEM_RECT(CMD_Rectangle,Skin29Rect,0,0,203,38,0,0,98,98,0,0,0)
SHOW_MAP_BEGIN(Skin29)
SHOW_MAP_BODY(Skin29Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin29,0,0,203,38)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text31,0,0,203,31,STRID_NULL,0,0,0,0,1,1,1,256,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Pressed28)
SHOW_MAP_BODY(Skin29)
SHOW_MAP_BODY(Text31)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Pressed28,58,48,261,86)

CREATE_MENU_ITEM_DATA(STRID_AUTO32,STRID_AUTO,ICONID_NULL,STATUS_ENABLE,NULL,NULL) 
CREATE_MENU_ITEM_DATA(STRID_WB_DAY33,STRID_WB_DAY,ICONID_NULL,STATUS_ENABLE,NULL,NULL) 
CREATE_MENU_ITEM_DATA(STRID_WB_CLOUDY34,STRID_WB_CLOUDY,ICONID_NULL,STATUS_ENABLE,NULL,NULL) 
CREATE_MENU_ITEM_DATA(STRID_WB_TUNGSTEN35,STRID_WB_TUNGSTEN,ICONID_NULL,STATUS_ENABLE,NULL,NULL) 
CREATE_MENU_ITEM_DATA(STRID_WB_FLUORESCENT36,STRID_WB_FLUORESCENT,ICONID_NULL,STATUS_ENABLE,NULL,NULL) 
SHOW_MAP_BEGIN(UIMenuWndPhotoWB_Menu)
SHOW_MAP_BODY(Normal5)
SHOW_MAP_BODY(Focused9)
SHOW_MAP_BODY(Normal_Disable20)
SHOW_MAP_BODY(Focused_Disable24)
SHOW_MAP_BODY(Pressed28)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndPhotoWB_Menu)
MENU_LIST_BEGIN(UIMenuWndPhotoWB_Menu)
MENU_LIST_ITEM(STRID_AUTO32)
MENU_LIST_ITEM(STRID_WB_DAY33)
MENU_LIST_ITEM(STRID_WB_CLOUDY34)
MENU_LIST_ITEM(STRID_WB_TUNGSTEN35)
MENU_LIST_ITEM(STRID_WB_FLUORESCENT36)
MENU_LIST_END

CREATE_MENU_DATA(UIMenuWndPhotoWB_Menu,0,4,MENU_LAYOUT_VERTICAL|MENU_DISABLE_SHOW|MENU_SCROLL_CYCLE|MENU_SCROLL_NEXT_PAGE|MENU_DISABLE_NORMAL|MENU_DRAW_IMAGE)

CREATE_MENU_CTRL(UIMenuWndPhotoWB_Menu,UIMenuWndPhotoWB_Menu,0,44,3,247,41)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(UIMenuWndPhotoWB_Panel)
SHOW_MAP_BODY(Skin2)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndPhotoWB_Panel)
DECLARE_CTRL_LIST(UIMenuWndPhotoWB_Panel)
CREATE_CTRL(UIMenuWndPhotoWB_Panel,UIMenuWndPhotoWB_Panel,CTRL_WND,NULL,0 ,14,45,307,213)
SHOW_MAP_BEGIN(UIMenuWndPhotoWB)
SHOW_MAP_BODY(Skin1)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndPhotoWB)
DECLARE_CTRL_LIST(UIMenuWndPhotoWB)
CREATE_CTRL(UIMenuWndPhotoWB,UIMenuWndPhotoWB,CTRL_WND,NULL,0 ,0,0,319,239)
#endif
