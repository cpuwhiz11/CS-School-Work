/*
   Assignment #2
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

	case 0 : /* child process */
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
	  execlp("sort", "sort", "-k", "3.3n", "-k", "1.1", "-k", "2.2", NULL);

	  /* If we reach this line the sort did not work */ 
	  perror("Sort has failed to run correctly.\n");
	  exit(4);

        default : /* for the parent */
	  break; 

        } /* switch and child end */

	/* Close uneeded pipes */
	if(close(childOut[0]) == -1 || close(childIn[1]) == -1){
	  printf("PARENT : Could not close pipes");
	  exit(3);
	}

	int fileDesc = 0;
        fileDesc = open("cs308a2_sort_data", O_RDONLY, 0);

	/* Read the data from the file and into the pipe */
	/* The pipe is hooked up to the child which is running sort */
	char buffer[512];
	int numBytesRead;

	while(numBytesRead = read(fileDesc, buffer, 80)){
	  if(write(childOut[1], buffer, numBytesRead) == -1){
	    printf("PARENT : Could not write to child.\n");
	    exit(2);
	  }     

	}

	if(close(childOut[1]) == -1){
	  printf("PARNET : Could not close pipe.\n");
	  exit(1);
	}

	/* Open the child's stdout as if it were a file */ 
	FILE* fp = fdopen(childIn[0], "r"); 
 	
	/* Number of area codes of the same number */
	int areaCodeCount = -1;

	/* Old Area code number */
	int oldAreaCode = 0; 

	char firstName[100], lastName[100];
	int areaCode, prefix, tel;
	/*
	fscanf(fp, "%s %s %d %d %d\n", lastName, firstName, &areaCode, &prefix , &tel);
	printf("%s %s %d %d %d\n", lastName, firstName, areaCode, prefix, tel);
	*/
	while(fscanf(fp, "%s %s %d %d %d\n", lastName, firstName, &areaCode, &prefix, &tel) != EOF){
	  /*printf("%s %s %d %d %d\n", lastName, firstName, areaCode, prefix, tel);*/
	 
	  if (oldAreaCode == 0) {
	    /* First run of this loop */
	    oldAreaCode = areaCode;
	    areaCodeCount++;
	  } 

	  if (oldAreaCode == areaCode){
	    areaCodeCount++;
	    continue; 
	  } else { 
	    /* New area codes */
	    /* Print out data on the previous code and reset */ 
	    printf("%d : %d\n", oldAreaCode, areaCodeCount); 
	    oldAreaCode = areaCode;
	    areaCodeCount = 1;
	  }

	}


	/* Print remaining area code info, since the loop finishes leaving it unprinted */
	printf("%d : %d", oldAreaCode, areaCodeCount);

	fclose(fp);

	return 0; 

}
