#include "unistd.h"

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		char ascii[128];
		int i = 0;
		while (i < 128)
		{
			ascii[i] = 0;
			i++;
		}
		char *s1 = av[1];
		char *s2 = av[2];
		i = 0;
		while (s1[i])
		{
			unsigned char c = s1[i];
			if (ascii[c] == 0)
			{
				write(1, &c, 1);
				ascii[c] = 1;
			}
			i++;
		}
		i = 0;
		while (s2[i])
		{
			unsigned char c = s2[i];
			if (ascii[c] == 0)
			{
				write(1, &c, 1);
				ascii[c] = 1;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}