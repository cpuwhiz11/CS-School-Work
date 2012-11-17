/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 38: Blank Removal                                   */
/*                                                             */
/* Approximate completion time: 50 minutes                     */
/***************************************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  int c, state = 0 ; 
  
  FILE *fin ;
  
  fin = fopen ( argv[ 1 ], "r" ) ;  

  while( ( c = fgetc( fin ) ) != EOF ) {

    if ( state == 0 ) {

      if ( c != 32 ) {

	putchar( c ) ;

      }

      else {

	putchar ( c ) ;

	state = 1 ;   

      }

    }

    if ( ( state == 1 ) && ( c != 32 ) ) {

	putchar ( c ) ;

	state = 0 ; 

    }  
  
  }

  fclose( fin ) ; 

  return  0 ;
}

