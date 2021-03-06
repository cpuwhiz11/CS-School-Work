/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program : Recursive Factorial                               */
/*                                                             */
/* Approximate completion time: 20 minutes                     */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

int factorial( n ) {

  if( n == 0 ) return 1 ;

  else return ( n * factorial( n - 1 ) ) ;

} 


int main( int argc, char *argv[] ) {

  int n, ans ;

  n = atoi( argv[ 1 ] ) ;

  ans = factorial( n ) ;

  printf( "\n%d\n", ans ) ;

  return 0 ;

}


