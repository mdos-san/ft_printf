#include "libftprintf.h"

static char *convert_octal(unsigned long n)
{
	int	i;
	int mod;
	char buf[65];

	i = 0;
	ft_bzero(buf, 65);
	while (n != 0)
	{
		mod = n % 8;
		if (mod <= 9)
			buf[63 - i] = mod + 48;
		else
		{
			mod -= 10;
			buf[63 - i] = mod + 97;
		}
		n /= 8;
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

void	print_lo(void *o, t_flag flag)
{
	char			*array;
	int		w;
	int		p;
	int	i;

	i = -1;
	array = convert_octal(*(unsigned long*)o);
	p = flag.precision - ft_strlen(array);
	p = (p < 0) ?  0 : p;
	p = (p == 0 && flag.flag['#'] == 1) ? 1 : p;
	w = flag.width - ft_strlen(array) - p;
	w = (w < 0) ? 0 : w;
	(flag.flag['-'] == 0) ? print_width(w): 0;
	while (++i < p)
		ft_putchar('0');
	ft_putstr(array);
	(flag.flag['-'] == 1) ? print_width(w): 0;
	ft_strdel(&array);
	(void)flag;
	(void)print_width;
}
