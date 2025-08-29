#include "unistd.h"
#include <string.h>

void ft_putnbr(int n){

    if (n >=10)
        ft_putnbr(n / 10);
    char c = n % 10 + '0';
    write(1, &c, 1);
}

int ft_atoi(char *s)
{
    int i;
    int n;

    i = 0;
    while (s[i] && s[i] >= 48 && s[i] <= 57)
    {
        n *= 10;
        n += s[i] - '0';
        i++;
    }
    return (n);
}

int	main(int argc, char **argv)
{
	int	num;
	int sum;

	num = ft_atoi(argv[1]);
	if (argc == 1)
	{
		write(1, "\n", 1);
	}
	else if (argc == 2)
	{
		for (int i = 1; i < 10; i++)
		{
			sum = i * num;
			ft_putnbr(i);
			write(1, " x ", 3);
            ft_putnbr(num);
			write(1, " = ", 3);
			ft_putnbr(sum);
            write(1, "\n", 2);
		}
	}
	return (0);
}
