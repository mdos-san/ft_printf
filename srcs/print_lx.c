#include "libftprintf.h"

static char	*convert_hexa(unsigned long n)
{
	int	i;
	int mod;
	char buf[65];

	i = 0;
	ft_bzero(buf, 65);
	while (n != 0)
	{
		mod = n % 16;
		if (mod <= 9)
			buf[63 - i] = mod + 48;
		else
		{
			mod -= 10;
			buf[63 - i] = mod + 97;
		}
		n /= 16;
		++i;
	}
	return (ft_strdup(buf + 63 - i + 1));
}

static void print_width(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(' ');
		++i;
	}
}

void	print_lx(void *arg, t_flag flag)
{
	char	*arr;
	int		w;
	int		p;
	int		i;

	i = -1;
	arr = convert_hexa(*(unsigned long*)arg);
	p = flag.precision - ft_strlen(arr);
	p = (p < 0) ? 0 : p;
	w = flag.width - ft_strlen(arr) - p;
	w = (flag.flag['#'] == 1) ? w - 2 : w;
	w = (w < 0) ? 0 : w;
	(flag.flag['-'] == 0) ? print_width(w) : 0;
	(flag.flag['#'] == 1) ? ft_putstr("0x") : 0;
	while (++i < p)
		ft_putchar('0');
	ft_putstr(arr);
	(flag.flag['-'] == 1) ? print_width(w): 0;
	ft_strdel(&arr);
	(void)flag;
}
