//This source code is generated by UI Designer Studio.

#ifndef UIMENUWNDPHOTOSTILLRES_H
#define UIMENUWNDPHOTOSTILLRES_H

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

SHOW_ITEM_RECT(CMD_Rectangle,Skin2Rect,0,0,295,170,0,0,255,255,0,0,0)
SHOW_MAP_BEGIN(Skin2)
SHOW_MAP_BODY(Skin2Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin2,0,0,295,170)

SHOW_MAP_BEGIN(PhotoMenuBackground)
SHOW_MAP_BODY(Skin2)
SHOW_MAP_END

DECLARE_EVENT(PhotoMenuBackground)
DECLARE_CTRL_LIST(PhotoMenuBackground)
CREATE_CTRL(PhotoMenuBackground,PhotoMenuBackground,CTRL_WND,NULL,0 ,12,44,307,214)
SHOW_ITEM_IMAGE(CMD_Image,Image4, 118, 0, 178,39, ICON_TITLE_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image5, 176, 0, 236,39, ICON_TITLE_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image6, 235, 0, 295,39, ICON_TITLE_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image7, 0, 0, 60,39, ICON_MENU_STILL_ON,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image8, 60, 0, 120,39, ICON_MENU_SETUP_OFF,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin3)
SHOW_MAP_BODY(Image4)
SHOW_MAP_BODY(Image5)
SHOW_MAP_BODY(Image6)
SHOW_MAP_BODY(Image7)
SHOW_MAP_BODY(Image8)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin3,0,0,295,39)

SHOW_ITEM_IMAGE(CMD_Image,Image11, 2, 0, 48,37, ICON_TITLE_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image12, 48, 0, 94,37, ICON_TITLE_BAR,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin10)
SHOW_MAP_BODY(Image11)
SHOW_MAP_BODY(Image12)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin10,0,0,108,39)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text14,6,6,99,30,STRID_NULL,0,0,0,0,2,1,1,0,0,18,0,0,0,0)
SHOW_MAP_BEGIN(Normal9)
SHOW_MAP_BODY(Skin10)
SHOW_MAP_BODY(Text14)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal9,197,5,305,44)

CREATE_STATE_ITEM_DATA(STRID_STILL15,STRID_STILL,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_CAP_MODE16,STRID_CAP_MODE,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_RESOLUTION17,STRID_RESOLUTION,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_QUALITY18,STRID_QUALITY,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_SHARPNESS19,STRID_SHARPNESS,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_WB20,STRID_WB,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_COLOR21,STRID_COLOR,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_ISO22,STRID_ISO,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_SCENESETTING23,STRID_SCENESETTING,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_FACE_DET24,STRID_FACE_DET,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_ANTI_SHAKING25,STRID_ANTI_SHAKING,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_QUICK_VIEW26,STRID_QUICK_VIEW,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_DATE_STAMP27,STRID_DATE_STAMP,ICONID_NULL,NULL) 
SHOW_MAP_BEGIN(UIMenuWndPhotoStill_TitleName)
SHOW_MAP_BODY(Normal9)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndPhotoStill_TitleName)
STATE_LIST_BEGIN(UIMenuWndPhotoStill_TitleName)
STATE_LIST_ITEM(STRID_STILL15)
STATE_LIST_ITEM(STRID_CAP_MODE16)
STATE_LIST_ITEM(STRID_RESOLUTION17)
STATE_LIST_ITEM(STRID_QUALITY18)
STATE_LIST_ITEM(STRID_SHARPNESS19)
STATE_LIST_ITEM(STRID_WB20)
STATE_LIST_ITEM(STRID_COLOR21)
STATE_LIST_ITEM(STRID_ISO22)
STATE_LIST_ITEM(STRID_SCENESETTING23)
STATE_LIST_ITEM(STRID_FACE_DET24)
STATE_LIST_ITEM(STRID_ANTI_SHAKING25)
STATE_LIST_ITEM(STRID_QUICK_VIEW26)
STATE_LIST_ITEM(STRID_DATE_STAMP27)
STATE_LIST_END

