/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program : Knights Tour                                      */
/*                                                             */
/* Approximate completion time: X minutes                      */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

int count = 0 ;

void knight_tour( int *a, int *visited, int n, int r, int c ) ;

int main( int argc, char *argv[] ) {

  int *a, *visited, i, j, n ;

  n = atoi( argv[ 1 ] ) ; 

  a = ( int * ) malloc( sizeof( int ) * n * n ) ;
  visited = ( int * ) malloc( sizeof( int ) * n * n ) ;

  for( i = 0 ; i < n ; i++ ) {
    for( j = 0 ; j < n ; j++ ) {
      a[ i * n + j ] = 0 ;
      visited[ i * n + j ] = 0 ;
    }
  }

  knight_tour( a, visited, n, atoi( argv[ 2 ] ), atoi( argv[ 3 ] ) ) ;  

  printf( "\n" ) ;
  for( i = 0 ; i < n ; i++ ) {
    for( j = 0 ; j < n ; j++ ) printf( "  %3d  ", a[ i * n + j ] ) ;
    printf( "\n" ) ;
  }
  printf( "\n" ) ;
  return 0 ;

}

void knight_tour( int *a, int *visited, int n, int r, int c ) {

  if( r < 0 ) return ;
  if( r >= n  ) return ;
  if( c < 0 ) return ;
  if( c >= n  ) return ;

  if( visited[ r * n + c ] != 0 ) return ;

  count++ ; 
  a[ r * n + c ] = count ;
  visited[ r * n + c ] = count ; 

  if( count == ( n * n ) ) return ;

  knight_tour( a, visited, n, r + 1, c + 2 ) ;  
  knight_tour( a, visited, n, r + 1, c - 2 ) ;

  knight_tour( a, visited, n, r - 1, c + 2 ) ;
  knight_tour( a, visited, n, r - 1, c - 2 ) ;
  
  knight_tour( a, visited, n, r + 2, c + 1 ) ;
  knight_tour( a, visited, n, r + 2, c - 1 ) ;
  
  knight_tour( a, visited, n, r - 2, c + 1 ) ;
  knight_tour( a, visited, n, r - 2, c - 1 ) ;



}

