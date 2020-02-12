#include <stdio.h>

int main()
{

	int i;
	int s;
	int d1, d2, d3;

	i = 0;
	s = 0;
	while (i < 130)
	{
		d1 = i / 100;
		d2 = (i - d1 * 100) / 10;
		d3 = i - d1 * 100 - d2 * 10;
		s = s + d1 + d2 + d3;
		// printf("d = %d\n", d);
		i++;
	}
	printf("s = %d\n", s);
	return (0);
}