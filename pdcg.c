#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int num1 = atoi(av[1]);
		int num2 = atoi(av[2]);
        int min_num = 0;
        if (num1 >= num2)   
            min_num = num2;
        else
            min_num = num1;
        int i = 1;
        int max_den = 1;
        while (i <= min_num)
        {
            if (num1 % i == 0 && num2 % i == 0){
                max_den = i;
                printf("%d && %d loop %d max den = %d\n", num1 % max_den, num2 % max_den, i, max_den);
            }
            i++;
        }
        printf("%d\n", max_den);
        return (0);
	}
	write(1, "\n", 1);
	return (0);
}