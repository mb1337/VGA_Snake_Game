/*
 * vga.h
 *
 *  Created on: Nov 28 2012
 *      Author: Matthew Borneman
 */

#ifndef __VGA_H
#define __VGA_H

#define     HEIGHT               60U
#define     WIDTH                80U
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

void FLAT_FAR set_vid_ptr(char * ptr);

#endif
