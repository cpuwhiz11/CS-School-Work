/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 64: Square Deal                                     */
/*                                                             */
/* Approximate completion time: X minutes                      */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

int prime( int x ) {

  int i, code = 0 ;

  for( i = ( x - 1 ) ; i > 0 ; i-- ) {

    if( ( x % i ) == 0 ) code++ ;

  }

  if( code == 1 ) return 1 ; 

  else return 0 ; 

}



int squared( int **odd, int in, int size ) {

  int i = 0, j, x, y, plan = 1, count = 1, k = 2,  mid, state = 0 ;

  mid = size / 2 ;

  odd[ mid ][ mid ] = in ;
  
  x = mid ;
  y = mid ;

  while( k < size ) {

    if( state == 0 ) {
      for( i = 0 ; i < plan ; i++ ) {
	if( ( plan % 2 ) == 0 ) y = y - plan ;
	else y = y + plan ; 
	odd[ y ][ x ] = in + count ;
	count++ ;
	state = 1 ;
      } 
    }
    if( state == 1 ) {
      for( j = 0 ; j < plan ; j++ ) {
	if( plan % 2 == 0 ) x = x + plan ;
	else x = x - plan ;
	odd[ y ][ x ] = in + count ;
	count++ ; 
	state = 0 ; 
      }
    }
    plan++ ;
    k++ ;
  }
  for( i = 0 ; i < size ; i++ ) {
    odd[ i ][ size - 1 ] = in + count ;
    count++ ;
  }

  return 0 ;
}
int main( int argc, char *argv[] ) {

  int **odd, n, temp, i, j ;

  printf( "Please enter an odd integer from 3 - 15 for the size of a square array. " ) ;
  scanf( "%d", &temp ) ;

  if( ( temp < 3 ) || ( temp > 15 ) || ( ( temp % 2 ) == 0 ) ) {
    printf( "You must enter a number that fulfills the requirements." ) ;
    return 0 ;
  }

  printf( "Please enter a number for the intial value." ) ;
  scanf( "%d", &n ) ;
  
  if( ( temp + n ) * ( temp + n ) > 1000 ) {
    printf( "The values you entered are too big." ) ;
    return 0 ;
  }

  odd = ( int ** ) malloc( sizeof( int ) * temp ) ;
  
  for( i = 0 ; i < temp ; i++ ) {

    odd[ i ] = ( int * ) malloc( sizeof( int ) * temp ) ;
  
  }

  squared( odd, n, temp ) ;

  for( i = 0 ; i < temp ; i++ ) {
    for( j = 0 ; j < temp ; j++ ) {
      printf( " %d", odd[ i ][ j ] ) ;
    }
    printf( "\n" ) ;
  }

  return  0 ;
}

