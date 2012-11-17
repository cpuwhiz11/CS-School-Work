/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 34: Simulating Call by Reference                    */
/*                                                             */
/* Approximate completion time: 10 minutes                     */
/***************************************************************/

#include <stdio.h>

void swap( int *a, int *b ) {

  int temp ;

  temp = *a ; 

  *a = *b ;

  *b = temp ; 

} 

int main( int argc, char *argv[] ) {

  int a , b  ;

  printf( "Please enter a number for a. \n" ) ;

  scanf( "%d", &a ) ; 

  printf( "Please enter a number for b. \n" ) ;

  scanf( "%d", &b ) ;

  swap( &a, &b ) ;

  printf( "Like magic the numbers swapped: %d and %d.", a, b ) ;

  return  0 ;

}

