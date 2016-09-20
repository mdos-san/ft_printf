#include "libftprintf.h"

static void	print_width(int nb, int *r)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		ft_putchar(' ');
		++*r;
		++i;
	}
}

void	print_d(void *arg, t_flag flag, int *r)
{
	char	*arr;
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	arr = ft_itoa(*(int*)arg);
	if (flag.width > flag.precision)
	{
		nb = (flag.precision > (int)ft_strlen(arr))
			? (int)(flag.width - ft_strlen(arr)  - flag.precision + ft_strlen(arr))
			: (int)(flag.width - ft_strlen(arr));
		(*(int*)arg < 0 && flag.precision > (int)ft_strlen(arr)) ? --nb : 0;
	}
	(flag.flag['+'] == 1 && *(int*)arg >= 0) ? --nb : 0;
	(flag.flag['-'] == 0) ? print_width(nb, r) : 0;
	(flag.flag['+'] == 1 && *(int*)arg >= 0 && (*r += 1)) ? ft_putchar('+') : 0;
	if (flag.precision > (int)ft_strlen(arr))
	{
		(*(int*)arg < 0 && *r++) ? ft_putchar('-') : 0;
		(*(int*)arg < 0 ) ? flag.precision++ : 0;
		while (i < (int)(flag.precision - ft_strlen(arr)))
		{
			ft_putchar('0');
			++*r;
			++i;
		}
		(*(int*)arg < 0 ) ? ft_putnbr(*(int*)arg * -1) : ft_putnbr(*(int*)arg);
		*r += ft_strlen(arr);
	}
	else
	{
		ft_putnbr(*(int*)arg);
		*r += ft_strlen(arr);
	}
	(flag.flag['-'] == 1) ? print_width(nb, r) : 0;
}
