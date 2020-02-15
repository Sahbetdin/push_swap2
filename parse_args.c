#include "ps_header.h"




int main(int ac, char **av)
{
	int i;
	int j;
	int cnt;
	int flag;
	char *tmp;

	if (ac == 1)
		return (0);
	i = 0;
	cnt = 0;
	flag = 0;
	while (i < ac)
	{
		j = 0;
		tmp = ft_strtrim(av[i]);
		while (tmp[j])
		{
			if (tmp[j] == ' ' && flag == 0)
			{
				cnt++;
				flag = 1;
			}
			else if (tmp[j] != ' ' && flag == 1)
				flag = 0;
			j++;
		}
		free(tmp);
		i++;
	}
	printf("%d \n", ft_atoi(av[1]));
	printf("%d\n", cnt + ac - 1);
	
	return (0);
}