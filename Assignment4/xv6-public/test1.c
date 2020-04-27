#include "types.h"
#include "user.h"
#include "fcntl.h"
#include "stat.h"

int main() {
  int ext_fd = open("extentfile1.txt", O_CREATE|O_RDWR|O_EXTENT);
	if(ext_fd < 0) {
		printf(2, "Cannot open Extent-Based file\n");
		exit();
	}
	printf(1, "Extent Based File Descriptor: %d\n", ext_fd);
	
	int norm_fd = open("pointerfile1.txt", O_CREATE|O_RDWR);
	if(norm_fd < 0) {
		printf(2, "Cannot open Pointer-Based File\n");
		exit();
	}
	printf(1, "Pointer-Based File Descriptor:: %d\n", norm_fd);

	char buffer[1024]; 
	for(int i = 0; i < 1024; i++) {
		buffer[i] = 's';
	}

	printf(1, "Attempting to write 28KB into extent-based file ... \n\n");
	
	for(int i = 0; i < 28; i++) {
		if(write(ext_fd, &buffer, 1024) != 1024) {
			printf(2, "Write failed\n");
		}
	}
	printf(1, "Attempting to write 70KB into extent-based file ... \n\n");
	for(int i = 0; i < 70; i++) {
		if(write(ext_fd, &buffer, 1024) != 1024) {
			printf(2, "Write failed\n");
		}
	}

	struct stat ext_info;
	if(fstat(ext_fd, &ext_info) == 0) {
		printf(1, "Extent-based File Size: %d\n", ext_info.size);
		int bcount = 0;
		for(int i = 0; i < 12; i++) {
			if(!ext_info.extents[i].len) {
				break;
			}
			bcount += ext_info.extents[i].len;
			printf(1, "Extent [%d] Address: %d, Length: %d\n", i, ext_info.extents[i].addr, ext_info.extents[i].len);
		}
		printf(1, "Total Blocks: %d\n", bcount);
	}
	printf(1, "Write to extent file successful. \n\n");
	printf(1, "Attempting to write 28KB into pointer-based file ... \n\n");

	for(int i = 0; i < 28; i++) {
		if(write(norm_fd, &buffer, 1024) != 1024) {
			printf(2, "Write failed\n");
			break;
		}
	}
	printf(1, "Attempting to write 70KB into pointer-based file ... \n\n");
	
	for(int i = 0; i < 70; i++) {
		if(write(norm_fd, &buffer, 1024) >= 1024) {
			printf(2, "Write failed\n");
			break;
		}
		
	}
	printf(1, "Write to pointer-based file unsuccessful. \n\n");
	struct stat norm_info;
	if(fstat(norm_fd, &norm_info) == 0) {
		printf(1, "Pointer-based File Size: %d\n", norm_info.size);
	}

	

	close(ext_fd);
	close(norm_fd);
	exit();
}
