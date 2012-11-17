/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 53: Close Enough for All Practical Purposes         */
/*                                                             */
/* Approximate completion time: 50 minutes                     */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double square( double n, double acc ) {

  double  x = 1.0 ; 

  while ( ( fabs( ( x * x ) - n ) > acc )) {
 
    x = ( ( .5 ) * ( x + ( n / x ) ) ) ;
   
  }

  return x ; 

}

int main( int argc, char *argv[] ) {

  double n, acc, ans ;

  n = atof( argv[ 1 ] ) ;

  acc = atof( argv[ 2 ] ) ;

  printf( "\nThe value you are testing is %lf.", n ) ;

  printf( "\nThe accuracy you are testing to is %lf.", acc ) ;

  ans = square( n, acc ) ;

  printf( "\nThe square root of %lf is %lf.\n", n, ans ) ;

  return  0 ;
}

