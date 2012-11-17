/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 44: Random Numbers 2                                */
/*                                                             */
/* Approximate completion time: 20 minutes                     */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int myrand( int x ) {

  srand( time( NULL ) ) ;

  x = rand() % 39 + -19 ;

  return x ;

}

int main( int argc, char *argv[] ) {

  int x ;

  x = myrand( x ) ;

  printf( "The randomly generated number this time is: %d.", x ) ;

  return  0 ;

}


