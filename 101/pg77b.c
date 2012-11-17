/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 77: Ramanujan Numbers                               */
/*                                                             */
/* Approximate completion time: 65 minutes                     */
/***************************************************************/

#include <stdio.h>

int i, j, a, b ;

int ram( int n ) { 

  int temp1, temp2 ;

  for( i = 1 ; i <= 75 ; i++ ) {

    for( j = 1 + i ; j <= 75 ; j++ ) {

      for( a = 1 + i ; a <= 75 ; a++ ) {

	for( b = 1 + i ; b <= 75 ; b++ ) {
	 temp1 = ( i * i * i ) + ( j * j * j ) ;
         temp2 = ( a * a  * a ) + (  b * b * b ) ;  
	 if( ( temp1 == temp2 ) && ( temp1 > n ) ) return temp1 ;
	}
      }
    }
  }
  return 0 ; 
}


int main( int argc, char *argv[] ) {

  int n, r ;

  printf( "Please enter the number you would like to test to." ) ; 
  scanf( "%d", &n ) ; 
  
  while ( 1 ) {

    r = ram( n ) ;
    printf( "\nA Ramanujan number would be %d.\n", r ) ;
    if( r > 1 )  n = r ;
  }
  

  return  0 ;
}

