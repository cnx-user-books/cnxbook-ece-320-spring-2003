; Lab 3 assembly module
                        
        .copy "v:\ece320\54x\dspclib\core.inc"
	                                ; Useful macros for C interfacing
        
        .global _dec_rate		; Decimation rate - in lab3main.c
        .global _filter			; Filter code in this file
        .global _init_filter

FIR_len	.set	13  

	.sect ".data"

	.align 16			; Align to a multiple of 16
firstate
	.space 16*13			; Allocate 13 words of storage for
					; filter state.	
	.align 16
coef	.copy "coef1.asm" 

stateptr .word 0

_dec_rate .word 4

	.sect ".text"    
	
_init_filter 		; need the leading _ for a C name.
	ENTER_ASM
	
	stm	#firstate, AR3
	mvmd	AR3, stateptr		; Save AR3
	
	LEAVE_ASM
	ret
	
_filter                                          
	ENTER_ASM
	; Input in low part of A accumulator
	
	mvdm	stateptr, AR3		; Restore state pointer
	
	stm 	#FIR_len,BK		; initialize circular buffer length
	stm 	#coef,AR2    		; initialize coefficient pointer
	stm 	#1,AR0			; initialize AR0 for pointer increment
	
	stl   	A,*AR3+%		; store current input into state buffer
    	rptz  	A,(FIR_len-1)		; clear A and repeat
    	mac   	*AR2+0%,*AR3+0%,A	; multiply coefficient by state & accumulate
    
    	rnd	A			; Round off value in 'a' to 16 bits                            
	
        sfta 	a,-16			; Shift output to low part of accumulator
        
        mvmd	AR3, stateptr		; Save state pointer
        
	; Output in low part of A accumulator
	
	LEAVE_ASM
	ret	                                        


