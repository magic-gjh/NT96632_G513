/**
    Type declaration

    Type declaration.

    @file       Type.h
    @ingroup
    @note       Nothing.

    Copyright   Novatek Microelectronics Corp. 2005.  All rights reserved.
*/

#ifndef _TYPE_H
#define _TYPE_H

#include "StdCMac.h"
#include "mIType.h"

/**
    @addtogroup
*/
//@{

typedef char                CHAR;       ///< Character type (8 bits)
typedef unsigned char       UCHAR;      ///< Unsigned character type (8 bits)
typedef short               SHORT;      ///< Short type (16 bits)
                                        ///< @note  Declare to INT16 instead of SHORT
typedef unsigned short      USHORT;     ///< Unsigned short type (16 bits)
                                        ///< @note  Declare to UINT16 instead of USHORT
typedef long                LONG;       ///< Long type (32 bits)
                                        ///< @note  Declare to INT32 instead of LONG
typedef unsigned long       ULONG;      ///< Unsigned long type (32 bits)
                                        ///< @note  Declare to UINT32 instead of ULONG

typedef unsigned long long  UINT64;     ///< Unsigned 64 bits data type
typedef long long           INT64;      ///< Signed 64 bits data type
typedef unsigned long       UINT32;     ///< Unsigned 32 bits data type
typedef long                INT32;      ///< Signed 32 bits data type
typedef unsigned short      UINT16;     ///< Unsigned 16 bits data type
typedef short               INT16;      ///< Signed 16 bits data type
typedef unsigned char       UINT8;      ///< Unsigned 8 bits data type
typedef char                INT8;       ///< Signed 8 bits data type
                                        ///< @note  Beware!!! INT8 (char type) is actually unsigned in ADS
typedef float               FLOAT;      ///< Floating point integer


#define NO_TASK_LOCKED      0           ///< The resource is not locked by any task
#define TASK_LOCKED         1           ///< The resource is locked by some task

#define DISABLE             0           ///< Feature is disabled
#define ENABLE              1           ///< Feature is enabled

#define OFF                 0           ///< Feature is OFF
#define ON                  1           ///< Feature is ON

// Macro to generate dummy element for enum type to expand enum size to word (4 bytes)
#define ENUM_DUMMY4WORD(name)           E_##name = 0x10000000

// Macro to align to 32 / 16 / 8 / 4 (Upper)
// Example: SIZE_ALIGN32_U(32) = 32, SIZE_ALIGN32_U(33) = 64, SIZE_ALIGN32_U(63) = 64
#define SIZE_ALIGN32_U(size)            (((size) + 0x1F) & ~0x1F)
#define SIZE_ALIGN16_U(size)            (((size) + 0x0F) & ~0x0F)
#define SIZE_ALIGN8_U(size)             (((size) + 0x07) & ~0x07)
#define SIZE_ALIGN4_U(size)             (((size) + 0x03) & ~0x03)

// Macro to align to 32 / 16 / 8 / 4 (Lower)
// Example: SIZE_ALIGN32_L(32) = 32, SIZE_ALIGN32_L(33) = 32, SIZE_ALIGN32_L(63) = 32
#define SIZE_ALIGN32_L(size)            ((size) & ~0x1F)
#define SIZE_ALIGN16_L(size)            ((size) & ~0x0F)
#define SIZE_ALIGN8_L(size)             ((size) & ~0x07)
#define SIZE_ALIGN4_L(size)             ((size) & ~0x03)

// For backward compatible, don't use any more
#define SIZE_ALIGN32                    SIZE_ALIGN32_U
#define SIZE_ALIGN16                    SIZE_ALIGN16_U
#define SIZE_ALIGN8                     SIZE_ALIGN8_U
#define SIZE_ALIGN4                     SIZE_ALIGN4_U

// General Macro
#define MAKE_WORD(l, h)                 ((UINT16)(((UINT8)(l)) | ((UINT16)((UINT8)(h))) << 8))
#define MAKE_LONG(l, h)                 ((UINT32)(((UINT16)(l)) | ((UINT32)((UINT16)(h))) << 16))
#define LO_LONG(x)                      ((UINT32)(x))
#define HI_LONG(x)                      ((UINT32)((x>>32) & ((1ULL<<32) - 1)))
#define LO_WORD(l)                      ((UINT16)(l))
#define HI_WORD(l)                      ((UINT16)(((UINT32)(l) >> 16) & 0xFFFF))
#define LO_BYTE(w)                      ((UINT8)(w))
#define HI_BYTE(w)                      ((UINT8)(((UINT16)(w) >> 8) & 0xFF))
#define BIT(b, x)                       ( ((1 << (b)) & (x)) >> (b) )
#define BITS(s, e, x)                   ( (((((1 << ((e)-(s) + 1)) - 1) << (s)) & (x)) >> (s)) )
#define MAKE_EVEN(x)                    ((x) & ~1)
#define MAKE_QUAD(x)                    ((x) & ~3)

#define LIMIT(var,min,max)              (var) = ((var) < (min)) ? (min) : \
                                                (((var) > (max)) ? (max) : (var))

#define LIMITR(var,min,max)             (var) = ((var) > (max)) ? (min) : \
                                                (((var) < (min)) ? (max) : (var))

// Macro to swap bytes
// Example: SWAP_BYTES(0x2211) = 0x1122
#define SWAP_BYTES(x)                   (MAKE_WORD( HI_BYTE(x), LO_BYTE(x)))

// Macro to swap words
// Example: SWAP_WORDS(0x33221100) = 0x00112233
#define SWAP_WORDS(x)                   (MAKE_LONG( MAKE_WORD( HI_BYTE(HI_WORD(x)),   \
                                                               LO_BYTE(HI_WORD(x))),  \
                                                    MAKE_WORD( HI_BYTE(LO_WORD(x)),   \
                                                               LO_BYTE(LO_WORD(x)))))

/**
    Enumeration for RGB color

    Enumeration for RGB color.
*/
typedef enum
{
    COLOR_B,                ///< B color
    COLOR_G,                ///< G color
    COLOR_R                 ///< R color
} COLOR;

/**
    Structure for point

    Structure for point.
*/
typedef struct
{
    UINT16  uiLeft;         ///< X coordinate of the point
    UINT16  uiTop;          ///< Y coordinate of the point
} POINT, *PPOINT;

/**
    Structure for rectangle size

    Structure for rectangle size.
*/
typedef struct
{
    UINT16  uiWidth;        ///< Rectangle width
    UINT16  uiHeight;       ///< Rectangle height
} SIZE, *PSIZE;

/**
    Structure for rectangle

    Structure for rectangle.
*/
typedef struct _RECT
{
    UINT16  uiLeft;         ///< X coordinate of the top-left point of the rectangle
    UINT16  uiTop;          ///< Y coordinate of the top-left point of the rectangle
    UINT16  uiWidth;        ///< Rectangle width
    UINT16  uiHeight;       ///< Rectangle height
} RECT, *PRECT;

//@}

#endif
