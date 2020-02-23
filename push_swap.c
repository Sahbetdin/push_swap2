#include "ps_header.h"

int main(int ac, char **av)
{
	int			i;
	t_stacks	*st;
	int			*sorted;

	st = NULL;
	if (ac == 1)
		return (0);
	i = set_st_a(ac, av, &st, &sorted);
	// printf("n = %d\n", st->n);
	if (i == 0)
		write(1, "\033[1;31mMalloc error in 'a'\n\033[0m", 24);
	else if (i == -1)
		write(1, "\033[1;31mNo numerical input\n\033[0m", 31);
	else if (i == -2)
		write(1, "\033[1;31mInteger overflaw\n\033[0m", 28);
	else if (i == -3)
		write(1, "\033[1;31mDuplicates fou'nd\n\033[0m", 28);
	if (i == 0 || i == -1 || i == -2 || i == -3)
		return (0);
	i = set_st_b(st);
	if (i == 0)
		write(1, "\033[1;31mMalloc error in 'b'\n\033[0m", 24);
	// print_sorted(sorted, st->n);

	t_info *pc;
	int n;
	n = 100; 
	if (!(pc = (t_info *)malloc(sizeof(t_info) * 100)))
		return (0);

	set_first_info(pc + 1, st->n); //we start from 1st, because in some time,
	//as instanse in sort_top_top(...), we can access pc[-1]

	// print_sorted(sorted, st->n);
	// print_arrays(st);

	// process_stacks(st, pc, sorted);
	// process_stacks(st, pc, sorted);
	// process_stacks(st, pc, sorted);
	// process_stacks(st, pc, sorted);
	// process_stacks(st, pc, sorted);
	// process_stacks(st, pc, sorted);
	// process_stacks(st, pc, sorted);
	// process_stacks(st, pc, sorted);
	// process_stacks(st, pc, sorted);
	// process_stacks(st, pc, sorted);
	// process_stacks(st, pc, sorted);
	// process_stacks(st, pc, sorted);
	// process_stacks(st, pc, sorted);
	// process_stacks(st, pc, sorted);
	// process_stacks(st, pc, sorted);
	// process_stacks(st, pc, sorted);
	// print_arrays(st);
	// process_stacks(st, pc, sorted);
	// print_arrays(st);

	// process_stacks(st, pc, sorted);
	// print_arrays(st);

	// process_stacks(st, pc, sorted);
	// print_arrays(st);

	// process_stacks(st, pc, sorted);
	// print_piece(pc[0]);
	// print_piece(pc[1]);
	// print_piece(pc[2]);
	// print_arrays(st);
// print_sorted(sorted, st->n);
// printf("check = %d\n", check_stacks(st));

	// process_stacks(st, pc, sorted);
	// print_arrays(st);



	while (check_stacks(st) == 0)
	{
		process_stacks(st, pc, sorted);
	}
	// print_arrays(st);


	free(st->a);
	free(st->b);
	st->a = NULL;
	st->b = NULL;
	free(st);
	st = NULL;


	
	return (0);
}