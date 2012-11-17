/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 49: Bits of Fun                                     */
/*                                                             */
/* Approximate completion time: 50 minutes                     */
/***************************************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  int x, bits, temp ;
 
  FILE * fin ;
  
  fin = fopen( "testdata47", "r" ) ;

  while( fscanf( fin, "%d", &x ) != EOF ) {
    
    printf( "\nThe number in question is: %d.", x ) ;
    
    temp = x ;    

    bits = 0 ;     

    while( x != 0 ) {

	if( x < 0 ) bits++ ;

	x = x << 1 ;  

      }

    printf( "\nThe number of ones in %d is %d.\n", temp, bits ) ;
    
  }

  fclose( fin ) ;

  return  0 ;
}

