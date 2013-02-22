/************************************************************************/
/* This file contains functions to convert from integer and long integer*/
/* to ascii string and from ascii string to binary values.              */
/* Author: Dr. Han-Way Huang.                                           */
/* Organization: Minnesota State University, Mankato                    */
/* Date:   July 8, 2004                                                 */
/************************************************************************/
/************************************************************************/
/* This function convert an alphabetic string to its equivalent binary  */
/* representation in 16 bits.                                           */
/************************************************************************/
#if 0
int alpha2int(char *ptr)
{
    int temp;
    temp = 0;
    while(*ptr) {
         temp = temp * 10 + *ptr - 0x30;
         ptr++;
    }
    return temp;
}
#endif
/************************************************************************/
/* This function convert an alphabetic string to its equivalent binary  */
/* representation in 32 bits.                                           */
/************************************************************************/
#if 0
long alpha2long(char *ptr)
{
     long temp;
     temp = 0;
     while(*ptr) {
         temp = temp * 10 + *ptr - 0x30;
         ptr++;
     }
     return temp;
}
#endif
/*********************************************************************/
/* The following function reverses the  string stored in arr[].      */
/*********************************************************************/
void reverse(char arr[], int k, char sign)
{
    int i, lim, m;
    char temp;

    if (sign) {
       i = 1;
       lim = (k - 1)/2;
     }
     else {
         i = 0;
         lim = k/2;
     }
     m = k - 1;
    while(lim) {
        temp = arr[m];
        arr[m] = arr[i];
        arr[i] = temp;
        m--;
        i++;
        lim--;
    }
}
/************************************************************************/
/* The following function converts the integer xx to an ASCII string    */
/* terminated by a NULL character and stores the string in a buffer     */
/* pointed to by ptr.                                                   */
/************************************************************************/
int int2alpha(int xx, char arr[])
{
    char  cnt;
    char  sign;
    sign = 0;     /* the value xx is positive */
    cnt = 0;      /* initialize digit count to 0 */
    
    if (xx == 0) {
        arr[0] = 0x30;
        arr[1] = 0;
        return 0;
    }
    else if (xx < 0) {
        sign = 1;
        xx = ~xx + 1;
        cnt = 1;
        arr[0] = 0x2D;  /* minus sign */
    }
    while (xx) {
        arr[cnt] = xx % 10 + 0x30;
        xx /= 10;
        cnt++;
    }
    arr[cnt] = 0;
    reverse(arr,cnt,sign);
    return 0;
}
/*************************************************************************/
/* The following function convert a 32-bit integer into an ASCII string. */
/*************************************************************************/
#if 0
int long2alpha(long xx, char arr[])
{
    char  cnt;
    char  sign;
    sign = 0;     /* the value xx is positive */
    cnt = 0;      /* initialize digit count to 0 */

    if (xx == 0) {
        arr[0] = 0x30;
        arr[1] = 0;
        return 0;
    }
    else if (xx < 0) {
        sign = 1;
        xx = ~xx + 1;
        cnt = 1;
        arr[0] = 0x2D;  /* minus sign */
    }
    while (xx) {
        arr[cnt] = xx % 10 + 0x30;
        xx /= 10;
        cnt++;
    }
    arr[cnt] = 0;
    reverse(arr,cnt,sign);
    return 0;
}
#endif
