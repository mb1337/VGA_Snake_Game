/*
 * vga.h
 *
 *  Created on: Nov 28 2012
 *      Author: Matthew Borneman
 */

#ifndef __VGA_H
#define __VGA_H

#define     VID_POINTER          (*(unsigned short  volatile *)0x3580)
#define     SET_VID_POINTER(p)   ((VID_POINTER) = (p))
#define     bufferA              (*(unsigned char  volatile *)0x1000)
#define     bufferB              (*(unsigned char  volatile *)0x22C0)
#define     HEIGHT               30
#define     WIDTH                40
#define     BUF_LEN              (HEIGHT * WIDTH)

/*
 * Start counter for video interrupt
 * video interrupts every 800 clock cycles
 */
void FLAT_FAR video_enable(void);

/*
 * Assembly function that draws the video to the screen
 */
void FLAT_FAR video_draw(void);

#endif
