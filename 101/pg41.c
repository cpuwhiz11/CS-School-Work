/********************************************************************/
/* Programmer: Paul Geromini                                        */
/*                                                                  */
/* Program 41: Greatest Common Divisor ( Recursive Euclid Method )  */
/*                                                                  */
/* Approximate completion time: 40 minutes                          */
/********************************************************************/

#include <stdio.h>

int gcd( int x, int y ) {

  int temp1, temp2 ;

  if ( x > y ) {

      temp1 = x ;

      temp2 = y ; 

  }

  else {

      temp1 = y ;

      temp2 = x ; 

  }

  if( temp1 % temp2 == 0 ) return temp2 ;

  else return gcd( temp2, ( temp1 % temp2 ) ) ; 

}

int main( int argc, char *argv[] ) {

  int x, y ;

  FILE *fin ;

  fin = fopen( argv[ 1 ], "r" ) ; 

  while( fscanf( fin, "%d", &x ) != EOF ) {

     fscanf( fin, "%d", &y ) ;
  
     printf( "\n The pair is %d and %d.", x, y ) ;

     printf( "\n The greatest common factor is %d. \n", gcd( x, y ) ) ;      

  }

  printf( "\n This would be the end of the file. \n" ) ;

  fclose( fin ) ; 

  return  0 ;

}









