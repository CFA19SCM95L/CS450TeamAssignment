#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]) {

	int pid = getpid();



	printf(1, "\n===========================================\n");
	printf(1, "> Test 1 : Init page information...\n");
	printf(1, "\n============================================\n");

	hasPages(pid);

	printf(1, "\n===========================================\n");
	printf(1, "> Test 2 : Add 1024 bytes...\n");
	printf(1, "\n============================================\n");

	printf(1, "Adding 1024 bytes to memory...\n");
	sbrk(1024);
	hasPages(pid);

	printf(1, "\n===========================================\n");
	printf(1, "> Test 3 : Decrease 1024 bytes...\n");
	printf(1, "\n============================================\n");

	sbrk(-1024);
	hasPages(pid);

	printf(1, "\n===========================================\n");
	printf(1, "> Test 4 : Add 2048 bytes...\n");
	printf(1, "\n============================================\n");

	printf(1, "Adding 2048 bytes to memory...\n");
	sbrk(2048);
	hasPages(pid);

	sbrk(-2048);

	printf(1, "\n===========================================\n");
	printf(1, "> Test 5 : Add 4096 bytes...\n");
	printf(1, "\n============================================\n");

	printf(1, "Adding 4096 bytes to memory...\n");
	sbrk(4096);
	hasPages(pid);

	sbrk(-4096);

	printf(1, "\n===========================================\n");
	printf(1, "> Test 6 : Add 4097 bytes...\n");
	printf(1, "\n============================================\n");

	printf(1, "Adding 4097 bytes to memory...\n");
	sbrk(4097);
	hasPages(pid);

	printf(1, "\n===========================================\n");
	printf(1, "> Test 7 : Passing a non-existed pid\n");
	printf(1, "\n============================================\n");
	hasPages(-1);
	exit();
}