/*
 * speaker.c
 *
 *  Created on: Dec 8, 2012
 *      Author: Matthew Borneman
 */
#include "hcs12.h"
#include "speaker.h"

#define  B4 48595U
#define  C5 45867U
#define  D5 40863U

/*
 * Plays a  C5 note
 */
void FLAT_FAR playGameSound(void)
{
   PWMCLK = 0x00;
   PWMCTL = 0x40;
   PWMPRCLK = 0x00;
   PWMPOL = 0;
   PWMPER45 = C5;
   PWMDTY45 = C5 / 2;
   PWME = 0x20;
}

/*
 * Plays a  D5 note
 */
void FLAT_FAR playPointSound(void)
{
   PWMCLK = 0x00;
   PWMCTL = 0x40;
   PWMPRCLK = 0x00;
   PWMPOL = 0;
   PWMPER45 = D5;
   PWMDTY45 = D5 / 2;
   PWME = 0x20;
}

/*
 * Plays a  B4 note
 */
void FLAT_FAR playDeathSound(void)
{
   PWMCLK = 0x00;
   PWMCTL = 0x40;
   PWMPRCLK = 0x00;
   PWMPOL = 0;
   PWMPER45 = B4;
   PWMDTY45 = B4 / 2;
   PWME = 0x20;
}
