/*
 * vga_timing.asm
 *
 *  Created on: Nov 28, 2012
 *      Author: Matthew Borneman
 */

.include "hcs12.inc"

.global video_draw

; ----------- VIDEO VARIABLES ----------
.equ vid_pointer,0x1960
.equ vid_blanks,0x1962

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

; ---------- VIDEO MACROS ----------

   ; writes a pixel color to PORTA
   video_1:  macro
              inx             ; increment X    (1 cycle)
              jsr nop10       ; waste time     (10 cycles)
              movb 0,X, PORTA ; write to pins  (5 cycles)
              endm

   video_9:  macro          ; 16x9 => 144 cycles
              video_1
              video_1
              video_1
              video_1
              video_1
              video_1
              video_1
              video_1
              video_1
              endm

   video_10: macro         ; 16x10 => 160 cycles
              video_9
              video_1
              endm


; video drawing routine
; PT0 = HSYNC
; PT1 = VSYNC
; PORTA = COLOR
video_draw:
           ; *****************************************************
           ; *    ATTENTION: This function is timing-critical    *
           ; *****************************************************

           tst vid_blanks   ; check if blank count is zero   (3 cycles)
           beq start_active ; go begin active video section

           ; common                          (1 cycle) <- NOT BRANCHED
           ldaa vid_blanks ; load A          (3 cycles)
           cmpa #33        ; VSYNC start?    (1 cycle)
           beq vs_low

           ; (A/=31)       ;               (1 cycle) <- NOT BRANCHED
           cmpa #31        ; VSYNC end?    (1 cycle)
           beq vs_high

           ; else                          (1 cycle) <- NOT BRANCHED
           nop             ; burn time     (1 cycle)
           bclr PTJ,1      ; HS=0          (4 cycles)
           bra hs_pulse
           ; TOTAL FROM START=(3)+(1+3+1)+(1+1)+(1+4+1)=17

            ; (A=31)
    vs_low: ; bring VSYNC low              (3 cycles) <- BRANCHED
           nop2            ; burn time     (2 cycles)
           movb #0,PTJ     ; VS=0, HS=0    (4 cycles)
           bra hs_pulse
           ; TOTAL FROM START=(3)+(1+3+1)+(3+4+2)=17

            ; (A=29)
   vs_high: ; bring VSYNC high             (3 cycles) <- BRANCHED
           movb #2,PTJ     ; VS=1, HS=0    (4 cycles)
           bra hs_pulse
           ; TOTAL FROM START=(3)+(1+3+1)+(1+1)+(3+4)=17

  hs_pulse:
            ; ----- BLANK HORIZONTAL SYNC PULSE = 96 cycles -----
                               ; delay from entry = (3 cycles)
            dec vid_blanks     ; dec blank counter  (4 cycles)
            jsr nop50          ; burn time          (50 cycles)
            jsr nop10          ; burn time          (10 cycles)
            jsr nop10          ; burn time          (10 cycles)
            jsr nop10          ; burn time          (10 cycles)
            nop                ; burn time          (1 cycle)
            movb #0x80,MCFLG ; clear interrupt flag (4 cycles)
            bset PTJ,1       ; raise HS             (4 cycles)
            rts ; return from subroutine

 start_active:
            ; prepare for active video section  (3 cycles) <- BRANCHED
            nop
            ldx  vid_pointer ; video_pointer    (3 cycles)
            clra           ; V repeat counter   (1 cycle)
            clrb           ; V rows counter     (1 cycle)
            nop            ; burn time          (1 cycle)
            bclr PTJ,0x01  ; lower HS for sync  (4 cycles)
            ; TOTAL FROM START=(3)+(3+1+3+1+1+1+4)=17
            nop2
            nop2  ; 4 cycles for entry
 a_hs_pulse:
            ; ----- ACTIVE HORIZONTAL SYNC PULSE = 96 cycles -----
                          ; delay from entry = (4 cycles)
            jsr nop50  ; burn time             (50 cycles)
            jsr nop10  ; burn time             (10 cycles)
            jsr nop10  ; burn time             (10 cycles)
            jsr nop10  ; burn time             (10 cycles)
            nop5       ; burn time             (5 cycles)
            nop2       ; burn time             (2 cycles)
            nop        ; burn time             (1 cycle)
            bset PTJ,0x01         ; raise HS   (4 cycles)

            ; ----- HORIZONTAL BACK PORCH = 48 cycles -----
            jsr nop10   ; burn time             (10 cycles)
            jsr nop10   ; burn time             (10 cycles)
            jsr nop10   ; burn time             (10 cycles)
            jsr nop10   ; burn time             (10 cycles)
            nop2        ; burn time             (2 cycles)
            tfr X, Y    ; line start addr -> Y  (1 cycle)
            movb 0,X, PORTA ; write first pixel (5 cycles)

            ; ----- HORIZONTAL ACTIVE VIDEO = 640 cycles -----
            video_10  ; video to screen     (160 cycles)
            video_10  ; video to screen     (160 cycles)
            video_10  ; video to screen     (160 cycles)
            video_9   ; video to screen     (144 cycles)
            inx       ; increment for next  (1 cycle)
            jsr nop10 ; burn time           (10 cycle)
            nop2      ; burn time           (2 cycle)
            clr PORTA ; blacken video       (3 cycles)

            ; ----- HORIZONTAL FRONT PORCH = 16 cycles -----
            ; if B=15, A=29 => EXIT
            ; elsif B=15    => A++, B=0
            ; else          => B++, X=X-40

            cmpb #15 ; compare B with 15 (1 cycle)
            beq done_reps ; branch if B = 15

            ; (B!=15)
            ; more repeats to go         (1 cycle) <- NOT BRANCHED
            incb      ; inc repeat count (1 cycle)
            tfr Y, X  ; start line again (1 cycle)
            nop2      ; burn time        (2 cycles)
            nop2      ; burn time        (2 cycles)
            nop2      ; burn time        (2 cycles)
            nop2      ; burn time        (2 cycles)
            bclr PTJ,0x01 ; lower HS     (4 cycles)
            lbra a_hs_pulse ; go repeat row
            ; TOTAL=(1)+(1+1+1+2+2+2+4)=16

 done_reps: ; (B=15)                      (3 cycles) <- BRANCHED
            clrb     ; clear B            (1 cycle)
            cmpa #29 ; compare A with 29  (1 cycle)
            beq done_rows ; branch if A = 29

            ; (B=15) && (A!=0)
            ; move to next line           (1 cycle) <- NOT BRANCHED
            inca       ; inc line count   (1 cycle)
            nop2       ;                  (2 cycles)
            nop2       ;                  (2 cycles)
            bclr PTJ,0x01 ; lower HS      (4 cycles)
            lbra a_hs_pulse ; go new line
            ; TOTAL=(1)+(3+1+1)+(1+1+2+2+4)=16

            ; (B=15) && (A=29)            (3 cycle) <- BRANCHED
 done_rows: nop2        ; burn time       (2 cycles)
            nop         ; burn time       (1 cycles)
            bclr PTJ,0x01 ; lower HS      (4 cycles)
            ; TOTAL=(1)+(3+1+1)+(3+2+1+4)=16

            ; ----- NEXT HORIZONTAL SYNC PULSE = 96 cycles -----
            jsr nop50      ; burn time              (50 cycles)
            jsr nop10      ; burn time              (10 cycles)
            jsr nop10      ; burn time              (10 cycles)
            jsr nop10      ; burn time              (10 cycles)
            movb #44, vid_blanks ; 44 blank lines   (4 cycles)
            movb #0x80,MCFLG ; clear interrupt flag (4 cycles)
            nop2                                   ;(2 cycles)
            nop2                                   ;(2 cycles)
            bset PTJ,0x01   ; raise HS              (4 cycles)
            ; end active video!
            rts
