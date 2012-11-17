/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 15: Using the sqrt Function                         */
/*                                                             */
/* Approximate completion time: 10 Minutes                     */
/***************************************************************/

#include <stdio.h>
#include <math.h>
int main( int argc, char *argv[] ) {


  double x, sum ;

  printf( "\n Please enter a number: \n\n" ) ;
 
  scanf( "%lf", &x ) ;
 
  sum = sqrt( x ) ;
 
  printf( "\n The square root of your number is: %lf \n", sum ) ; 


  return  0 ;
}

