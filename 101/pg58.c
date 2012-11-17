/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 58: Guardian Angles                                 */
/*                                                             */
/* Approximate completion time: 30 minutes                     */
/***************************************************************/

#include <stdio.h>

int triangle( int x, int y, int z ) {

  if( ( ( x + y ) > z ) && ( ( y + z ) > x ) && ( ( x + z ) > y ) ) {
    if( ( x != y ) && ( y != z ) && ( x != z ) ) {
      if( ( x * x ) + ( y * y ) == ( z * z ) ) return 1 ; 
      else return 2 ;
    }
    if( ( ( x == y ) && ( x != z ) ) || ( ( z == y ) && ( z != x ) ) || ( ( x == z ) && ( x != y ) ) ) return 3 ; 
    if( ( x == y ) && ( y == z ) && ( z == x ) ) return 4 ;
  }
  
  return 0 ;

}

int main( int argc, char *argv[] ) {

  int x, y, z, tri ;

  printf( "Please enter three postive integers that represent the lengths of a triangle. " ) ;
  scanf( "%d%d%d", &x, &y, &z ) ;

  tri = triangle( x, y, z ) ;

  if( ( tri == 0 ) ) printf( "%d,%d,%d, is not a triangle. ", x, y, z ) ;
  if( ( tri == 1 ) ) printf( "%d,%d,%d, is a right scalene triangle. ", x, y, z ) ;
  if( ( tri == 2 ) ) printf( "%d,%d,%d, is a scalene triangle. ", x, y, z ) ;
  if( ( tri == 3 ) ) printf( "%d,%d,%d, is an isosceles right triangle.", x, y, z ) ;
  if( ( tri == 4 ) ) printf( "%d,%d,%d, is an equilateral triangle.", x, y, z ) ;
 

  return  0 ;

}

