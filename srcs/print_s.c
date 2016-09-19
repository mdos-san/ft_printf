#include "libftprintf.h"

void	print_s(void *s)
{
	int	i;

	i = ft_strlen((char *)s);
	write(1, (char *)s, i);
}
