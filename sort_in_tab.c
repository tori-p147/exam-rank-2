#include "stdio.h"

void sort_int_tab(int *tab, unsigned int size)
{
    int i;

    i = 0;
    while (i < size - 1)
    {
        
        if (tab[i] > tab[i + 1])
        {
            int tmp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = tmp;
            i = 0;
        }
        else 
            i++;
    }
}

int main(void)
{
    int ints[6] = {1,4,2,4,6,3};
    sort_int_tab(ints, 6);
    int i;
    i = 0;
    while (i < 6)
        printf("%d ", ints[i++]);
    return (0);
}