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

  while(1) {
    // main program here
        time_t waktu_log;
        time(&waktu_log);
        int i;
        struct tm *waktu;

        //mengkonversi raw time di time_t biar jd kepisah pisah hari jam bulan
        waktu = localtime(&waktu_log);
        char a[100];
        char pisah_waktu[100];
        sprintf(pisah_waktu, "%d:%d:%d-%d:%d", waktu->tm_mday, waktu->tm_mon+1,$
        printf("%s", pisah_waktu);
        sprintf(a, "/home/paramastri/sisop19/modul2/log5/%s", pisah_waktu);
        mkdir(a, 0777); //777 biar bisa akses semua
        for(i=1; i<30; i++){
                FILE *file_sys, *file_baru;
                file_sys = fopen("/var/log/syslog", "r");
                char nama_file[100];
                sprintf(nama_file, "/home/paramastri/sisop19/modul2/log5/%s/log%d.log", pisah_waktu, i);
                file_baru = fopen(nama_file, "w");
                //pindah seluruh isi file ke log$#.log
                char karakter;
                while(fscanf(file_sys, "%c", &karakter) != EOF)
                {fprintf(file_baru, "%c", karakter);}
                fclose(file_sys);
                fclose(file_baru);
                sleep(60);
        }
  }
  exit(EXIT_SUCCESS);
}

