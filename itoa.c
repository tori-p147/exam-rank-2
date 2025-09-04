#include "stdio.h"
#include "stdlib.h"

int count_len(int nbr)
{
    int len = 0;
    if (nbr < 0)
        len++;
    while(nbr != 0)
    {
        nbr /= 10;
        len++;
    }
    return (len);
}

char	*ft_itoa(int n)
{
    if (n == 0)
        return ("0");
    int len = 0;
    long nbr = n;
    len = count_len(nbr);
    char *res = malloc(sizeof(char) * (len + 1));
    res[len] = '\0';
    int i = len - 1;
    printf("i = %d\n", i);
    if (nbr < 0)
    {
        res[0] = '-';
        nbr = -nbr;
    }
    while (nbr > 9)
    {
        printf("index = %d\n", i);
        printf("num = %ld\n", nbr);
        char c = nbr % 10 + '0';
        res[i] = c;
        nbr /= 10;
        i--;
    }
    res[i] = nbr + '0';
    return (res);
}

int main(void)
{
    printf("%s", ft_itoa(0));
    return (0);
}