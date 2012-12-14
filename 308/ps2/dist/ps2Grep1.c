/*
   Assignment #2 GREP1
   Paul Geromini
   01056543
*/

/* Based off Assignment_7_help.txt from ~bill/cs305 */
/* Based off Assign1.c from ~bill/cs308 */
/* Based off ps1.c from my past work */ 

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(void){
	int     childOut[2], childIn[2]; 
	int     fileDesc, numBytesRead;
	char    buffer[80];

	/* use the pipe() system call to create the pipe */
        /* could return -1 so check to make sure it does not */
        /* if it did it could not make the pipe */ 
        if(pipe(childOut) == -1 || pipe(childIn) == -1){
                perror("failed in Parent pipe creation:");
                exit(7);
        }
	
	switch(fork()){

	case -1: /* call failed */
	  perror("Fork call failed: ");
	  exit(1);

	case 0 : 
	{
	  /* child process */
	  /* Close the Child's stdout and stdin */
          /* Use parents stdout/stdin as the child's own */
	  if (close(0) == -1) {
	    perror("CHILD : Could not close stdout.\n");
            exit(6);
	  }
	  
          if (dup(childOut[0]) != 0) {
            perror("CHILD : Could use parents stdout.\n");
            exit(6);
          }

          if (close(1) == -1) {
            perror("CHILD : Could not close stdin.\n");
            exit(6);
          }

          if (dup(childIn[1]) != 1) {
            perror("CHILD : Could not use parents stdout.\n");
            exit(6);
          }

	  /* Close uneeded pipes */
	  if ( close(childOut[0]) == -1 || close(childOut[1]) == -1 ||
	       close(childIn[0]) == -1 || close(childIn[1]) == -1) {
	    
	    perror("CHILD : One of the pipes failed to close.\n");
	    exit(5);
	  }

	  /* Load the sort */
	  execlp("grep", "grep", "123", NULL);

	  /* If we reach this line the grep did not work */ 
	  perror("Grep has failed to run correctly.\n");
	  exit(4);
	}
	
        default : /* for the parent */
	  break; 

        } /* switch and child end */

	/* Close uneeded pipes */
	if(close(childOut[0]) == -1 || close(childIn[1]) == -1){
	  printf("PARENT : Could not close pipes");
	  exit(3);
	}

        if((fileDesc = open("cs308a2_grep_data_1", O_RDONLY, 0)) == -1){
	  perror("PARENT : Failed to open file");
	  exit(-1);
	}

	/* Read the data from the file and into the pipe */
	/* The pipe is hooked up to the child which is running grep */
	while((numBytesRead = read(fileDesc, buffer, 80)) != 0){
	  if(numBytesRead == -1){
	    printf("Write error");
	    exit(3); 
	  }
	  
	  if(write(childOut[1], buffer, numBytesRead) == -1){
	    printf("PARENT : Could not write to child.\n");
	    exit(2);
	  }   
	}
	
	if(close(fileDesc) == -1 || close(childOut[1]) == -1){
	  printf("PARNET : Could not close pipe or fileDesc.\n");
	  exit(1);
	}
	
	/* Create and use temp file to store grep output*/
	FILE* fp = fopen("temp.temp", "w+");
        
	fileDesc = open("temp.temp", O_RDWR);
 	
	/* Read back from grep */ 
	while((numBytesRead = read(childIn[0], buffer, sizeof(buffer))) != 0){
	  write(fileDesc, buffer, numBytesRead); 
	}

	/* Count lines in temp file */
	int count = 0;
	while(fgets(buffer, sizeof(buffer), fp) != NULL){
	  count++;
	}

	printf("Grep has %d hits\n", count); 
	close(childIn[0]);
	return 0; 

}
