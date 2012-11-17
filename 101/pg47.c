/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 47: Twin Primes                                     */
/*                                                             */
/* Approximate completion time: 32 minutes                     */
/***************************************************************/

#include <stdio.h>

int isprime( int x ) ;

int main( int argc, char *argv[] ) {

  int i ;

  for( i = 0 ; i <= 3000 ; i++ ) {

    if( ( isprime( i ) == 1 ) && ( isprime( i + 2 ) == 1 ) && ( i + 2 <= 3000 ) ) {

      printf( "\n %d and %d are twin primes.",i , i + 2 ) ;
    }

  }

  return  0 ;

}

int isprime( int x ) {

  int i , prime = 0 ; 

 
 for( i = 1 ; i <= x ; i++ ) {

    if( ( x % i ) == 0 ) prime++ ; 

  }

  return ( prime == 2 ) ;

} 
