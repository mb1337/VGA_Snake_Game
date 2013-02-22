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
#include "colors.h"

#define MAX_LEN      256
#define MAX_TRAPS    256
#define START_LEN    8
#define START_TRAPS  16

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
void FLAT_FAR eat_apple(void);
void FLAT_FAR do_nothing(void);
void FLAT_FAR clearBuffer(char * buf);
void FLAT_FAR display_menu(void);
void FLAT_FAR draw_start(char * buf);
void FLAT_FAR draw_death(char * buf);

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
   unsigned char x,y;
} typedef position_t;

/*
 * position macros
 */
#define BUF_POS(pos)    ((((unsigned int)(pos).y) * WIDTH) + (pos).x)
#define EQUALS(p1,p2)   (((p1).x == (p2).x) && ((p1).y == (p2).y))

char FLAT_FAR collides(position_t p);
void FLAT_FAR find_position(position_t * p);

static position_t trap_pos[MAX_TRAPS];

static position_t pos[MAX_LEN];
static int start = 0;

static position_t apple_pos = {-1,-1};

static char vid_bufA[BUF_LEN] = {0};
static char vid_bufB[BUF_LEN] = {0};

/*
 * Snake Game main loop
 */
int main(void)
{
   int i,toggle = 0;
   initInput(&btnPress);
   set_max_rand(BUF_LEN);
   openLCD();
   clearBuffer(vid_bufA);
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
         set_vid_ptr(vid_bufB);
         draw(vid_bufA);
      }
      else
      {
         set_vid_ptr(vid_bufA);
         draw(vid_bufB);
      }

      toggle = !toggle;

      while( time_ov < 5 ); // wait until timer overflows 5 times
      time_ov = 0;          // for a ~220ms loop period
   }
   return 0;
}

void FLAT_FAR display_menu(void)
{
   clearLCD();
   putsLCD("VGA Snake Game");
   newlineLCD();
   delayby10ms(1);
   putsLCD("Press <- to start");
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

   switch(collides(pos[start]))
   {
   case 0:
      do_nothing();
      break;
   case 1:
      eat_apple();
      break;
   case 2:
      die();
      break;
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

void FLAT_FAR eat_apple(void)
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

void FLAT_FAR do_nothing(void)
{
   playGameSound();
   delayby10ms(5);
   stopSound();
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
   buf[BUF_POS(apple_pos)] = RED;
   for(j = 0,k = start; j < len; j++)
   {
      buf[BUF_POS(pos[k])] = GREEN;
      k = (k + 1) % MAX_LEN;
   }
   for(j = 0; j < traps; j++)
   {
      buf[BUF_POS(trap_pos[j])] = VIOLET;
   }
}

void FLAT_FAR draw_start(char * buf)
{

}

void FLAT_FAR draw_death(char * buf)
{

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
 * 0 -- No collision
 * 1 -- Apple
 * 2 -- Deadly Object
 */
char FLAT_FAR collides(position_t p)
{
   int j,k;
   if(EQUALS(p,apple_pos))
      return 1;
   for(j = 1,k = (start + 1) % MAX_LEN; j < len; j++)
   {
      if(EQUALS(p,pos[k]))
         return 2;
      k = (k + 1) % MAX_LEN;
   }
   for(j = 0; j < traps; j++)
   {
      if(EQUALS(p,trap_pos[j]))
         return 2;
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
