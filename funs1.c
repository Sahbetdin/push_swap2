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


void	set_arr_with_numbers(int *a)
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
	
	//40 чисел
// a[0] = 27; 
// a[1] = 42; 
// a[2] = 19; 
// a[3] = 15;
// a[4] = 45; 
// a[5] = 47; 
// a[6] = 25;
// a[7] = 46; 
// a[8] = 22; 
// a[9] = 36; 
// a[10] = 20;
// a[11] = 33; 
// a[12] = 44;
// a[13] = 5;
// a[14] = 49; 
// a[15] = 48; 
// a[16] = 43;
// a[17] = 10;

a[0] = 5; 
a[1] = 42; 
a[2] = 19; 
a[3] = 15;
a[4] = 10; 
a[5] = 47; 
a[6] = 25;
a[7] = 46; 
a[8] = 22; 
a[9] = 36; 
a[10] = 20;
a[11] = 33; 
a[12] = 44;
a[13] = 27;
a[14] = 49; 
a[15] = 48; 
a[16] = 43;
a[17] = 45;
a[18] = 8;
a[19] = 16;
a[20] = 9;
a[21] = 50;
a[22] = 13;
a[23] = 90;
a[24] = 98;
a[25] = 11;
a[26] = 68;
a[27] = 65;
a[28] = 67;
a[29] = 69;


a[30] = 230;
a[31] = 226;
a[32] = 227;
a[33] = 228;
a[34] = 229;
a[35] = 222;
a[36] = 224;
a[37] = 223;
a[38] = 215;
a[39] = 220;


a[80] = 62;
a[81] = 64;
a[82] = 66;
a[83] = 71;
a[84] = 93;
a[85] = 74;
a[86] = 73;
a[87] = 79;
a[88] = 80;
a[89] = 70;



a[40] = 95;
a[41] = 94;
a[42] = 75;
a[43] = 100;
a[44] = 92;
a[45] = 99;
a[46] = 4;
a[47] = 96;
a[48] = 97;
a[49] = 101;


a[50] = 85;
a[51] = 84;
a[52] = 83;
a[53] = 86;
a[54] = 185;
a[55] = 89;
a[56] = 88;
a[57] = 81;
a[58] = 82;
a[59] = 91;

a[60] = 103;
a[61] = 148;
a[62] = 107;
a[63] = 106;
a[64] = 111;
a[65] = 109;
a[66] = 105;
a[67] = 125;
a[68] = 112;
a[69] = 104;


a[70] = 130;
a[71] = 134;
a[72] = 127;
a[73] = 128;
a[74] = 129;
a[75] = 122;
a[76] = 124;
a[77] = 123;
a[78] = 115;
a[79] = 121;




a[90] = 170;
a[91] = 176;
a[92] = 177;
a[93] = 178;
a[94] = 179;
a[95] = 162;
a[96] = 174;
a[97] = 173;
a[98] = 175;
a[99] = 140;


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
	printf("%s\n", act);
	st->oper++;
}

