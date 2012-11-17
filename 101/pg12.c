/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 12: Positive, Negative, or Zero?                    */
/*                                                             */
/* Approximate completion time: 10 minutes                     */
/***************************************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {


  int x ;
 
  printf( "\nPlease enter a number.\n\n" ) ;

  scanf( "%d", &x ) ;

  if ( x > 0 ) printf( "\nThe number is positive.\n\n" ) ;

  else if ( x == 0 ) printf( "\nThe number is zero.\n\n" ) ;

  else if ( x < 0 ) printf( "\nThe number is negative.\n\n" ) ;


  return  0 ;

}

