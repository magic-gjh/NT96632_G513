//This source code is generated by UI Designer Studio.

#ifndef UIMENUWNDPRINT_SELECTIMAGESRES_H
#define UIMENUWNDPRINT_SELECTIMAGESRES_H

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIDisplayUtil.h"
//------------------------------------------------------------

SHOW_ITEM_RECT(CMD_Rectangle,Skin1Rect,0,0,319,239,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin1)
SHOW_MAP_BODY(Skin1Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin1,0,0,319,239)

SHOW_ITEM_RECT(CMD_Rectangle,Skin2Rect,0,0,296,170,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin2)
SHOW_MAP_BODY(Skin2Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin2,0,0,296,170)

SHOW_MAP_BEGIN(UIMenuWndPrint_SelectImages_Content_Panel)
SHOW_MAP_BODY(Skin2)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndPrint_SelectImages_Content_Panel)
DECLARE_CTRL_LIST(UIMenuWndPrint_SelectImages_Content_Panel)
CREATE_CTRL(UIMenuWndPrint_SelectImages_Content_Panel,UIMenuWndPrint_SelectImages_Content_Panel,CTRL_WND,NULL,0 ,12,44,308,214)
SHOW_ITEM_IMAGE(CMD_Image,Image4, 115, 0, 175,39, ICON_TITLE_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image5, 175, 0, 235,39, ICON_TITLE_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image6, 235, 0, 295,39, ICON_TITLE_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image7, 58, 0, 118,39, ICON_TITLE_BAR,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin3)
SHOW_MAP_BODY(Image4)
SHOW_MAP_BODY(Image5)
SHOW_MAP_BODY(Image6)
SHOW_MAP_BODY(Image7)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin3,0,0,295,39)

SHOW_ITEM_IMAGE(CMD_Image,Image10, 2, 0, 48,37, ICON_TITLE_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image11, 48, 0, 94,37, ICON_TITLE_BAR,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin9)
SHOW_MAP_BODY(Image10)
SHOW_MAP_BODY(Image11)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin9,0,0,129,39)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text13,1,0,130,39,STRID_NULL,0,0,0,0,2,1,1,0,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Normal8)
SHOW_MAP_BODY(Skin9)
SHOW_MAP_BODY(Text13)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal8,179,5,308,44)

CREATE_STATE_ITEM_DATA(STRID_SELECT_IMAGES14,STRID_SELECT_IMAGES,ICONID_NULL,NULL) 
SHOW_MAP_BEGIN(UIMenuWndPrint_SelectImages_Title_Text_Status)
SHOW_MAP_BODY(Normal8)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndPrint_SelectImages_Title_Text_Status)
STATE_LIST_BEGIN(UIMenuWndPrint_SelectImages_Title_Text_Status)
STATE_LIST_ITEM(STRID_SELECT_IMAGES14)
STATE_LIST_END

CREATE_STATE_DATA(UIMenuWndPrint_SelectImages_Title_Text_Status,0)
CREATE_STATE_CTRL(UIMenuWndPrint_SelectImages_Title_Text_Status,0,166,0,295,39)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin16)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin16,0,0,61,38)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon17, 0, 0, 15,15, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal15)
SHOW_MAP_BODY(Skin16)
SHOW_MAP_BODY(Icon17)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal15,13,5,74,43)

CREATE_STATE_ITEM_DATA(ICON_MENU_PRINT_OFF18,STRID_NULL,ICON_MENU_PRINT_OFF,NULL) 
SHOW_MAP_BEGIN(UIMenuWndPrint_SelectImages_Title_Icon_Status)
SHOW_MAP_BODY(Normal15)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndPrint_SelectImages_Title_Icon_Status)
STATE_LIST_BEGIN(UIMenuWndPrint_SelectImages_Title_Icon_Status)
STATE_LIST_ITEM(ICON_MENU_PRINT_OFF18)
STATE_LIST_END

CREATE_STATE_DATA(UIMenuWndPrint_SelectImages_Title_Icon_Status,0)
CREATE_STATE_CTRL(UIMenuWndPrint_SelectImages_Title_Icon_Status,0,0,0,61,38)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(UIMenuWndPrint_SelectImages_Title_Panel)
SHOW_MAP_BODY(Skin3)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndPrint_SelectImages_Title_Panel)
DECLARE_CTRL_LIST(UIMenuWndPrint_SelectImages_Title_Panel)
CREATE_CTRL(UIMenuWndPrint_SelectImages_Title_Panel,UIMenuWndPrint_SelectImages_Title_Panel,CTRL_WND,NULL,0 ,13,5,308,44)
SHOW_ITEM_IMAGE(CMD_Image,Image20, 0, 0, 30,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image21, 30, 0, 60,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image22, 60, 0, 90,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image23, 89, 0, 119,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image24, 119, 0, 149,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image25, 149, 0, 179,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image26, 178, 0, 208,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image27, 207, 0, 237,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image28, 236, 0, 266,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image29, 265, 0, 295,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin19)
SHOW_MAP_BODY(Image20)
SHOW_MAP_BODY(Image21)
SHOW_MAP_BODY(Image22)
SHOW_MAP_BODY(Image23)
SHOW_MAP_BODY(Image24)
SHOW_MAP_BODY(Image25)
SHOW_MAP_BODY(Image26)
SHOW_MAP_BODY(Image27)
SHOW_MAP_BODY(Image28)
SHOW_MAP_BODY(Image29)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin19,0,0,296,22)

