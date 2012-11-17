//Program will calculate the circumfrence and area of a circle based upon a user entered radius.

import java.util.Scanner ;
import java.lang.Math ;

class Circles {

    public static void main( String[] args ) {

	int radius = 0 ; //Variable for user entered radius
	double temp ; //Double variable for calculations
	Scanner input = new Scanner( System.in ) ; //Scanner object for user input
	boolean bool = true ; //Bool value for Error checking while loop

	//Get a user entered value and check to see if its greater than -1 
	while( bool ) {
	    System.out.print( "Please enter a radius: " ) ;
	    radius = input.nextInt() ; 
	    if( radius < 0 ) System.out.print( "Please enter a value greater than -1. \n " ) ;
	    else break ;
	}

	//Calculate and print out circumfrence. 
	temp = 2 * Math.PI * radius ; 
	System.out.print( " The circumfrence of the circle of radius : " +  radius ) ;
	System.out.print( " is : " + temp ) ;

	System.out.print( "\n" ) ;

	//Calculate and print out area
	temp = Math.PI * ( radius * radius ) ;
	System.out.print( " The area of the circle of radius : " + radius ) ;
	System.out.print( " is : " + temp ) ;  


    } 

}
