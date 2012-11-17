/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 37: Perfect Numnbers                                */
/*                                                             */
/* Approximate completion time: 35 minutes                     */
/***************************************************************/

#include <stdio.h>

int IsPerfect( int x ) {

  int i, sum = 0 ;

  for (i = 1 ; i < x ; i++ ) {
  
    if ( ( x % i ) == 0 ) sum = sum + i ;  
  
  }

  return ( x == sum ) ;  
 
}

int main( int argc, char *argv[] ) {

  int n, code ;

  printf( "Please enter an integer." ) ;
  
  scanf( "%d", &n ) ;

  code = IsPerfect( n ) ;  

  if ( code == 1 ) printf( "The number is perfect." ) ;

  else printf( "The number is not perfect." ) ;

  return  0 ;
}

