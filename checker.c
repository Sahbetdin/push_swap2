#include "ps_header.h"




int	main(int ac, char **av)
{
	char *s;
	int n_am;	
	t_stacks	*st;
	int			*sorted;
	int res;

	st = NULL;
	if (ac == 1)
		return (0);

	res = set_st_a(ac, av, &st, &sorted);

	// printf("n = %d\n", st->n);
	if (res == 0)
		write(1, "\033[1;31mMalloc error in 'a'\n\033[0m", 24);
	else if (res == -1)
		write(1, "\033[1;31minput\n\033[0m", 18);
	else if (res == -2)
		write(1, "\033[1;31mInteger overflaw\n\033[0m", 28);
	else if (res == -3)
		write(1, "\033[1;31mDuplicates fou'nd\n\033[0m", 28);
	if (res == 0 || res == -1 || res == -2 || res == -3)
		return (0);
	res = set_st_b(st);
	if (res == 0)
		write(1, "\033[1;31mMalloc error in 'b'\n\033[0m", 24);
	res = set_st_b(st);
	if (res == 0)
		write(1, "\033[1;31mMalloc error in 'b'\n\033[0m", 24);

	while (get_next_line(0, &s) > 0)
	{
		res = action(st, s, 0);
		if (res != 1)
			write(1, "BAD INPUT\n", 10);
		// printf("%s\n", s);
		free(s);
	}
	if (check_stacks(st) == 1)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	free(st->a);
	free(st->b);
	free(st);
	free(sorted);
	return (0);
}