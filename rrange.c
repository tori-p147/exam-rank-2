# include "stdio.h"
# include "stdlib.h"

int     *ft_rrange(int start, int end)
{
    int i = end;
    int len = 1;
    int *nums = NULL;
    if (end > start)
    {
        while (i-- > start)
            len++;
    } else {
        while (i++ < start)
            len++;
    }
    printf("%d\n", len);
    nums = malloc(sizeof(int) * len);
    i = 0;
    if (end > start)
    {
        while(end >= start)
        {
            nums[i++] = end--;
        }
    } else {
        while(end <= start)
        {
            nums[i++] = end++;
        }
    }
    return(nums);
}

int main(int ac, char **av)
{
    int *nums = ft_rrange(0, 3);
    int i = 0;
    while (i < 4)
    {
        printf("%d ", nums[i]);
        i++;
    }
    return (0);
}