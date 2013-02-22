/*
 * input.h
 *
 *  Created on: Dec 5, 2012
 *      Author: Matthew Borneman
 */

#ifndef __INPUT_H
#define __INPUT_H
#include "hcs12.h"

#define LEFT    0
#define RIGHT   1
#define DOWN    2
#define UP      3
#define stopSound() PWME = 0

void FLAT_FAR initInput(void (*callback)(int));
void FLAT_FAR resetDirection(int dir);
void INTERRUPT input_isr(void);
int FLAT_FAR get_direction(void);

#endif
