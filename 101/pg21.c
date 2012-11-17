/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 21: Argv                                            */
/*                                                             */
/* Approximate completion time: 10 minutes                     */
/***************************************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  int i ;

  for ( i = 0 ; i < argc ; i++ ) {

    printf( "\n\n %s", argv[ i ] ) ;

  }

  return  0 ;

}

