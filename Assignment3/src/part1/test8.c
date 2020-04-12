#include <stdio.h>
#include <stdlib.h>

//Possible memory leak example.

void test8()
{
	char *s = "Hello World";
	char *d = strdup(s);
	d+=1;
	exit(1);
	d-=1;
	free(d);
	
}

int main()
{
    test8();
    return 0;
}
