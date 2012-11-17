/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 81: Selection Sort                                  */
/*                                                             */
/* Approximate completion time: 45 minutes                     */
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
  
  selectionsort( A, count ) ;

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

