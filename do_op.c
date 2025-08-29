#include "stdio.h"
#include "stdlib.h"

int main(int ac, char **av)
{
    int res;

    res =0;

    if (ac == 4)
    {
        int i1;
        int i2;
        i1 = atoi(av[1]);
        i2 = atoi(av[3]);
        if (*av[2] == '+')  
            res = i1 + i2;
        else if (*av[2] == '-')
            res = i1 - i2;
        else if (*av[2] == '*')
            res = i1 * i2;
        else if (*av[2] == '/')
            res = i1 / i2;
        else if (*av[2] == '%')
            res = i1 % i2;
        printf("%d", res);
    }
    printf("\n");
    return (0);
}