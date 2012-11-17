/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 32: Inner Product of Two Vectors                    */
/*                                                             */
/* Approximate completion time: 20 minutes                     */
/***************************************************************/

#include <stdio.h>

float inner( float u[], float v[], int size ) {

  int i ;

  float answer = 0 ;

  for ( i = 0 ; i < size ; i++ ) {

    answer = answer + ( u[ i ] * v[ i ] ) ;
  
  }

  return answer ;

}

int main( int argc, char *argv[] ) {

  int i ;

  float  v1[ 8 ] , v2[ 8 ], answer ;

  printf( "Please enter in 8 numbers each followed by a space. \n" ) ;

  for ( i = 0 ; i < 8 ; i++ ) {
 
    scanf( "%f", &v1[ i ] ) ;

  }

  printf( "Please enter in 8 numbers each followed by a space. \n" ) ;

  for ( i = 0 ; i < 8 ; i++ ) {

    scanf( "%f", &v2[ i ] ) ;
 
  }

  answer = inner( v1, v2, 8 ) ;

  printf( "The inner product of the vectors is: %f.", answer ) ;

  return  0 ;

}

