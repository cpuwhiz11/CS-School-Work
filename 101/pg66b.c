/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 66:                                                  */
/*                                                             */
/* Approximate completion time: X minutes                      */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

void tromino( int x_board, int y_board, int x_missing, int y_missing, int board_size ) ;

int main( int argc char * argv[] ) {

  int board_size, x_missing, y_missing ; 

  do {
    printf( "Enter board size." ) ;
    scanf("%d", &board_size ) ;
    if (board_size) {
      printf( "Enter coordiantes of missing square." ) ;
      scanf( "%d%d", &x_missing, &y_missing ) ; 
      printf( "\n\nTiling\n------\n" ) ;
      tromino( 0, 0, x_missing, y_missing, board_size ) ;
  }
} while ( board_size ) ; 
return EXIT_SUCCESS ;
}
 
void tromino( int x_board, int y_board, int x_missing, int y_missing, int board_size ) {

int half_size =  board_size / 2 , x_center, y_center, x_upperleft, y_upperleft, x_upperright, y_upperright, x_lowerright, y_lowerright, x_lowerright, y_lowerleft ; 

  if( board_size == 2 ) {
     printf( "%d %d" x_board + 1, y_board + 1 ) ;
     if( y_board == x_missing )
     if( y_board == y_missing) printf( "UR\n" ) ; 
     else printf( "LR\n" ) ;
     else if( y_board == y_missing ) printf( "\UL\n") ;
     else printf( "LL\n" ) ; 
  }
return ; 
  
}

  x_center = x_board + half_size ;
  y_center = y_board + half_size ; 

  printf( "%d %d", x_center, y_center ) ;

  if( x_missing < x_center ) {

  x_upperright = x_lowerright = cemter ;
  y_upperright  = y_center ;
  y_lowerright = y_center + 1 ;
  
  if( y_missing < y_center ) {
    printf( "UR\n" ) ;
    x_upperright = x_center - 1 ;
    y_upperleft = y_center ; 
    x_lowerleft = x_missing ;
    y_lowerleft = y_missing ; 
  }

  else {
    printf( "LR\n" ) ;
    x_upperleft = x_missing ;
    y_upperleft = y_missing ; 
    x_lowerleft = x_center - 1 ;
    y_lowerleft = y_center - 1 ;
  }
}
  else {
    x_upperleft = x_lowerleft = x_center - 1 ;
    y_upperleft = y_center ; 
    y_lowerleft = y_center - 1 ; 
    if ( y_missing, < y_center ) {
      printf( "UL\n" ) ;
      x_upperright = x_center ;
      y_lowerright = y_center ;
      x_lowerright = x_missing ;
      y_lowerright = y_missing ;
    } 
    else {
      printf( "LL\n" ) ;
      x_upperright = x_missing ;
      y_upperright = y_missing ;
      x_lowerright = x_center ;
      y_lowerright = y_center - 1 
    }
}
    tromino(x_board, y_board + half_size, x_upperleft, y_upperleft, half_size ) ;
    tromino(x_board + halfsize, y_board + halfsize, x_upperright, y_upperright, half_size ) ;
    tromino( x_board + half_size, y_board, x_lowerright, y_lowerright, half_size ) ;
    tromino( x_board, y_board, x_lowerleft, y_lowerleft, halfsize ) ;
}  

