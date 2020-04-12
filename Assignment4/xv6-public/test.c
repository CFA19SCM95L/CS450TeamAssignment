#include "types.h"
#include "stat.h"
#include "user.h"


int main(int argc, char *argv[]) {

  int id = fork();
  if (id < 0) {
    printf(1,"%d Failed");
  } else if ( id > 0) {             //parent process
    if (argc > 1) {                 //execute alsoNice if we pass an argument
      alsoNice(atoi( argv[1]));
    }
    for (int i = 0, j = 0; i < 200000; i++) {
      if ( i % 1000 == 0) {
        printf(1, "Parent pid %d: Print %d ......\n", getpid(), j++);
      }
    }
    printf(1, "Parent: Done\n");
  } else {              //child process
    for (int i = 0, j = 0; i < 200000; i++) {
      if ( i % 1000 == 0) {
        printf(1, "Child pid %d: Print %d ......\n", getpid(), j++);
      }
    }
    printf(1, "Child: Done\n");
  }
  exit();
   
}
