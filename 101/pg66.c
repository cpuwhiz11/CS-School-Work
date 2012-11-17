/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 66: Tromino Tiling                                  */
/*                                                             */
/* Approximate completion time: 55 minutes                     */
/***************************************************************/

#include <stdio.h>

int symbol = 33 ; 

int tile( int quad, int n ) {

  n = n / 2 ;
  
  if( quad == 0 ) {
 
    printf("%c_\n%c%c", symbol, symbol, symbol ) ;
  
  }

  if( quad == 1 ) { 

    printf( "%c_\n%c%c", symbol, symbol, symbol ) ;  

  }

  if( quad == 2 ) {

    printf( "%c%c\n_%c", symbol, symbol, symbol ) ;

  }

  if( quad == 3 ) {

    printf( "%c%c\n%c_", symbol, symbol, symbol ) ;

  } 

  return 0 ; 

}

int quad( int x, int y, int n ) {

  if ( ( x <= ( n / 2 ) ) && ( y <= ( n / 2 ) ) ) return 0 ; 

  if ( ( x > ( n / 2 ) ) && ( y <= ( n / 2 ) ) ) return 1 ;

  if ( ( x <= ( n / 2 ) ) && ( y > ( n / 2 ) ) ) return 2 ;

  if ( ( x > ( n / 2 ) ) && ( y > ( n / 2 ) ) ) return 3 ;

  return 0 ; 
}

int main( int argc, char *argv[] ) {

  int x, y, n, blank ;

  printf( "Please enter a number for the size of the square. " ) ;

  scanf( "%d", &n ) ; 

  if( ( n % 2 ) != 0 ) {

    printf( "You must enter a number that is a power of 2." ) ;

    return 0 ; 

  }

  printf( "Please enter a number for the x coordinate of the blank tile. " ) ;

  scanf( "%d", &x ) ;

  if( x > n ) {

    printf( "You must enter a number less than the size of the square.") ;

    return 0 ; 

  }

  printf( "Please enter a number for the y coordinate of the blank tile. " ) ;

  scanf( "%d", &y ) ;

  if( y > n ) {

    printf( "You must enter a number less than the size of the square." ) ;

    return 0 ;

  }

  blank = quad( x, y, n ) ;

    printf ( "The blank is located in quadrant: %d\n", blank ) ; 

  tile( blank, n ) ;

  return  0 ;
}

