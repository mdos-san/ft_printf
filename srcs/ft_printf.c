#include "libftprintf.h"

static void *get_arg(va_list cp, char c)
{
	void	*i;

	i = (void*)malloc(64);
	(c == 'c') ? (*(int*)i = va_arg(cp, int)) : 0;
	(c == 'C') ? (*(int*)i = va_arg(cp, int)) : 0;
	(c == 's') ? (i = (void*)va_arg(cp, char *)) : 0;
	(c == 'S') ? (i = (void*)va_arg(cp, int	*)) : 0;
	(c == 'd') ? (*(int*)i = va_arg(cp, int)) : 0;
	(c == 'p') ? (*(unsigned long int*)i = va_arg(cp, unsigned long int)) : 0;
	return (i);
}

static int	get_width(char *s)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	while (s[i])
	{
		if (s[i] == '.')
			break ;
		if (ft_isdigit(s[i]))
		{
			ret = atoi(s + i);
			break ;
		}
		++i;
	}
	return (ret);
}

int	ft_printf(char *str, ...)
{
	t_ftpf *ftpf;
	va_list ap;	
	va_list cp;	
	int		i;
	int		nb;
	void	*ret;

	i = 0;
	nb = 0;
	va_start(ap, str);
	ftpf = ftpf_init(str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			va_copy(cp, ap);
			ftpf->c = ft_str_last_char(ftpf->params[nb]);	
			ftpf->tmp = ft_strchr(ftpf->params[nb], '.');
			ftpf->flag.precision = 0;
			ftpf->flag.width = get_width(ftpf->input);
			(ftpf->tmp) ? ftpf->flag.precision = ft_atoi(ftpf->tmp + 1) : 0;
			ret = get_arg(cp, ftpf->c);
			(*ftpf->fct[(int)ftpf->c])(ret, ftpf->flag);
			va_arg(ap, void*);
			i += ft_strlen(ftpf->params[nb]) - 1;
			++nb;
		}
		else
			ft_putchar(str[i]);
		++i;
	}
	ftpf_del(&ftpf);
	va_end(ap);
	return (0);
}
