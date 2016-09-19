#include "libftprintf.h"

void	print_d(void *arg, int precision)
{
	char	*arr;
	int		i;

	i = 0;
	arr = ft_itoa(*(int*)arg);
	if (precision > (int)ft_strlen(arr))
	{
		(*(int*)arg < 0 ) ? ft_putchar('-') : 0;
		(*(int*)arg < 0 ) ? precision++ : 0;
		while (i < (int)(precision - ft_strlen(arr)))
		{
			ft_putchar('0');
			++i;
		}
		(*(int*)arg < 0 ) ? ft_putnbr(*(int*)arg * -1) : ft_putnbr(*(int*)arg);
	}
	else
		ft_putnbr(*(int*)arg);
	(void)precision;
}
