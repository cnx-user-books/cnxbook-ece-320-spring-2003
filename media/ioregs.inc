;============================================
;===== Memory Mapped I/O Port Registers =====
;============================================
 .global mmBootload
 .global mmIntMask
 .global mmIntrpt
 .global mmPCIDPRAMAddr
 .global mmPCIAddrLSW
 .global mmPCIAddrMSW
 .global mmPCIOffset
 .global mmPCIXferCount
 .global mmPCIControl
 .global mmDMASRAMAddr
 .global mmDMAXferCount
 .global mmDMAControl
 .global mmMiscControl
 .global mmVoiceCodecCntrl
 .global mmStereoCodecCntrl
 .global mmDPRAMPtrs
 .global mmBSPCE0
 .global mmBSPC0  
 .global mmAXR0
 .global mmARR0


mmBSPCE0			.set 023h
mmBSPC0				.set 022h    
mmAXR0				.set 038h
mmARR0				.set 03Ah
mmIntMask          .set 050h
mmIntrpt           .set 051h
mmPCIDPRAMAddr     .set 052h
mmPCIAddrLSW       .set 053h
mmPCIAddrMSW       .set 054h
mmPCIOffset        .set 055h
mmPCIXferCount     .set 056h
mmPCIControl       .set 057h
mmDMASRAMAddr      .set 058h
mmDMAXferCount     .set 059h
mmDMAControl       .set 05Ah
mmMiscControl      .set 05Bh
mmVoiceCodecCntrl  .set 05Ch
mmStereoCodecCntrl .set 05Dh
mmDPRAMPtrs        .set 05Eh


;==============================
;===== I/O Port Registers =====
;==============================

 .global ioDMAPingAddr
 .global ioDMABuffSize
 .global ioVCXmitPingAddr
 .global ioVCXmitBuffSize
 .global ioVCRecvPingAddr
 .global ioVCRecvBuffSize
 .global ioSCXmitPingAddr
 .global ioSCXmitBuffSize
 .global ioSCRecvPingAddr
 .global ioSCRecvBuffSize
 .global ioSCPIOControl
 .global ioSRAMControl

ioDMAPingAddr     .set 060h
ioDMABuffSize     .set 061h
ioVCXmitPingAddr  .set 062h
ioVCXmitBuffSize  .set 063h
ioVCRecvPingAddr  .set 064h
ioVCRecvBuffSize  .set 065h
ioSCXmitPingAddr  .set 066h
ioSCXmitBuffSize  .set 067h
ioSCRecvPingAddr  .set 068h
ioSCRecvBuffSize  .set 069h
ioSRAMControl     .set 06Ah

ioPCIInterrupt    .set 06Ch
ioASICControl     .set 06Dh
ioSCPIOControl    .set 06Eh
ioSCPIOAddrData   .set 06Fh

;=====================================
;===== I/O Port Config Constants =====
;=====================================

;========== PCI Control_Register Configurations ========
;15 14 13 12  11 10  9  8   7  6  5  4   3  2  1  0
; x  x  x  o   o  x  x  o   o  o  o  o   o  x  x  o    PCI_Control_Reg
;          |   |        |   |  |  |  |   |        |
;          |   |        |   +--+--+--+   |        +----- 1=Start PCI Macro
;          |   |        |            |   +---------- 1=Abort PCI Macro Xaction
;          |   |        |            +---------- 4-Bit PCI Command
;          |   |        +--------------------- 0=Byte Xfer, 1=Word Xfer
;          |   +-------------------------- 0=ProgSpace PCI Addr, 1=DSP PCI Addr
;          +-------------------------- 1=DMA Enable

PSTART .set 00001h

PWRITE .set 00070h
PREAD  .set 000E0h

PWORD  .set 00100h
PBYTE  .set 00000h

PPRG   .set 00000h
PDSP   .set 00800h

PDMA   .set 01000h


;========== DMA Control_Register Configurations ========
;15 14 13 12  11 10  9  8   7  6  5  4   3  2  1  0
; o  o  o  o   o  o  o  o   o  o  o  o   o  x  x  o    DMA_Control_Reg
; |  |  |  |   |  |  |  |   |  |  |  |   |        |
; +--+--+--+---+--+--+--+   |  |  +--+   |        +----- 1=Start DMA
;                       |   |  |     |   +---------- 1=Abort DMA Xaction
;                       |   |  |     +---------- 2-Bit Granularity
;                       |   |  +------------ 0=Data Space, 1=Program Space
;                       |   +----------- DMA Direction, 0=To SRAM, 1=To DPRAM
;                       +--------- 8-Bit DMA Delay
;

