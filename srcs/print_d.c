#include "libftprintf.h"

void	print_d(void *arg, int precision)
{
	ft_putnbr(*(int*)arg);
	(void)precision;
}
