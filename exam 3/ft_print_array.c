#include "unistd.h"
#include "stdio.h"

void print_nbr(int nbr)
{
	if (nbr < 0)
		write(1, "-", 1);
	if (nbr >=10)
		print_nbr(nbr / 10);
	char c = nbr % 10 + '0';
	write(1, &c, 1);
}

void ft_print_array(int size, int arr[size])
{
	int i;
	i = 0;
	while (i < size)
	{
		print_nbr(arr[i]);
		if (i != (size - 1))
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

// int main(void)
// {
// 	int size = 9;
// 	int arr[9] = {10, 20, 30, 40, 50, 60, 70, 80, 90};

// 	ft_print_array(size, arr);
// 	return (0);
// }
