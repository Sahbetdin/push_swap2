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

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (int)(p1[i] - p2[i]);
		i++;
	}
	return (0);
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

void	set_arr_to_zero(int *b, int n)
{
	int i;
	i = -1;
	while (++i < n)
		b[i] = 0;
}

void	set_arr_with_numbers(int *a, int n)
{
	//17 чисел
	// a[0] = 15; a[1] = 21; a[2] = 23; 
	// a[3] = 8; a[4] = 20; 
	// a[5] = 2; 
	// a[6] = 3; 
	// a[7] = 9; a[8] = 14; a[9] = 16; a[10] = 18; 
	// a[11] = 10; a[12] = 11; 
	// a[13] = 4; 
	// a[14] = 13; a[15] = 12;
	// a[16] = 6;
	
	//23 чисел
a[0] = 27;
a[1] = 42;
a[2] = 19;
a[3] = 5;
a[4] = 45;
a[5] = 47;
a[6] = 25;
a[7] = 46;
a[8] = 22;
a[9] = 36;
a[10] = 20;
a[11] = 33;
a[12] = 44;
a[13] = 10;
a[14] = 49;
a[15] = 48;
a[16] = 43;
a[17] = 15;
a[18] = 8;
a[19] = 16;
a[20] = 9;
a[21] = 50;
a[22] = 13;
}


//push from c.
void	push_1_to_2(t_stacks *st, char c)
{
	if (c == 'A') //push from A to B
	{
		st->b[st->pb] = st->a[st->pa];
		st->pa++;
		st->pb--;
	}
	else if (c == 'B') //push from B to A
	{
		st->pa--;
		st->pb++;
		st->a[st->pa] = st->b[st->pb];
	}
}

//rotate what in c is
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
		i = st->pb; //starts from next one
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

//swap first two elements in stack c
void	swap_in_stack(t_stacks *st, char c)
{
	if (c == 'A' && st->pa < st->n - 1)
	{
		ft_swap(st->a + st->pa, st->a + st->pa + 1);
	}
	else if (c == 'B' && st->pb + 2 < st->n)
	{
		// printf("WAS\n");
		ft_swap(st->b + st->pb + 1, st->b + st->pb + 2);
	}
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

void	action(t_stacks *st, char *act)
{
	if (ft_memcmp(act, "sa", 2) == 0)
		swap_in_stack(st, 'A');
	else if (ft_memcmp(act, "sb", 2) == 0)
		swap_in_stack(st, 'B');
	else if (ft_memcmp(act, "ss", 2) == 0)
		swap_both(st);
	else if (ft_memcmp(act, "ra", 2) == 0)
		rotate(st, 'A');
	else if (ft_memcmp(act, "rb", 2) == 0)
		rotate(st, 'B');
	else if (ft_memcmp(act, "rra", 3) == 0)
		reverse_rotate(st, 'A');
	else if (ft_memcmp(act, "rrb", 3) == 0)
		reverse_rotate(st, 'B');
	else if (ft_memcmp(act, "rrr", 3) == 0)
		reverse_rotate_both(st);
	else if (ft_memcmp(act, "rr", 2) == 0)
		rotate_both(st);
	else if (ft_memcmp(act, "pa", 2) == 0)
		push_1_to_2(st, 'B');
	else if (ft_memcmp(act, "pb", 2) == 0)
		push_1_to_2(st, 'A');
	else
		printf("NO"); //CORRECT AFTERWARDS !!!
}

