/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program : image.h                                           */
/*                                                             */
/* Approximate completion time: 15 minutes                     */
/***************************************************************/


#include "image.h"
#include <stdio.h> 

#define SCREENMAX 100 

static int screen[ SCREENMAX ][ SCREENMAX ] ;
static int xmax, ymax ;

extern int init_image( char *filename ) {

  /*
Read the image file called filename. The first line of the image should contain the number of rows and columns of the image. An "image" is just a set of digits representing colors at each pixel.
  */  

  FILE *fd = fopen( filename, "r" ) ;
  char linebuffer[ BUFSIZ ] ;
  int row, col ;

  if( fd == NULL ) return -1 ; 

  /* First read image size */

  fgets( linebuffer, BUFSIZ, fd ) ;
  sscanf( linebuffer, "%d %d", &xmax, &ymax ) ; 
  
  if( ( xmax < 0 ) || ( ymax < 0 ) ) {
    fprintf( stderr, "Invalid image dimensions (%d,%d).\n", xmax, ymax ) ;
    fclose( fd ) ;
    return -1;
  }

  for( row = 0 ; row < xmax ; row++ ) {
    if( fgets( linebuffer, BUFSIZ, fd ) == NULL ) {
      fprintf( stderr, "Missing %d rows in data file.\n", xmax - row ) ;
      break ;
    }
    col = 0 ; 
    while( col < ymax ) {
      if( linebuffer[ col ] == 'n' ) {
	fprintf( stderr, "Missing %d columns on line %d.\n", ( ymax - col ), row ) ;
	for( ; col < ymax ; screen[ row ][ col++ ] = 0 ) ;
      } else {
	screen[ row ][ col ] = linebuffer[ col ] -  '0' ; 
	col++ ;
      }
    }
  }
 
  xmax = row ;
  fclose( fd ) ;
  return 0 ;

}

extern int read_pixel( int x, int y ) {

  /* Return the color at pixel x, y. */
 
  if( ( x < 0 ) || ( x >= xmax ) || ( y < 0 ) || ( y >= ymax ) ) return -1 ;

  return screen[ x ][ y ] ;

}

extern int write_pixel( int x, int y, int color ) {

  /* Set the color at pixel x, y to color. */
 
  if( ( x < 0 ) || ( x >= xmax ) || ( y < 0 ) || ( y >= ymax ) ) return -1 ;
  
  return screen[ x ][ y ] = color ; 

}

extern void display_image() {

  /* "Display" an image by writing the dimensions and then prinitning the "color" at each pixel. */

  int row, col ; 

  printf( "Dimension: %d x %d\n", xmax, ymax ) ;
  for( row = 0 ; row < xmax ; row++ ) {
    printf( "%3d ", row ) ;
    for( col = 0 ; col < ymax ; col++ ) {
      printf( "%1d", screen[ row ][ col ] ) ;
      /*putchar( '\n' ) ;*/
    }

    putchar( '\n' ) ;

  }

}
