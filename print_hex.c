#include "unistd.h"

void puthex(unsigned int n)
{
    char *s = "0123456789abcdef";
    char c;
    if (n >=16)
        puthex(n / 16);
    c = s[n % 16];
    write(1, &c, 1);
}

unsigned int ft_atoi(char *s)
{
    int i;
    unsigned int n;

    i = 0;
    while (s[i] && s[i] >= 48 && s[i] <= 57)
    {
        n *=10;
        n += s[i] - '0';
        i++;
    }
    return (n);
}

int main(int argc, char **argv)
{
    unsigned int n;

    n = ft_atoi(argv[1]);
    puthex(n);
    write(1, "\n", 2);
    return (0);
}
