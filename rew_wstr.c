#include "stdlib.h"
#include "unistd.h"

int	main(int ac, char **av)
{
	char	*s;
	int		start;
	int		end;

	s = av[1];
	end = 0;
	while (s[end])
	{
		end++;
	}
	start = 0;
	while (end > 0)
	{
		start = end;
		while (start > 0 && s[start - 1] != ' ')
		{
			start--;
		}
        int i = start;
		while (i < end)
			write(1, &s[i++], 1);
		if (start > 0)
		{
			write(1, " ", 1);
		}
        end = start - 1;
	}
	write(1, "\n", 1);
	return (0);
}
