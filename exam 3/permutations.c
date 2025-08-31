#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>

int	has_dup(char *s)
{
	char	chars[128];
	int		i;

	i = 0;
	while (s[i])
	{
		if (chars[s[i]] == 0)
			chars[s[i]] = 1;
		else if (chars[s[i]] == 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_factorial(int len)
{
	if (len <= 1)
		return (1);
	return (len * (ft_factorial(len - 1)));
}

void generate_all_perms(int current_index, int size, char *s, char **strs, int *perms_row_index)
{
	if (current_index == size)
	{

		return;
	}
	for (size_t i = current_index; i < size; i++)
	{
		
	}
}

int	main(int ac, char **av)
{
	char	*s;
	int		len;
	int		f;
	char	**strs;
	char	**ptr;
	int		i;
	int		perms_row_index;
	int		current_index;

	if (ac == 2)
	{
		s = av[1];
		if (has_dup(s))
			return (1);
		len = 0;
		while (s[len])
			len++;
		int size = ft_factorial(len);
		strs = malloc(sizeof(char *) * (len * f));
		perms_row_index = 0;
		current_index = 0;
		generate_all_perms(current_index, size, s, strs, &perms_row_index);
		ptr = strs;
		i = 0;
		while (*ptr)
		{
			printf("str [%d] = %s\n", i++, *ptr++);
		}
	}
	return (0);
}
