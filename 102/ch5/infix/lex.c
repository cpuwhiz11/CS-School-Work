
/********************************************************************/
/* lex.c for the infix to postfix problem                           */
/********************************************************************/

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "lex.h"

extern tokendata *gettoken( void ) {

  /*
Return a token ( a pointer to a static location ). Buffer contains an entire input line and bufptr points to the next character to be scanned.
  */

  static bool eof = FALSE ;
  static char buffer[ BUFSIZ ], *bufptr = NULL ;
  static tokendata token ; 
  char *operators = "+-*/(" ;

  if( eof == TRUE ) {
    token.tokentype = EOF_T ;
    return &token ;
  }

  if( bufptr == NULL ) {

    /* No data currenlty in buffer, so read an entire line. */

    printf( "? " ) ;
    if( ( ( bufptr = fgets( buffer, BUFSIZ, stdin ) ) == NULL ) || ( *bufptr == '\0' ) ) {
      eof = TRUE ;
      token.tokentype = EOF_T ;
      return &token ;
    }
  }

  while( isspace( *bufptr ) ) bufptr++ ;

  if( *bufptr == '\0' ) token.tokentype = EOL_T ;
  else if( *bufptr == ')' ) token.tokentype = RIGHTPAREN_T ;
  else if( strchr( operators, *bufptr ) != NULL ) token.tokentype = OPERATOR_T ;
  /* Character is in the list of operators */
  else token.tokentype = VARIABLE_T ;

  token.tokenvalue = *bufptr ;

  if( ( token.tokentype = EOL_T ) ) bufptr = NULL ;
  else bufptr++ ;

  return &token ;

}
