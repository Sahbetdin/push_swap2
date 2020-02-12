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
	if (pc0->lett == 'A' && st->arr_a[st->ptr_a] < st->arr_a[st->ptr_a + 1])
	{
		action(st, "ra");
		action(st, "ra");
	}
	else if (pc0->lett == 'A' && st->arr_a[st->ptr_a] > st->arr_a[st->ptr_a + 1])
	{
		action(st, "sa");
		action(st, "ra");
		action(st, "ra");
	}
	else if (pc0->lett == 'B' && st->arr_b[st->ptr_b + 1] < st->arr_b[st->ptr_b + 2])
	{
		action(st, "pa");
		action(st, "ra");
		action(st, "pa");
		action(st, "ra");
	}
	else if (pc0->lett == 'B' && st->arr_b[st->ptr_b + 1] > st->arr_b[st->ptr_b + 2])
	{
		action(st, "pa");
		action(st, "pa");
		action(st, "ra");
		action(st, "ra");
	}
	pc0->lett = 0;
	pc0->begin = 0;
	pc0->end = 0;
	pc0->amount = 0;
}
