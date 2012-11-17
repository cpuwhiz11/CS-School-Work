/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 54: Fibonacci Sequence ( Non-Recursive )            */
/*                                                             */
/* Approximate completion time: 45 minutes                     */
/***************************************************************/

#include <stdio.h>

int Fibonacci( int n ) {

  int temp, first = 0, second = 1 ;

  if( ( n == 1 ) || ( n == 2 ) ) return 1 ;

  while( n > 0 ) {

    temp = first + second ;

    first = second ;

    second = temp ;

    n-- ;

  }

  return first ; 

}

int main( int argc, char *argv[] ) {

  int n, temp ;

  while( 1 ) { 

    printf( "\nPlease enter a number. " ) ;

    scanf( "%d", &n ) ;
 
    if( n == EOF ) break ; 
 
    temp = n ;

    n = Fibonacci( n ) ;

    printf( "\nThe %dth Fibonacci number is: %d. ", temp, n ) ;

  }

  return  0 ;

}

