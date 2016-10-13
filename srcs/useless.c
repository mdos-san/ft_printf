#include "libftprintf.h"

void	useless(void *param, t_flag flag, int *r)
{
	ft_putstr(flag.param + 1);
	*r += ft_strlen(flag.param + 1);
	(void)param;
	(void)flag.precision;
	(void)r;
}
