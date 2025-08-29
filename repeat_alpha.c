#include "unistd.h"

void	print_a(char c)
{
	int	i;

	if (c >= 'A' && c <= 'Z')
		i = c - 'A' + 1;
	else if (c >= 'a' && c <= 'z')
		i = c - 'a' + 1;
	else
		i = 1;
	while (i-- > 0)
		write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int i;

	i = 0;
	while (av[1][i])
	{
		if ((av[1][i] >= 'A' && av[1][i] <= 'Z') || (av[1][i] >= 'a'
				&& av[1][i] <= 'z'))
			print_a(av[1][i]);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}