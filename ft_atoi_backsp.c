#include "ps_header.h"

/*
**  
*/

static int	cut_backspaces(const char *s)
{
	int i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' \
		|| s[i] == '\v' || s[i] == '\f' || s[i] == '\r'))
		i++;
	return (i);
}


int			ft_atoi_backsp(const char *str, )
{
	int			i;
	long long	res;
	long long	sign;

	res = 0;
	i = 0;
	sign = 1;
	i += cut_backspaces(&str[i]);
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res < 0 && sign == 1)
			return (-1);
		else if (res < 0 && sign == -1)
			return (0);
		i++;
	}
	return (sign * res);
}

