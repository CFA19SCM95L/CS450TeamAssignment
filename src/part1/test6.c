#include <stdio.h>
#include <stdlib.h>

//Allocate insufficient memory and then try to write into it

void test6()
{
	int *val = malloc(1);//insufficient because an int variable occupies 4 bytes
	val[0] = 2020;
	free(val);
}

int main()
{
    test6();
    return 0;
}
