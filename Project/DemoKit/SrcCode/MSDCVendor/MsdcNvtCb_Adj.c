#include "OSCommon.h"
#include "MsdcNvtCallback.h"
#include "MsdcNvtCb_Int.h"    
#include "MsdcNvtCb_Adj.h"
#include <string.h>
           
//MsdcNvtCb_Adj.c
typedef enum _VAR_TYPE{
    VAR_TYPE_BOOL,
    VAR_TYPE_UINT32,
    VAR_TYPE_INT32,
    VAR_TYPE_UINT16,
    VAR_TYPE_INT16,
    VAR_TYPE_UINT8,
    VAR_TYPE_INT8
}eVAR_TYPE;

typedef struct _ADJ_ITEM{
    void*       pVar;
    eVAR_TYPE   VarType;
    INT32       MaxValue;
    INT32       MinValue;
    CHAR        Tag[64];
}tADJ_ITEM;

#define ADJ_METHOD_SAMPLE           0
#define ADJ_METHOD_IDE_CMULTS       1

#define CFG_ADJ_METHOD              ADJ_METHOD_SAMPLE

#if (CFG_ADJ_METHOD==ADJ_METHOD_SAMPLE)
//Step 1: Includes
//Step 2: Variables Control
static UINT32 Param[6] = {0};
//Step 3: Setup Up Item
static tADJ_ITEM Items[] = {
    {&Param[0] ,VAR_TYPE_UINT32,255,0,"Param[0]"},
    {&Param[1] ,VAR_TYPE_UINT32,255,0,"Param[1]"},
    {&Param[2] ,VAR_TYPE_UINT32,255,0,"Param[2]"},
    {&Param[3] ,VAR_TYPE_UINT32,255,0,"Param[3]"},
    {&Param[4] ,VAR_TYPE_UINT32,255,0,"Param[4]"},
    {&Param[5] ,VAR_TYPE_UINT32,255,0,"Param[5]"},
};
//Step 4: (Optional) Implement Get Callback, as xxx_get_xxx to refresh your variable controls
static void ItemsGetData(void)
{    
}
//Step 5: Implement Set Callback, as xxx_set_xxx to set variables to active
static void ItemsSetData(void)
{
}
#elif (CFG_ADJ_METHOD==ADJ_METHOD_IDE_CMULTS)
//Step 1: Includes
#include "ide.h"
//Step 2: Variables Control
static UINT32 uiCMULTS=64;
//Step 3: Setup Up Item
static tADJ_ITEM Items[] = {
    {&uiCMULTS ,VAR_TYPE_UINT32,511,0,"uiCMULTS"},
};
//Step 4: (Optional) Implement Get Callback, as xxx_get_xxx to refresh your variable controls
static void ItemsGetData(void)
{    
}
//Step 5: Implement Set Callback, as xxx_set_xxx to set variables to active
static void ItemsSetData(void)
{
    ide_setCmults(uiCMULTS);
    ide_set_load();
    ide_waitFrameEnd();
}
#elif
#error "unknown CFG_ADJ_METHOD"
#endif

void MsdcNvtCb_AdjGetNumOfItem(void* pData)
{
    tMSDCEXT_UINT32* pDesc = BEGIN_MSDC_NVT_CB(tMSDCEXT_UINT32,pData);
    if(pDesc==NULL)
        return;

    pDesc->uiValue = sizeof(Items)/sizeof(Items[0]);
    pDesc->tParent.bOK = TRUE;
}

void MsdcNvtCb_AdjGetItemsDesc(void* pData)
{
    tMSDCEXT_ADJ_ALL_DESC* pDesc = BEGIN_MSDC_NVT_CB(tMSDCEXT_ADJ_ALL_DESC,pData);
    tMSDCEXT_ADJ_ITEM_DESC* pItemDesc = (tMSDCEXT_ADJ_ITEM_DESC*)(&pDesc[1]);
    
    UINT32 i,nItem = sizeof(Items)/sizeof(Items[0]);

    for(i=0;i<nItem;i++)
    {
        tADJ_ITEM* pSrc = &Items[i];
        tMSDCEXT_ADJ_ITEM_DESC* pDst = pItemDesc+i;
        memset(pDst,0,sizeof(tMSDCEXT_ADJ_ITEM_DESC));
        switch(pSrc->VarType)
        {
            case VAR_TYPE_INT32:
            case VAR_TYPE_INT16:
                pDst->bIsSign = TRUE;
        }
        pDst->MaxValue = pSrc->MaxValue;
        pDst->MinValue = pSrc->MinValue;
        strcpy(pDst->Tag,pSrc->Tag);
    }
     pDesc->tParent.bOK = TRUE;
}

