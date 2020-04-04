#include <stdlib.h>
#include <stdio.h>
//Response to Question 1 of Part 1 of PA3
int
main(void){
	
	int *var = (int *)malloc(sizeof(*var)); //memory is allocated here
	var[0] = 2020; //value is stored in assigned memory
	return 0; 
}
