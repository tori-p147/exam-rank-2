#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"

int strcmp(char *a, char *b)
{
    while (*a && *b && *a == *b)
    {
        a++;
        b++;
    }
    return (*a - *b);
}

void sort(char **list, int size)
{
    int i = 0;
    while (i < size - 1)
    {
        if (strcmp(list[i], list[i + 1]) > 0)
        {
            char *tmp = list[i];
            list[i] = list[i + 1];
            list[i + 1] = tmp;
            i = 0;
        }
        else
            i++;
    }
}

int ft_strlen(char *str)
{
    int len = 0;
    while(str[len])
        len++;
    return (len);
}

int factorial(int len)
{
    if (len <= 1)
        return (1);
    return (len * (factorial(len - 1)));
}

void ft_strcpy(char *src, char *dest)
{
    int i = 0;
    int j = 0;
    while (src[i])
        dest[j++] = src[i++];
    dest[j] = '\0';
    // printf("%s\n", dest);
}

void make_all_perms(int curr_i, int len, char *str, int *perms_i, char **all_perms)
{
    if (curr_i == len)
    {
        // printf("%s\n", str);
        ft_strcpy(str, all_perms[*(perms_i)]);
        (*perms_i)++;
        return ;
    }
    for (size_t i = curr_i; i < len; i++)
    {
        char c = str[i];
        str[i] = str[curr_i];
        str[curr_i] = c;
        make_all_perms(curr_i + 1, len, str, perms_i, all_perms);

        c = str[curr_i];
        str[curr_i] = str[i];
        str[i] = c;
    }
}

int main(int ac, char **av)
{
    char *str;
    char **all_perms;
    if (ac == 2)
    {
        str = av[1];
        int len = ft_strlen(str);
        int size = factorial(len);
        all_perms = malloc(sizeof(char *) * size);
        int i = 0;
        while(i < size)
            all_perms[i++] = malloc(sizeof(char) * (len + 1));
        int curr_i = 0;
        int perms_i = 0;
        make_all_perms(curr_i, len, str, &perms_i, all_perms);
        sort(all_perms, size);
        i = 0;
        while (i < size)
        {
            write(1, all_perms[i], len);
            write(1, "\n", 1);
            i++;
        }
    }
    return (0);
}
