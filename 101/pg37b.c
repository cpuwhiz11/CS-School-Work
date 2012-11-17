/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 37: Perfect Numbers                                 */
/*                                                             */
/* Approximate completion time: 45 minutes                     */
/***************************************************************/

#include <stdio.h>

int IsPerfect( int x ) {

  int i, sum = 0 ;

  if ( x == 0 ) return 0 ; 

  for (i = 1 ; i < x ; i++ ) {
  
    if ( ( x % i ) == 0 ) sum = sum + i ;  
  
  }

  return ( x == sum ) ;  
 
}

int main( int argc, char *argv[] ) {

  int i, code ;

  for ( i = 0 ; i <= 100000 ; i++ ) {

     code = IsPerfect( i ) ;  
  
     if ( code == 1 ) printf( "\n The number, %d, is perfect.", i ) ;

  }

  return  0 ;

}

