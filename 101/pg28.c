/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 28: Digit Sum                                       */
/*                                                             */
/* Approximate completion time: 15 minutes                     */
/***************************************************************/

#include <stdio.h>

int digitsum( int x ) {

  int sum = 0, digit ; 

  while( x > 0 ) {

    digit = x % 10 ;

    sum = sum + digit ;

    x = x / 10 ;

  }

  return sum ;

}

int main( int argc, char *argv[] ) {

  int x, sum ;
 
  FILE *fin ;
 
  fin = fopen( argv[ 1 ], "r" ) ; 

  while( ( fscanf( fin, "%d", &x ) ) != EOF ) {
 
    printf( "\n The number in the file is %d.", x ) ;

    sum = digitsum( x ) ;
 
    printf( "\n The sum of the digits is %d. \n", sum ) ;
  
  }

  fclose( fin ) ;
  
  return  0 ;

}



