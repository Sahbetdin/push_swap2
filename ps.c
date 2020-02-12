#include "ps_header.h"

void set_first_info(t_info *pc, int n)
{
	pc->begin = 0;
	pc->end = n;
	pc->amount = pc->end - pc->begin;
	pc->lett = 'A';

}

//we need to be sure if next pc is available
void divide_piece_info(t_info *pc)
{
	int mid;
	char c;
	t_info *old;

	old = pc;
	pc++;
	mid = (old->begin + old->end) / 2;
	if (old->lett == 'A')
		pc->lett = 'B';
	else if (old->lett == 'B')
		pc->lett = 'A';
	pc->begin = old->begin;
	pc->end = mid;
	pc->amount = pc->end - pc->begin;
	old->begin = mid;
	old->amount = old->end - old->begin;
}

void	print_piece(t_info piece0)
{
	printf("order = %d, ", piece0.order);
	printf("begin = %d, ", piece0.begin);
	printf("end = %d, ", piece0.end);
	printf("amount= %d, ", piece0.amount);
	printf("lett  = %c\n", piece0.lett);
	printf("~~~~~~~~~~~~~\n");
}

int	*make_me_sorted(t_stacks *st)
{
	int *sorted;
	int i;
	int n;

	sorted = (int *)malloc(sizeof(int) * st->n);
	i = -1;
	while (++i < st->n)
		sorted[i] = st->arr_a[i];
	sort_array(sorted, st->n);

//print sorted array
	i = -1;
	printf("               ");
	while (++i < st->n)
		printf(" %2d ", i);
	printf("\n");
	i = -1;
	printf("\033[0;32m sorted array:\033[0m ");
	while (++i < st->n)
		printf(" %2d ", sorted[i]);
	printf("\n");
	return (sorted);
}

void		free_stacks(t_stacks *st)
{
	free(st->arr_a);
	free(st->arr_b);
	free(st);	
}

void	print_arrays(t_stacks *st)
{
	int i;

	printf("\033[0;36m arr_a:       \033[0m");
	printf("%3d,", st->ptr_a);
	i = -1;
	while (++i < st->n)
		printf("%4d", st->arr_a[i]);
	printf("\n");

	printf("\033[0;36m arr_b:      \033[0m ");
	printf("%3d,", st->ptr_b);
	i = -1;
	while (++i < st->n)
		printf("%4d", st->arr_b[i]);
	printf("\033[0;33m \n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n \033[0m");
}

void	process_stacks(t_stacks *st, t_info *pc, int *sorted)
{
	int i; //for pieces
	int j; //for counter during one piece processing
	int count;
	int rot_cnt;

	i = 0;
	while (i < 50)
	{
		if (pc[i].amount != 0 && pc[i + 1].amount == 0)
			break;
		i++;
	}
	printf("in processing i = %d\n", i);
//	pc[i].order = 1;
	if (pc[i].amount > 4)
	{		
		count = pc[i].amount;
		divide_piece_info(pc + i);
		// print_piece(pc[i + 1]);

		// if (pc[i].lett == 'A')
		// 	count = st->n - st->ptr_a;
		// else if (pc[i].lett == 'B')
		// 	count = st->n - st->ptr_b - 1;

		printf("count = %d\n", count);
		j = 0;
		// // printf("%d %d\n", sorted[pc[1].begin] , sorted[pc[1].end]);
		printf("%d %d\n", sorted[pc[i + 1].begin], sorted[pc[i + 1].end]);
		rot_cnt = 0; //rotations count
		while (j < count)
		{
//			write(1, "R\n", 2);
			if (pc[i].lett == 'A')
			{
				if (st->arr_a[st->ptr_a] >= sorted[pc[i + 1].begin] &&
					st->arr_a[st->ptr_a] < sorted[pc[i + 1].end])
					action(st, "pb");
				else
				{
					action(st, "ra");
					rot_cnt++;
				}
			}
			else if (pc[i].lett == 'B')
			{
				//printf("IN B\n");
				if (st->arr_b[st->ptr_b + 1] >= sorted[pc[i + 1].begin] &&
					st->arr_b[st->ptr_b + 1] < sorted[pc[i + 1].end])
				{

					action(st, "pa");
				}
				else
				{
					action(st, "rb");
					rot_cnt++;
				}
			}
			j++;
		}
		//put back rotations
		while (rot_cnt > 0 && pc[i].amount < st->n)
		{
			if (pc[i].lett == 'A')
				action(st, "rra");
			else if (pc[i].lett == 'B')
				action(st, "rrb");
			rot_cnt--;
		}


	}
	else
	{
		printf("NOW < 4\n");
		printf("i = %d\n", i);
		if (pc[i].amount == 2)
			sort_2_elements(st, pc + i);
		else if (pc[i].amount == 3)
			;
		else if (pc[i].amount == 4)
			sort_4_elements(st, pc + i);
		print_piece(pc[i]);

//		...launch sorting;
//		...reset order;
	}
//	printf("%d\n", pc[i].end);
	printf("FINISHED\n\n");
}


int main()
{
	t_info		*pc;
	int			n;
	int			i;
	int			*sorted;
	t_stacks	*st;
	int			count;

	n = 17;
	pc = (t_info *)malloc(sizeof(t_info) * 50);
	i = 0;
	// while (i < 50)
	// {
	// 	pc[i].order = 0;
	// 	i++;
	// }
	set_first_info(pc, n);
	// // print_piece(pc[0]);
	// divide_piece_info(pc);
	// divide_piece_info(pc + 1);
	// print_piece(pc[0]);
	// print_piece(pc[1]);
	// print_piece(pc[2]);

	// free(pc);
	// pc = NULL;


	st = (t_stacks *)malloc(sizeof(t_stacks));
	st->arr_a = (int *)malloc(sizeof(int) * n);
	st->arr_b = (int *)malloc(sizeof(int) * n);
	st->n = n;
	st->ptr_a = 0;
	st->ptr_b = n - 1;

	set_arr_to_zero(st->arr_b, st->n);
	set_arr_with_numbers(st->arr_a, st->n);
	sorted = make_me_sorted(st);
	print_arrays(st);
	// 	push_1_to_2(st, 'A');
		// push_1_to_2(st, 'A');
		// push_1_to_2(st, 'A');
		// push_1_to_2(st, 'A');
	// reverse_rotate(st, 'A');
	// reverse_rotate(st, 'B');
	// swap_in_stack(st, 'B');
	// rotate(st, 'B');

	//count - сколько раз надо прогнать стэк А/B. равно n - ptr_a/b.

//работаем над тем, чтобы провернуть А count раз.
//если элементы в выбранном диапазоне, то убирем в В, иначе rotate_a
//знаем, что берем с А
// st->arr_a[st->ptr_a] - верхний элемент
//если нечетное кол-во, то бОльшее отдаем в след.стэк

	process_stacks(st, pc, sorted);
	print_arrays(st);
	process_stacks(st, pc, sorted);
	print_arrays(st);
	process_stacks(st, pc, sorted);
	print_arrays(st);
	process_stacks(st, pc, sorted);
	print_arrays(st);
	
	process_stacks(st, pc, sorted);
	print_arrays(st);
	
	process_stacks(st, pc, sorted);
	print_arrays(st);

	
	process_stacks(st, pc, sorted);
	print_arrays(st);

	process_stacks(st, pc, sorted);
	print_arrays(st);

	// print_piece(pc[0]);
	// print_piece(pc[1]);
	// print_piece(pc[2]);



//free all that's in stack and the stacks
	free_stacks(st);
	free(pc);
	free(sorted);
	return (0);
}