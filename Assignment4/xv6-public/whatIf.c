#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char buf[512];
int n;
int fd1;
int fd2;
int fd3;
int p[2];

void whatIf(int fd) {

  while((n = read(fd, buf, sizeof(buf))) > 0) { //read from user input
    char temp[512];
    strcpy(temp, buf);
    temp[strlen(temp) - 1] = 0;
    
    if((fd1 = open(temp, O_RDONLY)) < 0){   //usertype != program
      pipe(p);
      int rc = fork();
      if (rc == 0) {
        int rc = fork();
        if (rc == 0) {
          dup(p[0]);
          fd3 = open("child.txt", O_CREATE|O_RDWR);
          char temp1[512]; 
          read(fd3, temp1, sizeof(temp1));  
          write( fd3 , buf, n);
        } 
      } else {
        fd2 = open("parent.txt", O_CREATE|O_RDWR);
        char temp1[512];
        read(fd2, temp1, sizeof(temp1)); 
        write( fd2 , buf, n);    
      }
    } else {                               //usertype == program
      printf(1,"program exist, Copy file\n");
      int rc = fork();
      if (rc == 0) {
        fd3 = open("child.txt", O_CREATE|O_RDWR);
        char temp1[512];
        read(fd3, temp1, sizeof(temp1)); 
        int fd4 = open(temp, O_RDONLY);   // To avoid error, open a new file instead sharing fd1
        while ((n = read (fd4, buf, sizeof(buf))) > 0) {
          write( fd3 , buf, n);
        } 
      } else {
        fd2 = open("parent.txt", O_CREATE|O_RDWR);
        char temp1[512];
        read(fd2, temp1, sizeof(temp1)); 
        while ((n = read (fd1, buf, sizeof(buf))) > 0) {
          write( fd2 , buf, n);
        } 
      }  
    }
  }
}

int main(int argc, char *argv[]) {
  if(argc > 1){
    printf(1, "No argument needed!\n");
    exit();
  }
  int rc = fork();
  if (rc == 0) {
    whatIf(0);
  } else
  {
    wait();
    close(fd1);
    close(fd2);
    close(fd3);
    exit();
  }  
  exit();
}
