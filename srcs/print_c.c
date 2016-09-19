#include "libftprintf.h"

void	print_c(void *c, t_flag flag)
{
	int	i;

	i = 0;
	while (i < flag.width - 1)
	{
		ft_putchar(' ');
		++i;
	}
	ft_putchar(*(char*)c);
	(void)flag;
}
