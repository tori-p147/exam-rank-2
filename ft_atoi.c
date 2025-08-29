#include "stdio.h"

int	ft_atoi(const char *str)
{
    int i;

    i = 0;
    int nbr;
    int sign;
    sign = 1;
    nbr = 0;
    while (str[i] >= 9 && str[i] <= 13 || str[i] == 32)
        i++;
    while (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -sign;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        nbr = nbr * 10 + (str[i] - '0');
        i++;
    }
    return (nbr * sign);
}

int main(void)
{
    printf("%d\n", ft_atoi("+--4567"));
    return (0);
}