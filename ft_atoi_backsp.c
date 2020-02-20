#include "ps_header.h"

static int	cut_backspaces(const char *s)
{
	int i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' \
		|| s[i] == '\v' || s[i] == '\f' || s[i] == '\r'))
		i++;
	return (i);
}

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
	i += cut_backspaces(&str[i]);
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	// if (*str == '\0')
	// 	...
	// {
	// 	ptr = NULL;
	// 	return (1);
	// }
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

