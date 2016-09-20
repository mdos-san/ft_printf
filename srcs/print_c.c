#include "libftprintf.h"

static void	print_width(int	nb, int *r)
{
	int	i;

	i = 0;
	while (i < nb - 1)
	{
		ft_putchar(' ');
		++*r;
		++i;
	}
}

void	print_c(void *c, t_flag flag, int *r)
{
	(flag.flag['-'] == 0) ? print_width(flag.width, r) : 0;
	ft_putchar(*(char*)c);
	++*r;
	(flag.flag['-'] == 1) ? print_width(flag.width, r) : 0;
}