CREATE_STATE_DATA(UIMenuWndPhotoStill_TitleName,0)
CREATE_STATE_CTRL(UIMenuWndPhotoStill_TitleName,0,185,0,293,39)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(UIMenuWndPhotoStill_TitleBar)
SHOW_MAP_BODY(Skin3)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndPhotoStill_TitleBar)
DECLARE_CTRL_LIST(UIMenuWndPhotoStill_TitleBar)
CREATE_CTRL(UIMenuWndPhotoStill_TitleBar,UIMenuWndPhotoStill_TitleBar,CTRL_WND,NULL,0 ,12,5,307,44)
SHOW_ITEM_IMAGE(CMD_Image,Image29, 0, 0, 31,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image30, 31, 0, 62,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image31, 62, 0, 93,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image32, 93, 0, 124,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image33, 124, 0, 155,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image34, 155, 0, 186,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image35, 186, 0, 217,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image36, 217, 0, 248,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image37, 248, 0, 279,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image38, 264, 0, 295,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin28)
SHOW_MAP_BODY(Image29)
SHOW_MAP_BODY(Image30)
SHOW_MAP_BODY(Image31)
SHOW_MAP_BODY(Image32)
SHOW_MAP_BODY(Image33)
SHOW_MAP_BODY(Image34)
SHOW_MAP_BODY(Image35)
SHOW_MAP_BODY(Image36)
SHOW_MAP_BODY(Image37)
SHOW_MAP_BODY(Image38)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin28,0,0,295,22)

SHOW_MAP_BEGIN(Skin40)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin40,0,0,57,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon41, 0, 2, 54,24, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal39)
SHOW_MAP_BODY(Skin40)
SHOW_MAP_BODY(Icon41)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal39,24,212,81,239)

SHOW_MAP_BEGIN(UIMenuWndPhotoStill_ReturnTips)
SHOW_MAP_BODY(Normal39)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndPhotoStill_ReturnTips)
CREATE_STATIC_DATA(UIMenuWndPhotoStill_ReturnTips,ICON_MENU_RETURN)
CREATE_STATIC_CTRL(UIMenuWndPhotoStill_ReturnTips,0,12,-2,69,25)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_IMAGE(CMD_Image,Image44, 0, 2, 16,21, ICON_DIR_LEFT,83886080,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image45, 31, 6, 45,25, ICON_DIR_DOWN,83886080,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image46, 50, 2, 64,18, ICON_DIR_RIGHT,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin43)
SHOW_MAP_BODY(Image44)
SHOW_MAP_BODY(Image45)
SHOW_MAP_BODY(Image46)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin43,0,0,82,27)

SHOW_MAP_BEGIN(UIMenuWndPhotoStill_LDRTips)
SHOW_MAP_BODY(Skin43)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndPhotoStill_LDRTips)
DECLARE_CTRL_LIST(UIMenuWndPhotoStill_LDRTips)
CREATE_CTRL(UIMenuWndPhotoStill_LDRTips,UIMenuWndPhotoStill_LDRTips,CTRL_WND,NULL,0 ,148,0,230,27)
SHOW_ITEM_IMAGE(CMD_Image,Image48, 0, 2, 16,21, ICON_DIR_LEFT,83886080,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image49, 14, 5, 28,24, ICON_DIR_UP,83886080,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image50, 31, 6, 45,22, ICON_DIR_DOWN,83886080,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image51, 50, 2, 64,18, ICON_DIR_RIGHT,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin47)
SHOW_MAP_BODY(Image48)
SHOW_MAP_BODY(Image49)
SHOW_MAP_BODY(Image50)
SHOW_MAP_BODY(Image51)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin47,0,0,83,28)

SHOW_MAP_BEGIN(UIMenuWndPhotoStill_LUDRTips)
SHOW_MAP_BODY(Skin47)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndPhotoStill_LUDRTips)
DECLARE_CTRL_LIST(UIMenuWndPhotoStill_LUDRTips)
CREATE_CTRL(UIMenuWndPhotoStill_LUDRTips,UIMenuWndPhotoStill_LUDRTips,CTRL_WND,NULL,0 ,148,0,231,28)
SHOW_ITEM_IMAGE(CMD_Image,Image53, 0, 2, 16,21, ICON_DIR_LEFT,83886080,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image54, 14, 5, 28,24, ICON_DIR_UP,83886080,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image55, 31, 6, 45,22, ICON_DIR_DOWN,83886080,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image56, 68, 2, 82,18, ICON_OK,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin52)
SHOW_MAP_BODY(Image53)
SHOW_MAP_BODY(Image54)
SHOW_MAP_BODY(Image55)
SHOW_MAP_BODY(Image56)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin52,0,0,110,27)

