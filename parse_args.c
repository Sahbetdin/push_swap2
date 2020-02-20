#include "ps_header.h"

char	*ft_atoi_backsp(const char *str, int *p_numb, int *n);

int		free_st_a_overflaw(t_stacks *st)
{
	free(st->a);
	st->a = NULL;
	free(st);
	st = NULL;
	return (-2);
}

int		free_st_a_dupl(t_stacks *st)
{
	free(st->a);
	st->a = NULL;
	free(st);
	st = NULL;
	return (-3);
}

int	*make_me_sorted(t_stacks *st)
{
	int *sorted;
	int i;

	sorted = (int *)malloc(sizeof(int) * st->n);
	i = -1;
	while (++i < st->n)
		sorted[i] = st->a[i];
	sort_array(sorted, st->n);
	return (sorted);
}

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
			if (!((av[i][j] >= '0' && av[i][j] <= '9') || av[i][j] == ' '))
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
	int		*sorted;
	int		j;

	*srt = make_me_sorted(st);
	j = 0;
	while (j < st->n - 1)
	{
		if ((*srt)[j] == (*srt)[j + 1])
			return (free_st_a_dupl(st));
		j++;
	}
	return (1);
}

/*
** amount of numbers in av[i]
*/

int amount_of_numb_in_one_av(char *str)
{
	int flag;
	char *trimi;
	int amount_in_one;
	int j;

	if (!(trimi = ft_strtrim(str)))
		return (-1);
	flag = 0;
	amount_in_one = 0;
	j = 0;
	while (trimi[j] != '\0')
	{
		if (trimi[j] == ' ' && flag == 0)
		{
			amount_in_one++;
			flag = 1;
		}
		else if (trimi[j] != ' ' && flag == 1)
			flag = 0;
		j++;
	}
	amount_in_one++;
	free(trimi);
	return(amount_in_one);
}

int amount_of_numb(int ac, char **av)
{
	int i;
	int curr;
	int amount;

	i = 1;
	amount = 0;
	while (i < ac)
	{
		if ((curr = amount_of_numb_in_one_av(av[i])) != -1)
			amount += curr;
		else
			return(-1);
		i++;
	}
	return(amount);
}


int parse_all_args(t_stacks *st, char *ptr, int *j_addr, int *n_addr)
{
	if (ft_strchr(ptr, ' '))
	{
		while (ptr != NULL && *ptr != '\0')
		{
		ptr = ft_atoi_backsp(ptr, st->a + *j_addr, n_addr);
		if (*n_addr == -1)
			return (free_st_a_overflaw(st));
		(*j_addr)++;
		}
	}
	else
	{
		ptr = ft_atoi_backsp(ptr, st->a + *j_addr, n_addr);
		if (*n_addr == -1)
			return (free_st_a_overflaw(st));
		(*j_addr)++;
	}
	return (1);
}

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
	st->b = (int *)malloc(sizeof(int) * st->n); ///???????????????????????
	set_arr_to_zero(st->b, st->n);
	st->oper = 0;
	st->pa = 0;
	st->pb = st->n - 1;
	return (1);
}



