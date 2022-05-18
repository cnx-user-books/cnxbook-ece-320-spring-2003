	.copy "core.asm"

	.sect ".text"
main
	; initialize here

loop
	; Wait for a new block of 64 samples to come in
	WAITDATA
	
    	; BlockLen = the number of samples that come from WAITDATA (64)
    	stm 	#BlockLen-1, BRC
    	rptb 	copy

    	ld      *AR6,16, A		; Receive ch1
    	mar 	*+AR6(2)                ; Rcv data is in every other channel
    	ld      *AR6,16, B		; Receive ch2
    	mar 	*+AR6(2)                ; Rcv data is in every other channel

; single sample code goes here....


    	sth 	A, *AR7+		; Store into output buffer, ch1
    	sth 	A, *AR7+		; ch2
    	sth 	A, *AR7+		; ch3
  
    	sth 	B, *AR7+		; Store into output buffer, ch4
    	sth 	B, *AR7+		; ch5
    	sth 	B, *AR7+		; ch6
    
copy:
    	nop				; Can't have a branch here

    	b 	loop	
