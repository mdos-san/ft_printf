#include "libftprintf.h"

static void convert(unsigned long int n)
{
	int	i;
	int mod;
	char buf[33];

	i = 0;
	ft_bzero(buf, 33);
	while (n != 0)
	{
		mod = n % 16;
		if (mod <= 9)
			buf[31 - i] = mod + 48;
		else
		{
			mod -= 10;
			buf[31 - i] = mod + 97;
		}
		n /= 16;
		++i;
	}
	ft_putstr("0x");
	ft_putstr(buf + 31 - i + 1);
}

void	ft_putptn(unsigned long int pnt)
{
	convert(pnt);	
}
