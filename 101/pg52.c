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

  int i, j, k, *ans, temp1, temp2 ; 
  
  ans = malloc( sizeof( int ) * n * n ) ;

  temp1 = 1 ;
  temp2 = 1 ;

  for( i = 0 ; i < n ; i++ ) {
    ans[ i ] = temp1 + temp2 ;
    printf( " %d", ans[i] ) ; 
    for( j = 0 ; j < n ; j++ ) {
      if( j >= 1 ) j = j + n ; 
      temp2 = mat[ 1 ][ j ] * temp2 ;  
      for( k = 0 ; k < n ; k++ ) {
	temp1 = temp1 * mat[ 0 ][ k ] ;   
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

