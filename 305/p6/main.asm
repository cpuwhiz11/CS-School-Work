;; Paul Geromini
;; Assignment #5
;; Uses code from IO_str_and_scan_number.asm in /bill/cs305
	
start:  lodd on:
        stod 4095		; Transmitter addr, turn on
	
        call xbsywt: 		; wait for it to be ready
        
	loco str1: 		; Load first string prompting for number
	call nextw:		; Transmit to screen
	call input:		; Get user number
        lodd binnum:		; This is the binary number
	stod sum:		; Store into sum
	
	loco str1:		; Prompt for next number
	call nextw:		; Transmit to screen
	
	call input:		; Get second number
	lodd binnum:		; put second number into ac
	addd sum:		; add the two numbers
	stod sum:		; store in sum
	stod ans:		; Store answer in ans
	
	jneg over:		; If negative we got an overflow

	call xbsywt:	        ; wait for transmitter to be ready
	loco str2:		; Load string for good addition	
	call nextw:		; Transmit to screen

	call xbsywt:	        ; Wait for transmitter to be ready
	call bitz:		; Convert results

	call xbsywt:		; Wait
	lodd zero:		; Put zero into AC

	halt			; halt 

over:	loco str3:		; Load overflow string
	call nextw:		; Transmit to screen
	lodd cneg1:		; put -1 into AC
	halt 			; halt
		
nextw:  pshi
        addd c1:
        stod pstr1:
        pop
        jzer crnl:
        stod 4094
        push
        subd c255:
        jneg crnl:
        call sb:
        insp 1
        push
        call xbsywt:
        pop
        stod 4094
        call xbsywt:
        lodd pstr1:
        jump nextw:

crnl:   lodd cr:
        stod 4094
        call xbsywt:
        lodd nl:
        stod 4094
        call xbsywt:
	retn

input:	lodd on:
	stod 4093
	call rbsywt:
	lodd 4092
	subd numoff:
	push

nxtdig:	call rbsywt:
	lodd 4092
	stod nxtchr:
	subd nl:
        jzer endnum:
	mult 10
	lodd nxtchr:
	subd numoff:
	addl 0
	stol 0
	jump nxtdig:
endnum: pop
	stod binnum:
        lodd 4092
        loco 0
	retn
sb:     loco 8
loop1:  jzer finish:
        subd c1:
        stod lpcnt:
        lodl 1
        jneg add1:
        addl 1
        stol 1
        lodd lpcnt:
        jump loop1:
add1:   addl 1
        addd c1:
        stol 1
        lodd lpcnt:
        jump loop1:

finish: lodl 1			
        retn

bitz:	lodd on:
	stod 4095
	lodd cneg1:		; put -1 in AC
	push 			; put -1 on stack
	lodd mask:		; load mask in ac
	push     		; push mask on stack

code:	lodd ans:		; Load ans into ac
	jzer print:		; If done print it
	lodd mask:
	push			; push mask onto stack
	lodd ans:		; put ans into ac
	push
	div			; divide ans by mask
	pop			; pop into ac
	stod ans:		; put new value into ans
	pop
	insp 2			; clear up stack
	addd numoff:		; convert to char
	push 			; push ac onto stack
	jump code:		; loop

print:	pop			; take result of loop and put into ac
	jneg done:		; if -1 we are done
	stod 4094		; store ac into content register
	call xbsywt:		; transmit result
	jump print:		; print next result

done: retn 			; Return


numoff: 48
nxtchr: 0
binnum: 0
lpcnt:  0
mask:   10
on:     8
nl:     10
cr:     13
c1:     1
c255:   255
cneg1:	-1 			; constant -1
pstr1:  0
str1:   "Please enter a 1-5 digit number followed by enter."
str2:   "The sum of the two numbers is: "
str3:   "The sum has overflowed."
sum:	0			; stores the first number
ans:	0			; stores the sum
zero:	0

