/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 30: Unfilled Box                                    */
/*                                                             */
/* Approximate completion time: 15 minutes                     */
/***************************************************************/

#include <stdio.h>

int main( int argc, char *argv[] ) {

  int l, h, i, j ;

  printf( "\n Please enter a length for the box of asterisks. \n" ) ;

  scanf( "%d", &l ) ;

  printf( "\n Please enter a height for the box of asterisks. \n" ) ; 

  scanf( "%d", &h ) ;
 
  for ( i = 1 ; i <= h ; i++ ) {

    printf( "\n" ) ; 

    if ( ( i == 1 ) || ( i == h ) ) {

      for ( j = 0 ; j < l ; j++ ) printf( "*" ) ; 

    }

    else {  

      for ( j = 1 ; j <= l ; j++ ) {

	if ( j < 1 && h < 1  ) printf( "*" ) ;

	else {

	  if(  j > 1  &&  j < l  ) printf( " " ) ;

	  else( printf( "*" ) ) ;

	}

      }

    }     

  }
   
  return  0 ;

}

