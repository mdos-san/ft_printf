#include "libftprintf.h"

int		ft_putwstr(int *wstr)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (wstr[i] != 0)
	{
		r += ft_putwchar(wstr[i]);
		++i;
	}
	return (r);
}
