#include "ps_header.h"


void	print_piece(t_info piece0)
{
	printf("begin =  %d, ", piece0.begin);
	printf("end =    %d, ", piece0.end);
	printf("amount = %d, ", piece0.amount);
	printf("letter = %c\n", piece0.lt);
	printf("~~~~~~~~~~~~~\n");
}

void	print_arrays(t_stacks *st)
{
	int i;

	printf("\033[0;36m a:       \033[0m");
	printf("%3d,", st->pa);
	i = st->pa - 1;
	while (++i < st->n)
		printf("%4d", st->a[i]);
	printf("\n");

	printf("\033[0;36m b:      \033[0m ");
	printf("%3d,", st->pb);
	i = st->pb;
	while (++i < st->n)
		printf("%4d", st->b[i]);
	printf("\033[0;33m \n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n \033[0m");
}

/*
** print sorted array
*/

void	print_sorted(int *srt, int n)
{
	int i;

	i = -1;
	printf("               ");
	while (++i < n)
		printf(" %2d ", i);
	printf("\n");
	i = -1;
	printf("\033[0;32m sorted array:\033[0m ");
	while (++i < n)
		printf(" %2d ", srt[i]);
	printf("\n");
}
