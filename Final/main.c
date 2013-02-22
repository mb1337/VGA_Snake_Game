/*
 * main.c
 *  -- VGA Snake Game
 *  Created on: Nov 28, 2012
 *      Author: Matthew Borneman
 */

#include "hcs12.h"
#include "vga.h"
#include "input.h"
#include "convert.h"
#include "delay.h"
#include "lcd_util.h"
#include "random.h"
#include "speaker.h"

#define BLACK  0x00
#define D_GRAY 0x15
#define L_GRAY 0x2A
#define RED    0x03
#define GREEN  0x0C
#define YELLOW (RED|GREEN)
#define BLUE   0x30
#define NAVY   0x10
#define VIOLET (BLUE|RED)
#define CYAN   (BLUE|GREEN)
#define WHITE  0x3C

#define MAX_LEN      128
#define MAX_TRAPS    128
#define START_LEN    5
#define START_TRAPS  10

void INTERRUPT video_isr(void);
void INTERRUPT timer_isr(void);
void FLAT_FAR btnPress(int);
void FLAT_FAR initTimer(void);
void FLAT_FAR draw(char * buf);
void FLAT_FAR update_pos(void);
void FLAT_FAR place_apple(void);
void FLAT_FAR place_trap(void);
void FLAT_FAR check_collisions(void);
void FLAT_FAR restart(void);
void FLAT_FAR die(void);
void FLAT_FAR clearBuffer(char * buf);

static volatile char go = 0;
static volatile char time_ov = 0;
static int dir = LEFT;
static int len = START_LEN;
static int points = 0;
static char traps = 0;

/*
 * Position on screen
 */
struct position_s
{
   int x,y;
} typedef position_t;

char FLAT_FAR collides(position_t p);
void FLAT_FAR find_position(position_t * p);

static position_t trap_pos[MAX_TRAPS];

static position_t pos[MAX_LEN];
static int start = 0;

static position_t apple_pos = {-1,-1};

/*
 * Snake Game main loop
 */
int main(void)
{
   char *bufferA_ptr, *bufferB_ptr;
   int i,toggle = 0;
   initInput(&btnPress);
   openLCD();
   bufferA_ptr = (char*)&bufferA;
   bufferB_ptr = (char*)&bufferB;
   clearBuffer(bufferA_ptr);
   SET_VID_POINTER((unsigned short)bufferA_ptr);
   restart();
   initTimer();
   video_enable();
   asm("cli");
   while(!go);     // Wait until user input
   seedRand(TCNT); // Get a random seed
   place_apple();
   for(i = 0; i < START_TRAPS; i++)
      place_trap();
   time_ov = 0;
   while(1) // Loop period ~220ms
   {
      if(go == 0) // Restart Game
      {
         while(!go);
         restart();
         place_apple();
         for(i = 0; i < START_TRAPS; i++)
            place_trap();
      }

      update_pos();

      /*
       * Double Buffering:
       * Video outputs bufferB while the game updates bufferA
       * and vice versa in order to prevent screen flicker
       */
      if(toggle)
      {
         SET_VID_POINTER((unsigned short)bufferB_ptr);
         draw(bufferA_ptr);
      }
      else
      {
         SET_VID_POINTER((unsigned short)bufferA_ptr);
         draw(bufferB_ptr);
      }

      toggle = !toggle;

      while( time_ov < 5 ); // wait until timer overflows 5 times
      time_ov = 0;          // for a ~220ms loop period
   }
   return 0;
}

/*
 * Restarts world back to start state
 */
void FLAT_FAR restart(void)
{
   int i;
   stopSound();
   start = 0;
   len = START_LEN;
   traps = 0;
   points = 0;
   apple_pos.x = apple_pos.y = -1;
   for(i = start; i < len; i++)
   {
      pos[i].x = 20 + i;
      pos[i].y = 15;
   }
   cmd2LCD(0x01);
   delayby100ms(1);
   putsLCD("Score: 0");
   resetDirection(LEFT);
}

/*
 * Updates the position of the snake
 * and checks collisions on the screen
 */
