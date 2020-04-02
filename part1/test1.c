#include <stdlib.h>
#include <stdio.h>

void test1(){

	int *var = (int *)malloc(sizeof(*var));//allocate memory
	var[0] = 2020; //fill with some value
	free(var); //free allocated memory
}
int
main(void){

	test1();	
	return 0;
}


