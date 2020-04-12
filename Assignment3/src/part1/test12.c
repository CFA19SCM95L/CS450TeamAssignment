#include <stdio.h>
#include <stdlib.h>

//

void test12()
{
	int i;
	const int ARR_SIZE = 19;
	int *arr = malloc(ARR_SIZE * sizeof(*arr));
	for(i = 0; i<ARR_SIZE;i++)
	{
	  if((arr = NULL)){
		arr = malloc(ARR_SIZE*sizeof(*arr));
		}

	}
	free(arr);
}

int main()
{
    test12();
    return 0;
}

