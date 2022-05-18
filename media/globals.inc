;============================================================================
; Filename: globals.inc
;
; Description:  Global Defines and Variables
;
;============================================================================

TRUE    .set   1
FALSE   .set   0

;===== Assemble Flags =====
SIMULATOR  .set TRUE

;===== RAM B2 Interrupt Vector Definitions =====
; These int vector definitions are per the ROM Bootloader assembly language
; code.  See the ISPTAB.ASM file.
int1v	.set	60h		; external interrupt vectors
int2v	.set	61h		;
int3v	.set	62h		;
int4v	.set	63h		;
rintv	.set	64h		; receive interrupt vector
xintv	.set	65h		; transmit interrupt vector
trntv	.set	66h		; TDM port receive interrupt vector
txntv	.set	67h		; TDM port transmit interrupt vector

tintv	.set	68h		; timer interrupt vector
trapv	.set	69h		; software trap vector
nmintv	.set	6ah		; non-maskable interrupt vector
swi12v	.set	6bh		; software interrupt vectors
swi13v	.set	6ch		;
swi14v	.set	6dh		; (Note: If these interrupts are unused
swi15v	.set	6eh		; these data memory locations may be
swi16v	.set	6fh		; assigned to other purposes.)

swi20v	.set	70h		; software interrupt vectors
swi21v	.set	71h		;
swi22v	.set	72h		;
swi23v	.set	73h		;
swi24v	.set	74h		;
swi25v	.set	75h		;
swi26v	.set	76h		;
swi27v	.set	77h		;

swi28v	.set	78h		; software interrupt vectors
swi29v	.set	79h		;
swi30v	.set	7ah		;
swi31v	.set	7bh		;

;===== RAM B2 Data Memory Not Used By ROM Boot Loader =====
unused1 .set  7ch   ;
unused2 .set  7dh   ;
unused3 .set  7eh   ;
unused4 .set  7fh   ;
