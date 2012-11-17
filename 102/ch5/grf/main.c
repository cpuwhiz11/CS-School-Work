/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program : main.c                                            */
/*                                                             */
/* Approximate completion time: 20 minutes                     */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "stackinterface.h"
#include "image.h"
#include "stack.h"

#define INIT_ERR "Error initializing stack. Region not filled. \n"
#define PUSH_ERR "Error adding to stack. Region may not be totally filled.\n"

#define PUSH_XY( p_S, x, y ) if( push_xy( p_S, x, y ) == ERROR ) { printf( PUSH_ERR ) ; continue ; }
 
void fill( int x, int y, int old_color, int new_color ) ;

int main() {

  /* Provides a user interface for the fill algorithm. */

  char filename[BUFSIZ] ;
  int x, y, old_color, new_color ;

  printf( "Enter image file name. " ) ;
  scanf( "%s", filename ) ;
  if( init_image( filename ) == - 1 ) {
    printf( "Error initializing the image.\n" ) ;
    exit( 1 ) ;
  }

  while( TRUE ) {
    display_image() ;
    printf( "Enter the point at which the fill should start ( x, y ) : " ) ;
    scanf( "%d, %d", &x, &y ) ;
    if( ( x == -1 ) && ( y == -1 ) ) break ;

    old_color = read_pixel( x, y ) ;
    
    do {
      printf( "Pixel color is %d. Enter the new color: ", old_color ) ;
      scanf( "%d", &new_color ) ;
    
    } while( old_color == new_color || new_color < 0 || new_color > 9 ) ;
   
    fill( x, y, old_color, new_color ) ;
  }

  printf( "All done.\n" ) ;
  return 0 ;
}

void fill( int x, int y, int old_color, int new_color ) {

  /* Perform an interior-defined 4-connected fill. */

  stack S ;

  if( init_stack( &S ) == ERROR ) {
    printf( INIT_ERR ) ;
    return ;
  }

  push_xy( &S, x, y ) ;
  while( !empty_stack( &S ) ) {

    pop_xy( &S, &x, &y ) ;
    if( read_pixel( x, y ) == old_color ) {
      write_pixel( x, y, new_color ) ;
      PUSH_XY( &S, x, ( y - 1 ) ) ;      
      PUSH_XY( &S, x, ( y + 1 ) ) ;
      PUSH_XY( &S, ( x - 1 ), y ) ;      
      PUSH_XY( &S, ( x + 1 ), y ) ; 
    }
  }
}
