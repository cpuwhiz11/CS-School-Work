/*****************************************************************/
/* Programmer: Paul Geromini                                     */
/*                                                               */
/* Program 52: Matrix Multiplication                             */
/*                                                               */
/* Approximate completion time: 75 minutes                       */
/*****************************************************************/

#include <stdio.h>
#include <stdlib.h>

void MatrixMult( int **A , int **B , int **C , int n ) {

  int i , j, k ;

  for( i = 0; i < n ; i++ ) {

    for( j = 0; j < n ; j++ ) {

      for( k = 0 ; k < n ; k++ ) {

	C[ i ][ j ] = C[ i ][ j ] + ( A[ i ][ k ] * B[ k ][ j ] ) ;
      
      }

    }

  }

}

int main( int argc , char *argv[] ) {
  
  int n , i , j , **A , **B , **C ;

  FILE *fin ; 

  fin = fopen( argv[ 1 ] , "r" ) ;

  fscanf( fin , "%d" , &n ) ;

  A = ( int ** ) malloc( sizeof( int * ) * n ) ;

  B = ( int ** ) malloc( sizeof( int * ) * n ) ;

  C = ( int ** ) malloc( sizeof( int * ) * n ) ;

  for( i = 0; i < n ; i++ ) {
    
    A[ i ] = ( int * ) malloc( sizeof( int ) * n ) ;

    B[ i ] = ( int * ) malloc( sizeof( int ) * n ) ;

    C[ i ] = ( int * ) malloc( sizeof( int ) * n ) ;

  }

  for( i = 0 ; i < n ; i++ ) {
    
    for( j = 0 ; j < n ; j++ ) {

      fscanf( fin , "%d" , &A[ i ][ j ] ) ;

    }

  }

  for( i = 0 ; i < n ; i++ ) {

    for( j = 0 ; j < n ; j++ ) {

      fscanf( fin , "%d" , &B[ i ][ j ] ) ;

    }
  
  }

  MatrixMult( A , B , C , n ) ;

  for( i = 0 ; i < n ; i++ ) {

    for( j = 0 ; j < n ; j++ ) {

      printf( "%d " , C[ i ][ j ] ) ;

    }

    printf( "\n" ) ;

  }

  fclose( fin ) ; 

  return 0 ; 

}
