#include "libftprintf.h"

static	void	print_bit(int c)
{
	int		i;
	char	buf[33];

	i = 0;
	ft_bzero(buf, 32);
	buf[32] = '\0';
	while (i < 32)
	{
		if (c % 2 == 1)
			buf[31 - i] = '1';
		else
			buf[31 - i] = '0';
		c = c / 2;
		++i;
	}
	ft_putendl("====PRINT_BIT====");
	write(1, buf, 8);
	ft_putchar(' ');
	write(1, buf + 8, 8);
	ft_putchar(' ');
	write(1, buf + 16, 8);
	ft_putchar(' ');
	write(1, buf + 24, 8);
	ft_putchar('\n');
}

void	ft_putwchar(int c)
{
	print_bit(c);


}
