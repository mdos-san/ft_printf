#include "libftprintf.h"

static int pnt(unsigned long int n)
{
	int	i;
	int mod;
	char buf[33];

	i = 0;
	ft_bzero(buf, 33);
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
	return (ft_strlen(buf + 31 - i + 1));
}

void	print_p(void *p, t_flag flag, int *r)
{
	int	i;
	unsigned long int	nb;
	int	size;
	int	n;

	i = 0;
	nb = *(unsigned long int*)p;
	size = pnt(nb);
	*r += size;
	n = (flag.width > flag.precision && flag.precision > size)
			? (n = flag.width - flag.precision  - 2) : 0;
	(flag.flag['-'] == 0) ? print_width(n, r) : 0;
	ft_putstr("0x");
	if (flag.precision > size)
	{
		while (i < flag.precision - size)
		{
			ft_putchar('0');
			++*r;
			++i;
		}
	}
	ft_putptn(nb);
	(flag.flag['-'] == 1) ? print_width(n, r): 0;
	(void)flag.precision;
}
