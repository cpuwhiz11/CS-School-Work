/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 40: Greatest Common Divisor ( Brute Force Method )  */
/*                                                             */
/* Approximate completion time: 35 minutes                     */
/***************************************************************/

#include <stdio.h>

int gcd( int x[] ) {

  int gcd, i, temp ; 

  if ( x[ 0 ] >= x[ 1 ] ) temp = x[ 0 ] ;

  else temp = x[ 1 ] ;

  for( i = temp ; i > 0 ; i-- ) {

     if( ( x[ 0 ] % i == 0 ) && ( x[ 1 ] % i == 0 ) ) {

        gcd = i ;

        break ; 

     }

  }

  return gcd ; 
 
}

int main( int argc, char *argv[] ) {

  int x[ 2 ] ;

  FILE *fin ;

  fin = fopen( argv[ 1 ], "r" ) ; 

  while( fscanf( fin, "%d", &x[ 0 ] ) != EOF ) {

     fscanf( fin, "%d", &x[ 1 ] ) ;
  
     printf( "\n The pair is %d and %d.", x[ 0 ], x[ 1 ] ) ;
 
     printf( "\n The greatest common factor is %d. \n", gcd( x ) ) ;      

  }
 
  printf( "\n This would be the end of the file. \n" ) ;

  fclose( fin ) ; 

  return  0 ;

}









