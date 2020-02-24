#include "ps_header.h"

/*
** returns 0 if non-numerical characters or not-backspace found
** otherwise returns 1
*/

int check_if_num_backsp(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (!((av[i][j] >= '0' && av[i][j] <= '9') || av[i][j] == ' ' ||
			av[i][j] == '-' || av[i][j] == '+'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*
** check for duplicates in input
** if duplicates found return -3
** otherwise, if all is good return 1
*/

int		check_if_dupl(t_stacks *st, int **srt)
{
	int		j;

	*srt = make_me_sorted(st);
	j = 0;
	while (j < st->n - 1)
	{
		if ((*srt)[j] == (*srt)[j + 1])
		{
			free(st->a);
			st->a = NULL;
			free(st);
			st = NULL;
			free(*srt);
			*srt = NULL;
			return (-3);
		}
		j++;
	}
	return (1);
}