void	process_stacks(t_stacks *st, t_info *pc, int *sorted)
{
	int i; //for pieces
	int j; //for counter during one piece processing
	int h; //one more counter to see if there are stacked pieces
	int count;
	int rot_cnt;
	int need_to_push;
	int k; //we push to another stack until k == need_to_push
	int flag;
	int last;
	int ii; //чтобы искать i для в другом стеке

	i = 0;
	while (i < 100)
	{
		if (pc[i].amount != 0 && pc[i + 1].amount == 0)
			break;
		i++;
	}
	// printf("in processing i = %d\n", i);
	if (pc[i].amount > 4)
	{
		count = pc[i].amount;

		flag = 1;

		if (pc[i].lt == 'A')
			last = st->a[st->n - 1];
		else if (pc[i].lt == 'B')
			last = st->b[st->n - 1];
		if (last >= sorted[pc[i].begin] && last <= sorted[pc[i].end - 1])
			flag = 0;
		printf("last = %d, flag = %d\n", last, flag);

		// if (pc[i].lt == 'A')
		// 	printf("st->a[st->pa +amount] = %d\n", st->a[st->pa + pc[i + 1].amount]);

		// // printf("st->pa = %d, n = %d\n", st->pa, st->n);
		// // else if (pc[i].lt == 'B')
		// // 	printf("st->b[st->pb + 1] = %d\n", st->b[st->pb + 1]);
		// flag = 0;
		// if (pc[i].lt == 'A' && sorted[pc[i].begin] > st->a[st->pa + pc[i].amount])
		// 	flag = 1;
		// else if (pc[i].lt == 'B' && sorted[pc[i].begin] > st->b[st->pb + 1 + pc[i].amount])
		// 	flag = 1;

		// printf("flag = %d\n", flag);

		divide_piece_info(pc + i, 1);
		if (pc[i + 1].amount > 3)
			divide_piece_info(pc + i + 1, 0);
		// print_piece(pc[i]);
		// print_piece(pc[i + 1]);
		// print_piece(pc[i + 2]);

		

		need_to_push = pc[i + 1].amount + pc[i + 2].amount;
		// printf("here\n");

		// print_piece(pc[i]);
		// print_piece(pc[i + 1]);
		// printf("here\n");
		// printf("need_to_push = %d\n", need_to_push);
		// print_piece(pc[i + 1]);

		// if (pc[i].lt == 'A')
		// 	count = st->n - st->pa;
		// else if (pc[i].lt == 'B')
		// 	count = st->n - st->pb - 1;

		// printf("count = %d\n", count);
		j = 0;
		// printf("%d %d\n", sorted[pc[i].begin] , sorted[pc[i].end]);
		// printf("%d %d\n", sorted[pc[i + 1].begin], sorted[pc[i + 1].end]);
		printf("%d %d\n", sorted[pc[i + 2].begin], sorted[pc[i + 2].end]);
		rot_cnt = 0; //rotations count
		k = 0;

		while (j < count && k < need_to_push)
		{
			// write(1, "R\n", 2);
			if (pc[i].lt == 'A')
			{
				// if (st->pb < st->n - 2 && st->a[st->pa] > st->a[st->pa + 1] &&
				// 	st->b[st->pb + 1] > st->b[st->pb + 2])
				// 	action(st, "ss");

				// printf("st->a[st->pa] = %d\n", st->a[st->pa]);
				if (st->a[st->pa] >= sorted[pc[i + 2].begin] &&
					st->a[st->pa] < sorted[pc[i + 1].end])
				{
					action(st, "pb");
					// printf("st->pb = %d, n = %d\n", st->pb, st->n);
					// if (!(st->b[st->pb + 1] >= sorted[pc[i + 2].begin] &&
					// 	st->b[st->pb + 1] < sorted[pc[i + 2].end]) && st->pb < st->n - 3 && flag == 1)
					// 	action(st, "rb");
					k++;		
				}
				else
				{
					action(st, "ra");
					rot_cnt++;
				}
				// write(1, "R\n", 2);

			}
			else if (pc[i].lt == 'B')
			{

	// printf("find two\n");
	// print_arrays(st);

				// if (st->pa < st->n - 1 && st->a[st->pa] > st->a[st->pa + 1] &&
				// 	st->b[st->pb + 1] > st->b[st->pb + 2])
				// 	action(st, "ss");
				if (st->b[st->pb + 1] >= sorted[pc[i + 2].begin] &&
					st->b[st->pb + 1] < sorted[pc[i + 1].end])
				{
					k++;
					action(st, "pa");
					// if (!(st->a[st->pa] >= sorted[pc[i + 2].begin] &&
					// 	st->a[st->pa] < sorted[pc[i + 2].end] && st->pa < st->n - 1 && flag == 1))
					// 	action(st, "ra");

				}
				else
				{
					action(st, "rb");
					rot_cnt++;
				}
			}
			// printf("k = %d\n", k);
			j++;
		}

		// h = 0;
		// flag = 0;
		// while (h < i)
		// {
		// 	if (pc[h].lt == pc[i].lt)
		// 		flag = 1;
		// 	h++;
		// }
		

		//st->a[st->pa] or st->b[st->pb + 1]

		// printf("st->pa = %d, n = %d\n", st->pa, st->n);
		// printf("h = %d, flag = %d\n", h, flag);
		//put back rotations
		// while (rot_cnt > 0 && flag == 1)
		// if (flag == 1)
		// 	printf("lett = %c, going to rot back\n", pc[i].lt);
		while (rot_cnt > 0 && flag == 1)
		{

			if (pc[i].lt == 'A')
				action(st, "rra");
			else if (pc[i].lt == 'B')
				action(st, "rrb");
			rot_cnt--;
		}


	}
	else
	{
		// printf("NOW < 4\n");
		// printf("i = %d  %d\n", i, pc[i].amount);
		if (pc[i].amount == 2)
			sort_2_elements(st, pc + i);
		else if (pc[i].amount == 3)
			sort_3_elements(st, pc + i, sorted);
		else if (pc[i].amount == 4)
			sort_4_elements(st, pc + i, sorted);
		// print_piece(pc[i]);

	}
//	printf("%d\n", pc[i].end);
	// printf("FINISHED\n\n");
}


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
		write(1, "\033[1;31mMalloc error\n\033[0m", 24);
	else if (i == -1)
		write(1, "\033[1;31mNot numerical input\n\033[0m", 31);
	else if (i == -2)
		write(1, "\033[1;31mInteger overflaw\n\033[0m", 28);
	else if (i == -3)
		write(1, "\033[1;31mDuplicates found\n\033[0m", 28);
	if (i == 0 || i == -1 || i == -2 || i == -3)
		return (0);
	set_st_b(st);

	// print_sorted(sorted, st->n);

	t_info *pc;
	int n;
	n = 100; 
	pc = (t_info *)malloc(sizeof(t_info) * 100);
	set_first_info(pc, st->n);


