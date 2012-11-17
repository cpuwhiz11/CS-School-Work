/*******************************************************************************/
/* Programmer: Mark Field                                                      */
/*                                                                             */
/* Program 64: Square Deal                                                     */
/*                                                                             */
/* Approximate completion time: x minutes                                      */
/*******************************************************************************/

#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

/*
int isPrime( int n ) {

  int i , limit ;

  if( n <= 1 ) return 0 ;

  if( n == 2 ) return 1 ;

  if( !( n % 2 ) ) return 0 ;

  limit = sqrt( (double) n ) + 1 ;

  for( i = 3 ; i <= n; i+=2 ) if( ( n % 2 ) == 0 ) return 0 ;

  return 1 ;

}
*/

int CCWFill( int **A , int size , int n ) {

  int x , y , state = 0 , halfsize , i = 1 , count = 1 , plan = 1 , j , k = 0 ;

  halfsize = size / 2 ;

  A[halfsize][halfsize] = n ;

  x = halfsize ;

  y = halfsize ;

  for( k = 0; k < size; k++ ) {

    if( state == 0 ) {

      for( i = 0; i < plan; i++ ) {

	if( plan % 2 == 0 ) x-- ;

	else x++ ;
	
	A[x][y] = n + count ;
 
	count++ ;

	state = 1 ;

      }

    }
      
    if( state == 1 ) {

      for( j = 0; j < plan; j++ ) {

	if( plan % 2 == 0 ) y++ ;

	else y-- ;

	A[x][y] = n + count ;

	count++ ;

	state = 0 ;

      }

    }

    plan++ ;

  }

  return 0 ;

}

int main( int argc , char *argv[] ) {
  
  int x , size , i , j , **A ;

  printf( "\nEnter the size of the square (between 3 and 15): " ) ;

  scanf( "%d" , &size ) ;

  printf( "\nEnter an initial value: " ) ;

  scanf( "%d" , &x ) ;

  if( ( x * x + size * size ) >= 1000 ) {

    printf( "\nThe value of the two numbers squared must be less than 1000.\n" ) ;

    printf( "\nEnter the size of the square (between 3 and 15): " ) ;

    scanf( "%d" , &size ) ;

    printf( "\nEnter an initial value: " ) ;

    scanf( "%d" , &x ) ;

  }

  printf( "\ni = %d , n = %d\n" , x , size ) ;

  A = (int **)malloc( sizeof(int *) * size ) ;

  for( i = 0; i < size; i++ ) A[i] = (int *)malloc( sizeof( int ) * size ) ;

  CCWFill( A , size , x ) ; 

  for( i = 0; i < size; i++ ) {

    for( j = 0; j < size; j++ ) {

      printf( "%d " , A[j][i] ) ;

    }

    printf( "\n" ) ;

  }

  return 0 ; 

}
