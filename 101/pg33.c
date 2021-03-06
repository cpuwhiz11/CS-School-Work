/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 33: Persistence of a Number                         */
/*                                                             */
/* Approximate completion time: 40 minutes                     */
/***************************************************************/

#include <stdio.h>

int pers( int n ) {

  int y = 1, temp, per = 0 ; 

    while ( n > 10 ) {

      temp = n ;

      while ( temp > 0 ) {

	n = temp % 10 ;

	temp = temp / 10 ;

	y = y * n ;

	if( ( n == 0 ) || ( y == 0 ) ) {

	  per = 1 ;

	  break ; 

	} 
        
        per++ ;

      }
    
      n = temp ; 

    }
 
  return per ;

} 

int main( int argc, char *argv[] ) {

  int per, number ;

  printf( "Please enter an integer. \n" ) ;
  
  while( ( scanf( "%d", &number ) ) !=EOF ) {

    per = pers( number ) ;   

    printf( "The persistence of %d is %d.", number, per ) ;
  
  }
  
  return  0 ;

}

