#include "libftprintf.h"

static void	print_width(int	nb)
{
	int	i;

	i = 0;
	while (i < nb - 1)
	{
		ft_putchar(' ');
		++i;
	}
}

void	print_c(void *c, t_flag flag)
{
	(flag.flag['-'] == 0) ? print_width(flag.width) : 0;
	ft_putchar(*(char*)c);
	(flag.flag['-'] == 1) ? print_width(flag.width) : 0;
}
