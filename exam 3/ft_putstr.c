#include "unistd.h"

void	ft_putstr(char *str)
{
	if (*str)
	{
		write(1, str, 1);
		ft_putstr(str + 1);
	}
}

// int	main(void)
// {
// 	char s[] = "abcdefg";
// 	ft_putstr(s);
// 	return (0);
// }