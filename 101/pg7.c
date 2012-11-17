/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Problem 7: Bigger than 100?                                 */
/*                                                             */
/* Approximate completion time: 5 minutes                      */
/***************************************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {


 int x ;

 printf( "\nPlease enter a number. " ) ;
 
 scanf( "%d", &x ) ;

 if ( x > 100 ) printf( "\nThe number is bigger than 100.\n\n" ) ;
   
 else printf( "\nThe number is not bigger than 100. \n\n" ) ;

  
 return  0 ;

}

