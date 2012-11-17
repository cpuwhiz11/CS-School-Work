//Program calculates partial sum of numbers 1 to x. 

import java.util.Scanner ;

class Sum {

    public static void main( String[] args ) {

	int num = 0 , i, temp = 1, sum = 0 ;
	Scanner input = new Scanner( System.in ) ; //Create scanner object to read in user defined numbers
	boolean bool = true ; 

	while( bool ) {
	    //Ask for a number, maker sure its not negative
	    System.out.print( "Please enter a value for x to test to." ) ;
	    num = input.nextInt() ; 

	    if( num < 0 ) System.out.print( "Please enter a number greater than -1\n" ) ;
	    else break ;
	}

	//Print out the number entered
	System.out.print( "The value you entered was : " + num  ) ;
	System.out.print( "\n" ) ;  

	System.out.print( "The partial sum printed out looks like this: " ) ;
	//Do the calculations upto said number 
	for( i = 1 ; i <= num ; i++ ) {
	    if( i == num ) System.out.print( temp ) ; //Will not print out final "+"
	    else System.out.print( temp + " + " ) ;
	    temp++ ; 
	    sum = i + sum ; 
	}
	System.out.print( "\nThe final sum of: " + num ) ;
	System.out.print( " is : " + sum ) ;
    }

}
