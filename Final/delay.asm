/*
 * delay.asm
 *
 *  Created on: Dec 8, 2012
 *      Author: Matthew Borneman
 */

; 25 MHz E Clock

.global delayby50us ; 1250 cycles
.global delayby1ms  ; 25000 cycles
.global delayby10ms ; 250000 cycles
.global delayby100ms ; 2500000 cycles

; ---------- DELAY MACROS ----------

     ; waste 2 cycles
     nop2: macro
              nop
              nop
              endm

     ; waste 5 cycles
     nop5: macro
              nop
              nop
              nop
              nop
              nop
              endm


 ; ---------- DELAY SUBROUTINES ------

    ; waste 10 cycles
     nop10:        ; cycles from JSR (4 cycles)
              nop  ;       burn time (1 cycle)
              rts  ; return from sub (5 cycles)

     ; waste 50 cycles
     nop50:        ; cycles from JSR (4 cycles)
              nop  ;       burn time (1 cycle)
              jsr nop10
              jsr nop10
              jsr nop10
              jsr nop10
              rts  ; return from sub (5 cycles)


    ; waste 100 cycles
    nop100:
                          ; cycles from JSR      (4 cycles)
              pshd        ; push D to the stack  (2 cycles)
              ldaa #21    ; load A               (1 cycle)

    loop100:  deca        ; A--                  (1 cycle)
              bne loop100 ; loop if not zero     (3 cycles)   <- BRANCH
              nop2        ; burn time            (1+2 cycles) <- NO BRANCH
              ; LOOP TOTAL = 4*21 = (84 cycles)

              nop         ; burn time            (1 cycle)
              puld        ; pull D from stack    (3 cycles)
              rts         ; return from sub      (5 cycles)

              ; TOTAL =(4+2+1)+(84)+(1+3+5)=100

delayby50us:
			pshy
			ldy		#11
loop50us:	jsr		nop100
			dbne	Y,loop50us
			puly
			jsr		nop10
			jsr		nop10
			jsr		nop10
			jsr		nop10
			nop5
			nop
			dbne	D,delayby50us
			rts

delayby1ms:
			pshd
			ldd		#19
			jsr		delayby50us
			puld
			pshy
			ldy		#11
loop1ms:	jsr		nop100
			dbne	Y,loop50us
			puly
			jsr		nop10
			jsr		nop10
			jsr		nop10
			jsr		nop10
			dbne	D,delayby1ms
			rts

delayby10ms:
			pshd
			ldd		#10
			jsr		delayby1ms
			puld
			dbne	D,delayby10ms
			rts

delayby100ms:
			pshd
			ldd		#100
			jsr		delayby1ms
			puld
			dbne	D,delayby100ms
			rts