SHOW_MAP_BEGIN(UIMenuWndPhotoStill_LUDOKTips)
SHOW_MAP_BODY(Skin52)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndPhotoStill_LUDOKTips)
DECLARE_CTRL_LIST(UIMenuWndPhotoStill_LUDOKTips)
CREATE_CTRL(UIMenuWndPhotoStill_LUDOKTips,UIMenuWndPhotoStill_LUDOKTips,CTRL_WND,NULL,0 ,148,0,258,27)
SHOW_MAP_BEGIN(UIMenuWndPhotoStill_TipsBar)
SHOW_MAP_BODY(Skin28)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndPhotoStill_TipsBar)
DECLARE_CTRL_LIST(UIMenuWndPhotoStill_TipsBar)
CREATE_CTRL(UIMenuWndPhotoStill_TipsBar,UIMenuWndPhotoStill_TipsBar,CTRL_WND,NULL,0 ,12,214,307,236)
SHOW_ITEM_RECT(CMD_Rectangle,Skin58Rect,0,0,284,40,0,0,255,255,0,0,0)
SHOW_MAP_BEGIN(Skin58)
SHOW_MAP_BODY(Skin58Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin58,0,0,284,40)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon59, 2, 7, 29,34, ICONID_NULL,83886080,0,0,3,0,0,0,0)
SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text61,40,7,284,31,STRID_NULL,0,0,0,0,2,1,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal57)
SHOW_MAP_BODY(Skin58)
SHOW_MAP_BODY(Icon59)
SHOW_MAP_BODY(Text61)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal57,18,49,302,89)

SHOW_ITEM_IMAGE(CMD_Image,Image64, 0, 5, 32,36, ICON_SEL_BAR_BEGIN,83886080,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image65, 32, 5, 64,36, ICON_SEL_BAR_MED,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image66, 64, 5, 96,36, ICON_SEL_BAR_MED,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image67, 96, 5, 128,36, ICON_SEL_BAR_MED,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image68, 126, 5, 158,36, ICON_SEL_BAR_MED,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image69, 157, 5, 189,36, ICON_SEL_BAR_MED,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image70, 189, 5, 221,36, ICON_SEL_BAR_MED,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image71, 220, 5, 252,36, ICON_SEL_BAR_MED,0,0,0,0,0,0,0,0)
SHOW_ITEM_IMAGE(CMD_Image,Image72, 252, 5, 284,36, ICON_SEL_BAR_END,83886080,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin63Rect,0,0,284,40,0,0,255,255,0,0,0)
SHOW_MAP_BEGIN(Skin63)
SHOW_MAP_BODY(Skin63Rect)
SHOW_MAP_BODY(Image64)
SHOW_MAP_BODY(Image65)
SHOW_MAP_BODY(Image66)
SHOW_MAP_BODY(Image67)
SHOW_MAP_BODY(Image68)
SHOW_MAP_BODY(Image69)
SHOW_MAP_BODY(Image70)
SHOW_MAP_BODY(Image71)
SHOW_MAP_BODY(Image72)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin63,0,0,284,40)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon73, 2, 7, 29,34, ICONID_NULL,83886080,0,0,1,0,0,0,0)
SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text75,40,7,284,31,STRID_NULL,0,0,0,0,14,5,0,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Focused62)
SHOW_MAP_BODY(Skin63)
SHOW_MAP_BODY(Icon73)
SHOW_MAP_BODY(Text75)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused62,18,49,302,89)

SHOW_ITEM_RECT(CMD_Rectangle,Skin77Rect,0,0,284,40,0,0,255,255,0,0,0)
SHOW_MAP_BEGIN(Skin77)
SHOW_MAP_BODY(Skin77Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin77,0,0,284,40)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon78, 2, 7, 29,34, ICONID_NULL,83886080,0,0,3,0,0,0,0)
SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text80,40,7,284,31,STRID_NULL,0,0,0,0,2,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal_Disable76)
SHOW_MAP_BODY(Skin77)
SHOW_MAP_BODY(Icon78)
SHOW_MAP_BODY(Text80)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal_Disable76,18,49,302,89)

SHOW_ITEM_RECT(CMD_Rectangle,Skin82Rect,0,0,284,40,0,0,255,255,0,0,0)
SHOW_MAP_BEGIN(Skin82)
SHOW_MAP_BODY(Skin82Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin82,0,0,284,40)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon83, 2, 7, 29,34, ICONID_NULL,83886080,0,0,3,0,0,0,0)
SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text85,40,7,284,31,STRID_NULL,0,0,0,0,2,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Focused_Disable81)
SHOW_MAP_BODY(Skin82)
SHOW_MAP_BODY(Icon83)
SHOW_MAP_BODY(Text85)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused_Disable81,18,49,302,89)

SHOW_MAP_BEGIN(Skin87)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin87,0,0,284,40)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon88, 6, 5, 34,32, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text90,40,7,284,31,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Pressed86)
SHOW_MAP_BODY(Skin87)
SHOW_MAP_BODY(Icon88)
SHOW_MAP_BODY(Text90)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Pressed86,18,49,302,89)

