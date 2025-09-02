#include "stdio.h"
#include "unistd.h"

int	to_remove(char *str)
{
	int	count_open;
	int	count_close;

	count_open = 0;
	count_close = 0;
	char *ptr = str;
	while (*ptr)
	{
		if (*ptr == '(')
			count_open++;
		else if (*ptr == ')' && count_open > 0)
			count_open--;
		else if (*ptr == ')' && count_open == 0)
			count_close++;
		ptr++;
	}
	// printf("%d %d\n", count_open, count_close);
	if (count_open != 0 || count_close != 0)
		return (count_open + count_close);
	ptr = str;
	while (*ptr)
		write(1, &(*ptr++), 1);
	return (0);
}

int	has_only_paranthesis(char *str)
{
	char *ptr = str;
	while (*ptr)
	{
		if (*ptr != '(' && *ptr != ')')
			return (0);
		ptr++;
	}
	return (1);
}
void solve(int current_index, int need_remove, int was_removed, int len, char *str) {

	if (current_index == len && need_remove == was_removed && !to_remove(str))
	{
		puts(str);
		return ;
	}
	if (was_removed > need_remove)
		return ;
	if (current_index == '(' || current_index == ')')
	{
		char tmp = str[current_index];
		str[current_index] = ' ';
		solve(current_index + 1, need_remove, was_removed + 1, len, str);
		str[current_index] = tmp;
		solve(current_index + 1, need_remove, was_removed, len, str);
	}
	else
		solve(current_index + 1, need_remove, was_removed, len, str);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char *str = av[1];
		if (!has_only_paranthesis(str))
			return (1);
		int need_remove = to_remove(str);
		if (need_remove == 0)
			return (0);
		char *ptr = str;
		int len = 0;
		while (*ptr++)
			len++;
		printf("%d\n", len);
		int was_removed = 0;
		int current_index = 0;
		solve(current_index, need_remove, was_removed, len, str);
	}
	return (0);
}