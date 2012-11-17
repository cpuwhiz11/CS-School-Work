/***************************************************************/
/* Programmer: Mark Field                                      */
/*                                                             */
/* Program 13: The abs Function                                */
/*                                                             */
/* Approximate completion time: 15 minutes                     */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] ) {

  int x ; 

  x = atoi( argv[ 1 ] );

  printf( "\n\nThe absolute value of %d is %d.\n\n", x , abs( x ) ) ;

  return  0 ;

}

