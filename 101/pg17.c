/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 17: Count Characters                                */
/*                                                             */
/* Approximate completion time: 10 minutes                     */
/***************************************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  int x = 0 ;
 
  while( getchar() ! = EOF ) x++ ;  

  printf( "\nThe number of characters you entered was: %d.\n", x) ;

  return  0 ;

}

