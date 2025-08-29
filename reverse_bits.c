#include "unistd.h"
#include "stdio.h"

unsigned char	reverse_bits(unsigned char octet)
{
	int				i;
	unsigned char	bit;
	unsigned char	reverse;

	bit = 0;
	reverse = 0;
	i = 8;
	while (i--)
	{
		bit = octet >> i & 1;
		reverse |= bit << 7 - i;
	}
	return (reverse);
}

int	main(void)
{
	unsigned char	octet;
	unsigned char	reverse;
    unsigned char	bit;

	octet = 1;
        int i;

    i = 8;
    while(i--)
    {
        bit = (octet >> i & 1) + '0';
        write(1, &bit, 1);
        
    }
    write(1, "\n", 2);
	reverse = reverse_bits(octet);

    i = 8;
	while(i--)
    {
        bit = (reverse >> i & 1) + '0';
        write(1, &bit, 1);
    }
	return (0);
}
