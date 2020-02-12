#include <stdlib.h>
#include <stdio.h>

int main()
{

	int *a;

	a = (int *)malloc(sizeof(int) * 10);
	if (a + 10)
		printf("YES");
	else
		printf("NO");
	return (0);
}

//если gcc tst.c && ./a.out то пишет YES
//если пошагово сначала компилировать, затем запускать, то NO