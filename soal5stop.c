#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <signal.h>

int main()
{
        int panjang = 50;
        char proses[panjang];
        FILE * command = popen("pidof soal5","r");

        fgets(proses, panjang, command);

        pid_t pid = strtoul(proses, NULL, 10);
        kill(pid, SIGKILL);
        pclose(command);
}
