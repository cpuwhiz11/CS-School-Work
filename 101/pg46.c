/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 46: Malloc up Space for a 1 Dimensional Array       */
/*             of n Integers                                   */ 
/*                                                             */
/* Approximate completion time: 40 minutes                     */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] ) {

  int *x, n, i, sum = 0 ; 

  printf( "Please enter the size of the array. " ) ;

  scanf( "%d", &n ) ; 

  x = ( int * ) malloc( n * ( sizeof( int ) ) ) ;

  for( i = 0 ; i < n ; i++ ) {
    
    printf( "Please enter a number for loaction %d, then press <return>.", i ) ;
   
    scanf( "%d", &x[ i ] ) ;
  
  }

  for( i = 0 ; i < n ; i++ ) sum = sum + x[ i ] ; 

  printf( "\nThe sum of the number(s) is %d.\n", sum ) ;

  return  0 ;

}

