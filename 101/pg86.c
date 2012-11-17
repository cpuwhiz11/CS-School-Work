/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 86: Shell Sort                                      */
/*                                                             */
/* Approximate completion time: X minutes                      */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

int shellsort( int *A, int count ) {

  int i, j, k, temp1, temp2 ;

  for( i = 0 ; i < count ; i++ ) {
    temp1 = A[ i ] ; 
    for( j = i - temp1 ; j < count ; j++ ) {
      temp2 = A[ j ] ;
      for( k = j - temp1 ; ( ( temp2 < A[ k ] ) && ( k >= 0 ) ) ; k = k - temp1 ) {
	A[ k + temp1 ] = A[ k ] ;
      }
      A[ k + temp1 ] = temp2 ; 
    }
  }
  return 0 ; 
}

int main( int argc, char *argv[] ) {

  int *A, i = 0, count = 0, temp ;

  FILE *fin, *fun ; 

  fun = fopen( argv[ 1 ] , "r" ) ;
  fin = fopen( argv[ 1 ] , "r" ) ; 
 
  while( ( fscanf( fin , "%d", &temp ) ) != EOF ) {
 
   count++ ;
   
  }  

  fclose( fin ) ;

  A = ( int * ) malloc( sizeof( int ) * count ) ;

  while( ( fscanf( fun, "%d", &A[ i ] ) ) != EOF ) i++ ;
  
  shellsort( A, count ) ;

  printf( "\nThe first 5 numbers are." ) ;

  for( i = 0 ; i < 5 ; i++ ) {

    printf( " %d", A[ i ] ) ;

  }

  printf( "\nThe last 5 numbers are." ) ;

  for( i = ( count - 5 ) ; i <= count  ; i++ ) {

    printf( " %d", A[ i ]  ) ;

  }
    
  fclose( fun ) ;

  return  0 ;

}

