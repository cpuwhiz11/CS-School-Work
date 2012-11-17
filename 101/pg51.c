/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 51: Integer Decomposition                           */
/*                                                             */
/* Approximate completion time: 65 minutes                     */
/***************************************************************/

#include <stdio.h>

int i, j, k ;

int gcd( int x, int y ) {

  int temp1, temp2 ;

  if ( x > y ) {

      temp1 = x ;

      temp2 = y ; 

  }

  else {

      temp1 = y ;

      temp2 = x ; 

  }

  if( temp1 % temp2 == 0 ) return temp2 ;

  else return gcd( temp2, ( temp1 % temp2 ) ) ; 

}

int decomp( int n ) {

  for( i = 1 ; i < n ; i++ ) {

    for( j = ( i + 1 ) ; j < n ; j++ ) {

      for( k = ( j + 1 ) ; k < n ; k++ ) {

	if( ( i + j + k ) == n ) {

	  if( ( gcd( i, j ) == 1 ) && ( ( gcd( j, k ) == 1 ) ) && ( gcd( k, i ) == 1 ) ) return 0 ; 
	
	}
      
      }

    }

  }

  return 0 ;

}

int main( int argc, char *argv[] ) {

  int n ;

  FILE *fin ;

  fin = fopen( "testdata49", "r" ) ; 

  while( ( fscanf( fin, "%d", &n ) != EOF ) ) { 

    decomp( n ) ;

    printf( "\nThe decomposition of %d is %d + %d + %d.", n, i, j, k ) ;
  
  }

  fclose( fin ) ;

  return  0 ;
}

