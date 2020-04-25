#include "types.h"
#include "user.h"
#include "fcntl.h"

int main (int argc, char *argv[]) {
	int fileDescriptor = 0;
        int child = 0;
        int parent = 0;
        int sizebuffer;//stores the size of the buffer 
	if (argc == 2) { //if number of arguments entered into cmd line ==2 
		fileDescriptor = open (argv[1], O_RDONLY); //opens a file to read, filename specified in the second argument entered in cmd line
	
		if (fileDescriptor < 0) {//valid file does not exist
			printf (2, "File %s does not exist\n", argv[1]);
			exit(); //exits the program
		}
	}

	//creates and opens parent.txt and child.txt for writing and reading
	child = open ("child.txt", O_CREATE|O_WRONLY);
	parent = open ("parent.txt", O_CREATE|O_WRONLY);

	while (1) {
		char buffer[512];
		sizebuffer = sizeof(buffer);//specifies size of buffer
		memset (buffer, 0, sizebuffer);
		gets(buffer, sizebuffer);
		if (buffer[0] == 0) {
			break;
		}
		if (fork() == 0) {
			write (child, buffer, strlen(buffer));
			break;
		}
		else {
			write (parent, buffer, strlen(buffer));
			wait();
		}
	}
	exit();
}
