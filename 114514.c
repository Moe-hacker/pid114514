#define _GNU_SOURCE
#include <linux/prctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <signal.h>
#include <sys/prctl.h>
#include <sys/stat.h>
#include <wait.h>
int main(){
  if(getpid()>114514){
    printf("Error: pid 114514 is already in use\n");
    exit(1);
  }
  FILE *ps;
  char *buf;
  ps=popen("ps -ae|grep 1919810", "r");
  while (fgets(buf, sizeof(buf), ps)==NULL) {
    pid_t pid=fork();
    if (pid==0){
      if (getpid()<=114513) {
        printf("\033[1;38;2;114;51;4m%s%d\033[0m\n","Pid now: ",getpid());
        exit(0);
      }else{
        printf("\033[1;38;2;114;51;4m%s\033[0m\n","Pid now: 114514");
        prctl(PR_SET_NAME,"1919810",NULL,NULL,NULL);
        while (1){
          sleep(1);
        }
      }
    }
    waitpid(pid,NULL,0);
  }
  return 0;
}
