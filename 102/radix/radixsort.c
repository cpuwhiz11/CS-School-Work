/**************************************************************************************/
/* Radix Sort of integers numbers between 1000-9999 using polymorphic linked lists.   */
/**************************************************************************************/


#include <stdio.h>
#include "list.h"
#include <stdlib.h>
#include "numberinterface.h"
#include <math.h>

void static refill( int A[] , list Bins[] ) ;

int  static getdigit( int number, int position ) ;

int main( int argc, char *argv[] ) {

  int A[ 500000 ]   ;
  list Bins[ 10 ]   ;
  int i, j, k, n, digit ; 

  n = atoi( argv[ 1 ] ) ;

  for ( i = 0 ; i <  n  ; i++ ) { A[ i ] = rand() % 10000 ; } 

  printf( "\n        " );
  for ( i = 0 ; i <  20 ; i++ ) printf( " %d ", A[ i ] );    

  printf( "\n" );
  for ( i = 0 ; i <  10 ; i++ ) init_list( &Bins[ i ] ) ;

  for ( i = 1 ; i <= 4 ; i++ ) {
    printf( "\nPass %d: ", i ) ;
    for ( j = 0 ; j < n ; j++ ) {

      digit = getdigit( A[ j ] , ( i-1 )  ) ;

      appendanumber( &Bins[ digit ], A[ j ] ) ; 

    }

    refill( A, Bins ) ;
    for ( k = 0 ; k < 20 ; k++ ) printf(" %d ", A[ k ] );   printf( "\n" );

  }

  return 0 ;

}

static int getdigit( int number, int position ) {


  /* YOU NEED TO FILL IN THE BODY OF THIS FUNCTION. */
  /* HAVE A WONDERFUL TIME. ENJOY THE CHASE.        */
  /* YOU CAN DO THIS.                               */

  if( position == 0 ) return( number % 10 ) ;
  else return getdigit( ( number / 10 ), ( --position ) ) ; 

}

static void refill( int A[], list Bins[] ) {

  int i            ;
  int j = 0        ;
  int n ;

  /* YOU NEED TO FILL IN THE BODY OF THIS FUNCTION. */
  /* THINK ABOUT WHAT THIS DOES. WE WENT OVER THIS  */
  /* IN CLASS.                                      */

  for( i = 0 ; i < 10 ; i++ ) {

    while( !( empty_list( Bins[ i ] ) ) ) {
      getnextnumber( &Bins[ i ], &n ) ;
      A[ j ] = n ;
      j++ ;
    }
  }
} 
    
   
