#include "stdio.h"
#include "unistd.h"

void	ft_putnbr(int j)
{
	if (j < 0)
	{
		write(1, "-", 1);
		j = -j;
	}
	if (j >=10)
		ft_putnbr(j / 10);
	char c = j % 10 + '0';
	write(1, &c, 1);
}

// #include <limits.h>
// int main(void)
// { 
//     ft_putnbr(INT_MIN);
// 	return (0);
// }