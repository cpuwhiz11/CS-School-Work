/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 55: Fibonacci Sequence ( Recursive )                */
/*                                                             */
/* Approximate completion time: 35 minutes                     */
/***************************************************************/

#include <stdio.h>

int Fibonacci( int n ) {

  if( n == 0 ) return 0 ;

  if( n < 3 ) return 1 ;

  return  Fibonacci( n - 1 ) + Fibonacci( n - 2 )  ; 
 
}

int main( int argc, char *argv[] ) {

  int n, temp ;

  while( 1 ) {

    printf( "\nPlease enter a number. " ) ;
    
    if ( scanf( "%d", &n )  == EOF ) break ;
 
    temp = n ;
    
    n = Fibonacci( n ) ;

    printf( "\nThe %dth Fibonacci number is: %d. ", temp, n ) ;

  }

  return  0 ;

}

