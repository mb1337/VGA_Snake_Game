#ifndef __LCD_UTIL_H
#define __LCD_UTIL_H

#define clearLCD()   cmd2LCD(0x01);delayby1ms(2)
#define newlineLCD() cmd2LCD(0xC0)

void cmd2LCD(char cmd);
void openLCD(void);
void putcLCD(char cx);
void putsLCD (char *ptr);

#endif
