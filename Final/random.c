/*
 * random.c
 *
 *  Created on: Dec 7, 2012
 *      Author: Matthew Borneman
 */
#include "random.h"

#define P1      53U
#define P2      491U

static unsigned int seed = 7;
static unsigned int max_val = 0xFFFFU;

void FLAT_FAR set_max_rand(unsigned int max)
{
   max_val = max;
}

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
unsigned int FLAT_FAR rand(void)
{
   seed = (P1 + seed * P2) % max_val;
   return seed;
}
