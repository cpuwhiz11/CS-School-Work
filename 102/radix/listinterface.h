/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program  : listinterface.h                                  */
/***************************************************************/

#ifndef _listinterface
#define _listinterface

extern status term_insert( list *p_L, int coef, int deg ) ;
extern status term_delete( list *p_L, int *p_coef, int *p_deg ) ; 

#endif 
