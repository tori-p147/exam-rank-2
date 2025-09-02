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

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	while (*src)
		(*dest++) = (*src++);
	dest[i] = '\0';
}

void	generate_all_perms(int current_index, int word_len, char *s,
		char **strs, int *strs_row_index)
{
	char	tmp;

	if (current_index == word_len)
	{
		ft_strcpy(strs[*(strs_row_index)], s);
		(*strs_row_index)++;
		return ;
	}
	for (size_t i = current_index; i < word_len; i++)
	{
		tmp = s[i];
		s[i] = s[current_index];
		s[current_index] = tmp;
		generate_all_perms(current_index + 1, word_len, s, strs,
			strs_row_index);
		tmp = s[i];
		s[i] = s[current_index];
		s[current_index] = tmp;
	}
}

int	str_cmp(char *a, char *b)
{
	while (*a && *b && *a == *b)
	{
		a++;
		b++;
	}
	return (*a - *b);
}

void	sort_strs(char **strs, int strs_count)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < strs_count - 1)
	{
		if (str_cmp(strs[i], strs[i + 1]) > 0)
		{
			// printf("str i = %s i + 1 = %s\n", strs[i], strs[i + 1]);
			tmp = strs[i];
			strs[i] = strs[i + 1];
			strs[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

void	alloc_strs(char ***strs, int strs_count, int word_len)
{
	*strs = malloc(sizeof(char *) * (strs_count + 1));
	for (size_t i = 0; i < strs_count; i++)
		(*strs)[i] = malloc(sizeof(char) * (word_len + 1));
	(*strs)[strs_count] = NULL;
}

int	main(int ac, char **av)
{
	int		strs_row_index;
	int		current_index;
	char	*s;
	int		word_len;
	int		strs_count;
	char	**strs;
	char	**ptr;
	int		i;

	if (ac == 2)
	{
		s = av[1];
		if (has_dup(s))
			return (1);
		word_len = 0;
		while (s[word_len])
			word_len++;
		strs_count = ft_factorial(word_len);
		alloc_strs(&strs, strs_count, word_len);
		strs_row_index = 0;
		current_index = 0;
		generate_all_perms(current_index, word_len, s, strs, &strs_row_index);
		sort_strs(strs, strs_count);
		ptr = strs;
		i = 0;
		while (*ptr)
			printf("str [%d] = %s\n", i++, *ptr++);
	}
	return (0);
}
