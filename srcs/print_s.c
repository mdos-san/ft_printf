#include "libftprintf.h"

static void	print_width(int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		ft_putchar(' ');
		++i;
	}
}

void	print_s(void *s, t_flag flag)
{
	char	tmp;
	char	*str;
	int		i;
	int		nb;

	str = ft_strdup((char*)s);
	i = 0;
	nb = 0;
	if (flag.precision > 0)
	{
		tmp = str[flag.precision];
		str[flag.precision] = '\0';
	}
	nb = (flag.width > flag.precision) ? flag.width - ft_strlen(str) : 0;
	(flag.flag['-'] == 0) ? print_width(nb) : 0;
	ft_putstr(str);
	(flag.precision > 0) ? (str[flag.precision] = tmp) : 0;
	(flag.flag['-'] == 1) ? print_width(nb) : 0;
	ft_strdel(&str);
}
