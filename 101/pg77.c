/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 77: Taxi! Taxi!                                     */
/*                                                             */
/* Approximate completion time: 70 minutes                     */
/***************************************************************/

#include <stdio.h>

int i, j, a, b ;

int ram( int n, int r ) { 

  int temp1, temp2 ;

  for( i = 1 ; i <= 175 ; i++ ) {

    for( j = ( 1 + i ) ; j <= 175 ; j++ ) {

      for( a = ( 1 + i ) ; a <= 175 ; a++ ) {

	for( b = ( 1 + i ) ; b <= 175 ; b++ ) {

	 temp1 = ( i * i * i ) + ( j * j * j ) ;

         temp2 = ( a * a  * a ) + (  b * b * b ) ;  

	 if( ( temp1 == temp2 ) && ( temp1 > r ) && ( temp1 < n ) ) return temp1 ;
	 
	}

      }

    }

  }

  return 0 ; 

}

int main( int argc, char *argv[] ) {

  int n, r = 0, order = 0 ;

  printf( "Please enter the number you would like to test to. " ) ; 

  scanf( "%d", &n ) ; 

  printf( "\nRamanujan     First       Second       First     Second    Order" ) ;

  printf( "\nNumber        Cube         Cube        Root      Root" ) ;

  printf( "\n----------------------------------------------------------------" ) ;
  
  while ( 1 ) {

    r = ram( n, r ) ;

    if( r == 0 ) break ; 

    order++ ;

    printf( "\n%d            %d           %d         %d        %d       %d \n", r, ( i * i * i ), ( j * j * j ), i, j, order ) ;

    printf( "                %d         %d         %d        %d \n", ( a * a * a ), ( b * b * b ), a, b ) ;     
  }
  

  return  0 ;
}

