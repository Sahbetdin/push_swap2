/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funs3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:45:21 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/24 19:45:22 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

/*
** swap first two elements in stack c
*/

void	swap_in_stack(t_stacks *st, char c)
{
	if (c == 'A' && st->pa < st->n - 1)
		ft_swap(st->a + st->pa, st->a + st->pa + 1);
	else if (c == 'B' && st->pb + 2 < st->n)
		ft_swap(st->b + st->pb + 1, st->b + st->pb + 2);
}

void	swap_both(t_stacks *st)
{
	swap_in_stack(st, 'A');
	swap_in_stack(st, 'B');
}

void	rotate_both(t_stacks *st)
{
	rotate(st, 'A');
	rotate(st, 'B');
}

void	reverse_rotate_both(t_stacks *st)
{
	reverse_rotate(st, 'A');
	reverse_rotate(st, 'B');
}

int		put_action(t_stacks *st, char *act, int flag)
{
	if (flag == 1)
		ft_putendl(act);
	st->oper++;
	return (1);
}
