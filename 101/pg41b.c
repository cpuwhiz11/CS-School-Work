/********************************************************************/
/* Programmer: Paul Geromini                                        */
/*                                                                  */
/* Program 41: Greatest Common Divisor ( Recursive Euclid Method )  */
/*                                                                  */
/* Approximate completion time: X minutes                           */
/********************************************************************/

#include <stdio.h>

int gcd( int x[] ) {

  int temp1, temp2, rem ;

  if ( x[ 0 ] > x[ 1 ] ) {
      temp1 = x[ 0 ] ;
      temp2 = x[ 1 ] ; 
  }

  else {
      temp1 = x[ 1 ] ;
      temp2 = x[ 0 ] ; 
  }
  
  while ( temp2 != 0 ) {
    rem = temp1 % temp2 ;
    temp1 = temp2 ;   
    temp2 = rem ;  
  } 

  return temp1 ;

}

int main( int argc, char *argv[] ) {

  int x[2], n;

  FILE *fin ;
  
  fin = fopen( argv[ 1 ], "r" ) ; 
  
  while( fscanf( fin, "%d", &x[ 0 ] ) != EOF ) {
  
    fscanf( fin, "%d", &x[ 1 ] ) ;  
    
    printf( "\n The pair is %d and %d.", x[ 0 ], x[ 1 ] ) ;
    
    printf( "\n The greatest common factor is %d \n", n = gcd( x ) ) ;      

  }

  printf( "\n This would be the end of the file. \n" ) ;

  fclose( fin ) ; 

  return  0 ;

}
















