#include "libftprintf.h"

static	char *convert_ui(unsigned int ui)
{
	char	buf[257];
	int		i;
	int		mod;

	i = 0;
	ft_bzero(buf, 257);
	while (ui != 0)
	{
		mod = ui % 10;
		buf[255 - i] = mod + 48;
		ui /= 10;
		i += (ui != 0) ? 1 : 0;
	}
	return (ft_strdup(buf + 255 - i));
}

void	print_u(void *ui, t_flag flag, int *r)
{
	char	*arr;

	arr = convert_ui(*(unsigned int*)ui);
	ft_putstr(arr);
	*r += ft_strlen(arr);
	(void)flag;
}
