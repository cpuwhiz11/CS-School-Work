/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 42: Non recursive Factorial                         */
/*                                                             */
/* Approximate completion time: 35 minutes                     */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

int fact ( int x ) {

  int factx = 1,  i ;

  if ( ( x == 1 ) || ( x == 0 ) ) return 1 ; 

  for( i = 1 ; i <= x ; i++ ) {

    factx = factx * i ;

  }

  return factx ; 

}

int main( int argc, char *argv[] ) {

  int x, factx ;

  x = atoi( argv[ 1 ] ) ;

  factx = fact( x ) ;

  printf( "The factorial of %d is %d.", x, factx ) ;

  return  0 ;

}

