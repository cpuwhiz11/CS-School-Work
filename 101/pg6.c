/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Problem 6: The fscanf Function                              */
/*                                                             */
/* Approximate completion time: 10 minutes                     */
/***************************************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {


  int x ; 

  FILE *fin ; 

  fin = fopen( "testdata6", "r" ) ; 

  fscanf( fin, "%d", &x ) ;

  printf( "\n The number in the data file reads: %d. \n", x ) ; 

  fclose( fin ) ;


  return  0 ;

}

