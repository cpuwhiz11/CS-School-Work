//Program that implements CharSequence interface found in java.lang

import java.lang.* ;

class CharS {

    public static void main( String[] args ) {

	//Initialize an original string and a place to store reversed string
	String original = "This is the Original Sentence." ;
	String reverse ;

	//Print Original string
	System.out.println( original ) ;

	//Call reverse string, will return string reverse into "reverse"
	reverse = rev_str( original ) ;

	//Print out reverse string using subSequence method
	System.out.println( "\nThe string reversed is: " ) ;
	System.out.println( reverse.subSequence( 0, 30 ) ) ; 

    }
 

    public static String rev_str( String orig ) {
	
	//Delcare variables to hold reverse string and operate loop and the length of the string. 
	int i, length ;

	//set length to the length of the original string
	length = orig.length() ;
	
	//Creat a stringbuffer of said length  
	StringBuffer reverse = new StringBuffer( length ) ; 

	//use a loop to take the char at the end of the string and place it at the beginning. Length - 1 to remove /0 byte
	for( i = ( length - 1 ) ; i >= 0 ; i-- ) {
	    reverse.append( orig.charAt( i ) ) ; 
	}

	//Return String
	return reverse.toString() ; 

    }


} 
