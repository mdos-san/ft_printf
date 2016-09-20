#include "libftprintf.h"

static	void print_width(int nb, int *r)
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

void	print_lc(void *c, t_flag flag, int *r)
{
	int	nb;

	nb = flag.width;
	--nb;
	(*(int*)c > 127) ? --nb : 0;
	(*(int*)c > 2047) ? --nb : 0;
	(*(int*)c > 65535) ? --nb : 0;
	(flag.flag['-'] == 0) ? print_width(nb, r) : 0;
	ft_putwchar(*(int*)c);
	*r += 4;
	(flag.flag['-'] == 1) ? print_width(nb, r) : 0;
}
