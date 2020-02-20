/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:50:52 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/12 16:50:54 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	sort_2_elements(t_stacks *st, t_info *pc0)
{
	// printf("2 elements\n");
	// printf("pc0->amount = %d\n", pc0->amount);
	// printf("st->pa = %d\n", st->pa);
	// printf("st->n = %d\n", st->n);
	if (pc0->amount + st->pa == st->n)
	{
		if (pc0->lt == 'A' && st->a[st->pa] > st->a[st->pa + 1])
			action(st, "sa");
		else if (pc0->lt == 'B' && st->b[st->pb + 1] < st->b[st->pb + 2])
		{
			action(st, "pa");
			action(st, "pa");
			action(st, "sa");
		}
		else if (pc0->lt == 'B' && st->b[st->pb + 1] > st->b[st->pb + 2])
		{
			action(st, "pa");
			action(st, "pa");
		}
	}
	else
	{
		if (pc0->lt == 'A' && st->a[st->pa] < st->a[st->pa + 1])
		{
			action(st, "ra");
			action(st, "ra");
		}
		else if (pc0->lt == 'A' && st->a[st->pa] > st->a[st->pa + 1])
		{
			action(st, "sa");
			action(st, "ra");
			action(st, "ra");
		}
		else if (pc0->lt == 'B' && st->b[st->pb + 1] < st->b[st->pb + 2])
		{
			action(st, "pa");
			action(st, "ra");
			action(st, "pa");
			action(st, "ra");
		}
		else if (pc0->lt == 'B' && st->b[st->pb + 1] > st->b[st->pb + 2])
		{
			action(st, "pa");
			action(st, "pa");
			action(st, "ra");
			action(st, "ra");
		}
	}
	pc0->lt = 0;
	pc0->begin = 0;
	pc0->end = 0;
	pc0->amount = 0;
}
