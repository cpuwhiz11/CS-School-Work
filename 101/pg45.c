/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 45: Malloc up Space for one Integer                 */
/*                                                             */
/* Approximate completion time: 45 minutes                     */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] ) {

  int *x ; 

  x = ( int * ) malloc( sizeof( int ) ) ;

  *x = 6 ;

  printf( "The number in the malloced space is: %d.", *x ) ;

  return  0 ;

}

