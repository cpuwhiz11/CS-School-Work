/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program 20: Area of a Circle                                */
/*                                                             */
/* Approximate completion time: 15 minutes                     */
/***************************************************************/

#include <stdio.h>
#include <math.h>

int main( int argc, char *argv[] ) { 

 float r, area ;
 
 printf( "\nPlease enter the radius of the circle.\n" ) ;
 
 scanf( "%f", &r ) ;

 area = M_PI * ( r * r ) ; 

 printf( "\nThe area of the circle is %f.\n", area ) ;

 return  0 ;

}

