#include "stdio.h"

int	is_valid_base(char c, int str_base)
{
	char	*base16;
	char	*base16big;
	int		i;

	base16 = "0123456789abcdef";
	base16big = "0123456789ABCDEF";
	i = 0;
	while (i < str_base)
	{
		if (c == base16[i] || c == base16big[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	sign;
	int	result;
	int	i;

	sign = 1;
	result = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] && is_valid_base(str[i], str_base))
	{
		result *= str_base;
		if (str[i] >= 'a' && str[i] <= 'f')
			result += str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			result += str[i] - 'A' + 10;
		else if (str[i] >= '0' && str[i] <= '9')
			result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

int	main(void)
{
	printf("%d\n", ft_atoi_base("-16", 8));
	return (0);
}