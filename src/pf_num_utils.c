#include "../include/ft_printf.h"

int	pf_ltoa_base_len(long n, char buffer[], int base, int c)
{
	int			i;
	long			rest;
	unsigned long		u;
	
	if (base < 2 || base > 16)
		return (0);
	i = 0;
	c = c == 'X' ? 'A' : 'a';
	u = n < 0 ? -n : n;
	while (u)
	{
		rest = u % base;
		if (rest >= 10)
			buffer[i++] = c + (rest - 10);
		else
			buffer[i++] = '0' + rest;
		u /= base;
	}
	if (i == 0)
		buffer[i++] = '0';
	if (n < 0 && base == 10)
		buffer[i++] = '-';
	buffer[i] = '\0';
	ft_strnrevn(buffer, 0, i - 1);
	return (i);
}

int	pf_ultoa_base_len(unsigned long u, char buffer[], int base, int c)
{
	unsigned long 		rest;
	int			i;

	if (base < 2 || base > 16)
		return (0);
	i = 0;
	c = c == 'X' ? 'A' : 'a';
	while (u)
	{
		rest = u % base;
		if (rest >= 10)
			buffer[i++] = c + (rest - 10);
		else
			buffer[i++] = '0' + rest;
		u /= base;
	}
	if (i == 0)
		buffer[i++] = '0';
	buffer[i] = '\0';
	ft_strnrevn(buffer, 0, i - 1);
	return (i);
}
