#include "libftprintf.h"

static char	*convert_hexa(uintmax_t n, char up)
{
	int	i;
	int mod;
	char buf[65];

	i = 0;
	ft_bzero(buf, 65);
	if (n == 0)
	{
		buf[0] = '0';
		return (ft_strdup(buf));
	}
	while (n != 0)
	{
		mod = n % 16;
		if (mod <= 9)
			buf[63 - i] = mod + 48;
		else
		{
			mod -= 10;
			buf[63 - i] = mod + 97 - (32 * up);
		}
		n /= 16;
		++i;
	}
	return (ft_strdup(buf + 63 - i + 1));
}

void	print_jx(void *arg, t_flag flag, int *r)
{
	char	*arr;
	int		w;
	int		p;
	int		i;

	i = -1;
	arr = convert_hexa(*(uintmax_t*)arg, flag.uppercase);
	p = flag.precision - ft_strlen(arr);
	p = (p < 0) ? 0 : p;
	w = flag.width - ft_strlen(arr) - p;
	w = (flag.flag['#'] == 1) ? w - 2 : w;
	w = (w < 0) ? 0 : w;
	w = (flag.p_given && flag.precision == 0) ? flag.width : w;
	(flag.flag['-'] == 0 && flag.flag['0'] == 0) ? print_width(w, r) : 0;
	(flag.flag['#'] && !flag.uppercase && *(uintmax_t*)arg > 0 && (*r += 2)) ? ft_putstr("0x") : 0;
	(flag.flag['#'] && flag.uppercase && *(uintmax_t*)arg > 0 && (*r += 2)) ? ft_putstr("0X") : 0;
	(flag.flag['-'] == 0 && flag.flag['0'] == 1) ? print_width_z(w, r) : 0;
	while (++i < p)
	{
		ft_putchar('0');
		++*r;
	}
	(flag.p_given && flag.precision == 0) ? 0 : ft_putstr(arr);
	*r += (flag.p_given && flag.precision == 0) ? 0 : ft_strlen(arr);
	(flag.flag['-'] == 1) ? print_width(w, r): 0;
	ft_strdel(&arr);
}
