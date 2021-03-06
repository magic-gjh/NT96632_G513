#include <string.h>
#include "UIFramework.h"
#include "UIGraphics.h"
#include "Debug.h"
#include "FilesysTsk.h"
#include "ImageAlgInfor.h"
#include "UIFlowPhotoFuncs.h"
#include "UIMenuPhotoSettings.h"
#include "GxDCDraw.h"
#include "PlaybackTsk.h"
#include "SysCfg.h"
#include "GlobalVar.h"
#include "ime.h"
#include "ime_lib.h"
#include "ide.h"
#include "grph.h"
#include "pll.h"

#define DUMP_STAMP_RAW 0

#define PLAYSTAMP_STRING_LENGTH     128

static UINT32 g_pStringBuf, g_pTempBuf;

static void PlayStamp_SetMem(void)
{
    char *pBuf;

    get_blk((void*)&(pBuf), POOL_ID_SICD);
    rel_blk(POOL_ID_SICD, (VP)pBuf);

    g_pStringBuf = (UINT32)pBuf;
    g_pTempBuf   = (UINT32)(pBuf+PLAYSTAMP_STRING_LENGTH*2); // *2 means UINT16
}

static void PlayStamp_SetString(UINT32 strId)
{
    UINT16 *pStr, *pStr2;
    UINT32 i;

    pStr  = (UINT16 *)GxGfx_GetStringID(strId);
    pStr2 = (UINT16 *)g_pStringBuf;

    if(pStr[0] == 0xFEFF)
    {
        i = 0;
        while(pStr[i] != 0x0000)
        {
            pStr2[i] = pStr[i];
            i++;

            if(i == PLAYSTAMP_STRING_LENGTH-1)
            {
                debug_err(("%s: out of string length !!\r\n", __func__));
                break;
            }
        }

        pStr2[i] = 0x0000;
    }
}

