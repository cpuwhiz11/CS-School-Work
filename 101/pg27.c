/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 27: Reverse                                         */
/*                                                             */
/* Approximate completion time: 15 minutes                     */
/***************************************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  int x[ 10 ], i ;

  printf( "Please enter in 10 integers each followed by a space." ) ;  

  for( i = 0 ; i < 10 ; i++ ) {

    scanf( "%d", &x[ i ] ) ;

  }

  for( i = 9 ; i >= 0 ; i-- ) {

    printf( " %d", x[ i ] ) ; 

  }

  return  0 ;

}

