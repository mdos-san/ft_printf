#include "libftprintf.h"

void	print_width(int	nb, int *r)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		ft_putchar(' ');
		++*r;
		++i;
	}
}

void	print_width_z(int nb, int *r)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		ft_putchar('0');
		++*r;
		++i;
	}
}

