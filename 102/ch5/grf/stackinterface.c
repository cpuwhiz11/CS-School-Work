/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program : stackinterface.c                                  */
/*                                                             */
/* Approximate completion time: 15 minutes                     */
/***************************************************************/

#include "stackinterface.h"
#include <stdlib.h>

extern status push_xy( stack *p_S, int x, int y ) {

  /* Push the point (x,y) on the stack by allocating a point structure and using the stack primitive operation push(). */

  point *pt = ( point * ) malloc( sizeof( point ) ) ;

  if( pt == NULL ) return ERROR ;

  pt -> x = x ;
  pt -> y = y ;

  if( push( p_S, ( char *) pt ) == ERROR ) {
    free( pt ) ;
    return ERROR ;
  }

  return OK ;

}

extern status pop_xy( stack *p_S, int *p_x, int *p_y ) {

  /* Pop the point off the stack and return the data in p_x and p_y */

  point *pt ;

  if( pop( p_S, ( generic_ptr * ) &pt ) == ERROR ) return ERROR ;

  *p_x = pt -> x ;
  *p_y = pt -> y ;

  free( pt ) ;

  return OK ;

}


