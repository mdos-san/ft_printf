#include "libftprintf.h"

static	char *ft_ltoa(unsigned long long l)
{
	char	buf[257];
	int		i;

	i = 0;
	ft_bzero(buf, 257);
	if (l == 0)
		return (ft_strdup("0"));
	while (l != 0)
	{
		buf[255 - i] = l % 10 + 48;
		l /= 10;
		++i;
	}
	--i;
	return (ft_strdup(buf + 255 - i));
}

void	print_zu(void *arg, t_flag flag, int *r)
{
	char	*arr;
	int		i;
	int		nb;
	int		negative;

	i = 0;
	nb = 0;
	arr = ft_ltoa(va_arg(flag.arg, unsigned long long));
	negative = (arr[0] == '-') ? 1 : 0;
	if (flag.width > flag.precision)
	{
		nb = (flag.precision > (int)ft_strlen(arr))
			? (int)(flag.width - ft_strlen(arr)  - flag.precision + ft_strlen(arr))
			: (int)(flag.width - ft_strlen(arr));
		nb += (flag.p_given && !flag.precision && !*(unsigned long long*)arg) ? ft_strlen(arr) : 0;
	}
	(flag.flag[' '] && !flag.flag['+'] && !flag.flag['-'] && *(unsigned long long*)arg > 0 && !flag.width && !flag.precision && ++*r) ? ft_putchar(' ') : 0;
	(flag.flag['+'] == 1 && *(unsigned long long*)arg > 0) ? --nb : 0;
	(flag.flag['-'] == 0 && (!flag.flag['0'] || flag.precision) && flag.width - negative > flag.precision) ? print_width(nb, r) : 0;
	(flag.flag['+'] == 1 && ++*r) ? ft_putchar('+') : 0;
	if (flag.precision >= (int)ft_strlen(arr))
	{
		(negative == 1 && ++*r) ? ft_putchar('-') : 0;
		(flag.flag['-'] == 0 && flag.flag['0'] && !flag.precision) ? print_width_z(nb, r) : 0;
		while (i < flag.precision - (int)ft_strlen(arr) + negative)
		{
			ft_putchar('0');
			++*r;
			++i;
		}
		ft_putstr(arr + negative);
		*r += ft_strlen(arr + negative);
	}
	else
	{
		negative = (arr[0] == '-') ? 1 : 0;
		(negative == 1 && ++*r) ? ft_putchar('-') : 0;
		(flag.flag['-'] == 0 && flag.flag['0'] && !flag.precision) ? print_width_z(nb, r) : 0;
		(flag.p_given && !flag.precision && !*(unsigned long long*)arg) ? 0 : ft_putstr(arr + negative);
		*r += (flag.p_given && !flag.precision && !*(unsigned long long*)arg) ? 0 : ft_strlen(arr + negative);
	}
	(flag.flag['-'] == 1) ? print_width(nb, r) : 0;
	(void)arg;
}