CREATE_MENU_ITEM_DATA(STRID_CAP_MODE91,STRID_CAP_MODE,ICON_MODE_CAPTURE,STATUS_ENABLE,NULL,NULL) 
CREATE_MENU_ITEM_DATA(STRID_RESOLUTION92,STRID_RESOLUTION,ICON_RESOLUTION,STATUS_ENABLE,NULL,NULL) 
CREATE_MENU_ITEM_DATA(STRID_QUALITY93,STRID_QUALITY,ICON_QUALITY,STATUS_ENABLE,NULL,NULL) 
CREATE_MENU_ITEM_DATA(STRID_SHARPNESS94,STRID_SHARPNESS,ICON_SHARPNESS,STATUS_ENABLE,NULL,NULL) 
CREATE_MENU_ITEM_DATA(STRID_WB95,STRID_WB,ICON_WB_AUTO,STATUS_ENABLE,NULL,NULL) 
CREATE_MENU_ITEM_DATA(STRID_COLOR96,STRID_COLOR,ICON_COLOR,STATUS_ENABLE,NULL,NULL) 
CREATE_MENU_ITEM_DATA(STRID_ISO97,STRID_ISO,ICON_ISO,STATUS_ENABLE,NULL,NULL) 
CREATE_MENU_ITEM_DATA(STRID_FACE_DET98,STRID_FACE_DET,ICON_FACE_ON,STATUS_ENABLE,NULL,NULL) 
CREATE_MENU_ITEM_DATA(STRID_ANTI_SHAKING99,STRID_ANTI_SHAKING,ICON_SHAKE_ON,STATUS_ENABLE,NULL,NULL) 
CREATE_MENU_ITEM_DATA(STRID_QUICK_VIEW100,STRID_QUICK_VIEW,ICON_QUICK_REVIEW,STATUS_ENABLE,NULL,NULL) 
CREATE_MENU_ITEM_DATA(STRID_DATE_STAMP101,STRID_DATE_STAMP,ICON_DATE_STAMPING,STATUS_ENABLE,NULL,NULL) 
SHOW_MAP_BEGIN(UIMenuWndPhotoStill_Item)
SHOW_MAP_BODY(Normal57)
SHOW_MAP_BODY(Focused62)
SHOW_MAP_BODY(Normal_Disable76)
SHOW_MAP_BODY(Focused_Disable81)
SHOW_MAP_BODY(Pressed86)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndPhotoStill_Item)
MENU_LIST_BEGIN(UIMenuWndPhotoStill_Item)
MENU_LIST_ITEM(STRID_CAP_MODE91)
MENU_LIST_ITEM(STRID_RESOLUTION92)
MENU_LIST_ITEM(STRID_QUALITY93)
MENU_LIST_ITEM(STRID_SHARPNESS94)
MENU_LIST_ITEM(STRID_WB95)
MENU_LIST_ITEM(STRID_COLOR96)
MENU_LIST_ITEM(STRID_ISO97)
MENU_LIST_ITEM(STRID_FACE_DET98)
MENU_LIST_ITEM(STRID_ANTI_SHAKING99)
MENU_LIST_ITEM(STRID_QUICK_VIEW100)
MENU_LIST_ITEM(STRID_DATE_STAMP101)
MENU_LIST_END

CREATE_MENU_DATA(UIMenuWndPhotoStill_Item,0,4,MENU_LAYOUT_VERTICAL|MENU_DISABLE_SHOW|MENU_SCROLL_CYCLE|MENU_SCROLL_NEXT_PAGE|MENU_DISABLE_NORMAL|MENU_DRAW_IMAGE)

CREATE_MENU_CTRL(UIMenuWndPhotoStill_Item,UIMenuWndPhotoStill_Item,0,18,49,302,89)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_IMAGE(CMD_Image,Image104, 0, 0, 37,22, ICON_HINT_BAR,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin103)
SHOW_MAP_BODY(Image104)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin103,0,0,44,22)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text106,0,0,43,22,STRID_NULL,0,0,0,0,2,1,1,0,0,18,0,0,0,0)
SHOW_MAP_BEGIN(Normal102)
SHOW_MAP_BODY(Skin103)
SHOW_MAP_BODY(Text106)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal102,263,214,307,236)

SHOW_MAP_BEGIN(UIMenuWndPhotoStill_PageNum_Static)
SHOW_MAP_BODY(Normal102)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndPhotoStill_PageNum_Static)
CREATE_STATIC_DATA(UIMenuWndPhotoStill_PageNum_Static,STRID_MODE)
CREATE_STATIC_CTRL(UIMenuWndPhotoStill_PageNum_Static,0,263,214,307,236)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(UIMenuWndPhotoStill)
SHOW_MAP_BODY(Skin1)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndPhotoStill)
DECLARE_CTRL_LIST(UIMenuWndPhotoStill)
CREATE_CTRL(UIMenuWndPhotoStill,UIMenuWndPhotoStill,CTRL_WND,NULL,0 ,0,0,319,239)
#endif
