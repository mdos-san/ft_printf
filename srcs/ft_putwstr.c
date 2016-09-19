#include "libftprintf.h"

void	ft_putwstr(void *wstr)
{
	int	i;

	i = 0;
	while (((int*)wstr)[i] != 0)
	{
		ft_putwchar((void *)((int*)wstr + i));
		++i;
	}
}
