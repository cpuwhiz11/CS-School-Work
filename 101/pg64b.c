/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program #:                                                  */
/*                                                             */
/* Approximate completion time: X minutes                      */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] ) {
  int i , j, **array, **narray ; 

  array = ( int**) malloc( sizeof( int ) * 3) ;

  narray = ( int** ) malloc( sizeof( int ) * 3 ) ;   

  for( i = 0; i < 3 ; i++ ) {

    array[ i ] = ( int * ) malloc( sizeof( int ) * 3 ) ;
    narray[ i ] = ( int * ) malloc( sizeof( int ) * 3 ) ; 
  }

  for( i = 2 ; i >= 0 ; i-- ) {

    for( j = 0 ; j < 3 ; j++ ) {

      narray[j][3-i] = array[i][j] + i ;

      printf( " %d", narray[j][3-i] ) ;

    }

    printf( "\n" ) ;

  }

  return  0 ;
}

