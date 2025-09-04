#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"

int main(int ac,char **av)
{
    if (ac == 2)
    {
        int nbr = atoi(av[1]);
        int i = 1;
        if (nbr == 1)
        {
            printf("1");
            return (0);
        }
        while (i++ <= nbr)
        {
            if (nbr % i == 0)
            {
                printf("%d", i);
                nbr /= i;
                if (i < nbr)
                    printf("*");
            }
        }
        return (0);
    }
    printf("\n");
    return (0);
}