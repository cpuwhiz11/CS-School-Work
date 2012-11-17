/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 48: Relatively Prime to 351                         */
/*                                                             */
/* Approximate completion time: 35 minutes                     */
/***************************************************************/

#include <stdio.h>

int gcd( int x, int y ) {

  int gcd, i, temp ; 

  if ( x >= y ) temp = x ;

  else temp = y ;

  for( i = temp ; i > 0 ; i-- ) {

     if( ( x % i == 0 ) && ( y % i == 0 ) ) {

        gcd = i ;

        break ; 

     }

  }

  return gcd ; 
 
}

int main( int argc, char *argv[] ) {

  int  i ;

  for( i = 0 ; i <= 351 ; i++ ) {

    if( gcd( 351, i ) == 1 ) {
    
      printf( "\nThe number %d is relatively prime to 351.", i ) ;
  
    }
  
  }

  return 0 ;

}









