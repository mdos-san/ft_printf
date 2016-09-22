#include "libftprintf.h"

void	ft_putwstr(int *wstr)
{
	int	i;

	i = 0;
	while (wstr[i] != 0)
	{
		ft_putwchar(wstr[i]);
		++i;
	}
}
