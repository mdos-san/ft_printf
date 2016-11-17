/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 12:59:08 by mdos-san          #+#    #+#             */
/*   Updated: 2016/11/17 06:49:21 by mdos-san         ###   ########.fr       */
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

static void	get_flag(t_ftpf *ftpf, char *str)
{
	char	*c;
	int		i;

	i = 0;
	ftpf->flag.flag[' '] =
		((c = ft_strchr(str, ' ')) != NULL) ? 1 : 0;
	ftpf->flag.flag['#'] =
		((c = ft_strchr(str, '#')) != NULL) ? 1 : 0;
	ftpf->flag.flag['+'] =
		((c = ft_strchr(str, '+')) != NULL) ? 1 : 0;
	ftpf->flag.flag['-'] =
		((c = ft_strchr(str, '-')) != NULL) ? 1 : 0;
	while (!ft_isdigit(str[i]) && str[i] != 0)
		++i;
	ftpf->flag.flag['0'] = (str[i] == '0') ? 1 : 0;
}

static void	get_info_ftpf(t_ftpf *ftpf, int nb)
{
	ftpf->c = ft_str_last_char(ftpf->params[nb]);
	ftpf->flag.uppercase = (ftpf->c == 'X') ? 1 : 0;
	ftpf->tmp = ft_strchr(ftpf->params[nb], '.');
	ftpf->flag.p_given = (ft_strchr(ftpf->params[nb], '.')) ? 1 : 0;
	ftpf->flag.precision = 0;
	ftpf->flag.width = get_width(ftpf->params[nb]);
	ftpf->flag.param = ftpf->params[nb];
	get_flag(ftpf, ftpf->params[nb]);
	(ftpf->tmp) ? ftpf->flag.precision = ft_atoi(ftpf->tmp + 1) : 0;
}

static void	exec_ftpf(t_ftpf *ftpf, va_list *ap, int *nb, int *i)
{
	va_copy(ftpf->flag.arg, *ap);
	get_info_ftpf(ftpf, *nb);
	if (ft_strchr(ftpf->params[*nb], '*'))
	{
	}
	else if (ft_strstr(ftpf->params[*nb], "hh"))
		(*ftpf->hh[(int)ftpf->c])(&ftpf->flag, &ftpf->r);
	else if (ft_strstr(ftpf->params[*nb], "h"))
		(*ftpf->h[(int)ftpf->c])(&ftpf->flag, &ftpf->r);
	else if (ft_strstr(ftpf->params[*nb], "l"))
		(*ftpf->l[(int)ftpf->c])(&ftpf->flag, &ftpf->r);
	else if (ft_strstr(ftpf->params[*nb], "j"))
		(*ftpf->j[(int)ftpf->c])(&ftpf->flag, &ftpf->r);
	else if (ft_strstr(ftpf->params[*nb], "z"))
		(*ftpf->z[(int)ftpf->c])(&ftpf->flag, &ftpf->r);
	else if (ft_strcmp(ftpf->params[*nb], "%") == 0)
	{
	}
	else
		(*ftpf->fct[(int)ftpf->c])(&ftpf->flag, &ftpf->r);
	*i += ft_strlen(ftpf->params[*nb]) - 1;
	va_copy(*ap, ftpf->flag.arg);
	++*nb;
}

int			ft_printf(char *str, ...)
{
	t_ftpf	*ftpf;
	va_list	ap;
	int		i;
	int		nb;
	int		value;

	i = 0;
	nb = 0;
	if (str == NULL)
		return (-1);
	va_start(ap, str);
	ftpf = ftpf_init(str);
	if (ftpf == NULL)
		return (ft_strlen(str));
	while (str[i])
	{
		if (str[i] != '%')
		{
			ftpf->buffer[ftpf->buf_i] = str[i];
			++ftpf->buf_i;
			if (ftpf->buf_i == BUFFER_SIZE - 1)
			{
				write(1, ftpf->buffer, BUFFER_SIZE - 1);
				ftpf->buf_i = 0;
			}
			++ftpf->r;
		}
		else
		{
			if (ftpf->buf_i > 0)
			{
				ftpf->buffer[ftpf->buf_i] = '\0';
				write(1, ftpf->buffer, ftpf->buf_i);
				ftpf->buf_i = 0;
			}
			exec_ftpf(ftpf, &ap, &nb, &i);
		}
		++i;
	}
	if (ftpf->buf_i > 0)
	{
		ftpf->buffer[ftpf->buf_i] = '\0';
		write(1, ftpf->buffer, ftpf->buf_i);
	}
	value = ftpf->r;
	va_end(ap);
	ftpf_del(&ftpf);
	return (value);
}
