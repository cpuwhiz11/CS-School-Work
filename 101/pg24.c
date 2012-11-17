/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 24: One Dimensional Array                           */
/*                                                             */
/* Approximate completion time: 15 minutes                     */
/***************************************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  int x[ 15 ], limit ; 
 
  FILE *fin ; 

  fin = fopen( "testdata21", "r" ) ;
  
  for ( limit = 0 ; limit < 15 ; limit++ ) {
  
    fscanf( fin, "%d", &x[ limit ] ) ;

  }

  for ( limit = 15 ; limit >= 0 ; limit-- ) {

    printf( "\n%d", x[ limit ] ) ;

  }

  fclose( fin ) ;

  return  0 ;

}

