; ***************************************************************************
; Author: Dr. Han-Way Huang
; Date: 07/18/2004
; Organization: Minnesota State University, Mankato
; *******************************************************************************************
; The following subroutine uses modulus counter to create a delay that is a multiple of
; 50 us. The multiple is passed in Y.
; *******************************************************************************************
delayby50us
loop1	ldaa	#60
	psha
	pula
	psha
	pula
	psha
	pula
	psha
	pula
	dbne	a,loop1
	dbne	y,delayby50us
	rts
; ***************************************************************************
; The following function creates a time delay which is equal to the multiple
; of 1 ms. The value passed in Y specifies the number of milliseconds to be
; delayed.
; ***************************************************************************
delayby1ms 	ldd	#600
again0		psha
		pula
		psha
		pula
		psha
		pula
		psha
		pula
		psha
		pula
		psha
		pula
		psha
		pula
		psha
		pula
		dbne	d,again0
		dbne	y,delayby1ms
		rts
; ***************************************************************************
; The following function creates a time delay which is equal to the multiple
; of 10 ms. The value passed in Y specifies the number of 10 milliseconds
; to be delayed.
; ***************************************************************************
delayby10ms 	ldd	#6000
again1		psha
		pula
		psha
		pula
		psha
		pula
		psha
		pula
		psha
		pula
		psha
		pula
		psha
		pula
		psha
		pula
		dbne	d,again1
		dbne	y,delayby10ms
		rts
; ***************************************************************************
; The following function creates a time delay which is equal to the multiple
; of 100 ms. The value passed in Y specifies the number of 100 milliseconds
; to be delayed.
; ***************************************************************************
delayby100ms 	ldd	#60000
again2		psha
		pula
		psha
		pula
		psha
		pula
		psha
		pula
		psha
		pula
		psha
		pula
		psha
		pula
		psha
		pula
		dbne	d,again2
		dbne	y,delayby100ms
		rts
		end

