/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 75: Malloc Up A Two Dimensional Array               */
/*                                                             */
/* Approximate completion time: 35 minutes                     */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] ) {

  int *x, r, c, i, j, sum = 0 ;

  printf( "Please enter a value for r (rows) followed by a space and a value for c (columns).\n" ) ;

  scanf( "%d %d", &r, &c ) ;

  x = ( int * ) malloc( sizeof( int ) * r * c ) ; 

  for( i = 0 ; i < r ; i++ ) {

    for( j = 0 ; j < c ; j++ ) {

      x[ i * c + j ] = 6 ; 

      sum = sum + x[ i * c + j ] ;

    } 

  }

  printf( "The sum of all the sixes in the arrays is: %d .", sum ) ; 

  return  0 ;

}

