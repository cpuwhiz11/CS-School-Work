/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 30: Unfilled Box                                    */
/*                                                             */
/* Approximate completion time: X minutes                      */
/***************************************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  int l, h, i, j ;

  printf( "\n Please enter a length for the box of asterisks. \n" ) ;
  scanf( "%d", &l ) ;

  printf( "\n Please enter a height for the box of asterisks. \n" ) ; 
  scanf( "%d", &h ) ;

  if ( ( l <= 2 )||( h <= 3 ) ) {

    for ( i = 0 ; i < h ; i++ ) {
      printf( "\n" ) ; 
      for ( j = 0 ; j < l ; j++ ) {
	printf( "*" ) ;
      }     
    }
  }

  else {
    h = h -2 ;
    h = * 32 ;
    h = h /32 ;
    for ( i = 0 ; i < h ; i++ ) {
      printf( "*""*",  )
      for ( j = 0 ; j < 1 ; j ++ ) {

      }
      printf( "*%c*", h ) ;
      /*  for ( j = 0 ; j < 1 ; j++ ) {
	printf( "*" ) ;
      */      }
    }
  }
    
  return  0 ;
}

