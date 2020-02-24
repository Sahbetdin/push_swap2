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
	if (pc0->amount + st->pa == st->n)
	{
		if (pc0->lt == 'A' && st->a[st->pa] > st->a[st->pa + 1])
			action(st, "sa", 1);
		else if (pc0->lt == 'B' && st->b[st->pb + 1] < st->b[st->pb + 2])
		{
			pa_2(st);
			action(st, "sa", 1);
		}
		else if (pc0->lt == 'B' && st->b[st->pb + 1] > st->b[st->pb + 2])
			pa_2(st);
	}
	else
	{
		if (pc0->lt == 'A' && st->a[st->pa] < st->a[st->pa + 1])
			ra_2(st);
		else if (pc0->lt == 'A' && st->a[st->pa] > st->a[st->pa + 1])
		{
			action(st, "sa", 1);
			ra_2(st);
		}
		else if (pc0->lt == 'B' && st->b[st->pb + 1] < st->b[st->pb + 2])
		{
			pa_ra(st);
			pa_ra(st);
		}
		else if (pc0->lt == 'B' && st->b[st->pb + 1] > st->b[st->pb + 2])
		{
			pa_2(st);
			ra_2(st);
		}
	}
	zerofy_piece(pc0);
}
