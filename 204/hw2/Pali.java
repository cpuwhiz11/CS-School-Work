//This program checks to see if a user entered string is a palindrome.

import java.lang.String ; 
import java.util.Scanner ;

public class Pali {

    public static void main( String args[] ) {

	String string = "" ; //Initialized string to empty
	String str_rev = "" ; 
	boolean error ;
	Scanner input = new Scanner( System.in ) ; 

	System.out.print( "Please enter a string of text : " ) ;

	//Read in the string and catch exceptions
	string = input.nextLine() ; 

	System.out.print( "\nThe string you entered was: " + string ) ;

	//Check to see if the string entered was a palindrome
	str_rev = Rev_Str.reverse_str( string ) ; //Reverse the string

	System.out.print( "\nThe string reversed is : " + str_rev ) ;

	//See if the strings are different
	error = str_rev.contentEquals( string ) ;
	if( error == true ) System.out.print( "\nThe strings are palindromes." ) ;
	if( error == false ) System.out.print( "\nThe strings are not palindromes." ) ;

    }

}

class Rev_Str {

    public static String reverse_str( String orig ) {
	int i, length ;
	length = orig.length() ; 

	StringBuffer rever = new StringBuffer( length ) ; //Create buffer of the length of the original string

	//Place characters into new string, go backwards
	for( i = ( length - 1 ) ; i >= 0 ; i-- ) {
	    rever.append( orig.charAt( i ) ) ;
	}
	//Return string
	return rever.toString() ; 

    }

}
