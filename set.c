/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:51:06 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/24 14:51:07 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	set_arr_to_zero(int *b, int n)
{
	int		i;

	i = -1;
	while (++i < n)
		b[i] = 0;
}

/*
** this function is used by the next one for parsing sth like " 3 4 1  "
*/

int		parse_complicated(int ac, char **av, t_stacks **st)
{
	int		i;
	int		j;
	char	*trimi;
	int		n;

	i = 1;
	j = 0;
	while (i < ac)
	{
		trimi = ft_strtrim(av[i]);
		if (parse_all_args((*st), trimi, &j, &n) == -2)
			return (-2);
		i++;
		free(trimi);
	}
	return (1);
}

/*
** 1. check if input consists of numbers and backspaces
** 2. number of available arguments
** 3. parse arguments
*/

int		set_st_a(int ac, char **av, t_stacks **st, int **sorted)
{
	int		cnt;

	if (check_if_num_backsp(ac, av) == 0)
		return (-1);
	if (!(*st = (t_stacks *)malloc(sizeof(t_stacks))))
		return (0);
	if ((cnt = amount_of_numb(ac, av)) != -1)
		(*st)->n = cnt;
	else
		return (0);
	if (!((*st)->a = (int *)malloc(sizeof(int) * (*st)->n)))
		return (0);
	if (parse_complicated(ac, av, st) == -2)
		return (-2);
	if (check_if_dupl(*st, sorted) == -3)
		return (-3);
	return (1);
}

int		set_st_b(t_stacks *st)
{
	if (!(st->b = (int *)malloc(sizeof(int) * st->n)))
		return (0);
	set_arr_to_zero(st->b, st->n);
	st->oper = 0;
	st->pa = 0;
	st->pb = st->n - 1;
	return (1);
}
