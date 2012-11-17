/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program : polynomial.h                                      */
/***************************************************************/

#ifndef _polynomial
#define _polynomial 

#include "list.h"
#include "globals.h"

typedef list polynomial ;

typedef struct term { int coefficient ; int degree ; } term ; 

extern status read_poly( polynomial *p_poly ) ;

extern void write_poly( polynomial poly ) ;

extern status write_term( term *p_term ) ; 

extern status add_poly( polynomial *p_poly1, polynomial *p_poly2 ) ;

extern int cmp_degree( term *p_term1, term *p_term2 ) ; 

extern void destroy_poly( polynomial *p_poly ) ;

#endif 
