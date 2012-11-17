/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 5: The Sum of Two Values                            */
/*                                                             */
/* Approximate completion time: 10 minutes                     */
/***************************************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {


  int val1, val2, sum ;

  printf( "\n Please enter the first of two numbers you wish to add together. \n\n" ) ;

  scanf( "%d", &val1 ) ;


  printf( "\n Please enter the second number you wish to add to the first. \n\n" );

  scanf( "%d", &val2 ) ;


  sum = val1 + val2 ;


  printf( "\n The value of %d, plus the value of %d, is: %d. \n", val1, val2, sum ) ;


  return  0 ;
}

