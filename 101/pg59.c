/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 59: Goldbach's Conjecture                           */
/*                                                             */
/* Approximate completion time: 35 minutes                     */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

int i, j ;

int prime( int x ) {

  int k, count = 0 ;

  if( ( x == 0 ) || ( x == 1 ) ) return 0 ;

  for( k = x ; k > 0 ; k-- ) {
  
    if( ( x % k ) == 0 ) count++ ;
  
  }

  return( count == 2 ) ; 
  
}

int goldbach( int start, int finish ) {

  for( i = 0 ; i <= finish ; i++ ) {

    for( j = 0 ; j <= finish ; j++ ) {

      if( ( start == ( i + j ) ) && ( 1 == prime( i ) ) && ( 1 == prime( j ) ) ) return 0 ;

    }

  }

  return 0 ;

}

int main( int argc, char *argv[] ) {

  int start, finish ; 
  start = atoi( argv[ 1 ] ) ;
  finish = atoi( argv[ 2 ] ) ;

  while( 1 ) {

    goldbach( start, finish ) ;
    if( ( start == ( finish + 2 ) ) ) break ; 
    printf( "\n%d = %d + %d", start, i, j ) ;
    start = start + 2 ; 
  }

  
  return  0 ;
}

