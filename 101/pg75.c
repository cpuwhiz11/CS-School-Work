/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 75: Malloc Up A Two Dimensional Array               */
/*                                                             */
/* Approximate completion time: 25 minute                      */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] ) {

  int **x, r, c, i, j ;

  printf( "Please enter a value for r (rows) followed by a space and a value for c (columns).\n" ) ;

  scanf( "%d %d", &r, &c ) ;

  x = ( int ** ) malloc( sizeof( int * ) * r ) ;

  for( i = 0 ; i < r ; i++ ) {

    x[ i ] = ( int * ) malloc( sizeof ( int ) * c ) ; 

  }

  for( i = 0 ; i < r ; i++ ) {

    for( j = 0 ; j < r ; j++ ) {

      x[ i ][ j ] = i + j ; 

      printf( " %d", x[ i ][ j ] ) ; 

    }

  } 

  return  0 ;

}

