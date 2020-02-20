/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:53:00 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/12 16:53:01 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void set_first_info(t_info *pc, int n)
{
	pc->begin = 0;
	pc->end = n;
	pc->amount = pc->end - pc->begin;
	pc->lt = 'A';

}

//we need to be sure if next pc is available
void divide_piece_info(t_info *pc, int flag)
{
	int mid;
	char c;
	t_info *old;

	old = pc;
	pc++;
	mid = (old->begin + old->end) / 2;
	if (flag == 1 && old->lt == 'A')
		pc->lt = 'B';
	else if (flag == 1 && old->lt == 'B')
		pc->lt = 'A';
	else if (flag == 0 && old->lt == 'A')
		pc->lt = 'A';
	else if (flag == 0 && old->lt == 'B')
		pc->lt = 'B';
	pc->begin = old->begin;
	pc->end = mid;
	pc->amount = pc->end - pc->begin;
	old->begin = mid;
	old->amount = old->end - old->begin;
}

void		free_stacks(t_stacks *st)
{
	free(st->a);
	free(st->b);
	free(st);	
}




//if pa is 0 and st->a is sorted, then return 1
//else return 0
int	check_stacks(t_stacks *st)
{
	int i;

	if (st->pa != 0)
		return (0);
	i = 0;
	while (i < st->n - 1)
	{
		if (st->a[i] > st->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}


// int main()
// {
// 	t_info		*pc;
// 	int			n;
// 	int			i;
// 	int			*sorted;
// 	t_stacks	*st;
// 	int			count;

// 	n = 100; 
// 	pc = (t_info *)malloc(sizeof(t_info) * 100);
// 	i = 0;
// 	set_first_info(pc, n);
// 	// // print_piece(pc[0]);
// 	// divide_piece_info(pc);
// 	// divide_piece_info(pc + 1);
// 	// print_piece(pc[0]);
// 	// print_piece(pc[1]);
// 	// print_piece(pc[2]);

// 	// free(pc);
// 	// pc = NULL;


// 	st = (t_stacks *)malloc(sizeof(t_stacks));
// 	st->a = (int *)malloc(sizeof(int) * n);
// 	st->b = (int *)malloc(sizeof(int) * n);
// 	st->n = n;
// 	st->oper = 0;
// 	st->pa = 0;
// 	st->pb = n - 1;

// 	set_arr_to_zero(st->b, st->n);
// 	set_arr_with_numbers(st->a, st->n);
// 	sorted = make_me_sorted(st);

// 	// i = 0;
// 	// while (i < n - 1)
// 	// {
// 	// 	if (sorted[i] == sorted[i + 1])
// 	// 	{
// 	// 		write(1, "\033[0;31mError \n\033[0m", 18);
// 	// 		printf("%d", sorted[i]);
// 	// 		return (0);
// 	// 	}
// 	// 	i++;
// 	// }
// 	// print_arrays(st);

// 	// 	push_1_to_2(st, 'A');
// 		// push_1_to_2(st, 'A');
// 		// push_1_to_2(st, 'A');
// 		// push_1_to_2(st, 'A');
// 	// reverse_rotate(st, 'A');
// 	// reverse_rotate(st, 'B');
// 	// swap_in_stack(st, 'B');
// 	// rotate(st, 'B');

// 	//count - сколько раз надо прогнать стэк А/B. равно n - pa/b.

// //работаем над тем, чтобы провернуть А count раз.
// //если элементы в выбранном диапазоне, то убирем в В, иначе rotate_a
// //знаем, что берем с А
// // st->a[st->pa] - верхний элемент
// //если нечетное кол-во, то бОльшее отдаем в след.стэк




// 	// printf("checking stack: %d\n", check_stacks(st));
// 	// process_stacks(st, pc, sorted);
// 	// print_arrays(st);
	
// // 	printf("checking stack: %d\n", check_stacks(st));
// // 	process_stacks(st, pc, sorted);
// // 	print_arrays(st);
	
// // 	printf("checking stack: %d\n", check_stacks(st));
// // 	process_stacks(st, pc, sorted);
// // 	print_arrays(st);
// // 	// print_piece(pc[0]);
// // 	// print_piece(pc[1]);
// // 	// print_piece(pc[2]);

// // 	printf("checking stack: %d\n", check_stacks(st));
// // 	process_stacks(st, pc, sorted);
// // 	print_arrays(st);
	
// // 	printf("checking stack: %d\n", check_stacks(st));
// // 	process_stacks(st, pc, sorted);
// // 	print_arrays(st);

// // 	printf("checking stack: %d\n", check_stacks(st));
// // 	process_stacks(st, pc, sorted);
// // 	print_arrays(st);
// // print_piece(pc[0]);

// // 	printf("checking stack: %d\n", check_stacks(st));
// // 	process_stacks(st, pc, sorted);
// // 	print_arrays(st);
// // 	print_piece(pc[0]);

// // 	printf("checking stack: %d\n", check_stacks(st));
// // 	process_stacks(st, pc, sorted);
// // 	print_arrays(st);

// // 	printf("checking stack: %d\n", check_stacks(st));
// // 	process_stacks(st, pc, sorted);
// // 	print_arrays(st);

// // 	printf("checking stack: %d\n", check_stacks(st));
// // 	process_stacks(st, pc, sorted);
// // 	print_arrays(st);

// // 	printf("checking stack: %d\n", check_stacks(st));
// // 	process_stacks(st, pc, sorted);
// // 	print_arrays(st);

// // // printf("FFFFFFFFFFFF\n");
// 	printf("checking stack: %d\n", check_stacks(st));
// 	printf("number of operations is: %d\n", st->oper);
// 	// process_stacks(st, pc, sorted);
// 	// print_arrays(st);

// // 	printf("checking stack: %d\n", check_stacks(st));
// // 	process_stacks(st, pc, sorted);
// // 	print_arrays(st);
// 	// printf("checking stack: %d\n", check_stacks(st));

// 	// print_piece(pc[0]);
// 	// print_piece(pc[1]);
// 	// print_piece(pc[2]);



// //free all that's in stack and the stacks
// 	free_stacks(st);
// 	free(pc);
// 	free(sorted);
// 	return (0);
// }
