#include "libftprintf.h"

static	void print_width(int nb)
{
	int	i;

	i = 0;
	nb = nb - 4;
	while (i < nb)
	{
		ft_putchar(' ');
		++i;
	}
}

void	print_lc(void *c, t_flag flag)
{
	(flag.flag['-'] == 0) ? print_width(flag.width) : 0;
	ft_putwchar(*(int*)c);
	(flag.flag['-'] == 1) ? print_width(flag.width) : 0;
	(void)flag;
}
