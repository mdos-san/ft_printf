#include "libftprintf.h"

void	print_s(void *s, int precision)
{
	char	tmp;
	char	*str;

	str = ft_strdup((char*)s);
	if (precision > 0)
	{
		tmp = str[precision];
		str[precision] = '\0';
	}
	ft_putstr(str);
	if (precision > 0)
		str[precision] = tmp;
	ft_strdel(&str);
}
