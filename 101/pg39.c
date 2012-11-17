/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 39: Left Shift Plus                                 */
/*                                                             */
/* Approximate completion time: 25 minutes                     */
/***************************************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  int x = 1, i, limit ;

  unsigned int y = 1 ; 

  printf( "\n The initial value of x is %d and the initial value of y is %u.", x, y ) ; 

  limit = sizeof( int ) * 8  ;

  printf( " \n\n Integer  Unsigned Integer \n" ) ;

  for( i = 0 ; i <= ( limit - 1 ) ; i++ ) {

    x = x << 1 ; 

    y = y << 1 ;

    if ( ( i < 16 ) || ( i == 31 ) ) printf( " %d \t\t %u \n", x, y ) ;
 
    else printf( " %d  \t %u \n", x, y ) ; 

  }

  return  0 ;

}

