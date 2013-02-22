/*********************************************************************/
/* Author: Dr. Han-Way Huang                                         */
/* Date: 01/31/2005                                                  */
/* Organization: Minnesota State University, Mankato                 */
/*********************************************************************/
/* The following function creates a time delay which is equal to the */
/* multiple of 50 us. The value passed in Y specifies the number of  */
/* milliseconds to be delayed.                                       */
/*********************************************************************/

#include "hcs12.h"

void delayby50us(int k)
{
asm(
"delayby50usASM:\n"
        "ldx    #60\n"
"loop1:  psha\n"
        "pula\n"
        "psha\n"
        "pula\n"
        "psha\n"
        "pula\n"
        "psha\n"
        "pula\n"
        "dbne    x,loop1\n"
        "dbne    d,delayby50usASM\n"
        "rts\n"
);
}

/**********************************************************************/
/* The following function creates a time delay which is equal to the  */
/* multiple of 1 ms. The value passed in Y specifies the number of one*/
/* milliseconds to bdelayed.                                          */
/**********************************************************************/
void delayby1ms(int k)
{
asm(
"delayby1msASM:\n"
        "ldx    #600\n"
"loop2:  psha\n"
        "pula\n"
        "psha\n"
        "pula\n"
        "psha\n"
        "pula\n"
        "psha\n"
        "pula\n"
        "psha\n"
        "pula\n"
        "psha\n"
        "pula\n"
        "psha\n"
        "pula\n"
        "psha\n"
        "pula\n"
        "dbne    x,loop2\n"
        "dbne    d,delayby1msASM\n"
        "rts\n"
);
}

/**********************************************************************/
/* The following function creates a time delay which is equal to the  */
/* multiple of 10 ms. The value passed in Y specifies the number of   */
/* one milliseconds to be delayed.                                    */
/**********************************************************************/
void delayby10ms(int k)
{
asm(
"delayby10msASM:\n"
        "ldx    #600\n"
"loop3:  psha\n"
        "pula\n"
        "psha\n"
        "pula\n"
        "psha\n"
        "pula\n"
        "psha\n"
        "pula\n"
        "psha\n"
        "pula\n"
        "psha\n"
        "pula\n"
        "psha\n"
        "pula\n"
        "psha\n"
        "pula\n"
        "dbne    x,loop3\n"
        "dbne    d,delayby10msASM\n"
        "rts\n"
);
}

