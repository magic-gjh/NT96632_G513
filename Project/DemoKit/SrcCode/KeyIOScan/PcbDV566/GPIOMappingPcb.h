/**
    Copyright   Novatek Microelectronics Corp. 2005.  All rights reserved.

    @file       GPIOMappingPcb.h
    @ingroup    mIPRJAPKeyIO

    @brief      Header file of GPIO mapping
                This file is the header file of GPIO mapping

    @note       Nothing.
    @date       2005/12/05
*/

/** \addtogroup mIPRJAPKeyIO */
//@{

#ifndef _GPIOMAPPINGPCB_H
#define _GPIOMAPPINGPCB_H

#include "pad.h"
#include "GPIO.h"
#include "SysCfg.h"


//LCD pwr ctrl
#define GPIO_LCD_PWR                D_GPIO_1//14//#Linfg@0915#for dv121na


#define GPIO_LCD_SLEEP              GPIO_LCD_PWR//28
//NT 20100210 Sun Chen add
#define GPIO_LCD_ROTATE             C_GPIO_39
#define PAD_LCD_ROTATE              PAD_PIN_MC39

#define GPIO_LIGHT_COMPENSATE       L_GPIO_11
#define PAD_LIGHT_COMPENSATE        PAD_PIN_LCD11
//Sun Chen end
//#define GPIO_LCD_RESET              (2| GPIO_IS_DGPIO)

// LCD backlight
//#NT#2010/01/27#Hideo Lin -begin
//#NT#The backlight control pin (DGPIO1) in DV569 real board seems different from the pin (DGPIO5) in HW circuit file
#define GPIO_PWM_BLG_PCTL           D_GPIO_1//D_GPIO_5
//#NT#2010/01/27#Hideo Lin -end

// CCD power
//#define GPIO_CCD_PCTL             62      // no use

// CCD reset
#define GPIO_CCD_RESET              (3 | GPIO_IS_DGPIO)//#Linfg@0915#for dv121na


#define GPIO_CCD_PCTL               (11 | GPIO_IS_DGPIO)
#define PAD_CCD_PCTL                PAD_PIN_DGPIO11

#define GPIO_SD_PCTL                D_GPIO_2//(14 | GPIO_IS_DGPIO)//#Linfg@0915#for dv121na
#define PAD_SD_PCTL                 PAD_PIN_DGPIO2//PAD_PIN_DGPIO14

// LED
#define GPIO_LED_R                  62//no use
#define GPIO_LED_G                  62//no use
#define GPIO_LED_FCS                (0 | GPIO_IS_DGPIO)//62//no use//#Linfg@0915#for dv121na

// LCD
#define GPIO_LCD_SIF_SEN            P_GPIO_7
#define GPIO_LCD_SIF_SCK            P_GPIO_8
#define GPIO_LCD_SIF_SDA            P_GPIO_9

#define GPIO_MACRO_DETECT           47

// TV
#define GPIO_TV_DETECT              C_GPIO_51
#define PAD_TV_DETECT               PAD_PIN_MC51

// Storage card detect
#define GPIO_CARD_DETECT            D_GPIO_6//15//#Linfg@0915#for dv121na
#define PAD_CARD_DETECT             PAD_PIN_DGPIO6//PAD_PIN_MC15

//SD card pwr ctrl
//#define GPIO_CARD_PWR                D_GPIO_2//14//#Linfg@0915#for dv121na
//#define PAD_CARD_PWR                 PAD_PIN_DGPIO2//PAD_PIN_MC14

// SD card write protect
#define GPIO_CARD_WP                D_GPIO_4//14//#Linfg@0915#for dv121na
#define PAD_CARD_WP                 PAD_PIN_DGPIO4//PAD_PIN_MC14

// NAND write protect
#define GPIO_NAND_WP                15//30//#Linfg@0915#for dv121na
#define PAD_NAND_WP                 PAD_PIN_MC15//PAD_PIN_PWM1

