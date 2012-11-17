/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program : Iterative ( Naive )                               */
/*                                                             */
/* Approximate completion time: X minutes                      */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

void minmax( int a[], int n, int *p_max, int *p_min ) ; 

int main( int argc, char *argv[] ) {

  int b[ 100 ], min, max, i ;

  for( i = 0 ; i < 100 ; i++ ) rand() % 1000 ;

  minmax( b, 100, &min, &max ) ;

  printf( "\nThe minimum is %d. \n", min ) ;
  printf( "\nThe maximum is %d. \n", max ) ;

  return  0 ;

}

void minmax( int a[], int n, int *p_max, int *p_min ) {

  int i ;

  *p_max = *p_min = a[ 0 ] ;

  for( i = 1 ; i < n ; i++ ) {
   
    if( a[ i ] > *p_max ) *p_max = a[ i ] ; 
    if( a[ i ] < *p_min ) *p_min = a[ i ] ;

  }

}
