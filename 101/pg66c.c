/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 66: Tromino Tiling                                  */
/*                                                             */
/* Approximate completion time: 55 minutes                     */
/***************************************************************/

#include <stdio.h>

int symbol = 33 ; 
char tile[ 16 ][ 16 ] ;

void cleartile() { 
  int x, y ; 

  for( x = 0 ; x <= 16 ; x++ ) {
    for( y = 0 ; y <= 16 ; y++ ) {
      tile[ x ][ y ] = 126 ;
    }
  }
}

void printtile( int length ) {
  int x, y ;

  for( x = 0 ; x <= length ; x++ ) {
    for( y = 0 ; y <= length ; y++ ) {
      printf( "%c", tile[ x ][ y ] ) ;
    }
 
  printf( "\n" ) ;
  }
}

int findquad( int x, int y, int length ) {

  int horiz = 1, vert = 1 ;

  if( x < ( length / 2 ) + 1 ) horiz = 0 ; 

  if( y < ( length / 2 ) + 1 ) vert = 0 ; 

  if( ( horiz == 0 ) && ( vert == 0 ) ) return 2 ;

  else if( ( horiz == 1 ) && ( vert == 0 ) ) return 1 ;

  else if( ( horiz == 0 ) && ( vert == 1 ) ) return 3 ; 

  else return 4 ; 
}

int find( int size, int x, int y ) {

  int j, k, quad ; 
 
  for( j = 0 ; j < size ; j++ ) {
    for( k = 0 ; k < size ; k++ ) {
      if( tile[ j + x ][ k + y ] != 126 ) {
	quad = findquad( j, k, ( size - 1 ) ) ;
	return quad ;
      }
    }
  }
  return 0 ; 
}

int action( int size, int x, int y ) {
  int length = ( size - 1 ) ;
  int quad ;

  quad = find( size, x, y ) ; 

  if( quad != 1 ) {
    tile[ x + ( length / 2 ) + 1 ][ y + ( length / 2 ) ] = symbol ;
  }
  if( quad != 2 ) {
    tile[ x + ( length / 2 ) ][ y + ( length / 2 ) ] = symbol ;
  }
  if( quad != 3 ) {
    tile[ x + ( length / 2 ) ][ y + ( length / 2 ) + 1 ] = symbol ;
  }
  if( quad != 4 ) {
    tile[ x + ( length / 2 ) + 1 ][ y + ( length / 2 ) + 1 ] = symbol ;
  }
  symbol++ ;

  if( size > 2 ) {
    action( ( size / 2 ), ( length / 2 ) + 1 + x, ( 0 + y ) ) ;
    action( ( size / 2 ),  ( 0 + x ), ( 0 + y ) ) ;
    action( ( size / 2 ), ( 0 + x ), ( length / 2 ) + 1 + y ) ;
    action( ( size / 2 ), ( length / 2 ) + 1 + x, ( length / 2 ) + 1 + y ) ;
  }
  return 0 ; 

}

int main( int argc, char *argv[] ) {

  int x, y, size, length ;

  printf( "Please enter a number for the size of the square. " ) ;

  scanf( "%d", &size ) ; 

  if( ( x > 0 ) || ( x == 1 || 3 || 5 || 7 || 9 || 10 || 11 || 12 || 13 || 14 || 15 ) || ( x > 16 ) ) {

    printf( "You must enter a number that is 2, 4, 6, 8, or 16." ) ;

    return 0 ; 

  }

  printf( "Please enter a number for the x coordinate of the blank tile. " ) ;

  scanf( "%d", &x ) ;

  if( x > size ) {

    printf( "You must enter a number that fits in the square.") ;

    return 0 ; 

  }

  printf( "Please enter a number for the y coordinate of the blank tile. " ) ;

  scanf( "%d", &y ) ;

  if( y > size ) {

    printf( "You must enter a number less than the size of the square." ) ;

    return 0 ;

  }

  length = ( size - 1 ) ;

  cleartile() ; 

  tile[ x - 1 ][ y - 1 ] = 32 ; 

  action( size, 0, 0 ) ; 

  printtile( length ) ;

  return  0 ;
}

