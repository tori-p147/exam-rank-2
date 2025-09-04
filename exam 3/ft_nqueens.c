void	ft_print_array(int size, int arr[size]);
void	ft_putnbr(int j);
void	ft_putstr(char *str);

#include <stdio.h>


int	ft_is_safe(int array[], int col, int row)
{
	for (int i = 0; i < col; i++)
	{
		if ()
		{

		}
	}
	return (1);
}

void	ft_array_max(int array[], int n, int row)
{
	if (n == row)
	{
		ft_print_array(n, array);
		return ;
	}
	for (int col = 0; col < n; col++)
	{
		if (ft_is_safe(array, col, row))
		{
			array[row] = col;
			// printf("call row: %d, col: %d\n", row, col);
			ft_array_max(array, n, row + 1);
			// printf("end row: %d col: %d\n", row, col);
		}
	}
}

int	main(void)
{
	int	array[4] = {0};
	int	n = 4;
	ft_array_max(array, n, 0);
	return (0);
}
