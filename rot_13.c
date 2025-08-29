#include "unistd.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char *s = av[1];
		int i = 0;
		while (s[i])
		{
			if (s[i] >= 'a' && s[i] <= 'z')
			{
                char base = 'a';
				s[i] = base + (s[i] - base + 13) % 26;
				write(1, &s[i], 1);
			}
			else if (s[i] >= 'A' && s[i] <= 'Z')
			{
                char base = 'A';
				s[i] = base + (s[i] - base + 13) % 26;
				write(1, &s[i], 1);
			}
            else
                write(1, &s[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}