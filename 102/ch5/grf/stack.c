/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program : stack.c                                           */
/*                                                             */
/* Approximate completion time: 20 minutes                     */
/***************************************************************/

#include <stdlib.h>
#include "stack.h"

extern status init_stack( stack *p_S ) {
  /* Intialize the stack to empty. */
  p_S -> base = ( generic_ptr * ) malloc( STACKINCREMENT * sizeof( generic_ptr ) ) ;
  if( p_S -> base == NULL ) return ERROR ;

  p_S -> top = p_S -> base ;
  p_S -> stacksize = STACKINCREMENT ;
  return OK ;

}

extern bool empty_stack( stack *p_S ) {
  /* Return TRUE if stack is empty, FALSE if otherwise. */
  return ( p_S -> top == p_S -> base ) ? TRUE : FALSE ;
}

extern status push( stack *p_S, generic_ptr data ) {
  /* Push data on p_S. If there is no room, return ERROR. */

  if( current_stacksize( p_S ) == p_S -> stacksize ) {
    generic_ptr * newstack = ( generic_ptr * ) realloc( p_S -> base ,( p_S -> stacksize + STACKINCREMENT ) * sizeof( generic_ptr * ) ) ;

    if( newstack == NULL ) return ERROR ;

    p_S -> base = newstack ;
    p_S -> top = p_S -> base + p_S -> stacksize ;
    p_S -> stacksize += STACKINCREMENT ;
  }

  *p_S -> top = data ;
  p_S -> top++ ;
  return OK ;

}

extern status pop( stack *p_S, generic_ptr *p_data ) {
  /* Pop the top value of p_S and put in p_data. */
  if( empty_stack( p_S ) == TRUE ) return ERROR ;
  p_S -> top-- ;
  *p_data = *p_S -> top ;
  return OK ;

}

extern status top( stack *p_S, generic_ptr *p_data ) {
  /* Return the value at the top of the stack without removing it. */
  if( pop( p_S, p_data ) == ERROR ) return ERROR ;
  return push( p_S, *p_data ) ;

}
