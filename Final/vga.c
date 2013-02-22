/*
 * vga.c
 *
 *  Created on: Nov 28, 2012
 *      Author: Matthew Borneman
 */

#include "hcs12.h"
#include "vga.h"

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
