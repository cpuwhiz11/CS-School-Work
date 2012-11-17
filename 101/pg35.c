/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 35: Passing a Two Dimensional Array                 */
/*                                                             */
/* Approximate completion time: 30 minutes                     */
/***************************************************************/

#include <stdio.h>

int sumfunc( int x[][ 3 ], int l, int w ) {
 
 int i, j, sum ;

  for ( i = 0 ; i < l ; i++ ) {

    for ( j = 0 ; j < w ; j++ ) {

      sum = sum + ( x[ i ][ j ] ) ;
    
    }

  }

  return sum ; 

}

int main( int argc, char *argv[] ) {

  int x[ 3 ][ 3 ], i, j, sum ;

  printf( "Please enter in 9 integer values each followed by a space." ) ;

  for ( i = 0 ; i < 3 ; i++ ) {

    for ( j = 0 ; j < 3 ; j++ ) {

      scanf( "%d", &x[ i ][ j ] ) ;

    }

  }

  sum = sumfunc( x, 3, 3 ) ;

  printf( "The sum of the integers in the array is: %d.", sum ) ;
 
  return  0 ;

}

