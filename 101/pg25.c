/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 25: Sum of a Bunch                                  */
/*                                                             */
/* Approximate completion time: 15 minutes                     */
/***************************************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  int x, sum = 0 ; 

  FILE *fin ;

  fin = fopen( "testdata22", "r" ) ; 
 
  while ( fscanf( fin , "%d", &x ) !=EOF ) sum = sum + x ;  

  printf( "\nThe sum of all the numbers in the file is %d.\n", sum ) ;

  fclose( fin ) ; 

  return  0 ;

}

