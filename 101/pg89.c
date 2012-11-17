/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 89: Recursive Digit Sum                             */
/*                                                             */
/* Approximate completion time: 35 minutes                     */
/***************************************************************/

#include <stdio.h>

int digitsum( int x ) {

  int sum = 0 ; 

  if( x == 0 ) return sum ;

  else return ( sum = sum + ( x % 10 ) ) + digitsum( x / 10 ) ;  

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



