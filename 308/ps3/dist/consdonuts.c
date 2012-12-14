/*

Assignment 3
Paul Geromini
Taken from ~/bill/308/call_help_assign3.txt

consdonuts.c

*/

#include "donuts.h"

int main(){

  int i, j, rand;

  int flavors[NUMFLAVORS][12];
  struct tm* ptm; 

  /* Shared memory */
  int shmid, semid[3];

  int c1, c2, c3, c4, c5;
  struct donut_ring* shared_ring;

  struct timeval randtime;
  char szTime[40];

  /* Attach shared memory */
  if((shmid = shmget(MEMKEY, 0, 0)) == -1) {
    perror("Consumer failed to access shared memory.");
    exit(1);
  }

  /* Pointer to shared memory */
  if((shared_ring = (struct donut_ring *) shmat(shmid, NULL, 0)) == -1){
    perror("Consumer failed to attach to shared memory.");
    exit(2);
  }

  /* Semaphores atachment */
  for( i = 0; i < NUMSEMIDS; i++ ) {
    if((semid[i] = semget(SEMKEY + i, NUMFLAVORS, IPC_CREAT | 0600)) == -1) {
      perror("Consumer failed to attach to semaphore.");
      exit(3);
    }
  }


  /* Consumer section */
  for(i = 0; i < 10; i++){
    /* clear counts */
    c1 = 0;
    c2 = 0;
    c3 = 0;
    c4 = 0;
    c5 = 0;
  
    /* get dem donuts */
    for(j = 0; j < 12; j++){
      /* get random num for donut type */
      gettimeofday(&randtime, (struct timezone *)0);

      unsigned short xsub1[3];
      xsub1[0] = (ushort) randtime.tv_usec;
      xsub1[1] = (ushort)(randtime.tv_usec >> 16);
      xsub1[2] = (ushort)(getpid());
      rand = nrand48(xsub1) & 3;

      /* Lock */
      p(semid[OUTPTR], rand);
      p(semid[CONSUMER], rand);

      int type = shared_ring -> flavor[rand][shared_ring -> outptr[rand]];
      switch(rand){
        case 0: {
	  flavors[rand][c1] = type;
	  c1++;
	  break;
	}

        case 1: {
	  flavors[rand][c2] = type;
	  c2++;
	  break;
	}


        case 2: {
	  flavors[rand][c3] = type;
	  c3++;
	  break;
	}

        case 3: {
	  flavors[rand][c4] = type;
	  c4++;
	  break;
	}

      } /* End of switch */

      /* Consume donut */
      if (shared_ring -> outptr[rand] >= NUMSLOTS){
	shared_ring -> outptr[rand] = 0;
      } else {
	shared_ring -> outptr[rand] = shared_ring -> outptr[rand] + 1;
      }

      /* Notify */
      v(semid[PROD], rand);
      v(semid[OUTPTR], rand);

    } /* End of inner for loop */

    /* Print out stuff */
    ptm = localtime(&randtime.tv_sec);

    /* Time formatting */
    strftime(szTime, sizeof(szTime), "%H:%M:%S", ptm);
    long ms = randtime.tv_usec / 1000;

    printf("\nProcess PID: %d", getpid());
    printf("\nTime: %s", szTime, ms);
    printf("\nDozen number: %d\n", i + 1);

    /* FLAVORS awwww yisss*/
    printf("Plain\tSprinkled\tApple\tCherry\n");

    int y;
    for(y = 0; y < 12; y++){
      printf("%d\t%d\t%d\t%d\n", 
	     flavors[0][y], flavors[1][y], flavors[2][y], flavors[3][y]);
    }

    for(y = 0; y < NUMFLAVORS; y++){
      for(j = 0; j < 12; j++){
	flavors[y][j] = 0;
      } 
    }
    
  } /* End of outer for loop */

  return 0;

}