//data would be prepared in PlayStamp_GenerateStringStamp ()
//PlayStamp_GenerateStringStamp would be calledn in the slice task,befoe stich stamp
static void PlayStamp_GenerateStringStamp(UINT32 *outAddr, UINT32 *outW, UINT32 *outH)
{
    //do step.1, step.2 and step.3

    DC _gStampDC;
    DC _gTempDC;
    DC _gTemp2DC;
    POINT_2D Pt;
    RECT_2D Rect,srcRect,destRect;
    SIZE_2D szStamp;
    UINT32 memszStampDC;
    UINT32 addrStamp;
    UINT32 memszTempDC;
    UINT32 addrTemp;
    UINT32 memszTemp2DC;
    UINT32 addrTemp2;
    int w,h;
    int tmpSize;
    UINT ui32CB_Addr2, ui32CR_Addr2;
    UINT i, j, k;

    //#NT#2007/08/30@Steven Wang begin
    //#Need initial local variable at beginning
    memset(&_gStampDC, 0x00, sizeof(DC));
    memset(&_gTempDC, 0x00, sizeof(DC));
    memset(&_gTemp2DC, 0x00, sizeof(DC));
    //#NT#2007/08/30@Steven Wang end

    GxGfx_SetTextStroke((const FONT* )&gDemoKit_Font, FONTSTYLE_NORMAL, SCALE_1X);
    GxGfx_SetTextColor(_OSD_INDEX_RED, _OSD_INDEX_TRANSPART, 0);

    // 1. get src text size by Text(index -> YUV422)
    GxGfx_Text(0, 0, 0, (const TCHAR*)g_pStringBuf); //not really draw
    szStamp = GxGfx_GetTextLastSize(); //just get text size
    w = szStamp.w;
    w = ((w+7)>>3)<<3; //make w to 8 byte alignment
    h = szStamp.h;
    h = ((h+1)>>1)<<1; //make h to 2 byte alignment

    POINT_Set(&Pt, 0, 0);
    RECT_Set(&Rect, 0, 0, w-1, h-1);

    //prepare stamp DC
    memszStampDC = GxGfx_CalcDCMemSize  (w, h, TYPE_BITMAP, PXLFMT_INDEX8);
    addrStamp = g_pTempBuf;
    GxGfx_AttachDC(&_gStampDC,
        TYPE_BITMAP, PXLFMT_INDEX8,
        w, h,
        0, //auto calculate pitch
        (UINT8*)addrStamp, 0, 0); //auto calulate buf1 and buf2
    //clear stamp DC
    //_GxGfx_FillRect(&_gStampDC, &Rect, 0);
    GxGfx_SetShapeColor(0, _OSD_INDEX_BLACK, 0);
    GxGfx_FillRect(&_gStampDC, 0, 0, w-1, h-1);

    // 2. draw text by Text(index -> YUV422)
    GxGfx_Text(&_gStampDC, 0, 0, (const TCHAR*)g_pStringBuf); //draw

    // 3. stretch blt (YUV422 -> YUV422)
    // (ignored)
    //prepare temp DC
    memszTempDC = GxGfx_CalcDCMemSize  (w, h, TYPE_BITMAP, PXLFMT_YUV444);
    addrTemp = memszTempDC + addrStamp;
    GxGfx_AttachDC(&_gTempDC,
        TYPE_BITMAP, PXLFMT_YUV444,
        w, h,
        0, //auto calculate pitch
        (UINT8*)addrTemp, 0, 0); //auto calulate buf1 and buf2

    //_GxGfx_BitBlt(&_gTempDC, 0, &_gStampDC, 0, ROP_COPY, 0, (const MAPPING_ITEM*)&gDemoKit_palette);   //convert INDEX8 to YUV422
    _GxGfx_SetClip(0);
    _GxGfx_SetImageROP(ROP_COPY, 0, (const MAPPING_ITEM*)&gDemoKit_Palette_Palette);
    _GxGfx_BitBlt(&_gTempDC, 0, &_gStampDC, 0);

#if DUMP_STAMP_RAW
    {
        UINT32 filesize;
        debug_err(("Dump raw data stamp Y addr write  %d %d\r\n ", w, h));
        filesize = w*h;
        FilesysWaitCmdFinish(FST_TIME_INFINITE);
        FilesysReadWriteByName2(FST_CMD_WRITE_BY_NAME,
                                "A:\\SAMY_1.Y",
                                (UB *)addrTemp,
                                (UW *)&filesize,
                                0,
                                FST_TIME_INFINITE);


        FilesysWaitCmdFinish(FST_TIME_INFINITE);
        FilesysReadWriteByName2(FST_CMD_WRITE_BY_NAME,
                                "A:\\SAMCB_1.RAW",
                                (UB *)addrTemp+filesize,
                                (UW *)&filesize,
                                0,
                                FST_TIME_INFINITE);

        FilesysWaitCmdFinish(FST_TIME_INFINITE);
        FilesysReadWriteByName2(FST_CMD_WRITE_BY_NAME,
                                "A:\\SAMCR_1.RAW",
                                (UB *)(addrTemp+(2*filesize)),
                                (UW *)&filesize,
                                0,
                                FST_TIME_INFINITE);
        debug_err(("write \r\n "));
    }
#endif

    memszTemp2DC = GxGfx_CalcDCMemSize  (w, h, TYPE_BITMAP, PXLFMT_YUV422);
    addrTemp2 = addrTemp + memszTempDC;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = w;
    srcRect.h = h;

    //444->422
    tmpSize = w*h;
    ui32CB_Addr2 = addrTemp + tmpSize;   //CB addr
    ui32CR_Addr2 = addrTemp + 2 * tmpSize;   //CR addr

    j = addrTemp2 + tmpSize;
    k = addrTemp2 + tmpSize + tmpSize/2;

    for (i = 0; i < tmpSize; i += 2)
    {
        memcpy((UINT8 *)j, (UINT8 *)ui32CB_Addr2, 1);
        memcpy((UINT8 *)k, (UINT8 *)ui32CR_Addr2, 1);
        j ++;
        k ++;
        ui32CB_Addr2 +=2;
        ui32CR_Addr2 +=2;
    }
    memcpy((UINT8 *)addrTemp2, (UINT8 *)addrTemp, tmpSize);

#if DUMP_STAMP_RAW
    {
        UINT32 filesize;
        debug_err(("Dump raw data stamp Y addr write  %d %d\r\n ", w, h));
        filesize = w*h;
        FilesysWaitCmdFinish(FST_TIME_INFINITE);
        FilesysReadWriteByName2(FST_CMD_WRITE_BY_NAME,
                                "A:\\STAMPY.Y",
                                (UB *)addrTemp2,
                                (UW *)&filesize,
                                0,
                                FST_TIME_INFINITE);
        filesize = filesize / 2;
        FilesysWaitCmdFinish(FST_TIME_INFINITE);
        FilesysReadWriteByName2(FST_CMD_WRITE_BY_NAME,
                                        "A:\\STAMPCB.RAW",
                                        (UB *)(addrTemp2+filesize+filesize),
                                        (UW *)&filesize,
                                        0,
                                        FST_TIME_INFINITE);

        FilesysWaitCmdFinish(FST_TIME_INFINITE);
        FilesysReadWriteByName2(FST_CMD_WRITE_BY_NAME,
                                "A:\\STAMPCR.RAW",
                                (UB *)(addrTemp2+filesize+filesize+filesize),
                                (UW *)&filesize,
                                0,
                                FST_TIME_INFINITE);

        filesize = w*h*2;
        FilesysWaitCmdFinish(FST_TIME_INFINITE);
        FilesysReadWriteByName2(FST_CMD_WRITE_BY_NAME,
                                "A:\\STAMP.YUV",
                                (UB *)(addrTemp2),
                                (UW *)&filesize,
                                0,
                                FST_TIME_INFINITE);


        debug_err(("write \r\n "));
    }
#endif

    *outAddr = addrTemp2;
    *outW = w;
    *outH = h;
}

