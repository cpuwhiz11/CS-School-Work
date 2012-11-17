/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 23: Scanf Returns What?                             */
/*                                                             */
/* Approximate completion time: 15 minutes                     */
/***************************************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  int x ; 

  FILE *fin ;

  fin = fopen ( "testdata20", "r" ) ;
 
  while ( fscanf( fin, "%d", &x ) != EOF ) {

    printf( "\n%d.", x ) ; 

  } 
  
  fclose( fin ) ; 

  return  0 ;

}

