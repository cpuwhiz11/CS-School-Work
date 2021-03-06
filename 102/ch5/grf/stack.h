/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program : stack.h                                           */
/*                                                             */
/* Approximate completion time: 15 minutes                     */
/***************************************************************/

#ifndef _stack
#define _stack

#include "globals.h"
#define STACKINCREMENT 100 
#define current_stacksize( p_S ) ( ( p_S ) -> top - ( p_S ) -> base )


typedef struct { generic_ptr *base ; generic_ptr *top ; int stacksize ; } stack ;

extern status init_stack( stack *p_S ) ; 

extern bool empty_stack( stack *p_S ) ;

extern status push( stack *p_S, generic_ptr data ) ;

extern status pop( stack *p_S, generic_ptr *p_data ) ;

extern status top( stack *p_S, generic_ptr *p_data ) ;

#endif
