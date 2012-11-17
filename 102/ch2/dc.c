/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program : Divide and Conquer ( Recursive )                  */
/*                                                             */
/* Approximate completion time: 35 minutes                     */
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

  int min2, max2 ;

  if( n == 1 ) *p_min = *p_max = a[ 0 ] ;

  else if ( n == 2 ) {

    if( a[ 0 ] < a[ 1 ] ) {

      *p_min = a[ 0 ] ;
      *p_max = a[ 1 ] ;

    }  

    else {

      *p_min = a[ 1 ] ;
      *p_max = a[ 0 ] ;

    }

  }

  else {

    minmax( a, ( n / 2 ), p_min, p_max ) ;
    minmax( ( a + ( n / 2 ) ), ( n - ( n / 2 ) ), &min2, &max2 ) ;
    if( min2 < *p_min ) *p_min = min2 ;
    if( max2 > *p_max ) *p_max = max2 ;

  }

}
