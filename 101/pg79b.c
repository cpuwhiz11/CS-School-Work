/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 79: Fun With Subtraction                            */
/*                                                             */
/* Approximate completion time: 30 minutes                     */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] ) {

  int x[4], i, temp ;

  FILE * fin ;

  fin = fopen( argv[ 1 ], "r" ) ;
  
  for( i = 0 ; i < 4 ; i++ ) {
 
    fscanf( fin, "%d", &x[ i ] ) ;
  
  }

  do {

    temp = x[ 0 ] ; 

    x[ 0 ] = abs( x[ 0 ] - x[ 1 ] ) ; 

    x[ 1 ] = abs( x[ 1 ] - x[ 2 ] ) ;

    x[ 2 ] = abs( x[ 2 ] - x[ 3 ] ) ;

    x[ 3 ] = abs( x[ 3 ] - temp ) ;

    for( i = 0 ; i < 4 ; i++ ) {
      if( ( x[ i ] == 0 ) && ( x[ i + 1 ] == 0 ) && ( x[ i + 2 ] == 0 ) && ( x[ i + 3 ] == 0 ) ) break ;
      printf( " %d", x[ i ] ) ;

    }

    printf( "\n" ) ;

  }  
  
  while( ( x[ 0 ] != 0 ) && ( x[ 0 ] != 0 ) && ( x[ 0 ] != 0 ) ) ;
  

  fclose( fin ) ;

  return  0 ;

}

