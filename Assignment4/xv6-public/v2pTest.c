#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]) {

	printf(1,"\n============================\n");
	printf(1,"Test Case1: pass 100, Read...\n");
	printf(1,"\n============================\n\n\n");
	myV2p( 100,1);		//read
	printf(1,"\n============================\n");
	printf(1,"Test Case2: pass 100, Write...\n");
	printf(1,"\n============================\n\n\n");
	myV2p( 100,2);		//write

	printf(1,"\n============================\n");
	printf(1,"Test Case3: pass 500, Read...\n");
	printf(1,"\n============================\n\n\n");
	myV2p( 500,1);		//read
	printf(1,"\n============================\n");
	printf(1,"Test Case4: pass 500, Write...\n");
	printf(1,"\n============================\n\n\n");
	myV2p( 500,2);		//write

	printf(1,"\n============================\n");
	printf(1,"Test Case5: pass 1000, Read...\n");
	printf(1,"\n============================\n\n\n");
	myV2p( 1000,1);		//read
	printf(1,"\n============================\n");
	printf(1,"Test Case6: pass 1000, Write...\n");
	printf(1,"\n============================\n\n\n");
	myV2p( 1000,2);		//write


	printf(1,"\n============================\n");
	printf(1,"Test Case7: pass 10000, Read...\n");
	printf(1,"\n============================\n\n\n");
	myV2p( 10000,1);		//read
	printf(1,"\n============================\n");
	printf(1,"Test Case8: pass 10000, Write...\n");
	printf(1,"\n============================\n\n\n");
	myV2p( 10000,2);		//write

	printf(1,"\n============================\n");
	printf(1,"Test Case9: pass 20000, Read...\n");
	printf(1,"\n============================\n\n\n");
	myV2p( 20000,1);		//read
	printf(1,"\n============================\n");
	printf(1,"Test Case10: pass 20000, Write...\n");
	printf(1,"\n============================\n\n\n");
	myV2p( 20000,2);		//write


	printf(1,"\n============================\n");
	printf(1,"Increasing the memory...\n");
	printf(1,"\n============================\n\n\n");
	sbrk(4096 * 2);


	printf(1,"\n============================\n");
	printf(1,"Test Case11: Again, pass 20000, Read...\n");
	printf(1,"\n============================\n\n\n");
	myV2p( 20000,1);		//read
	printf(1,"\n============================\n");
	printf(1,"Test Case12: Again, pass 20000, Write...\n");
	printf(1,"\n============================\n\n\n");
	myV2p( 20000,2);		//write

	printf(1,"\n============================\n");
	printf(1,"Decreasing the memory...\n");
	printf(1,"\n============================\n\n\n");
	sbrk(-8192);


	printf(1,"\n============================\n");
	printf(1,"Test Case13: Again, pass 20000, Read...\n");
	printf(1,"\n============================\n\n\n");
	myV2p( 20000,1);		//read
	printf(1,"\n============================\n");
	printf(1,"Test Case14: Again, pass 20000, Write...\n");
	printf(1,"\n============================\n\n\n");
	myV2p( 20000,2);		//write

	printf(1,"\n============================\n");
	printf(1,"Test Case15: Passing a vary large address\n");
	printf(1,"\n============================\n\n\n");
	myV2p( 1000000000,1);		//write

	printf(1,"\n============================\n");
	printf(1,"Test Case16: Passing a wrong operation(3)\n");
	printf(1,"\n============================\n\n\n");
	myV2p( 100,3);		//writez







	exit();
}