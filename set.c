
#include "ps_header.h"

void	set_arr_to_zero(int *b, int n)
{
	int i;
	i = -1;
	while (++i < n)
		b[i] = 0;
}


int		set_st_a(int ac, char **av, t_stacks **st, int **sorted)
{
	int i;
	int j;
	int cnt; //arg length
	int n;
	char *trimi;

//check if input consists of numbers and backspaces
	if (check_if_num_backsp(ac, av) == 0)
		return (-1);
//number of available arguments
	if (!(*st = (t_stacks *)malloc(sizeof(t_stacks))))
		return (0);
	if ((cnt = amount_of_numb(ac, av)) != -1)
		(*st)->n = cnt;
	else
		return (0);
	if (!((*st)->a = (int *)malloc(sizeof(int) * (*st)->n)))
		return (0);
//parse arguments
	i = 1;
	j = 0;
	while (i < ac)
	{
		trimi = ft_strtrim(av[i]);
		if (parse_all_args((*st), trimi, &j, &n) == -2)
			return (-2);
		i++;
		free(trimi);
	}
	if (check_if_dupl(*st, sorted) == -3)
		return (-3);
	return (1);
}


int set_st_b(t_stacks *st)
{
	if (!(st->b = (int *)malloc(sizeof(int) * st->n)))
		return (0);
	set_arr_to_zero(st->b, st->n);
	st->oper = 0;
	st->pa = 0;
	st->pb = st->n - 1;
	return (1);
}
