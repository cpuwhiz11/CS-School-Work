/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 70: Walsh Transform                                 */
/*                                                             */
/* Approximate completion time: X minutes                      */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

double *walsh8( double Q[], int size, double **A ) {

  int i, j ;
  double temp[ 8 ] ;
  double *ans ;

  ans = ( double * ) malloc( sizeof( double ) * size ) ;

  for( i = 0 ; i < size ; i++ ) temp[ i ] = 0 ;

  for( i = 0 ; i < size ; i++ ) {

    for( j = 0 ; j < size ; j++ ) {

      temp[ i ] = ( A[ i ][ j ] * Q[ j ] ) + temp[ i ] ;

    }
  }

  for( i = 0 ; i < size ; i++ ) {

    ans[ i ] = temp[ i ] / 8 ;

  }

  return ans ;

}


void fill( double **A, int n, int r, int c, int sign ) {

  if( n == 2 ) {
    A[ r ][ c ] = 1 * sign ;
    A[ r ][ c + 1 ] = 1 * sign ;
    A[ r + 1 ][ c ] = 1 * sign ;
    A[ r + 1 ][ c + 1 ] = 1 * ( - 1 * sign ) ;
  }

  else {

    fill( A, ( n / 2 ), r, c, sign ) ;
    fill( A, ( n / 2 ), r + ( n / 2 ), c, sign ) ;
    fill( A, ( n / 2 ), r, c + ( n / 2 ), sign ) ;
    fill( A, ( n / 2 ), r + ( n / 2 ), c + ( n / 2 ) , ( sign * -1 ) ) ;

  }

}

int main( int argc, char *argv[] ) {

  int i, n, count = 1 ;  
  
  double usr[ 8 ], **A, temp, *ans ;  

  printf( "Please enter a number for the Hadamard-matrix. " ) ;
  scanf( "%d", &n ) ; 

  while( count <= 2 ) {
    
    printf( "\nYou are entering numbers for vector %d.", count ) ;
    
    for( i = 0 ; i < n ; i++ ) {
  
 	printf( "\nPlease enter a number for array location %d. ", i ) ;
	
	scanf( "%lf", &temp ) ;
	
	usr[ i ] = temp ;
  
     }

    A = ( double** ) malloc( sizeof( double ) * n ) ;
   
    for( i = 0 ; i < n ; i++ ) {
    
      A[ i ] = ( double * ) malloc( sizeof( double ) ) ;
    
    } 

    fill( A, n, 0, 0, 1 ) ;  
    
    *ans = *walsh8( usr, n, A ) ;
    /*
    for( i = 0 ; i < n ; i++ ) {
    
      	printf( " %lf", ans[ i ] ) ;      

    }
    */ 
    count++ ;

  }

  return  0 ;

}






