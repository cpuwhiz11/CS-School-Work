/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 70: Walsh Transform                                 */
/*                                                             */
/* Approximate completion time: 45 minutes                     */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

double *walsh8( double **A, int size ) {

  int i, j, code = 0 ; 
  double **ans ; 

  ans = ( double ** ) malloc( sizeof( double * ) * size ) ;

  for( i = 0 ; i < size ; i++ ) {
    ans[ i ] = ( double * ) malloc( sizeof( double ) * size ) ;

  }
  for( i = 0 ; i < size ; i++ ) {
    for( j = 0 ; j < size ; j++ ) {
      code++ ; 
      if( code == 4 ) {
	ans[ i ][ j ] = -1 ; 
	code = 0 ; 
	j = size ; 
      }
      ans[ i ][ j ] = 1 ;
    }
  }
  return 0 ; 
}

int main( int argc, char *argv[] ) {

  int **x, j, i, n ; 
  double **A, **ans, temp ;

  printf( "Please enter the size of the matrix you wish to enter." ) ;
  scanf( "%d", &n ) ; 

  /*  printf( "Please enter the size of the Hadamard Matrix, which will be an n * n." ) ;
      scanf( "%d", &n ) ; */

 
  A = ( double ** ) malloc( sizeof( double * ) * n ) ;  

  for( i = 0 ; i < n ; i++ ) {
    for( j = 0 ; j < n ; j++ ) {
      printf( "Please enter a number for array location %d,%d. ", i, j ) ;
      scanf( "%lf", &temp ) ;
      A[ i ][ j ] = temp ;
    }
  }

  walsh8( A, n ) ;  

  for( i = 0 ; i < n ; i++ ) {
    for( j = 0 ; j < n ; j++ ) {
      ans[ i ][ j ] = 1 ; 
      printf( "%d", x[ i ][ j ] ) ;
    }
    printf( "\n" ) ; 
  }

  return  0 ;
}

