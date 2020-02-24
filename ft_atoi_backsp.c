/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_backsp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 21:22:08 by btrifle           #+#    #+#             */
/*   Updated: 2020/02/24 21:22:09 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

/*
** if int parsed then we put to p_numb what was parsed
** and return pointer to next char;
** if int was overflowed then return NULL;
*/

char	*ft_atoi_backsp(const char *str, int *p_numb, int *n)
{
	int	i;
	int	res;
	int	sign;

	res = 0;
	i = 0;
	sign = 1;
	i += ft_cut_backspaces(&str[i]);
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (ft_strstr(str, "2147483648") && sign == -1)
	{
		*p_numb = -2147483648;
		return ((char *)str + i + 10);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] > '7'))
		{
			*n = -1;
			return (NULL);
		}
		else
			res = res * 10 + (str[i] - '0');
		i++;
	}
	*p_numb = sign * res;
	if (str[i] == '\0')
	{
		*n = 0;
		return (NULL);
	}
	*n = 1;
	return ((char *)str + i);
}

