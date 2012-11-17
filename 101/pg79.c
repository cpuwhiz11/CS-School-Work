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
    
    printf( " %d", x[ i ]  ) ;
  
  }

  printf( "\n" ) ;

  while( 1 ) { 

    if( ( x[ 0 ] == x[ 1 ] ) && ( x[ 0 ] == x[ 2 ] ) && ( x[ 0 ] == x[ 3 ] ) ) break ;  

    temp = x[ 0 ] ; 

    x[ 0 ] = abs( x[ 0 ] - x[ 1 ] ) ; 

    x[ 1 ] = abs( x[ 1 ] - x[ 2 ] ) ;

    x[ 2 ] = abs( x[ 2 ] - x[ 3 ] ) ;

    x[ 3 ] = abs( x[ 3 ] - temp ) ;

    for( i = 0 ; i < 4 ; i++ ) {

      printf( " %d", x[ i ] ) ;

    }

    printf( "\n" ) ;

  }

  fclose( fin ) ;

  return  0 ;

}

