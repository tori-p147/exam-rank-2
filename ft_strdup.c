#include "stdlib.h"
#include "stdio.h"

char    *ft_strdup(char *src)
{
    int i = 0;
    int len = 0;
    while (src[len])
        len++;
        char *str = malloc(sizeof(char) * (len + 1));
    while (src[i])
    {
        str[i] = src[i];
        i++;
    }
    str[len] = '\0';
    return (str);
}

int main(void)
{
    printf("%s", ft_strdup("alalal"));
    return (0);
}