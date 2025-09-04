void	ft_print_array(int size, int arr[size]);
void	ft_putnbr(int j);
void	ft_putstr(char *str);

#include <stdio.h>

typedef struct s_board
{
	int y;
	int x;
} t_board;


int	ft_is_safe(int array[], int col, int row)
{
	for (int i = 0; i < row; i++)
	{
		if (array[i] = col)
			return (0);
		else if ()
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

void print_board(int y, int x, char q)
{
	for (size_t i = 0; i < y; i++)
	{
		for (size_t j = 0; j < x; j++)
		{
			write();
		}
	}
}

int	main(void)
{
	int	array[4] = {0};
	int	n = 4;
	t_board board;
	board.y = n;
	board.x = n;

	ft_array_max(array, n, 0);
	return (0);
}
