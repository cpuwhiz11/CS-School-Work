/*

Assignment #4
Paul Geromini

01056543

Based on code from ~bill/cs308/call_help_assign4.txt
*/

#ifndef _MAIN_H
#define _MAIN_H

#include <signal.h>
#include <sys/time.h>
#include <pthread.h>

#define NUMFLAVORS       4
#define NUMSLOTS         26700
#define NUMCONSUMERS     50
#define NUMPRODUCERS     30


struct  donut_ring {
  int     flavor[NUMFLAVORS][NUMSLOTS];
  int     outptr[NUMFLAVORS];
  int     in_ptr[NUMFLAVORS];
  int     serial[NUMFLAVORS];
  int     spaces[NUMFLAVORS];
  int     donuts[NUMFLAVORS];
};

/**********************************************************************/
/* SIGNAL WAITER, PRODUCER AND CONSUMER THREAD FUNCTIONS              */
/**********************************************************************/

void* sig_waiter ( void *arg );
void* producer   ( void *arg );
void* consumer ( void *arg);
void sig_handler ( int );

#endif
