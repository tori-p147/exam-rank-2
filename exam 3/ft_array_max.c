void	ft_print_array(int size, int arr[size]);
void	ft_putnbr(int j);
void	ft_putstr(char *str);

void	ft_array_max(int array[], int n, int input_n)
{
	if (n == input_n)
	{
		ft_print_array(n, array);
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		array[input_n] = i;
		ft_array_max(array, n, input_n + 1);
	}
}

// int	main(void)
// {
// 	int	array[3] = {0};
// 	int	n;

// 	n = 3;
// 	ft_array_max(array, n, 0);
// 	return (0);
// }
