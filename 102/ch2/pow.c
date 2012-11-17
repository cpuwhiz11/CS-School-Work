/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program : Power                                             */
/*                                                             */
/* Approximate completion time: 25 minutes                     */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

double power( double x, int n ) {

  if( n == 0 ) return( 1 ) ;

  else return( x * power( x, ( n - 1 ) ) ) ;

  return 0 ;

}

int main( int argc, char *argv[] ) {

  double ans ;
  int n, x ;

  n = atoi( argv[ 1 ] ) ;
  x = atoi( argv[ 2 ] ) ; 
 
  ans = power( x, n ) ; 

  printf( "The number %d raised to %d is %lf.", x, n, ans ) ;

  return  0 ;

}

