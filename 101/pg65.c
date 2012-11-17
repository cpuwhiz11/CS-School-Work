/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 65: Cube Crawling                                   */
/*                                                             */
/* Approximate completion time: 65 minutes                     */
/***************************************************************/

#include <stdio.h>

int move( int x, int y, int z, char dir1, char dir2, int time ) {

  /*int temp , over ; */
  
  if( ( dir1 == 120 ) || ( dir1 == 88 ) ) {
   
       x = x + time ;
       printf( "The x value is %d.", x ) ;
       return x ;

  }    
  
  if( dir1 == 121 ) {
  
    y = y + time ; 

  }
  
  if( dir1 == 122 ) {
    
    z = z + time ;
  
  }
  return 0 ; 
} 
int main( int argc, char *argv[] ) {

  int x, y, z, l, time ;
  char dir1, dir2 ; 

  printf( "Please enter a size of a cube of space. " ) ;
  scanf( "%d", &l ) ;

  x = l ;
  y = 2 * l ; 
  z = l ;

  printf( "\nThe starting coordinates for the ship are %d,%d,%d.", x, y, z ) ; 
 
  printf( "\nPlease enter the axis of the direction traveled using either x, y, or z." ) ; 
  scanf( "%*c%c", &dir1 ) ;

  if( ( dir1 != 120 ) && ( dir1 != 121 ) && ( dir1 != 122 ) && ( dir1 != 88 ) && ( dir1 != 89 ) && ( dir1 != 90 ) ) {
    printf( "\nThe axis you entered is not x, y, or z." ) ;
    return 0 ; 
    }
 
  printf( "\nPlease enter the amount of time traveled in %c direction.", dir1 ) ;
  scanf( "%d", &time ) ;

  printf( "\nPlease enter the direction to be travled, either positive or negative (+/-)." ) ; 
  scanf( "%*c%c", &dir2 ) ; 

  if( ( dir2 != 43 ) && ( dir2 != 45 ) ) {
    printf( "Please enter either a positive or negative." ) ;
    return 0 ; 
  }

  x, y, z = move( x, y, z, dir1, dir2, time ) ;

  printf( "The ship has relocated to %d, %d, %d.", x, y, z ) ;

  return  0 ;
}

