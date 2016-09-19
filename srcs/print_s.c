#include "libftprintf.h"

void	print_s(void *s, t_flag flag)
{
	char	tmp;
	char	*str;

	str = ft_strdup((char*)s);
	if (flag.precision > 0)
	{
		tmp = str[flag.precision];
		str[flag.precision] = '\0';
	}
	ft_putstr(str);
	if (flag.precision > 0)
		str[flag.precision] = tmp;
	ft_strdel(&str);
}
