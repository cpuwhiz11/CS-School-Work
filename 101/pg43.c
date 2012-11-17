/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 43: Recursive Factorial                             */
/*                                                             */
/* Approximate completion time: 25 minutes                     */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

int fact ( int x ) {

  int factx = 1 ;

  if ( ( x == 1 ) || ( x == 0 ) ) return 1 ; 

  return factx = x * ( fact( x - 1 ) ) ; 

}

int main( int argc, char *argv[] ) {

  int x, factx ;

  x = ( atoi( argv[ 1 ] ) ) ; 

  factx = fact( x ) ;

  printf( "The factorial of %d is %d.", x, factx ) ;

  return  0 ;

}

