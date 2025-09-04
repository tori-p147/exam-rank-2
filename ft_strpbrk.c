#include "stdlib.h"
#include "stdio.h"

char	*ft_strpbrk(const char *s1, const char *s2)
{
    int i = 0;
    int j = 0;
    char *ptr = (char *)s1;
    while (ptr[i])
    {
        j = 0;
        while (s2[j])
        {
            if (ptr[i] == s2[j])
                return (ptr + i);
            j++;
        }
        i++;
    }
    return (NULL);
}

int main(void)
{
    printf("%s", ft_strpbrk("hello, world", "w"));
    return (0);
}