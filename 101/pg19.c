/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 19: Area of a Rectangle                             */
/*                                                             */
/* Approximate completion time: 10 minutes                     */
/***************************************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  float l, h, area ;

  printf( "\nPlease enter the length of a rectangle.\n" ) ;

  scanf( "%f", &l ) ;

  printf( "\nPlease enter the height of a rectangle.\n" ) ;

  scanf( "%f", &h ) ;

  area = l * h ;

  printf( "\nThe area of the rectangle is: %f.\n", area ) ;

  return  0 ;

}

