#include "stdio.h"

unsigned int    lcm(unsigned int a, unsigned int b)
{
    if (a == 0 || b == 0)
        return (0);
    int g = 1;
    while (1)
    {
        if ((g % a == 0) && (g % b == 0))
            return (g);
        g++;
    }
}

int main(int ac, char **av)
{
    printf("%d\n", lcm(0, 7));
    return (0);
}