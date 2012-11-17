/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 82: Insertion Sort                                  */
/*                                                             */
/* Approximate completion time: 35 minutes                     */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

int insertsort( int *A, int n ) {

  int i, j, next ;

  for( i = 0 ; i < n ; i++ ) {

    next = A[ i ] ;
    j = i ;
    
    while( ( j > 0 ) && ( A[ j - 1 ] > next ) ) {
    
      A[ j ] = A[ j - 1 ] ; 
      j = j - 1 ; 
    
    }
    
    A[ j ] = next ;
  
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
  
  insertsort( A, count ) ;

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

