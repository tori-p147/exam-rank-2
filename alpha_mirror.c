#include "unistd.h"

int main(int ac, char **av)
{
    int i;
    char *s;

    s = av[1];

    i = 0;
    if (ac == 2)
    {
        while (s[i])
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                s[i] = 'z' - (s[i] - 'a');
                write(1, &s[i], 1);
            }
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                s[i] = 'Z' - (s[i] - 'A');
                write(1, &s[i], 1);
            }
            else
                write(1, &s[i], 1);
            i++;
        }
    }
    write(1,"\n", 1);
    return (0);
}