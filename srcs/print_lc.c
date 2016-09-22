#include "libftprintf.h"


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
	++*r;
	(flag.flag['-'] == 1) ? print_width(nb, r) : 0;
}
