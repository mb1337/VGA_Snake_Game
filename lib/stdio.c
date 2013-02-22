/******************************************************************/
/* This file contains six functions that either input or output   */
/* a single character or a string from the SCI0 port.             */
/* Author: Dr. Han-Way Huang                                      */
/* Organization: Minnesota State University, Mankato              */
/* Date:   July 8, 2004                                           */
/******************************************************************/
#include "hcs12.h"
// -----------------------------------------------------------------
// This function configure UART0 to operate at 9600 baud
// -----------------------------------------------------------------
void openSCI0(void)
{
     SCI0BDH = 0;
     SCI0BDL = 156;
     SCI0CR1 = 0x4C;
     SCI0CR2 = 0x0C;
}
/*****************************************************************/
/* The following function uses the polling method to output a    */
/* character to the SCI0 port.                                   */
/*****************************************************************/
int putch(char cx)
{
    while(!(SCI0SR1 & TDRE))
       continue;
    SCI0DRL = cx;
    return 0;
}
/*****************************************************************/
/* The following function outputs a NULL-terminated string       */
/* pointed to by cptr. The string is stored in program memory    */
/*****************************************************************/
int puts(char *cptr)
{
    while(*cptr) {
        putch(*cptr);
        cptr++;
    }
    return 0;
}
/*******************************************************************/
/* The following function outputs a carriage return and a linefeed */
/* to move the cursor to the first column of the next row.         */
/*******************************************************************/
int newline(void)
{
     putch(0x0D);
     putch(0x0A);
     return 0;
}

/******************************************************************/
/* The following function uses polling method to read a character */
/* from SCI0 port.                                                */
/******************************************************************/
char getch(void)
{
     while(!(SCI0SR1 & RDRF));
     return SCI0DRL;
}
/******************************************************************/
/* The following function reads a string from the SCI0 port by    */
/* calling the getch function until the CR character is reached   */
/******************************************************************/
int gets(char *ptr)
{
       char cx;
       while ((cx = getch()) != 0x0D) {
               *ptr++ = cx;
               putch(cx);
               if (cx == 0x08) { //is it a backspace character?
                       ptr--; // move back the string pointer
                       putch(0x20);// output a space
                       putch(0x08);// output another backspace character
               }
       }
       *ptr    = 0; // terminate the string with a NULL character
       return 0;
}

