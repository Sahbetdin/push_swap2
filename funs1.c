/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funs1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:52:49 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/12 16:52:50 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

int		*sort_array(int *arr, int n)
{
	int i;
	int j;

	j = 0;
	while (j < n)
	{
		i = j + 1;
		while (i < n)
		{
			if (arr[i] < arr[j])
				ft_swap(arr + i, arr + j);
			i++;
		}
		j++;
	}
	return (arr);
}

/*
** push from whatever in c is.
*/

void	push_1_to_2(t_stacks *st, char c)
{
	if (c == 'A')
	{
		st->b[st->pb] = st->a[st->pa];
		st->pa++;
		st->pb--;
	}
	else if (c == 'B')
	{
		st->pa--;
		st->pb++;
		st->a[st->pa] = st->b[st->pb];
	}
}

/*
** rotate what in c is
*/

void	rotate(t_stacks *st, char c)
{
	int tmp;
	int i;

	if (c == 'A')
	{
		tmp = st->a[st->pa];
		i = st->pa - 1;
		while (++i < st->n - 1)
			st->a[i] = st->a[i + 1];
		st->a[i] = tmp;
	}
	else if (c == 'B')
	{
		tmp = st->b[st->pb + 1];
		i = st->pb;
		while (++i < st->n - 1)
			st->b[i] = st->b[i + 1];
		st->b[i] = tmp;
	}
}

void	reverse_rotate(t_stacks *st, char c)
{
	int tmp;
	int i;

	i = st->n - 1;
	if (c == 'A')
	{
		tmp = st->a[i];
		while (i > st->pa)
		{
			st->a[i] = st->a[i - 1];
			i--;
		}
		st->a[st->pa] = tmp;
	}
	else if (c == 'B')
	{
		tmp = st->b[i];
		while (i > st->pb + 1)
		{
			st->b[i] = st->b[i - 1];
			i--;
		}
		st->b[st->pb + 1] = tmp;
	}
}
