#include "unistd.h"

void putn(int ac)
{
    if (ac >= 10)
    {
        putn(ac / 10);
    }
    char c = ac % 10 + '0';
    write(1, &c, 1);
}

int main(int ac, char **av)
{
    if (ac >= 1)
    {
        ac -= 1;
        putn(ac);
    }   
    write(1, "\n", 1);
    return (0);
}
