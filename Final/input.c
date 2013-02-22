/*
 * input.c
 *
 *  Created on: Dec 5, 2012
 *      Author: Matthew Borneman
 */

#include "hcs12.h"
#include "input.h"

static int direction = LEFT;
static void (*btnPress)(int);

void FLAT_FAR initInput(void (*callback)(int) )
{
   DDRH &= 0xF0;
   PIEH |= 0x0F;
   btnPress = callback;
}

void FLAT_FAR resetDirection(int dir)
{
   direction = dir;
}

void INTERRUPT input_isr(void)
{
   switch(PIFH)
   {
   case 0x01:
      if( direction != LEFT )
         direction = RIGHT;
      break;
   case 0x02:
      if( direction != DOWN )
         direction = UP;
      break;
   case 0x04:
      if( direction != UP )
         direction = DOWN;
      break;
   case 0x08:
      if( direction != RIGHT )
         direction = LEFT;
      break;
   }
   btnPress(direction);
   PIFH = 0xFF;
}

int FLAT_FAR get_direction(void)
{
   return direction;
}
