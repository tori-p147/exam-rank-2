#include "unistd.h"

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		int i = 1;
		while (i < ac)
		{
			char *str = av[i];
			int j = 0;
			while (str[j])
			{
				if (str[j] >= 'a' && str[j] <= 'z' && (str[j - 1] == ' ' || j == 0))
                {
                    char c = str[j] - 32;
                    write(1, &c, 1);
                }
                else if (str[j] >= 'A' && str[j] <= 'Z' && str[j - 1] != ' ')
                {
                    char c = str[j] + 32;
                    write(1, &c, 1);
                }
                else
                    write(1, &str[j], 1);
                j++;
			}
            write(1, "\n", 1);
			i++;
		}
        return (0);
	}
    write(1, "\n", 1);
	return (0);
}