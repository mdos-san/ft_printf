#include "libftprintf.h"

int	ft_printf(char *str, ...)
{
	t_ftpf *ftpf;
	va_list ap;	
	int		i;
	char	in;
	int		nb;

	i = 0;
	in = 0;
	nb = 0;
	va_start(ap, str);
	ftpf = ftpf_init(str);
	while (str[i])
	{
		(in == 0 && str[i] != '%') ? ft_putchar(str[i]) : 0;
		(in == 1 && ftpf->param[nb] == 's') ? ft_putstr(va_arg(ap, char *)) : 0;
		(in == 1 && ftpf->param[nb] == 'c') ? ft_putchar(va_arg(ap, int)) : 0;
		(in == 1 && ftpf->param[nb] == 'd') ? ft_putnbr(va_arg(ap, int)) : 0;
		(str[i] == '%') ? (in = 1) : 0;
		(in == 1 && str[i] == ' ') ? (in = 0) : 0;
		++i;
	}
	ftpf_del(&ftpf);
	va_end(ap);
	return (0);
}