SHOW_ITEM_IMAGE(CMD_Image,Image31, 0, 0, 59,23, ICON_MENU_RETURN,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_IMAGE(CMD_Image,Image32, 177, 0, 196,23, ICON_DIR_LEFT,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_IMAGE(CMD_Image,Image33, 197, 0, 216,23, ICON_DIR_UP,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_IMAGE(CMD_Image,Image34, 217, 0, 236,23, ICON_DIR_DOWN,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_IMAGE(CMD_Image,Image35, 237, 0, 256,23, ICON_DIR_RIGHT,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_IMAGE(CMD_Image,Image36, 257, 0, 296,23, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Skin30)
SHOW_MAP_BODY(Image31)
SHOW_MAP_BODY(Image32)
SHOW_MAP_BODY(Image33)
SHOW_MAP_BODY(Image34)
SHOW_MAP_BODY(Image35)
SHOW_MAP_BODY(Image36)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin30,0,0,296,23)

SHOW_MAP_BEGIN(UIMenuWndPrint_SelectImages_End_Dir_Menu_Panel)
SHOW_MAP_BODY(Skin30)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndPrint_SelectImages_End_Dir_Menu_Panel)
DECLARE_CTRL_LIST(UIMenuWndPrint_SelectImages_End_Dir_Menu_Panel)
CREATE_CTRL(UIMenuWndPrint_SelectImages_End_Dir_Menu_Panel,UIMenuWndPrint_SelectImages_End_Dir_Menu_Panel,CTRL_WND,NULL,0 ,0,-1,296,22)
SHOW_ITEM_IMAGE(CMD_Image,Image38, 0, 0, 59,23, ICON_MENU_RETURN,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_IMAGE(CMD_Image,Image39, 177, 0, 196,23, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_IMAGE(CMD_Image,Image40, 197, 0, 216,23, ICON_DIR_UP,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_IMAGE(CMD_Image,Image41, 217, 0, 236,23, ICON_DIR_DOWN,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_IMAGE(CMD_Image,Image42, 237, 0, 256,23, ICON_DIR_RIGHT,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_IMAGE(CMD_Image,Image43, 257, 0, 296,23, ICON_OK,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Skin37)
SHOW_MAP_BODY(Image38)
SHOW_MAP_BODY(Image39)
SHOW_MAP_BODY(Image40)
SHOW_MAP_BODY(Image41)
SHOW_MAP_BODY(Image42)
SHOW_MAP_BODY(Image43)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin37,0,0,296,23)

SHOW_MAP_BEGIN(UIMenuWndPrint_SelectImages_End_Dir2_Menu_Panel)
SHOW_MAP_BODY(Skin37)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndPrint_SelectImages_End_Dir2_Menu_Panel)
DECLARE_CTRL_LIST(UIMenuWndPrint_SelectImages_End_Dir2_Menu_Panel)
CREATE_CTRL(UIMenuWndPrint_SelectImages_End_Dir2_Menu_Panel,UIMenuWndPrint_SelectImages_End_Dir2_Menu_Panel,CTRL_WND,NULL,0 ,0,-1,296,22)
SHOW_MAP_BEGIN(UIMenuWndPrint_SelectImages_End_Panel)
SHOW_MAP_BODY(Skin19)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndPrint_SelectImages_End_Panel)
DECLARE_CTRL_LIST(UIMenuWndPrint_SelectImages_End_Panel)
CREATE_CTRL(UIMenuWndPrint_SelectImages_End_Panel,UIMenuWndPrint_SelectImages_End_Panel,CTRL_WND,NULL,0 ,12,214,308,236)
SHOW_ITEM_RECT(CMD_Rectangle,Skin45Rect,0,0,149,40,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin45)
SHOW_MAP_BODY(Skin45Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin45,0,0,149,40)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon46, 2, 7, 30,34, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text48,0,0,149,40,STRID_NULL,0,1280,0,0,2,1,1,0,0,16,0,0,0,0)
SHOW_MAP_BEGIN(Normal44)
SHOW_MAP_BODY(Skin45)
SHOW_MAP_BODY(Icon46)
SHOW_MAP_BODY(Text48)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal44,15,45,164,85)

SHOW_ITEM_IMAGE(CMD_Image,Image51, 0, 5, 32,36, ICON_SEL_BAR_BEGIN,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image52, 32, 5, 64,36, ICON_SEL_BAR_MED,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image53, 64, 5, 96,36, ICON_SEL_BAR_MED,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image54, 85, 5, 117,36, ICON_SEL_BAR_MED,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image55, 117, 5, 149,36, ICON_SEL_BAR_END,0,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin50Rect,0,0,149,40,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin50)
SHOW_MAP_BODY(Skin50Rect)
SHOW_MAP_BODY(Image51)
SHOW_MAP_BODY(Image52)
SHOW_MAP_BODY(Image53)
SHOW_MAP_BODY(Image54)
SHOW_MAP_BODY(Image55)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin50,0,0,149,40)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon56, 2, 7, 30,34, ICONID_NULL,83886080,0,0,1,0,0,0,0)
SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text58,0,0,149,40,STRID_NULL,0,0,0,0,14,5,0,0,0,16,0,0,0,0)
SHOW_MAP_BEGIN(Focused49)
SHOW_MAP_BODY(Skin50)
SHOW_MAP_BODY(Icon56)
SHOW_MAP_BODY(Text58)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused49,15,45,164,85)

