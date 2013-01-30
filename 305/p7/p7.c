/*
   Assignment #7 
   Paul Geromini
   01056543
*/

/* Based off Assignment_7_help.txt from ~bill/cs305 */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <string.h>

int main(void)
{
        pid_t   pid, ppid;
        int     ruid, rgid, euid, egid;
        int     priority;
        char    msg_buf[100];
        int 	msg_pipe[2];

	/* use the pipe() system call to create the pipe */
        /* could return -1 so check to make sure it does not */
        /* if it did it could not make the pipe */ 

        if(pipe(msg_pipe) == -1){
                perror("failed in Parent pipe creation:");
                exit(7);
        }

        /* Collete info about this process */ 

        printf("\nThis is the Parent process report:\n");
        pid  = getpid();
        ppid = getppid();
        ruid = getuid();
        euid = geteuid();
        rgid = getgid();
        egid = getegid();
        priority = getpriority(PRIO_PROCESS, 0);

        printf("\nPARENT PROG:  Process ID is:\t\t%d\n", pid);
        printf("PARENT PROC:  Process parent ID is:\t%d\n", ppid); 
	printf("PARENT PROC:  Real UID is:\t\t%d\n", ruid);
        printf("PARENT PROC:  Real GID is:\t\t%d\n", rgid);
        printf("PARENT PROC:  Effective UID is:\t\t%d\n", euid); 
        printf("PARENT PROC:  Effective GID is:\t\t%d\n", egid);
        printf("PARENT PROC:  Process priority is:\t%d\n", priority);

	printf("\nPARENT PROC: will now create child, write pipe,\n \
                and do a normal termination\n");

	sprintf(msg_buf, "Message from the parent with PID %d", pid);

	switch(pid = fork()){

	case -1: /* call failed */
	  perror("Fork call failed: ");
	  exit(1);

	default : /* for the parent */
	  printf("Created child with pid: %d\n", pid);
	  write(msg_pipe[1], msg_buf, strlen(msg_buf));
	  exit(1);

	case 0 : /* child process */
	  printf("Child Process info:\n");

	  pid  = getpid();
	  ppid = getppid();
	  ruid = getuid();
	  euid = geteuid();
	  rgid = getgid();
	  egid = getegid();
	  priority = getpriority(PRIO_PROCESS, 0);

          printf("\nPARENT PROG:  Process ID is:\t\t%d\n", pid);
          printf("PARENT PROC:  Process parent ID is:\t%d\n", ppid); 
	  printf("PARENT PROC:  Real UID is:\t\t%d\n", ruid);
          printf("PARENT PROC:  Real GID is:\t\t%d\n", rgid);
          printf("PARENT PROC:  Effective UID is:\t\t%d\n", euid); 
          printf("PARENT PROC:  Effective GID is:\t\t%d\n", egid);
          printf("PARENT PROC:  Process priority is:\t%d\n", priority);

	  /* Read from Parent */ 
	  read(msg_pipe[0], msg_buf, 100);
		
	  printf("CHILD PROC: parent's msg is %s\n", msg_buf);
	  printf("CHILD PROC: ### Goodbye ###\n");
	  exit(1); 

        } /* switch and child end */
       

	return 0; 

}
