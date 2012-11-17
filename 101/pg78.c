/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 78: Ramanujan Numbers                               */
/*                                                             */
/* Approximate completion time: X minutes                      */
/***************************************************************/

#include <stdio.h>

int ram( int n ) { 

  int i, j, a, b, temp1, temp 2 ;

  for( i = 0 ; i <= n ; i++ ) {

    for( j = 0 ; j <= n ; j++ ) {

      for( a = 0 ; a <= n ; a++ ) {

	for( b = 0 ; b <=n ; b++ ) {

	  if( a * a * a ) + ( b* b * b ) == ( i * i * i ) + ( j * j * j ) {
   
	
	
      }


  }

}

int main( int argc, char *argv[] ) {

  int n, r ;

  printf( "Please enter the number you would like to test to." ) ; 
  scanf( "%d", &n ) ; 

  r = ram( n ) ;

  printf( "A Ramanujan number would be %d.", r ) ;

  return  0 ;
}

