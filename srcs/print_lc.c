#include "libftprintf.h"

static	void print_width(int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		ft_putchar(' ');
		++i;
	}
}

void	print_lc(void *c, t_flag flag)
{
	int	nb;

	nb = flag.width;
	--nb;
	(*(int*)c > 127) ? --nb : 0;
	(*(int*)c > 2047) ? --nb : 0;
	(*(int*)c > 65535) ? --nb : 0;
	(flag.flag['-'] == 0) ? print_width(nb) : 0;
	ft_putwchar(*(int*)c);
	(flag.flag['-'] == 1) ? print_width(nb) : 0;
	(void)flag;
}
