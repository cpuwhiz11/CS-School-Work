/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program : polynomial.h                                      */
/*                                                             */
/* Approximate completion time: X minutes                      */
/***************************************************************/

#ifndef _polynomial
#define _polynomial 

#include "list.h"
#include "globals.h"

typedef list polynomial ;

typedef struct term { int coefficient ; int degre ; } term ; 

extern status read_poly( polynomial *p_poly ) ;

extern void write_poly( polynomial p_poly ) ;

extern status add_poly( polynomial *p_poly1, polynomial *p_poly2 ) ;

extern void destroy_poly( polynomial *p_poly ) ;

#endif 
