#include "types.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]) {
	int fd1;
	fd1 = open("file", O_CREATE | O_RDWR);
	printf(fd1,"A long string for testing the normal file.\n");
    int fd2;
    fd2 = open("eFile", O_CREATE | O_EXTENT | O_RDWR);
	printf(fd2,"A long string for testing the extent file.\n");
	
    printf(1,"==============================================\n\n");
    printf(1,"Test1: pass a negative offset\n");    
    printf(1,"Expect:\nError message\n");
    printf(1,"==============================================\n\n");

	if (lseek(fd1,-1) < 0 ) {
		printf(1, "Cannot pass a negative offset\n");
	}

    printf(1,"\n\n\n\n==============================================\n\n");
    printf(1,"Test2: pass an empty fd\n");    
    printf(1,"Expect:\nError message\n");
    printf(1,"==============================================\n\n");
	if (lseek(10,1) < 0 ) {
		printf(1, "Cannot pass an empty fd\n");
	}

    printf(1,"\n\n\n\n==============================================\n\n");
    printf(1,"Test3: pass a very large offset\n");    
    printf(1,"Expect:\nError message\n");
    printf(1,"==============================================\n\n");
    if (lseek(fd1,100000000) < 0 ) {
		printf(1, "Cannot pass an offset which is grater than file size\n");
	}

    printf(1,"\n\n\n\n==============================================\n\n");
    printf(1,"Test4: lseek on a normal file then read\n");
    printf(1,"Before:\nA long string for testing the normal file.\n");
    printf(1,"Expect:\ng string for testing the normal file.\n");
    printf(1,"==============================================\n\n");
    printf(1,"\n/Start at offset:5/\n");
    lseek(fd1,5);
    char buffer[512];
    read(fd1,buffer,sizeof(buffer));
    printf(1,buffer);


    printf(1,"\n\n\n\n==============================================\n\n");
    printf(1,"Test5: lseek on a normal file then write\n");    
    printf(1,"Before:\nA long string for testing the normal file.\n");
    printf(1,"Expect:\nA lon writingTest testing the normal file.\n");
    printf(1,"==============================================\n\n");
        printf(1,"\n/Start at offset:5/\n");

    lseek(fd1,5);
	write(fd1," writingTest ",13);
    lseek(fd1,0);
    char buffer2[512];
    read(fd1,buffer2,sizeof(buffer2));
    printf(1,buffer2);

    printf(1,"\n\n\n\n==============================================\n\n");
    printf(1,"Test6: lseek on an extent file then read\n");    
    printf(1,"Before:\nA long string for testing the extent file.\n");
    printf(1,"Expect:\ng string for testing the extent file.\n");
    printf(1,"==============================================\n\n");  
    printf(1,"\n/Start at offset:5/\n");
  
    lseek(fd2,5);
    char buffer3[512];
    read(fd2,buffer3,sizeof(buffer3));
    printf(1,buffer3);

    printf(1,"\n\n\n\n==============================================\n\n");
    printf(1,"Test7: lseek on an extent file then write\n");    
    printf(1,"Before:\nA long string for testing the extent file.\n");
    printf(1,"Expect:\nA lon writingTest testing the extent file.\n");
    printf(1,"==============================================\n\n");
    printf(1,"\n/Start at offset:5/\n");

    lseek(fd2,5);
	write(fd2," writingTest ",13);
    lseek(fd2,0);
    char buffer4[512];
    read(fd2,buffer4,sizeof(buffer4));
    printf(1,buffer4);

    printf(1,"\n\n\n\n==============================================\n\n");
    printf(1,"Test8: lseek on the parent and child process\n");    
    printf(1,"Before:\nA lon writingTest testing the normal file.\n");
    printf(1,"Expect:\nlon / writingTest\n");
    printf(1,"==============================================\n\n");

    int rc = fork();
    if (rc == 0) {
        printf(1, "/Offset: 2, read: 4/\n");
        printf(1,"Child process:\n");
        lseek(fd1,2);
        char buffer5[512];
        read(fd1,buffer5,4);
        printf(1,buffer5);        
    } else if (rc > 0) {
        wait();
        printf(1,"Parent process:\n");
        char buffer6[512];
        read(fd1,buffer6,11);
        printf(1,buffer6);  

    }
    printf(1,"\n\n");
	close(fd1);
	close(fd2);
	exit();
}