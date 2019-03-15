#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>

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

if ((chdir("/home")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

int urutan = 1;
char path[100];
strcpy(path,"/home/paramastri/Documents/makanan/makan_enak.txt");

while(1) {
    struct stat filenya;
    stat(path, &filenya);

	time_t akses_file;
	time_t akses_program;
	akses_file = filenya.st_atime;
	akses_program = time(NULL);

	double jangka_waktu = difftime(akses_program, akses_file);

        if(jangka_waktu <= 30)
        {
				FILE *buka;
                char filenya_baru[100];
                strcpy(filenya_baru,"/home/paramastri/Documents/makanan/makan_sehat");

                char tambahan[100];
                sprintf(tambahan, "%d", urutan);
                strcat(filenya_baru, tambahan);
                strcat(filenya_baru, ".txt");
                buka = fopen(filenya_baru, "w");
                fclose(buka);
                urutan++;
        }

    	sleep(5);
	}
	exit(EXIT_SUCCESS);
}
