#include <stdio.h>

//function returns maximum from 3 numbers
int give_max_from_3(int a, int b, int c)
{
	int max;

	if (a > b)
		max = a;
	else
		max = b;
	if (c > max)
		max = c;
	return (max);
}

//функция возвращает длину дорожки, состоящей из 2-х цветов
int give_length_from_2_colors(int a, int b)
{
	int chislo;
	int min;

	min ??

	if (a == b)
		chislo = a + b;
	else
		chislo = 2 * min + 1;

}

int main()
{
	int x, y, z;

	scanf("%i", &x);
	scanf("%i", &y);
	scanf("%i", &z);

	printf("max = %i\n", give_max_from_3(x, y, z));
	return 0;
}