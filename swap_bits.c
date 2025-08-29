#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
    return (octet >> 4 | octet << 4);
}

int main(void)
{
    unsigned char octet = 1;
    printf("%u", reverse_bits(octet));
    return (0);
}