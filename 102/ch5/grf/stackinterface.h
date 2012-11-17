/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program : stackinterface.h                                  */
/*                                                             */
/* Approximate completion time: 15 minutes                     */
/***************************************************************/

#ifndef _stackinterface
#define _stackinterface

#include "stack.h"

typedef struct { int x ; int y ; } point ;

extern status push_xy( stack *p_S, int x, int y ) ;

extern status pop_xy( stack *p_S, int *p_x, int *p_y ) ;

#endif
