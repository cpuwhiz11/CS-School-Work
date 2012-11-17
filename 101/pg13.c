/***************************************************************/
/* Programmer: Paul Matthew Geromini                           */
/*                                                             */
/* Program 13: The abs Function                                */
/*                                                             */
/* Approximate completion time: 12 minutes                     */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] ) {

  int x ;

  printf( "\nPlease enter a number.\n" ) ;

  scanf( "%d", &x ) ;

  printf( "\nThe absolute value of your number is: %d.\n\n", abs( x ) ) ; 

  return  0 ;

}

