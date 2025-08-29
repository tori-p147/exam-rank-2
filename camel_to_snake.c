#include "unistd.h"

int	main(int ac, char **av)
{
    char *s;
	if (ac == 2)
	{
        int i;

        i = 0;
        s = av[1];
        while (s[i])
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                s[i] = s[i] + 32;
                if (i >0)
                    write(1, "_", 1);
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