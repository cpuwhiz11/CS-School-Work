/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Problem 11: Equal to Zero?                                  */
/*                                                             */
/* Approximate completion time: 10 minutes                     */
/***************************************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  int x ; 

  printf( "\n Please enter a number of your choosing. \n\n" ) ;

  scanf( "%d", &x ) ;

  
  if ( x == 0 ) printf( "\n The number is equal to zero. \n\n" ) ;
  
  else printf( "\n The number is not equal to zero. \n\n" ) ;


  return  0 ;

}

