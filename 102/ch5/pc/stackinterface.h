/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program : stackinterface.h                                  */
/*                                                             */
/* Approximate completion time: 10 minutes                     */
/***************************************************************/

#ifndef _stackinterface
#define _stackinterface 

extern status push_char( stack *p_S, char c ) ;
extern status pop_char( stack *p_S, char *p_c ) ;
extern status top_char( stack *p_S, char *p_c ) ;

#endif 


