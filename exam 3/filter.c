#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	char	*filter;
	int		len;
	int		cap;
	char	*buff;
	ssize_t	total;
	ssize_t	read_bites;
	int		i;
	int		j;
	int		start;
	int		k;
	char	*tmp;

	if (ac != 2 || av[1][0] == '\0')
		return (1);
	filter = av[1];
	len = strlen(filter);
	cap = 100;
	buff = malloc(sizeof(char) * cap);
	if (!buff)
	{
		perror("Error: buff not alloocated");
		return (1);
	}
	total = 0;
	while ((read_bites = read(0, buff + total, cap - total)) > 0)
	{
		total += read_bites;
		if (total == cap)
		{
			cap *= 2;
			tmp = realloc(buff, cap);
			if (!tmp)
			{
				perror("Error: buff realloc miss");
				free(buff);
				return (1);
			}
			buff = tmp;
		}
	}
	if (read_bites == -1)
	{
		perror("Error: can`t read");
		free(buff);
		return (1);
	}
	buff[total] = '\0';
	i = 0;
	while (i < total)
	{
		j = 0;
		while (i + j < total && j < len && buff[i + j] == filter[j])
			j++;
		k = 0;
		if (j == len)
		{
			while (k < len)
			{
				printf("*");
				k++;
			}
			i += len;
		}
		else
		{
			printf("%c", buff[i]);
			i++;
		}
	}
	printf("\n");
	printf("input = %s\n", buff);
	return (0);
}
