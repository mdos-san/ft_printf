#include "libftprintf.h"

void	print_s(void *s, int precision)
{
	ft_putstr((char*)s);
	(void)precision;
}
