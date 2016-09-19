#include "libftprintf.h"

void	print_d(void *arg, t_flag flag)
{
	char	*arr;
	int		i;
	int		nb;

	i = 0;
	arr = ft_itoa(*(int*)arg);
	if (flag.width > flag.precision)
	{
		nb = (int)(flag.width - ft_strlen(arr)  - flag.precision + ft_strlen(arr));
		(*(int*)arg < 0) ? --nb : 0;
		while (i < nb)
		{
			ft_putchar(' ');
			++i;
		}
		i = 0;
	}
	if (flag.precision > (int)ft_strlen(arr))
	{
		(*(int*)arg < 0 ) ? ft_putchar('-') : 0;
		(*(int*)arg < 0 ) ? flag.precision++ : 0;
		while (i < (int)(flag.precision - ft_strlen(arr)))
		{
			ft_putchar('0');
			++i;
		}
		(*(int*)arg < 0 ) ? ft_putnbr(*(int*)arg * -1) : ft_putnbr(*(int*)arg);
	}
	else
		ft_putnbr(*(int*)arg);
}
