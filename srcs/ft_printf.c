#include "libftprintf.h"

int	ft_printf(char *str, ...)
{
	va_list ap;	
	char	*s;

	va_start(ap, str);
	s = va_arg(ap, char *);
	t_ftpf *ftpf;
	ftpf = ftpf_init(str);
	ft_putstr(ftpf->input);
	ft_putstr(s);
	ftpf_del(&ftpf);
	va_end(ap);
	return (0);
}
