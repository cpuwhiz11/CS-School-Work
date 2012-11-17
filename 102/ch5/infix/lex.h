
/********************************************************************/
/* lex.h for the infix to postfix problem                           */
/********************************************************************/

#ifndef _lex
#define _lex

#define BOTTOMMARKER '$'

#include "globals.h"

typedef enum { EOF_T, EOL_T, OPERATOR_T, VARIABLE_T, RIGHTPAREN_T } 
             inputtype ;

typedef struct { inputtype tokentype ; char tokenvalue ; } tokendata ;

extern tokendata *gettoken( void ) ;

#endif
