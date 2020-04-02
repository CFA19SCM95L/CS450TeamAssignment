#include <stdio.h>
#include <stdlib.h>

//Invalid read operation: Trying to read value at memory after freeing it
void
test4()
{
	int *d = malloc(sizeof(*d)); //allocating 4 byte of memory in heap
	d[0] = 2020; 
	free(d);
	printf("Value stored in d is: %d\n", d[0]); //illegal access because d has already been freed 
}

int main()
{
    test4();
    return 0;
}
