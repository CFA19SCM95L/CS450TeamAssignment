#include "types.h"
#include "stat.h"
#include "user.h"




int main(int argc, char *argv[]) {
  int p[2];
  if(argc <= 1){
    printf(1, "Need 1 arguments!\n");
    exit();
  }
  pipe(p);
  int rc = fork();
  if (rc < 0) { // fork failed; exit
    printf(1,"Fail to execute");
  } else if (rc == 0) { // child (new process)
    rc = fork();
    if (rc == 0) {
      dup(p[0]);
      argv++;

      exec(argv[0], argv); 
      printf(1,"Cannot find the application\n");
      close(rc);
      exit();
    }
  } else { // parent goes down this path (main)
    wait();
    exit();
  }
  exit();
}

