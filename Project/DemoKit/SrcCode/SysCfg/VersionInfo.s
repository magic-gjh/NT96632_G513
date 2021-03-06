;   Copyright   Novatek Microelectronics Corp. 2005.  All rights reserved.
;
;   @file       VersionInfo.s
;   @ingroup
;
;   @brief      Project version and build date information
;               Project version and build date information
;
;   @note       This file is generated by CreatePrjVer.bat
;
;   @version    V1.00.000
;   @author     Novatek FW Team
;   @date       2005/12/29

    AREA        VERSIONINFO, CODE, READONLY

;//#NT#2009/10/12#Scottie -begin
;//#NT#Use PART_TWO_RO base address instead of PART ONE size for Partial Load
    IMPORT      ||Load$$PART_TWO_RO$$Base||
;//#NT#2009/10/12#Scottie -end
    EXPORT      VersionNumber
    EXPORT      ReleaseDate
    EXPORT      ProjectCode
    EXPORT      PartLoad

LENGTH          EQU         0x0
CHECKSUM        EQU         0x0
CRCLENGTH       EQU         0x0
PARTLOAD        EQU         0x0
CRCTAG          EQU         0x0
RESERVEDSIZE    EQU         0x0
RESERVED1       EQU         0x0
RESERVED2       EQU         0x0
CMPRESSTAG      EQU         0x0

ProjectCode
    DCB         "NT96630 "
VersionNumber
    DCB         "1.00.000"
ReleaseDate
    DCB         "20090824"
Length
    DCD         LENGTH
Checksum
    DCD         CHECKSUM
CRCLength
    DCD         CRCLENGTH   ; Length check (CRC32)
PartLoad
    IF _FWCOMPRESS_TYPE_ = _FWCOMPRESS_NONE_ :LOR: _FWCOMPRESS_TYPE_ = _FWCOMPRESS_FULL_
    DCD         PARTLOAD
    ELSE
	DCD         ||Load$$PART_TWO_RO$$Base||         ; 0x74 --> partial load address
    ENDIF
;//#NT#NAND Reserved size offset
ReservedSize                                        ; 0x78 --> Reserved data
    DCD         RESERVEDSIZE
CRCTag                                              ; 0x7C
    DCD         CRCTAG      ; Binary tag (CRC32)
Reserved1                                           ; 0x80
    DCD         RESERVED1
Reserved2
    DCD         0                                   ; 0x84
Reserved3
    DCD         0                                   ; 0x88

CompressTag                                         ; 0x8C
    DCD         CMPRESSTAG
FlashSizeTag                                        ; 0x90
    DCD         0
    END
