/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 12:59:08 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/13 12:13:45 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
		if (ft_isdigit(s[i]) && s[i] != '0')
		{
			ret = ft_atoi(s + i);
			break ;
		}
		++i;
	}
	return (ret);
}

static	void	get_flag(t_ftpf *ftpf, char *str)
{
	char	*c;
	int		i;

	i = 0;
	ftpf->flag.flag[' '] = ((c = ft_strchr(str, ' ')) != NULL) ? 1 : 0;
	ftpf->flag.flag['#'] = ((c = ft_strchr(str, '#')) != NULL) ? 1 : 0;
	ftpf->flag.flag['+'] = ((c = ft_strchr(str, '+')) != NULL) ? 1 : 0;
	ftpf->flag.flag['-'] = ((c = ft_strchr(str, '-')) != NULL) ? 1 : 0;
	while (!ft_isdigit(str[i]) && str[i] != 0)
		++i;
	ftpf->flag.flag['0'] = (str[i] == '0') ? 1 : 0;
}

int	ft_printf(char *str, ...)
{
	t_ftpf *ftpf;
	va_list ap;	
	va_list cp;	
	int		i;
	int		nb;
	int		value;
	void	*ret;

	i = 0;
	nb = 0;
	va_start(ap, str);
	ftpf = ftpf_init(str);
	ret = NULL;
	while (str[i])
	{
		if (str[i] == '%')
		{
			va_copy(cp, ap);
			va_copy(ftpf->flag.arg, ap);
			ftpf->c = ft_str_last_char(ftpf->params[nb]);	
			ftpf->flag.uppercase = (ftpf->c == 'X') ? 1 : 0;
			ftpf->tmp = ft_strchr(ftpf->params[nb], '.');
			ftpf->flag.p_given = (ft_strchr(ftpf->params[nb], '.')) ? 1 : 0;
			ftpf->flag.precision = 0;
			ftpf->flag.width = get_width(ftpf->params[nb]);
			ftpf->flag.param = ftpf->params[nb];
			get_flag(ftpf, ftpf->params[nb]);
			(ftpf->tmp) ? ftpf->flag.precision = ft_atoi(ftpf->tmp + 1) : 0;
			if (ft_strstr(ftpf->params[nb], "hh"))
			{
				(*ftpf->hh[(int)ftpf->c])(ret, ftpf->flag, &ftpf->r);
			}
			else if (ft_strstr(ftpf->params[nb], "h"))
			{
				(*ftpf->h[(int)ftpf->c])(ret, ftpf->flag, &ftpf->r);
			}
			else if (ft_strstr(ftpf->params[nb], "l"))
			{
				(*ftpf->l[(int)ftpf->c])(ret, ftpf->flag, &ftpf->r);
			}
			else if (ft_strstr(ftpf->params[nb], "j"))
			{	
				(*ftpf->j[(int)ftpf->c])(ret, ftpf->flag, &ftpf->r);
			}
			else if (ft_strstr(ftpf->params[nb], "z"))
			{	
				(*ftpf->z[(int)ftpf->c])(ret, ftpf->flag, &ftpf->r);
			}
			else if (ft_strcmp(ftpf->params[nb], "%") == 0)
			{
			}
			else
			{
				(*ftpf->fct[(int)ftpf->c])(ret, ftpf->flag, &ftpf->r);
			}
			i += ft_strlen(ftpf->params[nb]) - 1;
			if (ftpf->c != '%')
			{
				va_arg(ap, void*);
			}
			++nb;
		}
		else
		{
			ft_putchar(str[i]);
			++ftpf->r;
		}
		++i;
	}
	value = ftpf->r;
	ftpf_del(&ftpf);
	va_end(ap);
	return (value);
}
