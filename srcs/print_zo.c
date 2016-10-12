#include "libftprintf.h"

static char *convert_octal(unsigned long long n)
{
	int	i;
	unsigned long long mod;
	char buf[65];

	i = 0;
	ft_bzero(buf, 65);
	if (n == 0)
		return (ft_strdup("0"));
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

void	print_zo(void *o, t_flag flag, int *r)
{
	char	*array;
	int		w;
	int		p;
	int		i;

	i = -1;
	array = convert_octal(*(unsigned long long*)o);
	p = flag.precision - ft_strlen(array);
	p = (p < 0) ?  0 : p;
	p = (p == 0 && flag.flag['#'] == 1 && ft_strcmp("0", array) != 0) ? 1 : p;
	w = flag.width - ft_strlen(array) - p;
	w = (w < 0) ? 0 : w;
	w = (flag.p_given && flag.precision == 0) ? flag.width : w;
	(!flag.flag['-'] && !flag.flag['0']) ? print_width(w, r): 0;
	(!flag.flag['-'] && flag.flag['0']) ? print_width_z(w, r): 0;
	while (++i < p)
	{
		ft_putchar('0');
		++*r;
	}
	(flag.p_given && flag.precision == 0 && flag.flag['#'] == 0) ? 0 : ft_putstr(array);
	*r += (flag.p_given && flag.precision == 0 && flag.flag['#'] == 0) ? 0 : ft_strlen(array);
	(flag.flag['-'] == 1) ? print_width(w, r): 0;
	ft_strdel(&array);
}
