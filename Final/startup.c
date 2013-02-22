#include "hcs12.h"

/*
 * The crystal freq. on the DRAGON12 board (Rev D or E MC689S12DP256) is 4 MHz 
 * so the default bus speed is 2 MHz.
 * 
 * In order to set the bus speed high than 2 MHz the PLL must be initialized
 * The math used to set the PLL frequency is:
 * PLLCLK = CrystalFreq * 2 * (initSYNR+1) / (initREFDV+1)
 * If CrystalFreq = 4Mhz on DRAGON12 board
 *   initSYNR     = 5    PLL multiplier will be 6
 *   initREFDV    = 0    PLL divisor will be 1
 * PLLCLK = 4*2*6/1 = 48MHz
 * 
 * The bus speed = PLLCLK / 2 = 24 MHz
 */

void __attribute__((near)) __premain (void);
void __attribute__((near)) __premain (void)
{
  // in case special mode enabled, avoid conflict on PORTE
  PEAR |= NECLK;

  // bgnd mode stops COP and RTI clocks
  COPCTL = RSBCK;

  // stops TCNT counter when debugging stops
  TSCR1 |= (1<<5);			// TFRZ

  // PLL
  CLKSEL = 0;				// Disable PLL to configure

  // xtal 16MHz, bus 24MHz
  SYNR  = 5;
  REFDV = 0;
  while (!(CRGFLG & 0x08))	// Wait for PLL LOCK
    {
      ARMCOP = 0x55;
      ARMCOP = 0xAA;
    }
  CLKSEL |= 0x80;			// Use PLL

  // init switch inputs
  PERH = 0xff;				// Pullups
}
