/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:42:05 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/21 23:39:17 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_s(t_flag *flag, int *r)
{
	char	tmp;
	char	*str;
	int		nb;
	char	*ss;

	ss = va_arg(flag->arg, char *);
	if (ss == NULL && flag->width == 0)
	{
		ft_putstr("(null)");
		*r += 6;
	}
	else
	{
		str = ft_strdup(ss);
		nb = 0;
		if (flag->precision > 0)
		{
			tmp = str[flag->precision];
			str[flag->precision] = '\0';
		}
		if (flag->width > 0)
		{
			nb = flag->width - ft_strlen(str);
			nb = (flag->p_given && !flag->precision) ? flag->width : nb;
			(flag->flag['-'] == 0 && !flag->flag['0']) ? print_width(nb, r) : 0;
			(flag->flag['-'] == 0 && flag->flag['0'])
				? print_width_z(nb, r) : 0;
		}
		if ((flag->p_given && flag->precision) || !flag->p_given)
		{
			(ss != NULL) ? ft_putstr(str) : ft_putstr("(null)");
			*r += ft_strlen(str);
		}
		(flag->precision > 0) ? (str[flag->precision] = tmp) : 0;
		(flag->flag['-'] == 1) ? print_width(nb, r) : 0;
		ft_strdel(&str);
	}
}
