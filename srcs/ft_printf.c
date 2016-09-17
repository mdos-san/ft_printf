#include "libftprintf.h"

int	ft_printf(char *str, ...)
{
	t_ftpf *ftpf;
	ftpf = ftpf_init(str);
	ft_putstr(ftpf->input);
	ftpf_del(&ftpf);
	return (0);
}
