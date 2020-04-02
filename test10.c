#include <stdio.h>
#include <stdlib.h>

//Allocate memory correctly using malloc(). Requested memory is assigned
//to specific pointer(*val in this case)
//But after that changing the assigned address of *val to NULL
//This loses track of the assigned memory as the pointer is redirected.
//so that now the assigned pointer points to NULL

void test10()
{
	int *val = malloc(sizeof(*val));
	val[0] = 2020;
	val = NULL; //2020 exists in user address space but no one can reach it now since the pointer to that address is lost.
}

int main()
{
    test10();
    return 0;
}
