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

void	sort_3_elements(t_stacks *st, t_info *pc0, int *srt)
{
	// printf("NOW WE SORT 3 ELEMENTS\n");
	// printf("begin %d\n", srt[pc0->begin]);
	// printf("end  %d\n", srt[pc0->end - 1]);
	// printf("lt  %c\n", pc0->lt);
	if (pc0->lt == 'A')
	{
		if (st->a[st->pa] == srt[pc0->begin])
		{ //works fine
			// printf("VOT\n");
			action(st, "ra");
			sort_2_elements(st, pc0);
		}
		else if (st->a[st->pa + 1] == srt[pc0->begin])
		{ //works fine
			// printf("BRE\n");
			action(st, "sa");
			action(st, "ra");
			sort_2_elements(st, pc0);
		}
		else if (st->a[st->pa + 2] < st->a[st->pa] &&
			st->a[st->pa] < st->a[st->pa + 1])
		{//works fine
			// printf("GLE\n");

				action(st, "pb");
				action(st, "sa");
				action(st, "ra");
				action(st, "pa");
				action(st, "ra");
				action(st, "ra");
		}
		else if (st->a[st->pa + 2] < st->a[st->pa + 1] &&
			st->a[st->pa + 1] < st->a[st->pa])
		{//works fine
			// printf("LED\n");
			action(st, "pb");
			action(st, "sa");
			action(st, "ra");
			action(st, "ra");
			action(st, "pa");
			action(st, "ra");
		}
	}
	else if (pc0->lt == 'B')
	{
		if (st->b[st->pb + 1] == srt[pc0->begin])
		{
			action(st, "pa");
			action(st, "ra");
			sort_2_elements(st, pc0);
		}
		else if (st->b[st->pb + 2] == srt[pc0->begin])
		{
			action(st, "sb");
			action(st, "pa");
			action(st, "ra");
			sort_2_elements(st, pc0);
		}
		else if (st->b[st->pb + 3] < st->b[st->pb + 1] &&
			st->b[st->pb + 1] < st->b[st->pb + 2])
		{
				action(st, "pa");
				action(st, "sb");
				action(st, "pa");
				action(st, "ra");
				action(st, "ra");
				action(st, "pa");
				action(st, "ra");
		}
		else if (st->b[st->pb + 3] < st->b[st->pb + 2] &&
			st->b[st->pb + 2] < st->b[st->pb + 1])
		{
				action(st, "pa");
				action(st, "pa");
				action(st, "pa");
				action(st, "ra");
				action(st, "ra");
				action(st, "ra");
		}

	}
	pc0->lt = 0;
	pc0->begin = 0;
	pc0->end = 0;
	pc0->amount = 0;
}


//gcc ps.c funs1.c sort4.c sort2.c sort3.c  && ./a.out
