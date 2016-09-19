#include "libftprintf.h"

void	print_c(void *c, int precision)
{
	ft_putchar(*(char*)c);
	(void)precision;
}
