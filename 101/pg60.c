/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 60: Products of Unequal Primes                      */
/*                                                             */
/* Approximate completion time: X minutes                      */
/***************************************************************/

#include <stdio.h>

int i, j ;

int prime( int x ) {

  int k, cn = 0 ;

  if( ( x == 0 ) || ( x == 1 ) ) return 0 ;
  for( k = x ; k > 0 ; k-- ) {
    if( ( x % k ) == 0 ) cn++ ;
  }
  return( cn == 2 ) ;
}

int unequal( int count ) {

  for( i = 0 ; i <= 500 ; i++ ) {
    for( j = 0 ; j <= 500 ; j++ ) {
      if( ( count == ( i * j ) ) && ( 1 == prime( i ) ) && ( 1 == prime( j ) ) && ( i != j ) ) return 1 ;
    }
  }
  return 0 ;
}

int main( int argc, char *argv[] ) {

  int temp, count = 300 ;

  while( 1 ) {

    if( count == 501 ) break ; 
    temp = unequal( count ) ;
    if( temp == 1 ) printf( "\n%d = %d * %d", count, i, j ) ;
    count++ ;

  }


  return  0 ;
}

