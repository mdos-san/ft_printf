#include "libftprintf.h"

static char	*convert(unsigned long int n)
{
	char	buf[257];
	int		i;
	unsigned long int	mod;

	mod = 0;
	i = 0;
	ft_bzero(buf, 257);
	if (n == 0)
		return (ft_strdup("0"));
	while (n > 0)
	{
		mod = n % 16;
		if (mod <= 9)
			buf[255 - i] = mod + 48;
		else
			buf[255 - i] = mod + 48 + 39;
		n /= 16;
		++i;
	}
	return (ft_strdup(buf + 255 - i + 1));
}

void	print_p(void *p, t_flag flag, int *r)
{
	char	*arr;
	int		pre;
	int		i;

	i = 0;
	arr = convert(*(unsigned long int*)p);
	pre = flag.precision - ft_strlen(arr);
	pre = (pre < 0) ? 0 : pre;
	flag.width = flag.width - ft_strlen(arr) - 2;
	(!flag.flag['0'] && !flag.flag['-']) ? print_width(flag.width ,r) : 0;
	ft_putstr("0x");
	*r += 2;
	(flag.flag['0'] && !flag.flag['-']) ? print_width_z(flag.width ,r) : 0;
	while (i < pre)
	{
		ft_putchar('0');
		++*r;	
		++i;
	}
	if (!(flag.p_given && flag.precision == 0))
	{
		ft_putstr(arr);
		*r += ft_strlen(arr);
	}
	(!flag.flag['0'] && flag.flag['-']) ? print_width(flag.width ,r) : 0;
	ft_strdel(&arr);
}
