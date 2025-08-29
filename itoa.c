#include "stdio.h"
#include "stdlib.h"

int	count_len(int nbr)
{
	int	c;

	c = 0;
	while (nbr != 0)
	{
		c++;
		nbr /= 10;
	}
	return (c);
}

char	*ft_itoa(int nbr)
{
	char *s;
	int n;

	n = count_len(nbr);
    s = malloc(sizeof(char) * (n + 1));
    s[n] = '\0';
    int i;
    i = n - 1;
    if (nbr < 0)
    {
        s[0] = '-';
        nbr = -nbr;
    }
    while (nbr > 9)
    {
        s[i] = nbr % 10 + '0';
        nbr /= 10;
        i--;
    }
    s[i] = nbr +'0';
	return (s);
}

int main(void)
{
    ;
    printf("%s\n", ft_itoa(116666666));
    return(0);
}