static void PlayStamp_PasteStamp(UINT SrcAddr, UINT SrcLineOffset, UINT StampAddr, UINT StampLineOffset, UINT StampH, UINT StampV, UB ColorKey)
{
    grph_open();
    grph_enableDMA();

    grph_setImg1(SrcAddr,
                 SrcLineOffset,
                 StampV,
                 StampH);

    grph_setImg2(StampAddr,
                 StampLineOffset);

    grph_setAOP(0,          //BOOL b16BitPrc
                0,          //GRPH_DST_SEL dstSel
                0x03,       //GRPH_AOP_MODE aopMode
                ColorKey);  //UINT32 uiProperty == Color Key

    grph_disableDMA();//DMA seems to keep moving unless being disabled,
    grph_swReset();
    grph_close();//mark this line or the second picture will make the cam. abnormal
}

static void PlayStamp_DecodeErrorScaleUpFunc(void)
{
    UINT32 ui32InW  = OSD_W, ui32InH = OSD_H;
    UINT32 ui32OutW = g_LCDSize.uiWidth, ui32OutH = g_LCDSize.uiHeight;
    UINT32 ui32FBBuf_Y, ui32FBBuf_Cb, ui32FBBuf_Cr;
    UINT32 ui32TmpBuf_Y, ui32TmpBuf_Cb, ui32TmpBuf_Cr;
    IME_OPENOBJ IMEOpenObj;
    IME_MODE_PRAM OneIme;

    PB_GetCurr3FBAddr(&ui32FBBuf_Y, &ui32FBBuf_Cb, &ui32FBBuf_Cr);
    PB_GetCurr3TempFBAddr(&ui32TmpBuf_Y, &ui32TmpBuf_Cb, &ui32TmpBuf_Cr);

    OneIme.op_mode = _D2D;
    OneIme.in_src = IMEALG_DMA2IME;

    OneIme.format.in_format      = IME_IN_FMT_422;
    OneIme.in_size.h_size        = ui32InW;
    OneIme.in_size.v_size        = ui32InH;
    OneIme.line_ofs.in_lineofs   = ui32InW;
    OneIme.in_addr.y_addr        = ui32TmpBuf_Y;
    OneIme.in_addr.cb_addr       = (OneIme.in_addr.y_addr + ui32InW * ui32InH);
    OneIme.in_addr.cr_addr       = (OneIme.in_addr.cb_addr + ((ui32InW * ui32InH) >> 1));

    OneIme.ycc_format.in_format  = 0;//pScale->in_pack;

    OneIme.path_num = IMEALG_1PATH;

    OneIme.format.out1_format    = IME_OUT_FMT_422_COSITED;
    OneIme.p1_out_size.h_size    = ui32OutW;
    OneIme.p1_out_size.v_size    = ui32OutH;

    OneIme.line_ofs.out1_lineofs = ui32OutW;
    OneIme.p1_out0_addr.y_addr   = ui32FBBuf_Y;
    OneIme.p1_out0_addr.cb_addr  = ui32FBBuf_Cb;
    OneIme.p1_out0_addr.cr_addr  = ui32FBBuf_Cr;

    OneIme.ycc_format.out1_format= IMEALG_YCBCR_PLANAR;
    OneIme.ycc_format.out2_format= IMEALG_YCBCR_PLANAR;

    IMEOpenObj.IME_CLOCKSEL = PLL_CLKSEL_IME_120;
    IMEOpenObj.FP_IMEISR_CB = NULL;
    ime_open(&IMEOpenObj);
    ime_setMode(&OneIme);
    ime_clrIntFlag();
    ime_setStart();
    ime_waitFlagFrameEnd();
    ime_setStop();
    ime_close();
}

void PlayStamp_DecodeErrorMsg(void)
{
    UINT32 ui32TmpBuf_Y, ui32TmpBuf_Cb, ui32TmpBuf_Cr;
    UINT32 strAddr, strW, strH, startX, startY;

    //Step1. Prepare stamp data
    PlayStamp_SetMem();
    PlayStamp_SetString(STRID_PICTUREERROR);
    PlayStamp_GenerateStringStamp(&strAddr, &strW, &strH);
    startY = OSD_H/2 - strH/2;
    startX = OSD_W/2 - strW/2;

    PB_GetCurr3TempFBAddr(&ui32TmpBuf_Y, &ui32TmpBuf_Cb, &ui32TmpBuf_Cr);

    //Step2. Clear temp buffer
    memset((void *)ui32TmpBuf_Y,  0x00, OSD_W*OSD_H);
    memset((void *)ui32TmpBuf_Cb, 0x80, OSD_W*OSD_H/2);
    memset((void *)ui32TmpBuf_Cr, 0x80, OSD_W*OSD_H/2);

    //Step3. Paste stamp data to temp buffer
    PlayStamp_PasteStamp((UINT)(ui32TmpBuf_Y+startX+startY*OSD_W), OSD_W, strAddr, strW, strW, strH, 0);
    PlayStamp_PasteStamp((UINT)(ui32TmpBuf_Cb+(startX+startY*OSD_W)/2), OSD_W/2, strAddr+strW*strH, strW/2, strW/2, strH, 0);
    PlayStamp_PasteStamp((UINT)(ui32TmpBuf_Cr+(startX+startY*OSD_W)/2), OSD_W/2, strAddr+strW*strH*3/2, strW/2, strW/2, strH, 0);

    PlayStamp_DecodeErrorScaleUpFunc();
}

