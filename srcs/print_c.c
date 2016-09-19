#include "libftprintf.h"

void	print_c(void *c)
{
	write(1, (char *)c, 1);
}