// Flash charge
//#define GPIO_FLASH_CHARGE         30//for tdc8a2vm??

// Flash trigger
#define GPIO_FLASH_TRIGGER          22

// Flash ready
//#define GPIO_FLASH_READY          (8 | GPIO_IS_DGPIO)//for tdc8a2vm
//#define PAD_FLASH_READY           PAD_PIN_DGPIO8

// Mechanical shutter
#define GPIO_MSHUT_1                20
#define GPIO_MSHUT_2                21

#define GPIO_POWER_CTRL             (7 | GPIO_IS_DGPIO)
#define PAD_POWER_CTRL              PAD_PIN_DGPIO7

// KEYS
//#define GPIO_KEY_ZOOMIN           (11 | GPIO_IS_DGPIO)
//#define PAD_KEY_ZOOMIN            PAD_PIN_DGPIO11
//#define GPIO_KEY_ZOOMOUT          (10 | GPIO_IS_DGPIO)
//#define PAD_KEY_ZOOMOUT           PAD_PIN_DGPIO10
#define GPIO_KEY_SHUTTER            C_GPIO_35
#define PAD_KEY_SHUTTER             PAD_PIN_MC35
#define GPIO_KEY_REC                C_GPIO_32
#define PAD_KEY_REC                 PAD_PIN_MC32
#define GPIO_KEY_UP                 C_GPIO_53
#define PAD_KEY_UP                  PAD_PIN_MC53
#define GPIO_KEY_DOWN               C_GPIO_54
#define PAD_KEY_DOWN                PAD_PIN_MC54
#define GPIO_KEY_LEFT               C_GPIO_34
#define PAD_KEY_LEFT                PAD_PIN_MC34
#define GPIO_KEY_RIGHT              C_GPIO_33
#define PAD_KEY_RIGHT               PAD_PIN_MC33
#define GPIO_KEY_ENTER              C_GPIO_52
#define PAD_KEY_ENTER               PAD_PIN_MC52
#define GPIO_KEY_PLAYBACK           C_GPIO_55
#define PAD_KEY_PLAYBACK            PAD_PIN_MC55
//#define GPIO_KEY_DISPLAY          (19 | GPIO_IS_DGPIO)
//#define PAD_KEY_DISPLAY           PAD_PIN_DGPIO19
//#define GPIO_KEY_MENU             (18 | GPIO_IS_DGPIO)
//#define PAD_KEY_MENU              PAD_PIN_DGPIO18
//#define GPIO_KEY_MODE             (12 | GPIO_IS_DGPIO)
//#define PAD_KEY_MODE              PAD_PIN_DGPIO12
//#define GPIO_KEY_POWER            (7 | GPIO_IS_DGPIO)
//#define PAD_KEY_POWER             PAD_PIN_DGPIO7

// Mode dial
#define GPIO_MODE_1                 50
#define PAD_MODE_1                  PAD_PIN_PWM2
#define GPIO_MODE_2                 51
#define PAD_MODE_2                  PAD_PIN_PWM3
#define GPIO_MODE_3                 52
#define PAD_MODE_3                  PAD_PIN_PWM4
#define GPIO_MODE_4                 53
#define PAD_MODE_4                  PAD_PIN_PWM5

// Storage card power control pin
#define DGPIO_CARD_POWER            (9 | GPIO_IS_DGPIO)

// SYSRST
#define GPIO_SYSRST                 (19 | GPIO_IS_DGPIO)

// LENS_RST
#define GPIO_LENS_RST               (10 | GPIO_IS_DGPIO)

//--------------------------------------------------------------------
// Other x_GPIO
//--------------------------------------------------------------------
//HDMI detection
#define GPIO_HDMI_DETECT            G_GPIO_11
#define PAD_HDMI_DETECT             PAD_PIN_HOTPLUG


#endif

//@}
