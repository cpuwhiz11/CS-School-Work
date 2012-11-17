/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 16: Sine Function                                   */
/*                                                             */
/* Approximate completion time: 10 minutes                     */
/***************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main( int argc, char *argv[] ) {

  float x ;
   
  x = atof( argv[1] ) ;

  printf( "\nThe sine value of the number you entered is: %f.\n", sin( x ) ) ; 

  return  0 ;

}

