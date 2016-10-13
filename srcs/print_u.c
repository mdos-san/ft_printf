#include "libftprintf.h"

static	char *convert_ui(unsigned int ui)
{
	char	buf[257];
	int		i;
	int		mod;

	i = 0;
	ft_bzero(buf, 257);
	if (ui == 0)
		return (ft_strdup("0"));
	while (ui != 0)
	{
		mod = ui % 10;
		buf[255 - i] = mod + 48;
		ui /= 10;
		i += (ui != 0) ? 1 : 0;
	}
	return (ft_strdup(buf + 255 - i));
}

void	print_u(void *arg, t_flag flag, int *r)
{
	char	*arr;
	int		i;
	int		nb;
	int		negative;
	unsigned int ui;

	i = 0;
	nb = 0;
	ui = va_arg(flag.arg, unsigned int);
	arr = convert_ui(ui);
	negative = (arr[0] == '-') ? 1 : 0;
	if (flag.width > flag.precision)
	{
		nb = (flag.precision > (int)ft_strlen(arr))
			? (int)(flag.width - ft_strlen(arr)  - flag.precision + ft_strlen(arr))
			: (int)(flag.width - ft_strlen(arr));
		nb += (flag.p_given && !flag.precision && !ui) ? ft_strlen(arr) : 0;
	}
	(flag.flag['-'] == 0 && (!flag.flag['0'] || flag.precision) && flag.width - negative > flag.precision) ? print_width(nb, r) : 0;
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
		(flag.p_given && !flag.precision && !ui) ? 0 : ft_putstr(arr + negative);
		*r += (flag.p_given && !flag.precision && !ui) ? 0 : ft_strlen(arr + negative);
	}
	(flag.flag['-'] == 1) ? print_width(nb, r) : 0;
	(void)arg;
}
