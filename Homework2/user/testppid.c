#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(void){

  int ret = fork();

  if(ret < 0){
    printf("fork failed\n");
    exit(1);
  }

  if(ret == 0){ // child
    printf("Child process:\n");
    printf("pid=%d\n", getpid());
    //printf("ppid=%d\n", getppid());

  } 
  else {// parent
    wait(0);
    printf("Parent process:\n");
    printf("pid=%d\n", getpid());
  }

  exit(0);
}
