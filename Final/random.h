/*
 * random.h
 *
 *  Created on: Dec 6, 2012
 *      Author: Matthew Borneman
 */

#ifndef __RANDOM_H
#define __RANDOM_H
#include "hcs12.h"

void FLAT_FAR seedRand(unsigned int s);
int FLAT_FAR rand(void);

#endif
