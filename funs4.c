/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 20:51:03 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/24 20:51:05 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

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

void	sort_234(t_stacks *st, t_info *pc_i, int *sorted)
{
	if (pc_i->amount == 2)
		sort_2_elements(st, pc_i);
	else if (pc_i->amount == 3)
		sort_3_elements(st, pc_i, sorted);
	else if (pc_i->amount == 4)
		sort_4_elements(st, pc_i, sorted);
}

void	rotate_back_stacks(t_stacks *st, t_info *pc_i, int rot_cnt, int flag)
{
	while (rot_cnt > 0 && flag == 1)
	{
		if (pc_i->lt == 'A')
			action(st, "rra", 1);
		else if (pc_i->lt == 'B')
			action(st, "rrb", 1);
		rot_cnt--;
	}
}
