#include "unistd.h"

void ft_putstr(char *s)
{
    while (*s)
        write(1, &(*s++), 1);
}

int main(int ac, char **av)
{
    if (ac == 3)
    {
        char *s1= av[1];
        char *s2= av[2];
        int count;
        count = 0;
        int i;
        i = 0;
        int j;
        j = 0;
        while (s2[j])
        {
            if (s2[j] == s1[i])
                i++;
            j++;
        }
        if (!av[1][i])
            ft_putstr(av[1]);
    }
    write(1, "\n", 1);
    return (0);
}
