/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 96: Finite Space on the Heap                        */
/*                                                             */
/* Approximate completion time: 20 minutes                     */
/***************************************************************/

#include <stdlib.h>
#include <stdio.h>

int main( int argc, char *argv[] ) {

  int *p ;

  while( 1 ) {
 
    p = ( int * ) malloc( 1000 * sizeof( int ) ) ;
    
    if( p == 0 ) break ; 
  
  }
  
  printf( "\nCongratulations, you have reserved all the space on the heap.\n" ) ;

  return  0 ;

}

