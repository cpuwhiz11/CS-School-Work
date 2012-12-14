/*
Paul Geromini
01056543

Assignment #6

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <time.h>

void printDetails(struct stat statBuf){

  char perms[10];
  struct passwd* pwd;
  struct group* group;
  int i;

  /* 
  File types :
  https://www.gnu.org/software/libc/manual/html_node/Testing-File-Type.html
  */

  if(S_ISDIR(statBuf.st_mode)){
    printf("Type: directory\n"); 
  }

  if(S_ISCHR(statBuf.st_mode)){
    printf("Type: character\n");
  }

  if(S_ISBLK(statBuf.st_mode)){
    printf("Type: block\n");
  }

  if(S_ISREG(statBuf.st_mode)){
    printf("Type: regular file\n");
  }

  if(S_ISFIFO(statBuf.st_mode)){
    printf("Type: pipe\n");
  }

  if(S_ISLNK(statBuf.st_mode)){
    printf("Type: link\n");
  }

  if(S_ISSOCK(statBuf.st_mode)){
    printf("Type: socket\n");
  }

  /* Write out file permissions */
  /* need null byte for string */
  perms[9] = '\0';

  /* Set all permissions to default */
  for(i = 0; i < 9; i++){
    perms[i] = '-';
  }

  /* change permission if the file has it */
  if(statBuf.st_mode & S_IRUSR){
    perms[0] = 'r'; 
  }

  if(statBuf.st_mode & S_IWUSR){
    perms[1] = 'w';
  }

  if(statBuf.st_mode & S_IXUSR){
    perms[2] = 'x';
  }

  if(statBuf.st_mode & S_IRGRP){
    perms[3] = 'r';
  }

  if(statBuf.st_mode & S_IWGRP){
    perms[4] = 'w';
  }

  if(statBuf.st_mode & S_IXGRP){
    perms[5] = 'w';
  }

  if(statBuf.st_mode & S_IWOTH){
    perms[6] = 'r';
  }

  if(statBuf.st_mode & S_IROTH){
    perms[7] = 'w';
  }
  if(statBuf.st_mode & S_IXOTH){
    perms[8] = 'x';
  }

  printf("Permissions: %s\n", perms);

  /* Owner info */
  if((pwd = getpwuid(statBuf.st_uid)) == NULL){
    printf("Owner: %d\n", statBuf.st_uid);
  } else {
    printf("Owner: %s\n", pwd -> pw_name);
  }

  /* Pgroup */
  if((group = getgrgid(statBuf.st_gid)) == NULL){
    printf("Group: %d\n", statBuf.st_gid);
  } else {
    printf("Group: %s\n", group -> gr_name);
  }

  /* Date info */
  printf("Last Modified: %s", ctime(&(statBuf.st_mtime)));
  printf("Links: %d\n", statBuf.st_nlink);

  /* Device type if applicable */
  if((S_ISCHR(statBuf.st_mode))|| S_ISBLK(statBuf.st_mode)) {
    printf("Major: %d, Minor %d\n", major(statBuf.st_rdev), minor(statBuf.st_rdev));
  } else {
    printf("Size: %d\n", statBuf.st_size);
    printf("I-Node Number: %d \n\n", statBuf.st_ino);
  }

}

int main(int argc, char *argv[]){

  struct stat statBuf;
  struct dirent* ent;
  DIR* dir;
  int i, j;

  /* Do we have cmd args */
  if (argc > 1){

  /* look at the files we got */
  /* start at 1 to ignore program name */
    for(i = 1; i < argc; i++){
      if(lstat(argv[i], &statBuf) == -1){
	printf("Lstat failed on this line: %s", argv[i]);
	exit(2);
      }

      /* Details about file */
      printf("File: %s\n", argv[i]);      
      printDetails(statBuf);

    }
  } else {
    /* open current directory */
    if((dir = opendir(".")) == NULL){
      printf("opendir failed.\n");
      exit(3);
    }

    /* read each file and print out some details */
    while((ent = readdir(dir)) != NULL){
      if(lstat(ent -> d_name, &statBuf) == -1){
        printf("Lstat failed.\n");
        exit(2);
      }

      /* Details about file */
      printf("File: %s\n", ent -> d_name);
      printDetails(statBuf);
      
    }
  }



  return 0; 

}
