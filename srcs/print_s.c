#include "libftprintf.h"

void	print_s(void *s, t_flag flag, int *r)
{
	char	tmp;
	char	*str;
	int		i;
	int		nb;

	str = ft_strdup((char*)s);
	i = 0;
	if (flag.precision > 0)
	{
		tmp = str[flag.precision];
		str[flag.precision] = '\0';
	}
	nb = flag.width - ft_strlen(str);
	nb += (flag.p_given && !flag.precision) ? ft_strlen(str) : 0;
	(flag.flag['-'] == 0) ? print_width(nb, r) : 0;
	((char *)s == NULL) ? ft_putstr("(null)") : 0;
	(flag.p_given && !flag.precision) ? 0 : ft_putstr(str);
	*r += (flag.p_given && !flag.precision) ? 0 :ft_strlen(str);
	(flag.precision > 0) ? (str[flag.precision] = tmp) : 0;
	(flag.flag['-'] == 1) ? print_width(nb, r) : 0;
	ft_strdel(&str);
}
