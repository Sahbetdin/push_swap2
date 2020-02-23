/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:51:36 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/21 14:51:38 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"


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

int		*make_me_sorted(t_stacks *st)
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
** returns amount of numbers in av[i]
*/

int		amount_of_numb_in_one_av(char *str)
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

/*
** returns total amount of numbers
*/

int		amount_of_numb(int ac, char **av)
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


int		parse_all_args(t_stacks *st, char *ptr, int *j_addr, int *n_addr)
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

/*
** is pushed to B
*/
int		is_pb(t_stacks *st, t_info *pc0, int *srt, int fl)
{
	int tmp;
	int res;

	res = 0;
	tmp = st->a[st->pa];
	if ((fl && tmp >= srt[pc0[2].begin] && tmp < srt[pc0[1].end]) ||
	(!fl && tmp >= srt[pc0[1].begin] && tmp < srt[pc0[1].end]))
		res = 1;
	return (res);
}

void	check_first_element(t_stacks *st, t_info *pc0, int *sorted)
{
	if (pc0->lt == 'A' && st->a[st->pa] == sorted[pc0->begin] && st->pa + 
		pc0->amount != st->n)
	{
		action(st, "ra", 1);
		pc0->begin++;
		pc0->amount--;
	}
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
	int flag1;
	int last;
	int ii; //чтобы искать i для в другом стеке
	int tmp1;
	int tmp2;

	// if (pc[-1].lt == 'A' || pc[-1].lt == 'B')
	// 	printf("    HERE\n");
	// else
		// printf("NOT HERE\n");

	i = 1;
	while (i < 100)
	{ //ищем текущий pc, который мы далее будем разбивать
		if (pc[i].amount != 0 && pc[i + 1].amount == 0)
			break;
		i++;
	}
	// printf("in processing i = %d\n", i);
	if (pc[i].amount > 4)
	{
		count = pc[i].amount;

		flag = 1; //отвечает, что в тек стеке мы будем вовр элем обратно
		//если весь pc помещается в стек, то не будем. Иначе, если в нем
		//как минимум еще один pc, который под текущим pc, то надо возвращать.

//способ 1:
		// if (pc[i].lt == 'A')
		// 	last = st->a[st->n - 1];
		// else if (pc[i].lt == 'B')
		// 	last = st->b[st->n - 1];
		// if (last >= sorted[pc[i].begin] && last <= sorted[pc[i].end - 1])
		// 	flag = 0;
		// printf("last = %d, flag = %d\n", last, flag);
//способ 2:
		// printf("this pc[i].amount we process: %d\n", pc[i].amount);
		if (pc[i].lt == 'A' && st->pa + pc[i].amount == st->n) //??  -1 ??
			flag = 0;
		else if (pc[i].lt == 'B' && st->pb + pc[i].amount + 1 == st->n)
			flag = 0;
		// printf("flag = %d\n", flag);

///
		//убираем если первый элемент есть минимальный в куске
		check_first_element(st, pc + i, sorted);
///

		if (st->pb + 1 == st->n) //значит В пустой
			flag1 = 1;
		else
			flag1 = 0;
		// printf("flag1 = %d\n", flag1);
		// print_piece(pc[i]);
		// print_piece(pc[i + 1]);
		// print_piece(pc[i + 2]);

		// printf("st->pa = %d\n", st->pa);
		// printf("st->pb = %d\n", st->pb);
		// printf("st->n = %d\n", st->n);
		// printf("st->pa + pc[i].amount = %d\n", st->pa + pc[i].amount);
		// printf("st->pb + pc[i].amount = %d\n", st->pb + pc[i].amount);



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
		if (pc[i + 1].amount > 3 && flag1) //если стэк В пустой и кол-во элементов, которе
			//нужно "ra" делать, более 3
		{
			divide_piece_info(pc + i + 1, 0);
			need_to_push = pc[i + 1].amount + pc[i + 2].amount;
		}
		else
			need_to_push = pc[i + 1].amount;

		// print_piece(pc[i]);
		// print_piece(pc[i + 1]);
		// print_piece(pc[i + 2]);
		// printf("here\n");
		// printf("need_to_push = %d\n", need_to_push);
		// printf("%d %d\n", sorted[pc[i].begin] , sorted[pc[i].end]);
		// printf("%d %d\n", sorted[pc[i + 1].begin], sorted[pc[i + 1].end]);
		// printf("%d %d\n", sorted[pc[i + 2].begin], sorted[pc[i + 2].end]);
		rot_cnt = 0; //rotations count
		k = 0;
		j = 0;
		while (j < count && k < need_to_push)
		{

			// write(1, "R\n", 2);
			if (pc[i].lt == 'A')
			{
				// if (st->pb < st->n - 2 && st->a[st->pa] > st->a[st->pa + 1] &&
				// 	st->b[st->pb + 1] > st->b[st->pb + 2])
				// 	action(st, "ss");

				// printf("st->a[st->pa] = %d\n", st->a[st->pa]);
				if (is_pb(st, pc + i, sorted, flag1))
				{
					action(st, "pb", 1);
					// printf("st->pb = %d, n = %d\n", st->pb, st->n);
					tmp2 = st->b[st->pb + 1];
					tmp2 = flag1 && !(tmp2 >= sorted[pc[i + 2].begin] &&
					 	tmp2 < sorted[pc[i + 2].end]) && st->pb < st->n - 2;
					if (tmp2 && !is_pb(st, pc + i,sorted, flag1))
					{
						action(st, "rr", 1);
						rot_cnt++;
					}
					else if (tmp2)
						action(st, "rb", 1);
					k++;		
				}
				else
				{
					action(st, "ra", 1);
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
					action(st, "pa", 1);
					// if (!(st->a[st->pa] >= sorted[pc[i + 2].begin] &&
					// 	st->a[st->pa] < sorted[pc[i + 2].end] && st->pa < st->n - 1 && flag == 1))
					// 	action(st, "ra");

				}
				else
				{

					action(st, "rb", 1);
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
				action(st, "rra", 1);
			else if (pc[i].lt == 'B')
				action(st, "rrb", 1);
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
	}
//	printf("%d\n", pc[i].end);
	// printf("FINISHED\n\n");
}




