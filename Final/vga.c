/*
 * vga.c
 *
 *  Created on: Nov 28, 2012
 *      Author: Matthew Borneman
 */

#include "hcs12.h"
#include "vga.h"

char * vid_ptr;

char vid_blanks = 44;

/*
 * Start counter for video interrupt
 * video interrupts every 800 clock cycles
 */
void FLAT_FAR video_enable(void)
{
   HPRIO = 0xCA;
   MCCTL = 0xC4;
   MCCNT = 800;
   PTJ |= 0x03;
   PORTA = 0;
   DDRJ |= 0x03;
   DDRA = 0xFF;
}

void FLAT_FAR set_vid_ptr(char * ptr)
{
   vid_ptr = ptr;
}
