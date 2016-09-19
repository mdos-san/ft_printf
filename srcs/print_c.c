#include "libftprintf.h"

void	print_c(void *c, t_flag flag)
{
	ft_putchar(*(char*)c);
	(void)flag;
}
