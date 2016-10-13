#include "libftprintf.h"


void	print_lc(void *c, t_flag flag, int *r)
{
	int	nb;
	int	ca;

	ca = va_arg(flag.arg, int);
	nb = flag.width;
	--nb;
	(ca > 127) ? --nb : 0;
	(ca > 2047) ? --nb : 0;
	(ca > 65535) ? --nb : 0;
	(flag.flag['-'] == 0) ? print_width(nb, r) : 0;
	*r += ft_putwchar(ca);
	(flag.flag['-'] == 1) ? print_width(nb, r) : 0;
	(void)c;
}