//	print_arrays(st);
	process_stacks(st, pc, sorted);
//	print_piece(pc[0]);
//	print_piece(pc[1]);
	// print_piece(pc[2]);
//	print_arrays(st);

	// process_stacks(st, pc, sorted);
	// print_piece(pc[0]);
	// print_piece(pc[1]);
	// print_piece(pc[2]);
	// print_arrays(st);

	// process_stacks(st, pc, sorted);
	// print_piece(pc[0]);
	// print_piece(pc[1]);
	// print_piece(pc[2]);
	// print_arrays(st);

	// process_stacks(st, pc, sorted);
	// print_piece(pc[0]);
	// print_piece(pc[1]);
	// printf("sorted[begin] = %d, sorted[end] = %d\n", sorted[pc[1].begin], sorted[pc[1].end]);
	// print_piece(pc[2]);
	// print_arrays(st);

	// process_stacks(st, pc, sorted);
	// print_piece(pc[0]);
	// print_piece(pc[1]);
	// print_piece(pc[2]);
	// print_arrays(st);

	// process_stacks(st, pc, sorted);
	// print_piece(pc[0]);
	// print_piece(pc[1]);
	// print_piece(pc[2]);
	// print_arrays(st);


	// process_stacks(st, pc, sorted);
	// print_piece(pc[0]);
	// print_piece(pc[1]);
	// print_piece(pc[2]);
	// print_arrays(st);

	// process_stacks(st, pc, sorted);
	// print_piece(pc[0]);
	// print_piece(pc[1]);
	// print_piece(pc[2]);
	// print_arrays(st);

	// process_stacks(st, pc, sorted);
	// print_arrays(st);

	// process_stacks(st, pc, sorted);
	// print_arrays(st);

	// process_stacks(st, pc, sorted);
	// print_arrays(st);

	// process_stacks(st, pc, sorted);
	// print_arrays(st);
	// print_piece(pc[0]);
	// print_piece(pc[1]);

	// process_stacks(st, pc, sorted);
	// print_arrays(st);

	// process_stacks(st, pc, sorted);
	// print_arrays(st);

	// while (check_stacks(st) == 0)
	// {
	// 	process_stacks(st, pc, sorted);
	// }
	// print_arrays(st);


	free(st->a);
	free(st->b);
	st->a = NULL;
	st->b = NULL;
	free(st);
	st = NULL;


	
	return (0);
}