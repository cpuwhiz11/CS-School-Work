/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 31: Bubble Sort                                     */
/*                                                             */
/* Approximate completion time: 35 minutes                     */
/***************************************************************/

#include <stdio.h>

void bubblesort( int A[], int n ) {

  int i, temp, j ; 

  for ( i = 0 ; i < ( n - 1 ); i++ ) {

    for ( j = 0 ; j < ( n - 1 ) - i ; j++ ) {

      if ( A [ j ] > A [ j + 1 ] ) {

	temp = A [ j ] ; 

	A [ j ] = A [ j + 1 ] ;

	A [ j + 1 ] = temp ; 

      }

    }

  }

  return ; 

}

int main( int argc, char *argv[] ) {

  int i, x[ 10 ] ; 

  FILE *fin ;

  fin = fopen( argv[1] , "r" ) ;

  for ( i = 0 ; i < 10 ; i++ ) {

    fscanf( fin, "%d", &x[ i ] ) ; 

  }

  bubblesort ( x , 10 ) ;

  for ( i = 0 ; i < 10 ; i++ ) printf( "%d", x[ i ] ) ;

  fclose( fin ) ;

  return  0 ;

}