DMA_2_SRAM_DS_FAST    .set 00001h
DMA_2_DPRAM_PS_FAST   .set 000C1h
DMA_2_DPRAM_DS_FAST   .set 00081h

DMA_2_DPRAM_DS_G1D1   .set 00191h
DMA_2_SRAM_DS_G1D1    .set 00111h

DMA_2_DPRAM_PS_G2D1   .set 001A1h
DMA_2_SRAM_DS_G2D1    .set 00121h

DMA_2_DPRAM_PS_G3D1   .set 001B1h
DMA_2_SRAM_DS_G3D1    .set 00131h

DMA_2_DPRAM_PS_G1D128 .set 08091h
DMA_2_SRAM_DS_G1D128  .set 08011h

DMA_2_DPRAM_PS_G1D256 .set 0FF91h
DMA_2_SRAM_DS_G1D256  .set 0FF11h

DMA_ABORT             .set 00008h


;===== Interrupt Register Defines =====
DMA_INT_TEST   .set BIT1_TEST
DMA_INT_SET    .set BIT1_1
DMA_INT_CLR    .set BIT1_1

;===== Voice Codec Control Register Configurations =====
;15 14 13 12  11 10  9  8   7  6  5  4   3  2  1  0
; x  x  x  x   x  o  o  o   x  x  x  x   x  o  o  o    VC_Control_Reg
;                 |  |  |                   |  |  |
;                 |  |  +--Rcv enable       |  |  +--Xmit enable
;                 |  +--Rcv ping valid      |  +--Xmit ping valid
;                 +--Rcv pong valid         +--Xmit pong valid

;===== Interrupt Register Definitions =====
VCRCV_INT_TEST .set BIT7_TEST
VCRCV_INT_SET .set BIT7_1
VCRCV_INT_CLR .set BIT7_1
VCXMT_INT_TEST .set BIT6_TEST
VCXMT_INT_SET .set BIT6_1
VCXMT_INT_CLR .set BIT6_1


;===== Stereo Codec Control Register Configurations =====
;15 14 13 12  11 10  9  8   7  6  5  4   3  2  1  0
; x  x  x  x   x  o  o  o   x  x  x  x   x  o  o  o    SC_Control_Reg
;                 |  |  |                   |  |  |
;                 |  |  +--Rcv enable       |  |  +--Xmit enable
;                 |  +--Rcv ping valid      |  +--Xmit ping valid
;                 +--Rcv pong valid         +--Xmit pong valid

;===== Interrupt Register Definitions =====
SCRCV_INT_TEST .set BIT4_TEST
SCRCV_INT_SET .set BIT4_1
SCRCV_INT_CLR .set BIT4_1
SCXMT_INT_TEST .set BIT3_TEST
SCXMT_INT_SET .set BIT3_1
SCXMT_INT_CLR .set BIT3_1

;===== Stereo Codec PIO Control Register Configurations =====
;15 14 13 12  11 10  9  8   7  6  5  4   3  2  1  0
; x  x  x  x   x  x  x  x   x  o  o  o   o  o  o  o    SC_PIO_Control_Reg
;                              |  |  |   |  |  |  |
;                              |  |  |   |  |  |  +--codec done
;                              |  |  |   |  |  +--codec start
;                              |  |  |   |  +--codec indirect
;                              |  |  |   +--transfer direction
;                              |  |  +--PIO=1 DMA=0
;                              +--+--PIO address

;===== Misc polling parameter =====
SC_DONE_BIT_TEST .set BIT0_TEST  ;not in DSP interrupt register

;===== PCI Macro Control Register =====
;15 14 13 12  11 10  9  8   7  6  5  4   3  2  1  0
; o  x  x  o   o  x  x  o   o  o  o  o   o  x  x  o
; |        |   |        |   |  |  |  |   |        |
; |        |   |        |   |  |  |  |   |        +--Start PCI Macro
; |        |   |        |   |  |  |  |   +--Abort PCI Macro transaction
; |        |   |        |   +--+--+--+--4 bit PCI Command
; |        |   |        +--0=byte xfers  1=word xfers
; |        |   +--0=Host generated PCI address  1=C5x generated PCI address
; |        +--0=DMA independent of PCI  1=DMA coupled to PCI transaction
; +--0=Diagnostic counter disabled  1=Diagnostic counter enabled

;===== Interrupt Register Definitions =====
PCIBUS_INT_TEST .set BIT0_TEST
PCIBUS_INT_SET .set BIT0_1
PCIBUS_INT_CLR .set BIT0_1