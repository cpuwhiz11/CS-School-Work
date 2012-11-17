/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program : main                                              */
/*                                                             */
/* Approximate completion time: 45 minutes                     */
/***************************************************************/

#define ERR_PUSH "Error in pushing symbol (character #%d).\n"
#define ERR_POP "Error in popping symbol to match character #%d.\n"
#define ERR_MATCH "Incorrect closing symbol '%c' (character #%d). Expecting '%c'.\n"
#define ERR_EOL "Unexpected end of input line. Expecting: \n\t"

#include <stdio.h>
#include "stack.h"
#include "stackinterface.h"

char matching_symbol( char c ) ;

int main() {

  /* A parenthesis matcher. Ensures that (){}[] are properly nested */

  char c, *ptr, buffer[BUFSIZ] ;
  bool error ; 
  stack S ;

  init_stack( &S ) ;
  /* 
     Prompt and read a lin of data The loop is entered as long as end of file has not been reached and the line read is not empty
  */
  printf( "? " ) ;

  while( fgets( buffer, BUFSIZ, stdin ) != NULL && buffer[ 0 ] != '\0') {
    error = FALSE ;
    /* Process each character on the line. */

    for( ptr = buffer ; *ptr != '\0' && error == FALSE ; ptr++ ) {
      switch( *ptr ) {
         case '(' :
         case '-' :
         case '[' :
	 case '{' :
	   if( push_char( &S, *ptr ) == ERROR ) {
	     error = TRUE ;
	     printf( ERR_PUSH, ptr - buffer + 1 ) ;
	   }
	   break ;

          case ')' :
          case '"' :
          case ']' :
          case '}' :
	    if( pop_char( &S, &c ) == ERROR ) {
	      error = TRUE ;;
	      printf( ERR_POP, ptr - buffer + 1 ) ;
	      break ;
	    }
	    
	    /* The symbol popped must match the input symbol */
	    if( *ptr != matching_symbol( c ) ) {
	      error = TRUE ;
	      printf( ERR_MATCH, *ptr, ( ptr - buffer + 1 ), matching_symbol( c ) ) ;
	    }
	    break ;
      }

    }
    if( error == TRUE ) 
      /* If an error occurs, clear the stack for the next line of input. */ 
      while( empty_stack( &S ) == FALSE ) pop_char( &S, &c ) ;
    else if( empty_stack( &S ) == TRUE ) printf( "Valid input.\n" ) ;
   
    else {
      /* If there is something on the stack, there were not enough closing parentheses ( braces, brackets ). */
      printf( "ERR_EOL " ) ;
      while( empty_stack( &S ) == FALSE ) {
	pop_char( &S, &c ) ;
	printf( "%c ", matching_symbol( c ) ) ;
      }

      printf( "\n" ) ;

    }

    printf( "? " ) ;
  }

  return 0 ;

}

char matching_symbol( char c ) {

  /* Return the opposite symbol of c. */

  switch( c ) {

    case '(' : return ')' ;
    case ')' : return '(' ;
    case '-' : return '"' ;
    case '"' : return '-' ;
    case '[' : return ']' ;
    case ']' : return '[' ;
    case '{' : return '}' ;
    case '}' : return '{' ;

  } 

  /* Can't get here. */

  return 0 ;

}