SHOW_ITEM_RECT(CMD_Rectangle,Skin60Rect,0,0,149,40,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin60)
SHOW_MAP_BODY(Skin60Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin60,0,0,149,40)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon61, 2, 7, 30,34, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text63,0,0,149,40,STRID_NULL,0,1280,0,0,183,1,1,0,0,16,0,0,0,0)
SHOW_MAP_BEGIN(Normal_Disable59)
SHOW_MAP_BODY(Skin60)
SHOW_MAP_BODY(Icon61)
SHOW_MAP_BODY(Text63)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal_Disable59,15,45,164,85)

SHOW_ITEM_RECT(CMD_Rectangle,Skin65Rect,0,0,149,40,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin65)
SHOW_MAP_BODY(Skin65Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin65,0,0,149,40)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon66, 2, 7, 30,34, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text68,0,0,149,40,STRID_NULL,0,0,0,0,183,1,1,0,0,16,0,0,0,0)
SHOW_MAP_BEGIN(Focused_Disable64)
SHOW_MAP_BODY(Skin65)
SHOW_MAP_BODY(Icon66)
SHOW_MAP_BODY(Text68)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused_Disable64,15,45,164,85)

SHOW_MAP_BEGIN(Skin70)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin70,0,0,149,40)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon71, 2, 7, 30,34, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text73,0,0,149,40,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Pressed69)
SHOW_MAP_BODY(Skin70)
SHOW_MAP_BODY(Icon71)
SHOW_MAP_BODY(Text73)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Pressed69,15,45,164,85)

CREATE_MENU_ITEM_DATA(STRID_IMAGES74,STRID_IMAGES,ICONID_NULL,STATUS_ENABLE,NVTEVT_EXE_FORMAT,NULL) 
CREATE_MENU_ITEM_DATA(STRID_COPY75,STRID_COPY,ICONID_NULL,STATUS_ENABLE,NULL,NULL) 
CREATE_MENU_ITEM_DATA(STRID_CROP76,STRID_CROP,ICONID_NULL,STATUS_ENABLE,NULL,NULL) 
CREATE_MENU_ITEM_DATA(STRID_PRINT_SETTING77,STRID_PRINT_SETTING,ICONID_NULL,STATUS_ENABLE,NULL,NULL) 
CREATE_MENU_ITEM_DATA(STRID_RETURN78,STRID_RETURN,ICONID_NULL,STATUS_ENABLE,NULL,NULL) 
SHOW_MAP_BEGIN(UIMenuWndPrint_SelectImages_Menu_Menu)
SHOW_MAP_BODY(Normal44)
SHOW_MAP_BODY(Focused49)
SHOW_MAP_BODY(Normal_Disable59)
SHOW_MAP_BODY(Focused_Disable64)
SHOW_MAP_BODY(Pressed69)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndPrint_SelectImages_Menu_Menu)
MENU_LIST_BEGIN(UIMenuWndPrint_SelectImages_Menu_Menu)
MENU_LIST_ITEM(STRID_IMAGES74)
MENU_LIST_ITEM(STRID_COPY75)
MENU_LIST_ITEM(STRID_CROP76)
MENU_LIST_ITEM(STRID_PRINT_SETTING77)
MENU_LIST_ITEM(STRID_RETURN78)
MENU_LIST_END

CREATE_MENU_DATA(UIMenuWndPrint_SelectImages_Menu_Menu,0,4,MENU_LAYOUT_VERTICAL|MENU_DISABLE_SHOW|MENU_SCROLL_CYCLE|MENU_SCROLL_NEXT_PAGE|MENU_DISABLE_SKIP|MENU_DRAW_IMAGE)

