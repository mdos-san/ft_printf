/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 12:59:08 by mdos-san          #+#    #+#             */
/*   Updated: 2016/09/21 20:25:51 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void *get_arg(va_list cp, unsigned char c)
{
	void	*i;

	i = (void*)malloc(64);
	(c == 'c') ? (*(int*)i = va_arg(cp, int)) : 0;
	(c == 'C') ? (*(int*)i = va_arg(cp, int)) : 0;
	(c == 's') ? (i = (void*)va_arg(cp, char *)) : 0;
	(c == 'S') ? (i = (void*)va_arg(cp, int	*)) : 0;
	(c == 'd' || c == 'i') ? (*(int*)i = va_arg(cp, int)) : 0;
	(c == 'D' || c == 'I') ? (*(long*)i = va_arg(cp, long)) : 0;
	(c == 'd' + 'j') ? (*(intmax_t*)i = va_arg(cp, intmax_t)) : 0;
	(c == 'o') ? (*(unsigned int*)i = va_arg(cp, unsigned int)) : 0;
	(c == 'O') ? (*(unsigned long*)i = va_arg(cp, unsigned long)) : 0;
	(c == 'x' || c == 'X') ? (*(unsigned int*)i = va_arg(cp, unsigned int)) : 0;
	(c == 'x' + 'j') ? (*(uintmax_t*)i = va_arg(cp, uintmax_t)) : 0;
	(c == 'u') ? (*(unsigned int*)i = va_arg(cp, unsigned int)) : 0;
	(c == 'U') ? (*(unsigned long*)i = va_arg(cp, unsigned long)) : 0;
	(c == 'u' + 'j') ? (*(uintmax_t*)i = va_arg(cp, uintmax_t)) : 0;
	(c == 'Y') ? (*(unsigned long*)i = va_arg(cp, unsigned long)) : 0;
	(c == 'p') ? (*(unsigned long int*)i = va_arg(cp, unsigned long int)) : 0;
	(c == 'h' + 'd') ? (*(short*)i = (short)va_arg(cp, int)) : 0;
	(c == 'h' + 'x') ? (*(unsigned short*)i = (unsigned short)va_arg(cp, int)) : 0;
	(c == 'H' + 'd') ? (*(char*)i = (char)va_arg(cp, int)) : 0;
	(c == 'H' + 'x') ? (*(unsigned char*)i = (unsigned char)va_arg(cp, int)) : 0;
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
	while (str[i])
	{
		if (str[i] == '%')
		{
			va_copy(cp, ap);
			ftpf->c = ft_str_last_char(ftpf->params[nb]);	
			ftpf->flag.uppercase = (ftpf->c == 'X') ? 1 : 0;
			(ft_strstr(ftpf->params[nb], "l") && (ftpf->c == 'x' || ftpf->c == 'X'))
				? (ftpf->c = 'y') : 0; 
			(ft_strstr(ftpf->params[nb], "l")) ? (ftpf->c -= 32) : 0; 
			ftpf->tmp = ft_strchr(ftpf->params[nb], '.');
			ftpf->flag.p_given = (ft_strchr(ftpf->params[nb], '.')) ? 1 : 0;
			ftpf->flag.precision = 0;
			ftpf->flag.width = get_width(ftpf->input);
			get_flag(ftpf, ftpf->params[nb]);
			(ftpf->tmp) ? ftpf->flag.precision = ft_atoi(ftpf->tmp + 1) : 0;
			if (ft_strstr(ftpf->params[nb], "hh"))
			{
				ret = get_arg(cp, 'H' + ftpf->c);
				(*ftpf->hh[(int)ftpf->c])(ret, ftpf->flag, &ftpf->r);
			}
			else if (ft_strstr(ftpf->params[nb], "h"))
			{
				ret = get_arg(cp, 'h' + ftpf->c);
				(*ftpf->h[(int)ftpf->c])(ret, ftpf->flag, &ftpf->r);
			}
			else if (ft_strstr(ftpf->params[nb], "j"))
			{	
				ret = get_arg(cp, 'j' + ftpf->c);
				(*ftpf->j[(int)ftpf->c])(ret, ftpf->flag, &ftpf->r);
			}
			else
			{
				ret = get_arg(cp, ftpf->c);
				(*ftpf->fct[(int)ftpf->c])(ret, ftpf->flag, &ftpf->r);
			}
			va_arg(ap, void*);
			i += ft_strlen(ftpf->params[nb]) - 1;
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
