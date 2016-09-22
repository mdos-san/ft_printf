#include "libftprintf.h"

void	print_s(void *s, t_flag flag, int *r)
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
	(flag.flag['-'] == 0 && !flag.flag['0']) ? print_width(nb, r) : 0;
	(flag.flag['-'] == 0 && flag.flag['0']) ? print_width_z(nb, r) : 0;
	((char *)s != NULL) ? ft_putstr(str) : ft_putstr("(null)");
	*r += ft_strlen(str);
	(flag.precision > 0) ? (str[flag.precision] = tmp) : 0;
	(flag.flag['-'] == 1) ? print_width(nb, r) : 0;
	ft_strdel(&str);
}