CREATE_MENU_CTRL(UIMenuWndPrint_SelectImages_Menu_Menu,UIMenuWndPrint_SelectImages_Menu_Menu,0,15,45,164,85)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin80Rect,0,0,99,29,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin80)
SHOW_MAP_BODY(Skin80Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin80,0,0,99,29)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text82,0,0,99,29,STRID_NULL,0,1280,0,0,2,1,1,256,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Normal79)
SHOW_MAP_BODY(Skin80)
SHOW_MAP_BODY(Text82)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal79,185,53,284,82)

CREATE_STATE_ITEM_DATA(STRID_NULL83,STRID_NULL,ICONID_NULL,NULL) 
SHOW_MAP_BEGIN(UIMenuWndPrint_SelectImages_Images_Status)
SHOW_MAP_BODY(Normal79)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndPrint_SelectImages_Images_Status)
STATE_LIST_BEGIN(UIMenuWndPrint_SelectImages_Images_Status)
STATE_LIST_ITEM(STRID_NULL83)
STATE_LIST_END

CREATE_STATE_DATA(UIMenuWndPrint_SelectImages_Images_Status,0)
CREATE_STATE_CTRL(UIMenuWndPrint_SelectImages_Images_Status,0,185,53,284,82)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin85Rect,0,0,99,29,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin85)
SHOW_MAP_BODY(Skin85Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin85,0,0,99,29)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text87,0,0,99,29,STRID_NULL,0,1280,0,0,2,1,1,256,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Normal84)
SHOW_MAP_BODY(Skin85)
SHOW_MAP_BODY(Text87)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal84,185,96,284,125)

CREATE_STATE_ITEM_DATA(STRID_NULL88,STRID_NULL,ICONID_NULL,NULL) 
SHOW_MAP_BEGIN(UIMenuWndPrint_SelectImages_Copy_Status)
SHOW_MAP_BODY(Normal84)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndPrint_SelectImages_Copy_Status)
STATE_LIST_BEGIN(UIMenuWndPrint_SelectImages_Copy_Status)
STATE_LIST_ITEM(STRID_NULL88)
STATE_LIST_END

CREATE_STATE_DATA(UIMenuWndPrint_SelectImages_Copy_Status,0)
CREATE_STATE_CTRL(UIMenuWndPrint_SelectImages_Copy_Status,0,185,96,284,125)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_IMAGE(CMD_Image,Image90, 0, 0, 14,29, ICON_DIR_LEFT,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_IMAGE(CMD_Image,Image91, 0, 43, 14,72, ICON_DIR_LEFT,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Skin89)
SHOW_MAP_BODY(Image90)
SHOW_MAP_BODY(Image91)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin89,0,0,14,72)

SHOW_MAP_BEGIN(UIMenuWndPrint_SelectImages_Dir_Left_Panel)
SHOW_MAP_BODY(Skin89)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndPrint_SelectImages_Dir_Left_Panel)
DECLARE_CTRL_LIST(UIMenuWndPrint_SelectImages_Dir_Left_Panel)
CREATE_CTRL(UIMenuWndPrint_SelectImages_Dir_Left_Panel,UIMenuWndPrint_SelectImages_Dir_Left_Panel,CTRL_WND,NULL,0 ,167,52,181,124)
SHOW_ITEM_IMAGE(CMD_Image,Image93, 0, 0, 14,29, ICON_DIR_RIGHT,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_IMAGE(CMD_Image,Image94, 0, 42, 14,71, ICON_DIR_RIGHT,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Skin92)
SHOW_MAP_BODY(Image93)
SHOW_MAP_BODY(Image94)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin92,0,0,14,71)

SHOW_MAP_BEGIN(UIMenuWndPrint_SelectImages_Dir_Right_Panel)
SHOW_MAP_BODY(Skin92)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndPrint_SelectImages_Dir_Right_Panel)
DECLARE_CTRL_LIST(UIMenuWndPrint_SelectImages_Dir_Right_Panel)
CREATE_CTRL(UIMenuWndPrint_SelectImages_Dir_Right_Panel,UIMenuWndPrint_SelectImages_Dir_Right_Panel,CTRL_WND,NULL,0 ,289,53,303,124)
SHOW_MAP_BEGIN(UIMenuWndPrint_SelectImages)
SHOW_MAP_BODY(Skin1)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndPrint_SelectImages)
DECLARE_CTRL_LIST(UIMenuWndPrint_SelectImages)
CREATE_CTRL(UIMenuWndPrint_SelectImages,UIMenuWndPrint_SelectImages,CTRL_WND,NULL,0 ,0,0,319,239)
#endif
