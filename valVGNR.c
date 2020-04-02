#include <stdio.h>
#include <stdlib.h>

void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void test8();

int main(){
    //test1();
    test2();
    //test3();
    //test4();
    //test5();
    //test6();
    //test7();
    //test8();
    return 0;
}

//Allocating memory but not freeing
void test1(){
    int *a = (int *)malloc(sizeof(int));
    return;
}

//Allocating memory of different types but not freeing
void test2(){
    char *b = (char *)malloc(sizeof(char));
    long *a = (long *)malloc(sizeof(long));
    float *f = (float *)malloc(sizeof(float));
    double *d = (double *)malloc(sizeof(double));
    return;
}

//Allocating insufficient memory and then writing to it : Invalid write of size 4
void test3(){
    int* value = malloc(1);
    value[0] = 10;
    free(value);
    return;
}

//Reading memory after freeing : Invalid read operation
void test4(){
    int* value = malloc(sizeof(int));
    value[0] = 10;
    free(value);
    printf("Value is %d",value[0]);
    return;
}

//Writing to memory after freeing : Invalid write operation
void test5(){
    int* value = malloc(sizeof(int));
    value[0] = 10;
    free(value);
    value[0] = 90;
    return;
}

//Memory is lost when changning the pointer to point to somethins else like NULL
void test6(){
    int* value = malloc(sizeof(int));
    value[0] = 10;
    value = NULL;
    return;
}

char *helper(){
    char msg[100] = "Hello World";
    char *p = msg;
    return p;
}

//Calling another function
void test7(){
    char *message = helper();
    printf("Value is %s  :", message);
}

//Valid operations with memory
void test8(){
    int* value = malloc(sizeof(int));
    value[0] = 10;
    free(value);
    return;
}
