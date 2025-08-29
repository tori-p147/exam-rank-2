#include "stdlib.h"
#include "unistd.h"

int	main(int ac, char **arv)
{
	char	*s;
	int		i;
	int		j;
	int		n;
	int		start;

	i = 0;
	n = 0;
	if (ac >= 2)
	{
		s = arv[1];
		while (s[i] && s[i] == ' ')
			i++;
        start = i;
		while (s[i] && s[i] != ' ')
		{
			n++;
			i++;
		}
		while (s[i])
		{
            if (s[i] == ' ')
			{
				write(1, " ", 1);
                while (s[i] == ' ')
				    i++;
			}
			else
				write(1, &s[i++], 1);
		}
        if (n > 0)
        {
           write(1, " ", 1);
           write(1, &s[start], n);
        }
	}
	write(1, "\n", 1);
}
