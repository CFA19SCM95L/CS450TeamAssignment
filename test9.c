#include <stdio.h>
#include <stdlib.h>

//Memory check demonstrating error due to uninitialized value

void test9()
{
	int i;
	printf("i : %d\n", i);
}

int main()
{
    test9();
    return 0;
}
