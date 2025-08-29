#include "unistd.h"

void	print_n(int n)
{
	char	*s;

	s = "0123456789";
	if (n > 9)
        print_n(n / 10);
	write(1, &s[n % 10], 1);
}

int	main(void)
{
	for (size_t i = 1; i <= 100; i++)
	{
		if (i % 15 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else
			print_n(i);
		write(1, "\n", 1);
	}
	return (0);
}