#include "libftprintf.h"

void	print_s(void *s, t_flag flag)
{
	char	tmp;
	char	*str;
	int		i;
	int		nb;

	str = ft_strdup((char*)s);
	i = 0;
	nb = 0;
	if (flag.width > flag.precision)
	{
		

	}
	if (flag.precision > 0)
	{
		tmp = str[flag.precision];
		str[flag.precision] = '\0';
	}
	if (flag.width > flag.precision)
	{
		nb = flag.width - ft_strlen(str);	
		while (i < nb)
		{
			ft_putchar(' ');
			++i;
		}
	}
	ft_putstr(str);
	if (flag.precision > 0)
		str[flag.precision] = tmp;
	ft_strdel(&str);
}
