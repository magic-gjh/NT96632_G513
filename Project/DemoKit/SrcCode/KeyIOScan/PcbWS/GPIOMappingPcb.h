/**
    Copyright   Novatek Microelectronics Corp. 2005.  All rights reserved.

    @file       GPIOMapphing.h
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

//--------------------------------------------------------------------
// AGPIO - Output
//--------------------------------------------------------------------
#define GPIO_LCD_SLEEP              (1 | GPIO_IS_DGPIO)

// LCD backlight
#define GPIO_PWM_BLG_PCTL           (5 | GPIO_IS_DGPIO)
#define PAD_PWM_BLG_PCTL            PAD_PIN_DGPIO5

// CCD power
#define GPIO_CCD_PCTL               (C_GPIO_53)
#define PAD_CCD_PCTL                PAD_PIN_MC53

// CCD RESET
#define GPIO_CCD_RESET              (3 | GPIO_IS_DGPIO)
#define PAD_CCD_RESET               PAD_PIN_DGPIO3

// LCD RESET
//#define GPIO_LCD_ROTATE             (1 | GPIO_IS_DGPIO)
//#define PAD_LCD_ROTATE              PAD_PIN_DGPIO1

// HDMI POWER
#define GPIO_HDMI_POWER             (2 | GPIO_IS_DGPIO)
#define PAD_HDMI_POWER              PAD_PIN_DGPIO2

// LED
#define GPIO_LED_R                  91   //No this LED
#define GPIO_LED_G                  53   //No this LED
#define GPIO_LED_FCS                (C_GPIO_48)

// LCD
#define GPIO_LCD_SIF_SEN            P_GPIO_7
#define GPIO_LCD_SIF_SCK            P_GPIO_8
#define GPIO_LCD_SIF_SDA            P_GPIO_9

// Macro
#define GPIO_MACRO_DETECT           (C_GPIO_36)
#define PAD_MACRO_DETECT            PAD_PIN_MC36

#define GPIO_USB_DETECT             (C_GPIO_32)
#define PAD_USB_DETECT              PAD_PIN_MC32

// Storage card detect
#define GPIO_CARD_DETECT            (6 | GPIO_IS_DGPIO)
#define PAD_CARD_DETECT             PAD_PIN_DGPIO6

// SD card write protect
#define GPIO_CARD_WP                (4 | GPIO_IS_DGPIO)
#define PAD_CARD_WP                 PAD_PIN_DGPIO4

// NAND write protect
#define GPIO_NAND_WP                (C_GPIO_17)
#define PAD_NAND_WP                 PAD_PIN_MC17

// Flash trigger
#define GPIO_FLASH_TRIGGER          (S_GPIO_8)
#define PAD_FLASH_TRIGGER           PAD_PIN_SN_FLCTR

// Flash ready
//#define GPIO_FLASH_READY          (8 | GPIO_IS_DGPIO)//for tdc8a2vm
//#define PAD_FLASH_READY           PAD_PIN_DGPIO8

// Mechanical shutter
#define GPIO_MSHUT_1                (S_GPIO_6)
#define GPIO_MSHUT_2                (S_GPIO_7)


//--------------------------------------------------------------------
// DGPIO
//--------------------------------------------------------------------

//#define GPIO_KEY_SHUTTER            (C_GPIO_33)
//#define PAD_KEY_SHUTTER             PAD_PIN_MC33
//#define GPIO_KEY_MODE               (C_GPIO_34)
//#define PAD_KEY_MODE                PAD_PIN_MC34


// Storage card power control pin
#define GPIO_CARD_POWER             (4 | GPIO_IS_DGPIO)

#define GPIO_TV_DETECT              (C_GPIO_56)
#define PAD_TV_DETECT               PAD_PIN_MC56

// Battery detection control enable pin
#define GPIO_BATT_DET_EN            (0 | GPIO_IS_DGPIO)

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
