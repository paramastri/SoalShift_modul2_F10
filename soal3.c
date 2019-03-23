#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <dirent.h>


int main() {
  pid_t child_id;

  child_id = fork();
  
  int fd1[2];
  int fd2[2];
  pipe(fd1); // sets up 1st pipe
  pipe(fd2); // sets up 2nd pipe

  int status;
  int status2;

  if (child_id < 0) {
    exit(EXIT_FAILURE);
  }

  DIR *dir;

  if ((child_id == 0) && ((dir = opendir("/home/paramastri/sisop19/modul2/campur2")) == NULL) ) {
    // this is child
    
    char *argv[] = {"unzip", "/home/paramastri/sisop19/modul2/campur2.zip", NULL};
    execv("/usr/bin/unzip", argv);
    
  } else {
    // this is parent
    while ((wait(&status)) > 0);
    child_id = fork();
    if (child_id < 0) {
    exit(EXIT_FAILURE);
  }
    if (child_id == 0) {
    // this is child
    
    char *argv[] = {"ls", "/home/paramastri/sisop19/modul2/campur2", NULL};
    dup2(fd1[1],1);
    close(fd1[0]);
    close(fd2[0]);
    close(fd2[1]);
    execv("/bin/ls", argv);

    } else
        {
        pid_t child_id2;
        child_id2 = fork();
        if (child_id2 == 0) {
        // this is child
        while ((wait(&status2)) > 0);
        char *argv[] = {"grep", ".txt$", NULL};
        dup2(fd1[0],0);
        close(fd1[1]);
        close(fd2[0]);
        dup2(fd2[1],1);
        execv("/bin/grep", argv);

        }
        else
        {

          FILE *file = fopen("/home/paramastri/sisop19/modul2/daftar.txt", "w+");
          close(fd1[0]);
          close(fd1[1]);
          close(fd2[1]);
          char str[10000];
          read(fd2[0],str,sizeof(str));
          fputs(str,file);
        }

    }
    
  }
}

