/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:22:59 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/24 14:23:00 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	ra_2(t_stacks *st)
{
	action(st, "ra", 1);
	action(st, "ra", 1);
}

void	pa_2(t_stacks *st)
{
	action(st, "pa", 1);
	action(st, "pa", 1);
}

void	pa_ra(t_stacks *st)
{
	action(st, "pa", 1);
	action(st, "ra", 1);
}

void	sa_ra(t_stacks *st)
{
	action(st, "sa", 1);
	action(st, "ra", 1);
}

void	sa_rra(t_stacks *st)
{
	action(st, "sa", 1);
	action(st, "rra", 1);
}
