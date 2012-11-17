
/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 70: Walsh Transform                                 */
/*                                                             */
/* Approximate completion time: 120 minutes                    */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

double *walsh8( double A[], int size ) {

  int i, j ;
  int h[ 8 ][ 8 ] = 
    {  { 1, 1, 1, 1, 1, 1, 1, 1  } ,
       { 1, -1, 1, -1, 1, -1, 1, -1 } , 
       { 1, 1, -1, -1, 1, 1, -1, -1 } ,
       { 1, -1, -1, 1, 1, -1, -1, 1 } ,
       { 1, 1, 1, 1, -1, -1, -1, -1 } ,
       { 1, -1, 1, -1, -1, 1, -1, 1 } ,
       { 1, 1, -1, -1, -1, -1, 1, 1 } , 
       { 1, -1, -1, 1, -1, 1, 1, -1 } } ;
  
  double temp[ 8 ] ;
  double *ans ;

  ans = ( double * ) malloc( sizeof( double ) * size ) ;

  for( i = 0 ; i < 8 ; i++ ) temp[ i ] = 0 ;

  for( i = 0 ; i < 8 ; i++ ) {

    for( j = 0 ; j < 8 ; j++ ) {
  
      temp[ i ] = ( h[ i ][ j ] * A[ j ] ) + temp[ i ] ; 
        
    }
  }
  
  for( i = 0 ; i < 8 ; i++ ) {
  
    ans[ i ] = temp[ i ] / 8 ;
  
  }

  return ans ; 

}

int main( int argc, char *argv[] ) {

  int i, count = 1 ;  
  
  double usr[ 8 ], *ans, temp ;  

  while( count <= 2 ) {
    
    printf( "\nYou are entering numbers for vector %d.", count ) ;
    
    for( i = 0 ; i < 8 ; i++ ) {
  
 	printf( "Please enter a number for array location %d. ", i ) ;
	
	scanf( "%lf", &temp ) ;
	
	usr[ i ] = temp ;
  
     }

    ans = walsh8( usr, 8 ) ;  
    
    for( i = 0 ; i < 8 ; i++ ) {
    
      	printf( " %lf", ans[ i ] ) ;      

    }

    count++ ;

  }

  return  0 ;

}

