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
	// printf("lett  %c\n", pc0->lett);
	if (pc0->lett == 'A')
	{
		if (st->arr_a[st->ptr_a] == srt[pc0->begin])
		{ //works fine
			// printf("VOT\n");
			action(st, "ra");
			sort_2_elements(st, pc0);
		}
		else if (st->arr_a[st->ptr_a + 1] == srt[pc0->begin])
		{ //works fine
			// printf("BRE\n");
			action(st, "sa");
			action(st, "ra");
			sort_2_elements(st, pc0);
		}
		else if (st->arr_a[st->ptr_a + 2] < st->arr_a[st->ptr_a] &&
			st->arr_a[st->ptr_a] < st->arr_a[st->ptr_a + 1])
		{//works fine
			// printf("GLE\n");

				action(st, "pb");
				action(st, "sa");
				action(st, "ra");
				action(st, "pa");
				action(st, "ra");
				action(st, "ra");
		}
		else if (st->arr_a[st->ptr_a + 2] < st->arr_a[st->ptr_a + 1] &&
			st->arr_a[st->ptr_a + 1] < st->arr_a[st->ptr_a])
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
	else if (pc0->lett == 'B')
	{
		if (st->arr_b[st->ptr_b + 1] == srt[pc0->begin])
		{
			action(st, "pa");
			action(st, "ra");
			sort_2_elements(st, pc0);
		}
		else if (st->arr_b[st->ptr_b + 2] == srt[pc0->begin])
		{
			action(st, "sb");
			action(st, "pa");
			action(st, "ra");
			sort_2_elements(st, pc0);
		}
		else if (st->arr_b[st->ptr_b + 3] < st->arr_b[st->ptr_b + 1] &&
			st->arr_b[st->ptr_b + 1] < st->arr_b[st->ptr_b + 2])
		{
				action(st, "pa");
				action(st, "sb");
				action(st, "pa");
				action(st, "ra");
				action(st, "ra");
				action(st, "pa");
				action(st, "ra");
		}
		else if (st->arr_b[st->ptr_b + 3] < st->arr_b[st->ptr_b + 2] &&
			st->arr_b[st->ptr_b + 2] < st->arr_b[st->ptr_b + 1])
		{
				action(st, "pa");
				action(st, "pa");
				action(st, "pa");
				action(st, "ra");
				action(st, "ra");
				action(st, "ra");
		}

	}
}


//gcc ps.c funs1.c sort4.c sort2.c sort3.c  && /a.out
