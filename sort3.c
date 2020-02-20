/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:52:23 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/12 16:52:25 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	sort_top_top(t_stacks *st)
{
	if (st->a[st->pa] < st->b[st->pb + 1])
	{ // [4]  [5]
		action(st, "ra");
		action(st, "pa");
		action(st, "ra");
	}
	else if (st->a[st->pa] > st->b[st->pb + 1])
	{ // [5]  [4]
		action(st, "pa");
		action(st, "ra");
		action(st, "ra");
	}
}


void	sort_3_elements(t_stacks *st, t_info *pc0, int *srt)
{
	// printf("NOW WE SORT 3 ELEMENTS\n");
	// printf("begin %d\n", srt[pc0->begin]);
	// printf("end  %d\n", srt[pc0->end - 1]);
	// printf("lt  %c\n", pc0->lt);

	if (pc0->lt == 'A' && pc0->amount + st->pa == st->n)
	{
		if (st->a[st->pa] < st->a[st->pa + 2] && st->a[st->pa + 2] < st->a[st->pa + 1])
		{ // 1 3 2, eg: "10 100 40"
			action(st, "rra");
			action(st, "sa");
		}
		else if (st->a[st->pa + 1] == srt[pc0->begin])
		{ // * 1 *
			if (st->a[st->pa] < st->a[st->pa + 2]) // 2 1 3
				action(st, "sa");
			else if (st->a[st->pa] > st->a[st->pa + 2]) // 3 1 2
				action(st, "ra");
		}
		else if (st->a[st->pa + 2] == srt[pc0->begin])
		{ // * * 1
			if (st->a[st->pa] < st->a[st->pa + 1]) // 2 3 1
				action(st, "rra");
			else if (st->a[st->pa] > st->a[st->pa + 1]) // 3 2 1
			{
				action(st, "sa");
				action(st, "rra");
			}
		}
	}
	else if (pc0->lt == 'A')
	{
		if (st->a[st->pa] == srt[pc0->begin]) // 1 * *
		{ //works fine ; the lowest element is on top
			action(st, "ra");
			sort_2_elements(st, pc0);
		}
		else if (st->a[st->pa + 1] == srt[pc0->begin]) // * 1 *
		{ //the lowest element is the second
			action(st, "sa");
			action(st, "ra");
			sort_2_elements(st, pc0);
		}
		else if (st->a[st->pa + 2] == srt[pc0->begin]) // * * 1
		{ 
			action(st, "pb");
			action(st, "sa");
			action(st, "ra"); // after that we have  two elements on both stacks
			sort_top_top(st);
		}
	}
	else if (pc0->lt == 'B' && pc0->amount + st->pb == st->n)
	{ //three elements alone
		if (st->b[st->pb + 1] == srt[pc0->begin]) //B: 1 * * далее пусто
		{ //first elem in B is the lowest
			action(st, "pa");
			action(st, "pa");
			action(st, "sa");
			action(st, "pa");
			if (st->a[st->pa] == srt[pc0->begin + 1]) //second lowest on the top of A: 2 1 3
				action(st, "sa");
			else if (st->a[st->pa] == srt[pc0->begin + 1]) //sec lowest is the third in A: 3 1 2
				action(st, "ra");
		}
		else if (st->b[st->pb + 2] == srt[pc0->begin])
		{ // B: * 1 *
			action(st, "pa");
			action(st, "pa");
			action(st, "pa");
			if (st->a[st->pa] == srt[pc0->begin + 1]) //A: 2 1 3
				action(st, "sa");
			else if (st->a[st->pa + 2] == srt[pc0->begin + 1]) //B: 3 1 2
				action(st, "ra");
		}
		else if (st->b[st->pb + 3] == srt[pc0->begin])
		{ // B: * * 1
			action(st, "pa");
			action(st, "pa");
			if (st->a[st->pa] == srt[pc0->begin + 1]) // A: 2 3, B: 1
				action(st, "pa");
			else if (st->a[st->pa + 1] == srt[pc0->begin + 1]) // A: 3 2, B: 1
			{
				action(st, "sa");
				action(st, "pa");
			}
		}
	}
	else if (pc0->lt == 'B')
	{
		if (st->b[st->pb + 1] == srt[pc0->begin])
		{ // B: 1 * *
		// && st->b[st->pb + 2] == srt[pc0->begin + 1]
			action(st, "pa");
			action(st, "ra");
			action(st, "pa"); //push second element to A and work up from here
			if (st->a[st->pa] == srt[pc0->begin + 1]) //A: 2 [other elements] 1, B: 3
			{
				action(st, "ra");
				action(st, "pa");
				action(st, "ra");
			}
			else if (st->a[st->pa] == srt[pc0->begin + 2]) //A: 3 [] 1, B: 2
			{
				action(st, "pa");
				action(st, "ra");
				action(st, "ra");
			}
		}
		else if (st->b[st->pb + 2] == srt[pc0->begin])
		{ // B: * 1 *
			action(st, "pa");
			action(st, "pa");
			action(st, "ra");
			sort_2_elements(st, pc0);
		}
		else if (st->b[st->pb + 3] == srt[pc0->begin])
		{ // B: * * 1
			action(st, "pa");
			action(st, "pa");
			action(st, "pa");
			action(st, "ra");
			sort_2_elements(st, pc0);
		}
	}
	pc0->lt = 0;
	pc0->begin = 0;
	pc0->end = 0;
	pc0->amount = 0;
}

//gcc parse_args.c ft_atoi_backsp.c funs1.c ps.c sort2.c sort3.c sort4.c fun_print.c -o push_swap my_libft/libft.a
//gcc ps.c funs1.c sort4.c sort2.c sort3.c  && ./a.out
//python3 pyviz.py `ruby -e "puts (1..3).to_a.shuffle.join(' ')"`