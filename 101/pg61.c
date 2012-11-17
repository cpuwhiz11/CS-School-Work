/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 61: Number Puzzle                                   */
/*                                                             */
/* Approximate completion time: X minutes                      */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

int selectionsort( int *A, int n ) {

  int i, j, min_index, temp ; 

  for( i = 0 ; i < ( n - 1 ) ; i++ ) {

    min_index = i ; 

    for( j = ( i + 1 ) ; j < n ; j++ ) {

      if( A[ j ] < A[ min_index ] ) min_index = j ; 

    }

    temp = A[ i ] ;

    A[ i ] = A[ min_index ] ; 

    A[ min_index ] = temp ; 

  }

  return 0 ; 

}


int sorter( int *x, int *ans, int n ) {

  int i, j, *temp, count = 0, larg = 0 ;

  for( i = 0 ; i < n ; i++ ) {
    if( x[ i ] > larg ) larg = x[ i ] ; 
  }

  temp = ( int * ) malloc( sizeof( int ) * n ) ;

  for( i = 1 ; i <= n ; i++ ) {
    if( x[ i - 1 ] != i ) {
      for( j = 1 ; j <= larg ; j++ ) {
	if( x[ i - 1 ] == j ) {
	  if( j > n ) temp[ i - 1 ] = j ;
	  else ans[ j - 1 ] = j ;
	} 
      }
    }
    else ans[ i - 1 ] = x[ i - 1 ] ; 
  }

  selectionsort( temp, n ) ;

  for( i = 0 ; i < n ; i++ ) {
    if( ans[ i ] == 0 ) {
      for( j = count ; j < n ; j++ ) {
	if( temp[ j ] > 0 ) {
	  ans[ i ] = temp[ j ] ;
	  count = j + 1 ; 
	  break ; 
	}
      }     
    }
  }
  
  return 0 ; 
}

int main( int argc, char *argv[] ) {

  int n, *x, i, *ans ;
  FILE *fin ;
  fin = fopen( argv[ 1 ], "r" ) ;
 
  fscanf( fin, "%d" ,&n ) ;
  x = ( int * ) malloc( sizeof( int ) * n ) ;
  ans = ( int * ) malloc( sizeof( int ) * n ) ;

  printf( "\nThe numbers in question are.\n" ) ;

  for( i = 0 ; i < n ; i++ ) {
    fscanf( fin, "%d", &x[ i ] ) ;
    printf( " %d" , x[ i ] ) ;
    ans[ i ] = 0 ; /* might not need this */
  }

  sorter( x, ans, n ) ;

  printf( "\nThe sorted answer is.\n" ) ;
 
  for( i = 0 ; i < n ; i++ ) {
    printf( " %d", ans[ i ] ) ;
  }

  fclose( fin ) ;

  return  0 ;
}

