;===== BIT Instruction Codes =====
BIT0_TEST  .set 0Fh
BIT1_TEST  .set 0Eh
BIT2_TEST  .set 0Dh
BIT3_TEST  .set 0Ch
BIT4_TEST  .set 0Bh
BIT5_TEST  .set 0Ah
BIT6_TEST  .set 09h
BIT7_TEST  .set 08h
BIT8_TEST  .set 07h
BIT9_TEST  .set 06h
BIT10_TEST .set 05h
BIT11_TEST .set 04h
BIT12_TEST .set 03h
BIT13_TEST .set 02h
BIT14_TEST .set 01h
BIT15_TEST .set 00h

;===== BIT Settings =====
BIT0_1  .set 01h
BIT1_1  .set 02h
BIT2_1  .set 04h
BIT3_1  .set 08h
BIT4_1  .set 010h
BIT5_1  .set 020h
BIT6_1  .set 040h
BIT7_1  .set 080h
BIT8_1  .set 0100h
BIT9_1  .set 0200h
BIT10_1 .set 0400h
BIT11_1 .set 0800h
BIT12_1 .set 01000h
BIT13_1 .set 02000h
BIT14_1 .set 04000h
BIT15_1 .set 08000h


;===== CMPR CM Codes =====
CM_EQ .set 0
CM_LT .set 1
CM_GT .set 2
CM_NE .set 3

;===== Loader Control Word Codes =====
CW_PROG  .set 00h
CW_DATA  .set 01h
CW_PRET  .set 02h
CW_BACC  .set 04h

PIOAutoWrite  .macro  Addr, Data
;===== Load Addr/Data reg (loaded data/addr b/c of ASIC feature)
    ld    #Data, 8, A
    nop
    nop
    add   #Addr, A
    nop
    nop
    portw AL, ioSCPIOAddrData
    nop
    nop
;===== Start SC PIO Auto Indirect write ====
    ld    #0006H, A
    nop
    nop
    portw AL, ioSCPIOControl
    nop
    nop
    nop
    nop
    .endm

PIOAutoRead  .macro  Addr
;===== Load Addr/Data reg with Addr (loaded data/addr b/c of ASIC feature)
    ld    #Addr, A
    nop
    nop
    portw AL, ioSCPIOAddrData
    nop
    nop
;===== Start SC PIO Auto Indirect read ====
    ld    #000EH, A
    nop
    nop
    portw AL, ioSCPIOControl
    nop
    nop
;===== Read from SC addr/data reg =====
    portr ioSCPIOAddrData, AL
    nop
    nop
    nop
    nop
    .endm
