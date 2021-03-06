/* 7x7 characters
 * Author: Matthew Borneman
 */
#include "hcs12.h"
#include "chars.h"

static const unsigned char mQ_bits[] = {
   0x0c, 0x12, 0x12, 0x12, 0x12, 0x0c, 0x18 };
static const unsigned char m4_bits[] = {
   0x10, 0x18, 0x14, 0x12, 0x3e, 0x10, 0x38 };
static const unsigned char mP_bits[] = {
   0x1e, 0x24, 0x24, 0x24, 0x1c, 0x04, 0x0e };
static const unsigned char mZ_bits[] = {
   0x3e, 0x22, 0x10, 0x08, 0x04, 0x22, 0x3e };
static const unsigned char mB_bits[] = {
   0x1f, 0x22, 0x22, 0x1e, 0x22, 0x22, 0x1f };
static const unsigned char mA_bits[] = {
   0x0c, 0x08, 0x14, 0x14, 0x1c, 0x22, 0x77 };
static const unsigned char mN_bits[] = {
   0x77, 0x26, 0x26, 0x2a, 0x2a, 0x32, 0x37 };
static const unsigned char mJ_bits[] = {
   0x3c, 0x10, 0x10, 0x10, 0x12, 0x12, 0x0c };
static const unsigned char m8_bits[] = {
   0x1c, 0x22, 0x22, 0x1c, 0x22, 0x22, 0x1c };
static const unsigned char mR_bits[] = {
   0x1e, 0x24, 0x24, 0x24, 0x1c, 0x24, 0x4e };
static const unsigned char mW_bits[] = {
   0x77, 0x22, 0x2a, 0x2a, 0x2a, 0x2a, 0x14 };
static const unsigned char m2_bits[] = {
   0x1c, 0x22, 0x10, 0x08, 0x04, 0x02, 0x3e };
static const unsigned char mG_bits[] = {
   0x3c, 0x22, 0x02, 0x02, 0x72, 0x22, 0x1c };
static const unsigned char mK_bits[] = {
   0x77, 0x22, 0x12, 0x0e, 0x12, 0x22, 0x67 };
static const unsigned char mS_bits[] = {
   0x2c, 0x32, 0x02, 0x1c, 0x20, 0x22, 0x1e };
static const unsigned char m0_bits[] = {
   0x1c, 0x22, 0x22, 0x22, 0x22, 0x22, 0x1c };
static const unsigned char mE_bits[] = {
   0x3e, 0x24, 0x14, 0x1c, 0x14, 0x24, 0x3e };
static const unsigned char m3_bits[] = {
   0x1c, 0x22, 0x20, 0x18, 0x20, 0x22, 0x1c };
static const unsigned char mH_bits[] = {
   0x77, 0x22, 0x22, 0x3e, 0x22, 0x22, 0x77 };
static const unsigned char m6_bits[] = {
   0x38, 0x04, 0x02, 0x1e, 0x22, 0x22, 0x1c };
static const unsigned char mU_bits[] = {
   0x77, 0x22, 0x22, 0x22, 0x22, 0x22, 0x1c };
static const unsigned char mL_bits[] = {
   0x0e, 0x04, 0x04, 0x04, 0x24, 0x24, 0x3e };
static const unsigned char mT_bits[] = {
   0x3e, 0x2a, 0x08, 0x08, 0x08, 0x08, 0x1c };
static const unsigned char m7_bits[] = {
   0x3e, 0x22, 0x20, 0x10, 0x10, 0x08, 0x08 };
static const unsigned char mD_bits[] = {
   0x0f, 0x12, 0x22, 0x22, 0x22, 0x12, 0x0f };
static const unsigned char m1_bits[] = {
   0x0c, 0x08, 0x08, 0x08, 0x08, 0x08, 0x3e };
static const unsigned char mI_bits[] = {
   0x3e, 0x08, 0x08, 0x08, 0x08, 0x08, 0x3e };
static const unsigned char mY_bits[] = {
   0x77, 0x22, 0x14, 0x08, 0x08, 0x08, 0x1c };
static const unsigned char mM_bits[] = {
   0x77, 0x36, 0x36, 0x2a, 0x22, 0x22, 0x77 };
static const unsigned char mC_bits[] = {
   0x3c, 0x22, 0x02, 0x02, 0x02, 0x22, 0x1c };
static const unsigned char m9_bits[] = {
   0x1c, 0x22, 0x22, 0x3c, 0x20, 0x10, 0x0e };
static const unsigned char mF_bits[] = {
   0x3e, 0x24, 0x14, 0x1c, 0x14, 0x04, 0x0e };
static const unsigned char mV_bits[] = {
   0x77, 0x22, 0x22, 0x12, 0x14, 0x14, 0x0c };
static const unsigned char mX_bits[] = {
   0x63, 0x22, 0x14, 0x08, 0x14, 0x22, 0x63 };
static const unsigned char m5_bits[] = {
   0x3c, 0x04, 0x04, 0x1c, 0x20, 0x22, 0x1c };
static const unsigned char mO_bits[] = {
   0x1c, 0x22, 0x22, 0x22, 0x22, 0x22, 0x1c };

const unsigned char * FLAT_FAR get_char_bits(char c)
{
   switch(c)
   {
   case 'Q':
      return mQ_bits;
   case '4':
      return m4_bits;
   case 'P':
      return mP_bits;
   case 'Z':
      return mZ_bits;
   case 'B':
      return mB_bits;
   case 'A':
      return mA_bits;
   case 'N':
      return mN_bits;
   case 'J':
      return mJ_bits;
   case '8':
      return m8_bits;
   case 'R':
      return mR_bits;
   case 'W':
      return mW_bits;
   case '2':
      return m2_bits;
   case 'G':
      return mG_bits;
   case 'K':
      return mK_bits;
   case 'S':
      return mS_bits;
   case '0':
      return m0_bits;
   case 'E':
      return mE_bits;
   case '3':
      return m3_bits;
   case 'H':
      return mH_bits;
   case '6':
      return m6_bits;
   case 'U':
      return mU_bits;
   case 'L':
      return mL_bits;
   case 'T':
      return mT_bits;
   case '7':
      return m7_bits;
   case 'D':
      return mD_bits;
   case '1':
      return m1_bits;
   case 'I':
      return mI_bits;
   case 'Y':
      return mY_bits;
   case 'M':
      return mM_bits;
   case 'C':
      return mC_bits;
   case '9':
      return m9_bits;
   case 'F':
      return mF_bits;
   case 'V':
      return mV_bits;
   case 'X':
      return mX_bits;
   case '5':
      return m5_bits;
   case 'O':
      return mO_bits;
   default:
      return 0;
   }
}
