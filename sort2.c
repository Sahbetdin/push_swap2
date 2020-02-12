#include "ps_header.h"

void	sort_2_elements(t_stacks *st, t_info *pc0)
{
	if (pc0->lett == 'A')
	{
	printf("WHILE SORTING 2 ELEMENTS from A\n");

	}
	else if (pc0->lett == 'B')
	{
		if (st->arr_b[st->ptr_b + 1] < st->arr_b[st->ptr_b + 2])
		{
			printf("WHILE SORTING 2 ELEMENTS from B first is less\n");
		}
		else
		{
			printf("WHILE SORTING 2 ELEMENTS from B second is less\n");

		}

	}
}