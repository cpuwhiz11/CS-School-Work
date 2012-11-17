/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 65: Cube Crawling                                   */
/*                                                             */
/* Approximate completion time: 65 minutes                     */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

int overflow( int *x, int *y, int *z ) {

}
int move( int *x, int *y, int *z, char dir1, char dir2, int time ) {

  int  over ; 

  if( ( dir1 == 120 ) || ( dir1 == 88 ) ) {

    if( dir2 == 43 ) {
      if( time < *x ) {
	*x = *x + time ;
	return *x ;
      }
      if( time > *x ) {
	if( time > *x ) overflow( x, y, z )
	over = time - *x ;
	time = time - over ; 
	*x = *x + time ; 
	*y = *y - over ; 
	return *y ; 
    
      }
    }
    if( dir2 == 45 ) {

      if( time < *x ) {
	*x = *x - time ;
	return *x ;
      }
      if( time > *x ) {
	
	over = time - *x ;
	time = time - over ; 
	*x = *x - time ; 
	*y = *y - over ; 
	return *y ; 
      }
    }
  }
  if( ( dir1 == 121 ) || ( dir1 == 89 ) ) {  

    if( dir2 == 43 ) {
 
      if( time < *y ) {
	*x = *x + time ;
	return *x ;
      }
    }
    if( dir2 == 45 ) {

      if( time < *y ) {
	*y = *y - time ;
	return *y ;
      }
      if( time > *y ) {
	
	over = time - *y ;
	*x = *x + over ; 
	return *y ; 
    
      }
    }
  }
  if( ( dir1 == 122 ) || ( dir1 == 90 ) ) {
    
    if( dir2 == 43 ) {

      if( time < *z ) {
	*z = *z + time ;
	return *z ;
      }
      if( time > *x ) {
	
	over = time - *z ;
	time = time - over ; 
	*z = *z + time ; 
	*y = *y - over ; 
	return *y ; 
    
      }
    }
    if( dir2 == 45 ) {

      if( time < *z ) {
	*z = *z - time ;
	return *z ;
      }
      if( time > *z ) {
	
	over = time - *z ;
	time = time - over ; 
	*y = *y - over  ; 
	*z = *z - time ; 
	return *y ; 
    
      }
    } 
  }
 
  return 0 ; 
} 
int main( int argc, char *argv[] ) {

  int *x, *y, *z, l, time, count, temp, face ;
  char dir1, dir2 ; 

  printf( "\nPlease enter a size of a cube of space (which will be squared to equal the actual size). " ) ;
  scanf( "%d", &l ) ;

  x = ( int * ) malloc( sizeof ( int ) ) ;
  y = ( int * ) malloc( sizeof ( int ) ) ;
  z = ( int * ) malloc( sizeof ( int ) ) ;

  *x = l ;
  *y = 2 * l ; 
  *z = l ;

  printf( "\nThe starting coordinates for the ship are %d,%d,%d.\n", *x, *y, *z ) ; 
 
  printf( "\nPlease enter the axis of the direction you want to travel using either x, y, or z. \n" ) ; 
  scanf( "%*c%c", &dir1 ) ;

  if( ( dir1 != 120 ) && ( dir1 != 121 ) && ( dir1 != 122 ) && ( dir1 != 88 ) && ( dir1 != 89 ) && ( dir1 != 90 ) ) {
    printf( "\nThe axis you entered is not x, y, or z.\n" ) ;
    return 0 ; 
    }
 
  printf( "\nPlease enter the amount of space in the %c direction you want to travel.\n", dir1 ) ;
  scanf( "%d", &time ) ;

  printf( "\nPlease enter the direction to be travled, either positive or negative (+/-). \n" ) ; 
  scanf( "%*c%c", &dir2 ) ; 

  if( ( dir2 != 43 ) && ( dir2 != 45 ) ) {
    printf( "\nPlease enter either a positive or negative.\n" ) ;
    return 0 ; 
  }

  if( dir1 == 120 ) {
    count = time / l ;
    if( ( count == 0 ) || ( count == 1 ) ) {
      move( x, y, z, dir1, dir2, time ) ;
    }
    else {

      time = time - ( count * l ) ;
      *x = abs( time - ( l * 2 )  ; 

    }
  
  if( ( ( *x % l ) == 0 ) || ( ( *y % ( l * 2 )  ) == 0 )  {
    printf( "\nThe ship has hit an exact edge, stopped, and entered an alternative universe, oops.\n" ) ;
  }

  printf( "\nThe ship has relocated to %d, %d, %d.\n", *x, *y, *z ) ;

  return  0 ;
}

