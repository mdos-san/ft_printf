#include "libftprintf.h"

void	print_lc(void *c, int precision)
{
	ft_putwchar(*(int*)c);
	(void)precision;
}
