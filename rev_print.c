#include "unistd.h"

int main(int ac, char **av)
{
    int i;

    int n;
    n = 0;
    i = 0;
    while (av[1][i++])
    {
        n++;
    }
    while (n-- > 0)
    {
        write(1, &av[1][n], 1);
    }
    write(1, "\n", 1);
    return(0);
}
