/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Problem 10: Sum of Five                                     */
/*                                                             */
/* Approximate completion time: 15 minutes                     */
/***************************************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {


  int x, sum , limit ;

  FILE *fin ; 

  fin = fopen( "testdata10", "r" ) ;

  for ( limit = 1 ; limit <= 20 ; limit++ ) { 

    fscanf( fin, "%d", &x ) ;

    sum = sum + x ; 
    
  }

  printf ( "\n The sum of the numbers in the file is %d. \n", sum ) ;

  fclose( fin ) ; 


  return  0 ;

}

