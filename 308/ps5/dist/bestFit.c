#include "main.h"

int allocateMemoryBest(struct request* request){

  /* Two free_list(s) */
  struct free_list* freeList = NULL;
  struct free_list* validList = NULL;

  int sizeDiff = 0;
  int leftover = 0;

  /* Do this the first time we do the loop */ 
  int bFlag = TRUE;
  
  /* Find the smallest block that fits on the free list */
  for(freeList = list_head.next; freeList; freeList = freeList -> next){
    if(request -> size <= freeList -> block_size){
      sizeDiff = freeList -> block_size - request -> size;

      /* only do this once */
      if(bFlag) leftover = sizeDiff;
      bFlag = FALSE;

      /* found smaller chunk */ 
      if (leftover >= sizeDiff){
	leftover = sizeDiff;
	validList = freeList; 
      }

    }
  }

  /* Did we find stuff we can use */
  if(validList != NULL){
    /* Set request */
    request -> is_allocated = TRUE;
    request -> base_adr = validList -> block_adr;
    request -> next_boundary_adr = request -> base_adr + request -> size;

    /* update remaining space */
    total_free = total_free - request -> size;
    request -> memory_left = total_free;

    /* If there is a perfect match, need to handle it.*/
    if((validList -> block_size = validList -> block_size - request -> size) == 0) {
	validList -> previous -> next = validList -> next;
	validList -> next -> previous = validList -> previous;
	
	free(validList);
	return 0;
    }

    validList -> block_adr = validList -> block_adr + request -> size;
    return 0;

  }

  /* Did not find a valid space */ 
  request -> memory_left = total_free;
  return 0;

}

int bestFit(int memorySize, char* fileToWrite){

  int i = 0;
  int requestSeq = 0;
  int requestSize = 0;
  
  /* Hold the string request type */ 
  char requestType[30];

  /* Write to this file */
  FILE* file = fopen(fileToWrite, "r");

  /* The list of free space */
  struct free_list* freeList; 

  /* Total amount of free space */ 
  total_free_space = total_free = (memorySize * 1024);

  /* init request array, all requests thus far false */
  for(i = 0; i < NUMBER_ENTRIES; i++){
    req_array[i].is_req = FALSE;
    req_array[i].is_allocated = FALSE;
  }

  /* First free node setup*/ 
  /* this struct is from the help file */
  top = malloc(sizeof(struct free_list));

  top -> next = NULL;
  top -> previous = &list_head;
  top -> block_size = total_free_space;
  top -> block_adr = 0;
  top -> adjacent_adr = total_free_space;

  /* set the list to the first free node */
  list_head.next = top;
  list_head.previous = NULL;
  list_head.block_size = -1;

  /* get the requests */
  while(fscanf(file, "%d %s %d", &requestSeq, &requestType, &requestSize) != EOF){

    /* Allocation? */
    if(strcmp(requestType, "alloc") == 0 ){
      
      /* Create request */
      req_array[requestSeq].is_req = TRUE;
      req_array[requestSeq].size = requestSize;

      allocateMemoryBest(&req_array[requestSeq]);

      /* Request complete, reset values */
      req_array[requestSeq].elements_on_free_list = 0;
      req_array[requestSeq].largest_chunk = 0;

      for(freeList = list_head.next; freeList; freeList = freeList -> next){
	/* get number of free things */
	++req_array[requestSeq].elements_on_free_list;

	/* get the largest chunk for the request */ 
	if(freeList -> block_size > req_array[requestSeq].largest_chunk){
	  req_array[requestSeq].largest_chunk = freeList -> block_size;
	}
      }

    } else {
      /* Free operation */
      req_array[requestSeq].size = req_array[requestSize].size;
      req_array[requestSeq].is_allocated = req_array[requestSize].is_allocated;

      update_list(requestSize);

      /* Request complete, reset values */
      req_array[requestSeq].memory_left = total_free; 
      req_array[requestSeq].elements_on_free_list = 0;
      req_array[requestSeq].largest_chunk = 0;

      for(freeList = list_head.next; freeList; freeList = freeList -> next){
        /* get number of free things */
        ++req_array[requestSeq].elements_on_free_list;

        /* get the largest chunk for the request */
        if(freeList -> block_size > req_array[requestSeq].largest_chunk){
          req_array[requestSeq].largest_chunk = freeList -> block_size;
        }
      }

    }

  }

  /* all done print it out */ 
  print_results("Best Fit", memorySize, req_array);

  /* All set close it out */ 
  fclose(file);

}
