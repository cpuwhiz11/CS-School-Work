/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 52: Matrix Multiplication                           */
/*                                                             */
/* Approximate completion time: 40 minutes                     */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

int MatrixMult( int *mat[], int n ) {

  int i, j, k, *ans ; 
  
  ans = malloc( sizeof( int ) * n * n ) ;
  
  ans[ i ] + mat[i][k] * mat[i][k] ; 


  for( i = 0 ; i < 2 ; i++ ) {
    for( j = 0 ; j < n ; j++ ) {
      ans[ i ]= 0 ;
      for( k = 0 ; k < n ; k++ ) {
	ans[ i ] += mat[ i ][ k ] * mat[ i ][ j ] ;
	printf( " %d", ans[ i ]  ) ;
      }
    }
  }

  return 0 ; 
}

int main( int argc, char *argv[] ) {

  int n , *mat[ 2 ], i, code, *ans ;
  FILE *fin ;
  fin = fopen( argv[ 1 ] , "r" ) ;

  fscanf( fin, "%d", &n ) ;

  mat[ 0 ] = malloc( sizeof( int ) * n * n ) ;
  mat[ 1 ] = malloc( sizeof( int ) * n * n ) ;

  for( i = 0 ; i < ( n * n ) ; i++ ) {
    fscanf( fin, "%d", &mat[ 0 ][ i ] ) ;
    /*printf( "%d", mat[0][i]) ; */
  }
  for( i = 0 ; i < ( n * n ) ; i++ ) {
    fscanf( fin, "%d", &mat[ 1 ][ i ] ) ;
  
  }
  
  MatrixMult( mat, n ) ;
  /*  printf( "The answer is." ) ;
  for( i = 0 ; i < ( n * n ) ; i++ ) {
    printf( " %d", ans[ i ] ) ;
    code++ ;
    if( code == 3 ) printf( "\n" ) ;
  }
  */
  return  0 ;
}

