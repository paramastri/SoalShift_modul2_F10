#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>

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

  if ((chdir("/home/paramastri/sisop19/modul2")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while(1) {
    	struct stat filenya;
	char path[100] = "hatiku/elen.ku";
	stat(path, &filenya);

	struct passwd *pass = getpwuid(filenya.st_uid);
	struct group *gro = getgrgid(filenya.st_gid);

	char own[100] = "www-data";

	int us = strcmp(pass->pw_name, own);
	int gr = strcmp(gro->gr_name, own);

	if(us==0 && gr==0)
	{
		remove(path);
	}
	sleep(3);
  }

  exit(EXIT_SUCCESS);
  return 0;
}

