; v:/ece320/54x/dspclib/c_fft_given.asm
; dgs - 9/14/2001
	.copy "v:\ece320\54x\dspclib\core.inc"

	.global	_bit_rev_data
	.global _fft_data
	.global _window
	
	.global _bit_rev_fft

	.sect	".data"

	.align 4*N
_bit_rev_data .space 16*2*N	; Input to _bit_rev_fft

	.align	4*N
_fft_data .space 16*2*N		; FFT output buffer


; Copy in the Hamming window
_window					; The Hamming window
	.copy	"window.asm"	

	.sect ".text"

_bit_rev_fft
	ENTER_ASM
                                                  
	call bit_rev                    ; Do the bit-reversal.

	call fft		        ; Do the FFT

	LEAVE_ASM
        RET                                     
	
; Copy the actual FFT subroutine.
fft_data  .set	_fft_data	; FFT code needs this.
          .copy 	"v:/ece320/54x/dsplib/fft.asm"


; If you need any more assembly subroutines, make sure you name them
; _name, and include a ".global _name" directive at the top. Also,
; don't forget to use ENTER_ASM at the beginning, and LEAVE_ASM
; and RET at the end!