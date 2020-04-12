#include <stdio.h>
#include <stdlib.h>

//Similar concept to test1: allocate memory but not free it
//Now trying this with different types of variables

void test3()
{
	long *a = (long *)malloc(sizeof(long)); //8 bytes
	float *b = (float *)malloc(sizeof(float)); //4 bytes
	char *c = (char *)malloc(sizeof(char)); //1 byte
	double *d = (double *)malloc(sizeof(double)); //8 bytes
}

int main()
{
    test3();
    return 0;
}
