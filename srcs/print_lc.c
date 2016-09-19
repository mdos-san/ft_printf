#include "libftprintf.h"

void	print_lc(void *c, t_flag flag)
{
	int	i;
	int	nb;

	i = 0;
	nb = flag.width - 4;
	while (i < nb)
	{
		ft_putchar(' ');
		++i;
	}
	ft_putwchar(*(int*)c);
	(void)flag;
}
