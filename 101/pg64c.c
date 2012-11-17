/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 64: Square Deal                                     */
/*                                                             */
/* Approximate completion time: 200 minutes                    */
/***************************************************************/
#include <stdio.h>

#include <stdlib.h>

int n, x, y, i ; 

int prime( int n ) {

  int k = 0 ;

  if( n == 0 ) return 0 ;

  for( i = 1 ; i <= n ; i++ ) {

    if( ( n % i ) == 0 ) k++ ;

  }

  return ( k == 2 ) ; 

}

int mover( int **odd, int count ) {

  for( i = 0 ; i < count ; i++ ) {

    n++ ;

    y++ ;

    odd[ x ][ y ] = n ;

  } 

  return 0 ;

}

int movel( int **odd, int count ) {

  for( i = 0 ; i < count ; i++ ) {
  
    n++ ;

    y-- ;

    odd[ x ][ y ] = n ;
  
  }

  return 0 ;

}

int moveu( int **odd, int count ) {

  for( i = 0 ; i < count ; i++ ) {

    n++ ;

    x-- ;

    odd[ x ][ y ] = n ;
  
  }

  return 0 ;

}

int moved( int **odd, int count ) { 

  for ( i = 0 ; i < count ; i++ ) {
  
    n++ ;

    x++ ;

    odd[ x  ][ y ] = n ;

  }

  return 0 ; 

}
int squared( int **odd, int size ) {

  int count = 1, mid ;

  mid = size / 2 ; 

  x = mid ;

  y = mid ; 

  odd[ x ][ y ] = n ; 

  while( count < size ) {

    mover( odd, count ) ;

    moveu( odd, count ) ; 

    count++ ;

    movel( odd, count ) ;

    moved( odd, count ) ;

    count++ ;

  }

  mover( odd, ( size - 1 ) ) ;

  return 0 ; 

}

int main( int argc, char *argv[] ) {

  int **odd, size, i, j ;

  printf( "Please enter an odd integer from 3 - 15 for the size of a square array. " ) ;

  scanf( "%d", &size ) ;

  if( ( size < 3 ) || ( size > 15 ) || ( ( size % 2 ) == 0 ) ) {

    printf( "You must enter a number that fulfills the requirements." ) ;

    return 0 ;

  }

  printf( "Please enter a number for the intial value." ) ;

  scanf( "%d", &n ) ;
  
  if( ( size + n ) * ( size + n ) > 1000 ) {

    printf( "The values you entered are too big." ) ;

    return 0 ;

  }

  odd = ( int ** ) malloc( sizeof( int ) * size ) ;
  
  for( i = 0 ; i < size ; i++ ) {

    odd[ i ] = ( int * ) malloc( sizeof( int ) * size ) ;
  
  }

  squared( odd, size ) ;

  for( i = 0 ; i < size ; i++ ) {

    for( j = 0 ; j < size ; j++ ) {

      if( prime( odd[ i ][ j ] ) == 0 ) {

	printf( " ***" ) ;

	}

	else printf( "  %d", odd[ i ][ j ] ) ;

    }

    printf( "\n" ) ;

  }

  return  0 ;

}

