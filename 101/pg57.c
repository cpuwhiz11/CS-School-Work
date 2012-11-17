/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 57: Atoi                                            */
/*                                                             */
/* Approximate completion time: 35 minutes                     */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

int counter( int x, int y ) {
  
  int temp, count = 0  ;
  
  if( x == y ) return 1 ; 

  while( x > 0 ) {

    temp = x % 10 ;

    if( temp == y ) count++ ;

    x = x / 10 ;  

  }

  return count ; 

}

int main( int argc, char *argv[] ) { 

  int x, y, n ; 

  x = atoi( argv[ 1 ] ) ;

  y = atoi( argv[ 2 ] ) ; 

  n = counter( x, y ) ; 

  printf( "\nThe number: %d occurs %d times in %d.\n", y, n, x ) ;

  return 0 ; 
}