void MsdcNvtCb_AdjSetItemsData(void* pData)
{
    tMSDCEXT_ADJ_DATA* pDesc = BEGIN_MSDC_NVT_CB(tMSDCEXT_ADJ_DATA,pData);
    UINT32* pVars = (UINT32*)(&pDesc[1]);
    UINT32 i,nItem = sizeof(Items)/sizeof(Items[0]);
    
    for(i=0;i<nItem;i++)
    {
        tADJ_ITEM* pItem = &Items[i];
        void*      pVar =  &pVars[i];
        
        switch(pItem->VarType)
        {
            case VAR_TYPE_BOOL:
                *((BOOL*)pItem->pVar) = *((BOOL*)pVar);
                debug_msg("%s=%d,",pItem->Tag,*((BOOL*)pVar));
                break;
            case VAR_TYPE_UINT32:
                *((UINT32*)pItem->pVar) = *((UINT32*)pVar);
                debug_msg("%s=%d,",pItem->Tag,*((UINT32*)pVar));
                break;
            case VAR_TYPE_INT32:
                *((INT32*)pItem->pVar) = *((INT32*)pVar);
                debug_msg("%s=%d,",pItem->Tag,*((INT32*)pVar));
                break;
            case VAR_TYPE_UINT16:
                *((UINT16*)pItem->pVar) = *((UINT16*)pVar);
                debug_msg("%s=%d,",pItem->Tag,*((UINT16*)pVar));
                break;
            case VAR_TYPE_INT16:
                *((INT16*)pItem->pVar) = *((INT16*)pVar);
                debug_msg("%s=%d,",pItem->Tag,*((INT16*)pVar));
                break;
            case VAR_TYPE_UINT8:
                *((UINT8*)pItem->pVar) = *((UINT8*)pVar);
                debug_msg("%s=%d,",pItem->Tag,*((UINT8*)pVar));
                break;
            case VAR_TYPE_INT8:
                *((INT8*)pItem->pVar) = *((INT8*)pVar);
                debug_msg("%s=%d,",pItem->Tag,*((INT8*)pVar));
                break;
        }
    }   
    debug_msg("\r\n");
        
    ItemsSetData();
    pDesc->tParent.bOK = TRUE;
}

void MsdcNvtCb_AdjGetItemsData(void* pData)
{
    tMSDCEXT_ADJ_DATA* pDesc = BEGIN_MSDC_NVT_CB(tMSDCEXT_ADJ_DATA,pData);
    UINT32* pVars = (UINT32*)(&pDesc[1]);       
    UINT32 i,nItem = sizeof(Items)/sizeof(Items[0]);

    ItemsGetData();

    for(i=0;i<nItem;i++)
    {
        tADJ_ITEM* pItem = &Items[i];
        void*      pVar = &pVars[i];

        *((UINT32*)pVar) = 0; //Reset to 0
        
        switch(pItem->VarType)
        {
            case VAR_TYPE_BOOL:
                *((BOOL*)pVar) = *((BOOL*)pItem->pVar);
                break;
            case VAR_TYPE_UINT32:
                *((UINT32*)pVar) = *((UINT32*)pItem->pVar);
                break;
            case VAR_TYPE_INT32:
                *((INT32*)pVar) = *((INT32*)pItem->pVar);
                break;
            case VAR_TYPE_UINT16:
                *((UINT16*)pVar) = *((UINT16*)pItem->pVar);
                break;
            case VAR_TYPE_INT16:
                *((INT16*)pVar) = *((INT16*)pItem->pVar);
                break;
            case VAR_TYPE_UINT8:
                *((UINT8*)pVar) = *((UINT8*)pItem->pVar);
                break;
            case VAR_TYPE_INT8:
                *((INT8*)pVar) = *((INT8*)pItem->pVar);
                break;
        }     
    }
     
    pDesc->tParent.bOK = TRUE;
}
