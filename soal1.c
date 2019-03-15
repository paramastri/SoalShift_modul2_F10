#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include<dirent.h>

int main() {
  pid_t pid, sid;

  pid = fork();

  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();

  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir("/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while(1) {
    // main program here
    DIR *dir;

    struct dirent *sd;
    const char *filename,*oldfile,*newfile;
    char newfilename[999];
    char dest[999],src[999];
    if((dir = opendir("/home/paramastri/sisop19/modul2")) == NULL){
		printf("tidak bisa buka folder.\n");
		return 0;
	  }

	  while((sd=readdir(dir)) != NULL )
	    {
        if(strcmp(strchr(sd->d_name,'.'),".png") == 0){
        strcpy(src,"/home/paramastri/sisop19/modul2/");
        oldfile = strcat(dest,sd->d_name);

        filename = strtok (sd->d_name,".");
        strcpy(newfilename,filename);
        strcat(newfilename,"_grey.png");

        strcpy(dest,"/home/paramastri/modul2/gambar/");
        newfile = strcat(dest,newfilename);
        rename(oldfile,newfile);
        }
	}
	
	  closedir(dir);
    sleep(30);
  }
  
  exit(EXIT_SUCCESS);
}
