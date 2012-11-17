/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 36: Brute Force Primes                              */
/*                                                             */
/* Approximate completion time: 20 minutes                     */
/***************************************************************/

#include <stdio.h>

int isprime( int x ) {

  int i, count = 0 ;

  for (i = 1 ; i <= x ; i++ ) {

    if ( ( x % i ) == 0 ) count++ ;

  }

  return ( count == 2 ) ; 

}

int main( int argc, char *argv[] ) {

  int x, count ;
 
  FILE *fin ;
 
  fin = fopen ( argv[ 1 ], "r" ) ;
  
  while ( ( fscanf( fin, "%d", &x ) ) != EOF ) {

    printf( "The number in the file is: %d. \n", x ) ;

    count = isprime( x ) ;

    if ( count == 1 ) printf( "The number is prime. \n" ) ;

    else  printf( "The number is not prime. \n") ; 

  }

  fclose( fin ) ;
 
  return  0 ;
  
}

