#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

void	search(int curr_i, int curr_sum, int *set, int set_size, int n, int *curr,
		int curr_size)
{
	if (curr_i == set_size)
	{
		if (curr_sum == n)
		{
			for (size_t i = 0; i < curr_size; i++)
			{
				if (i != 0)
					printf(" ");
                printf("%d", curr[i]);
			}
            printf("\n");
		}
		return ;
	}
	curr[curr_size] = set[curr_i];
    //plus set[i]
	search(curr_i + 1, curr_sum + set[curr_i], set, set_size, n, curr, curr_size + 1);
    //skip set[i]
	search(curr_i + 1, curr_sum, set, set_size, n, curr, curr_size);
}

int	main(int ac, char **av)
{
	if (ac <= 2)
    {
        printf("\n");
        return (0);
    }
	
    int set_size = ac - 2;
	int *set = malloc(sizeof(int) * set_size);
    int *curr = malloc(sizeof(int) * set_size);
	int n = atoi(av[1]);
	int j = 0;
	for (int i = 0; i < set_size; i++){
        set[i] = atoi(av[i + 2]);
    }
	int curr_i = 0;
	int curr_sum = 0;
	int curr_size = 0;
	search(curr_i, curr_sum, set, set_size, n, curr, curr_size);
    free(set);
    free(curr);
	return (0);
}
