/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 94: Simply Two Dimensional                          */
/*                                                             */
/* Approximate completion time: 65 minutes                     */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

float ave( float **a1, float ans1[], float ans2[] ) {

  int i, j ;

  float ave = 0 ;

  for( i = 0 ; i <= 3 ; i++ ) {

    if( i > 0 ) {

      ave = ave / 5 ;

      ans1[ i - 1 ] = ave ;

      ave = 0 ;

      if( i == 3 ) break ; 

    }

    for( j = 0 ; j < 5 ; j++ ) {
     
      ave = a1[ i ][ j ] + ave ; 
    
    }

  }

  for( i = 0 ; i <= 5 ; i++ ) {

    if( i > 0 ) {

      ave = ave / 3 ; 

      ans2[ i - 1 ] = ave ;

      ave = 0 ; 

      if( i == 5 ) break ;

    }

    for( j = 0 ; j < 3 ; j++ ) {

      ave = a1[ j ][ i ] + ave ; 

    }

  }
  
  return 0 ; 

}

int main( int argc, char *argv[] ) {

  int i, j ; 

  float **a1, ans1[ 3 ], ans2[ 5 ] ;

  FILE *fin ;

  fin = fopen( "textfile93", "r" ) ;

  a1 = ( float ** ) malloc( sizeof( float * ) * 3 ) ;
  

  for( i = 0 ; i < 3 ; i++ ) {

    for( j = 0 ; j < 5 ; j++ ) {

      a1[ i ] = ( float * ) malloc( sizeof( float ) ) ;  

    }

  }

  for( i = 0 ; i < 3 ; i++ ) {

    for( j = 0 ; j < 5 ; j++ ) {

      fscanf( fin, "%f", &a1[ i ][ j ] ) ;

    }

  }

  printf( "\nThe numbers in the array are.\n" ) ;

  for( i = 0 ; i < 3 ; i++ ) {

    for( j = 0 ; j < 5 ; j++ ) {

      printf( " %.2f", a1[ i ][ j ] ) ;

    }

    printf( "\n" ) ;

  }

  ave( a1, ans1, ans2 ) ;

  printf( "\nThe average values for the three rows are.\n" ) ;

  for( i = 0 ; i < 3 ; i++ ) {
     
    printf( " %f", ans1[ i ] ) ; 

  }

  printf( "\nThe average values for the five columns are.\n" ) ;

  for( i = 0 ; i < 5 ; i++ ) {

    printf( " %f ", ans2[ i ] ) ;

  }
    
  fclose( fin ) ;

  return  0 ;
}

