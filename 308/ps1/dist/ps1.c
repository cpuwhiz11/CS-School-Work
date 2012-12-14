/*
   Assignment #1
   Paul Geromini
   01056543
*/

/* Based off Assignment_7_help.txt from ~bill/cs305 */
/* Based off Assign1.c from ~bill/cs308 */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

int counter = 0, counter_2G = 0;

typedef union {
  int exit_status;

  struct {
    unsigned sig_num:7;
    unsigned core_dump:1;
    unsigned exit_num:8;
  } parts;
} Le_Wait_Status;

void sig_handler(int signal) {

  sigset_t mask;
  sigemptyset(&mask);
  sigprocmask(SIG_SETMASK, &mask, NULL);

  /* Clear output screan */
  fflush(stdout);

  printf("Starting assign proccess"); 
  execl("./assign1", "assign1", NULL);

  /* If exec did not work we get to this line which means an error happened */
  perror("execl for assign1 did not work\n");
  exit(5);

}

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

        /* Collete info about this process (the parent)*/ 
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

	switch(pid = fork()){

	case -1: /* call failed */
	  perror("Fork call failed: ");
	  exit(1);

	case 0 : /* child process */
	  printf("Child Process info:\n");

	  /* Handler for sigterm */
	  struct sigaction action;
	  sigset_t mask;

	  sigemptyset(&mask);
	    
	  action.sa_mask = mask;
	  action.sa_handler = &sig_handler;
	  action.sa_flags = 0;

	  if(sigaction(SIGTERM, &action, NULL) == -1) {
	    printf("Child failed to setup sig handler.");
	    exit(1); 
	  }

	  pid  = getpid();
	  ppid = getppid();
	  ruid = getuid();
	  euid = geteuid();
	  rgid = getgid();
	  egid = getegid();
	  priority = getpriority(PRIO_PROCESS, 0);

          printf("\nPARENT PROG:  Process ID is:\t\t%d\n", pid);
          printf("CHILD PROC:  Process parent ID is:\t%d\n", ppid); 
	  printf("CHILD PROC:  Real UID is:\t\t%d\n", ruid);
          printf("CHILD PROC:  Real GID is:\t\t%d\n", rgid);
          printf("CHILD PROC:  Effective UID is:\t\t%d\n", euid); 
          printf("CHILD PROC:  Effective GID is:\t\t%d\n", egid);
          printf("CHILD PROC:  Process priority is:\t%d\n", priority);

	  printf("CHILD PROC: Entering infinite loop\n");
	  fflush(stdout);

          write(msg_pipe[1],"v", 1);

	  /* Enter child into endless loop */
	  while (counter_2G < 10){
	    counter ++;
	    if (counter < 0){
	      counter = 0;
	      counter_2G++;
	    }
	  }
	  printf("CHILD PROG: timed out after 20 billion iterations\n");
	  exit(2);


        default : /* for the parent */
          printf("PARENT PROC: Created child with pid: %d\n", pid);

        } /* switch and child end */
       

	/* Parent needs to kill looping child */
	/* Wait for the child to start looping. */ 
	/* we know it is looping when the pipe is written to. */
	read(msg_pipe[0], &msg_buf, 1);
	
	/* Kill the child */
	kill(pid, SIGTERM);
	printf("Sent kill message to child\n");

	/* Child should quit */
	Le_Wait_Status waitStatus;
	if((pid = waitpid(-1, &waitStatus.exit_status, 0)) == -1) {
	  printf("PARENT PROC: Wait failed");
	  exit(1337);
	}

	/* Exit info */
	printf("PARENT PROC: Child with pid %d killed with the following information.\n", pid);
	if (waitStatus.parts.sig_num == 0) {
	  printf("Exit code: ");
	  printf("%d\n", waitStatus.parts.exit_num);
	} else {
          printf("Signal code: ");
          printf("%d\n", waitStatus.parts.sig_num);
	}

	return 0; 

}
