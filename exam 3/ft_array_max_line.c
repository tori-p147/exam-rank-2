void	ft_print_array(int size, int arr[size]);
void	ft_putnbr(int j);
void	ft_putstr(char *str);
#include "stdio.h"

int ft_array_max_line(int array[], int n, int input_n)
{
	int count = 0;
	if (n == input_n)
		return (1);
	for (int i = 0; i < n; i++)
	{
		array[input_n] = i;
		count += ft_array_max_line(array, n, input_n + 1);
	}
	return (count);
}

// int main(void)
// {
// 	int	array[3] = {0};
// 	int	n;

// 	n = 3;
// 	printf("%d", ft_array_max_line(array, n, 0));
// 	return (0);
// }
