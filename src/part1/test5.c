#include <stdio.h>
#include <stdlib.h>

//Invalid write operation: Writing to memory after freeing it

void test5()
{
	int *val = malloc(sizeof(*val));//allocates memory that's the size of whatever the type of variable val is(in this case int)
	val[0] = 2019;
	free(val); 
	val[0] = 2020;
}

int main()
{
    test5();
    return 0;
}
