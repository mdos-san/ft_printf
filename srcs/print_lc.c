#include "libftprintf.h"

void	print_lc(void *c, t_flag flag)
{
	ft_putwchar(*(int*)c);
	(void)flag;
}
