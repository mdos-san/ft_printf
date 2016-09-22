#include "libftprintf.h"

static char *pnt(unsigned long int n)
{
	int	i;
	int mod;
	char buf[33];

	i = 0;
	ft_bzero(buf, 33);
	if (!n)
		return (ft_strdup("0"));
	while (n != 0)
	{
		mod = n % 16;
		if (mod <= 9)
			buf[31 - i] = mod + 48;
		else
		{
			mod -= 10;
			buf[31 - i] = mod + 97;
		}
		n /= 16;
		++i;
	}
	return (ft_strdup(buf + 31 - i + 1));
}

void	print_p(void *p, t_flag flag, int *r)
{
	int	i;
	int	n;
	char *arr;

	i = 0;
	arr = pnt(*(unsigned int*)p);
	n = (flag.width > flag.precision) ? (flag.width - ft_strlen(arr) - 2) : 0;
	(flag.flag['-'] == 0) ? print_width(n, r) : 0;
	ft_putstr("0x");
	*r += 2;
	if (flag.precision > (int)ft_strlen(arr))
	{
		while (i < flag.precision - (int)ft_strlen(arr))
		{
			ft_putchar('0');
			++*r;
			++i;
		}
	}
	(flag.p_given && !flag.precision) ? 0 : ft_putstr(arr);
	*r += (flag.p_given && !flag.precision) ? 0 : ft_strlen(arr);
	(flag.flag['-'] == 1) ? print_width(n, r): 0;
}
