/*********************************************************************/
/* Author: Dr. Han-Way Huang                                         */
/* Date: 01/31/2005                                                  */
/* Organization: Minnesota State University, Mankato                 */
/*********************************************************************/
#ifndef __DELAY_H
#define __DELAY_H

void delayby50us(int k);       /* time delay computation is based on */
void delayby1ms(int k);	      /* 24 MHz crystal oscillator.         */
void delayby10ms(int k);
void delayby100ms(int k);

#endif
