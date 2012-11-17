/***************************************************************/
/* Programmer: Paul Geromini                                   */
/*                                                             */
/* Program : image.h                                           */
/*                                                             */
/* Approximate completion time: 15 minutes                     */
/***************************************************************/

#ifndef _image
#define _image 

extern int init_image( char *filename ) ;  
extern int read_pixel( int x, int y ) ;
extern int write_pixel( int x, int y, int color ) ; 
extern void display_image() ;

#endif 