void FLAT_FAR update_pos(void)
{
   int last_x = pos[start].x,last_y = pos[start].y;
   check_collisions();
   start = (start == 0) ? (MAX_LEN - 1) : (start - 1);
   switch(dir)
   {
   case LEFT:
      if(last_x == 0)
      {
         die();
         break;
      }
      pos[start].x = last_x - 1;
      pos[start].y = last_y;
      break;
   case RIGHT:
      if(last_x == WIDTH - 1)
      {
         die();
         break;
      }
      pos[start].x = last_x + 1;
      pos[start].y = last_y;
      break;
   case UP:
      if(last_y == 0)
      {
         die();
         break;
      }
      pos[start].y = last_y - 1;
      pos[start].x = last_x;
      break;
   case DOWN:
      if(last_y == HEIGHT - 1)
      {
         die();
         break;
      }
      pos[start].y = last_y + 1;
      pos[start].x = last_x;
      break;
   }

}

/*
 * Checks to see if any collisions occurred
 * if so it handles them appropriately
 */
void FLAT_FAR check_collisions(void)
{
   if (pos[start].x == apple_pos.x && pos[start].y == apple_pos.y)
   {
      char pnt[8];
      len += 2;
      place_trap();
      place_trap();
      place_apple();
      points++;
      int2alpha(points,pnt);
      cmd2LCD(0x01);
      playPointSound();
      delayby10ms(5);
      putsLCD("Score: ");
      putsLCD(pnt);
      stopSound();
   }
   else
   {
      if(collides(pos[start]))
      {
         die();
      }
      else
      {
         playGameSound();
         delayby10ms(5);
         stopSound();
      }
   }
}

/*
 * Signifies the end of the game
 */
void FLAT_FAR die(void)
{
   playDeathSound();
   cmd2LCD(0xC0);
   delayby10ms(2);
   putsLCD("You Lose!");
   go = 0;
}

/*
 * Clears a video buffer to black
 */
void FLAT_FAR clearBuffer(char * buf)
{
   int i;
   for(i = 0; i < BUF_LEN; i++)
   {
      buf[i] = D_GRAY;
   }
}


/*
 * Updates the video buffer to display each frame
 */
void FLAT_FAR draw(char * buf)
{
   int j,k;
   clearBuffer(buf);
   buf[(apple_pos.y * WIDTH) + apple_pos.x] = RED;
   for(j = 0,k = start; j < len; j++)
   {
      buf[(pos[k].y * WIDTH) + pos[k].x] = GREEN;
      k = (k + 1) % MAX_LEN;
   }
   for(j = 0; j < traps; j++)
   {
      buf[(trap_pos[j].y * WIDTH) + trap_pos[j].x] = VIOLET;
   }
}

/*
 * Finds a random empty position on the screen and set p to it
 */
void FLAT_FAR find_position(position_t * p)
{
   int r = rand();
   position_t z;
   z.x = r % WIDTH;
   z.y = r / WIDTH;
   while (collides(z))
   {
      seedRand(TCNT);
      r = rand();
      z.x = r % WIDTH;
      z.y = r / WIDTH;
   }
   p->x = z.x;
   p->y = z.y;
}

/*
 * Places an apple in a random empty spot on the screen
 */
void FLAT_FAR place_apple(void)
{
   find_position(&apple_pos);
}

/*
 * Places a trap in a random empty spot on the screen
 */
void FLAT_FAR place_trap(void)
{
   find_position(&trap_pos[traps]);
   traps++;
}

/*
 * Checks to see if p collides with anything on the map
 */
char FLAT_FAR collides(position_t p)
{
   int j,k;
   if(p.x == apple_pos.x && p.y == apple_pos.y)
      return 1;
   for(j = 1,k = (start + 1) % MAX_LEN; j < len; j++)
   {
      if(pos[k].x == p.x && pos[k].y == p.y)
         return 1;
      k = (k + 1) % MAX_LEN;
   }
   for(j = 0; j < traps; j++)
   {
      if(trap_pos[j].x == p.x && trap_pos[j].y == p.y)
         return 1;
   }
   return 0;
}

/*
 * Interrupt routine for video
 * Updates each line on the screen at ~31 kHz for a 60-Hz frame rate
 */
void INTERRUPT video_isr(void)
{
   video_draw();
}

/*
 * Timer interrupt for main loop
 * interrupts every ~44ms
 */
void INTERRUPT timer_isr(void)
{
   time_ov++;
   TFLG2 = 0x80;
}

/*
 * Callback function for when an input occurs
 */
void FLAT_FAR btnPress(int d)
{
   dir = d;
   go = 1;
}

/*
 * Initializes timer for a prescaler of 16
 * so that the timer overflows every ~44ms
 */
void FLAT_FAR initTimer(void)
{
   TSCR2 = 0x84;
   TSCR1 = 0x80;
}
