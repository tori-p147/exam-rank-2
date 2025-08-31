#include <stdlib.h>
#include "stdio.h"

int ft_abs(int j)
{
	if (j >= 0)
		return (j);
	else
		return(-j);
}

int main(void)
{
	printf("%d\n", ft_abs(-5));
	printf("%d\n", abs(5));
	printf("%d\n", abs(-5));
	return (0);
}
