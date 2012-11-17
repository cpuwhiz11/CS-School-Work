/***********************************************************************************/
/* numberinterface.c                                                               */
/***********************************************************************************/

#include <stdlib.h>
#include "list.h"
#include "globals.h"
#include "numberinterface.h"


extern status appendanumber( list *p_L , int n ) {

  /* Not much to write. Just a few lines. But if you can do it... you've got it */
  /* If you've got it... then I welcome you to the top of the mountain.        */

  int *p_int = ( int * ) malloc( sizeof( int ) ) ;

  if( p_int == NULL ) return ERROR ; 

  *p_int = n ;

  if( append( p_L, ( generic_ptr ) p_int ) == ERROR ) {
    free( p_int ) ;
    return ERROR ;
  }

  return OK ; 

}

extern status getnextnumber( list *p_L, int *p_n ) {

  /* Mountain climbers wanted. Just a few lines.                     */
  /* If you can see it then welcome.                                 */
  /* If not, perhaps you can browse term_delete on page 73.          */
  /* This is not exactly like term_delete - but if you understand    */
  /* term_delete --- you are well on your way.                       */

  int *p_num ;

  delete( p_L, ( generic_ptr * ) &p_num )  ;

  *p_n = *p_num ; 
 
  return OK ;

}

