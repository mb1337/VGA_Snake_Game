/*
 * random.c
 *
 *  Created on: Dec 7, 2012
 *      Author: Matthew Borneman
 */
#define MAX_VAL 1200U
#define P1      53U
#define P2      491U
static unsigned int seed = 7;

#include "random.h"

/*
 * Set the seed for random number generation
 */
void FLAT_FAR seedRand(unsigned int s)
{
   seed = s;
}

/*
 * Get next random number in sequence
 */
int FLAT_FAR rand(void)
{
   seed = (P1 + seed * P2) % MAX_VAL;
   return seed;
}
