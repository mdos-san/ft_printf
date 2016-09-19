#include "libftprintf.h"

void	print_ls(void *s, int precision)
{
	ft_putwstr((int*)s);
	(void)precision;
}
