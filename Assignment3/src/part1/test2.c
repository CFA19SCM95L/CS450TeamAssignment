#include <stdio.h>
#include <stdlib.h>

//Allocating memory with malloc() but not freeing it before exiting

void test2()
{
    int *a = malloc(sizeof(*a));
    *a = 10;
    printf("Value of a is: %d\n", *a);
}

int main()
{
    test2();
    return 0;
}


