#include <stdio.h>
#include <stdlib.h>

//

char *justanotherfunc(void)
{
	char string[20] = "Year 2020";
	char *dup = string;
	return dup;

}
void test11()
{
	char *input = justanotherfunc();
	printf("Value returned from JustAnotherFunc(): %s", input);
}

int main()
{
    test11();
    return 0;
}
