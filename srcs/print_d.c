/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:28:02 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/21 22:51:24 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_ltoa(long l)
{
	char	buf[21];
	int		i;
	char	negative;

	i = 0;
	ft_bzero(buf, 21);
	negative = (l < 0) ? 1 : 0;
	(negative == 1) ? (l *= -1) : 0;
	if (l == 0)
		return (ft_strdup("0"));
	while (l != 0)
	{
		buf[19 - i] = l % 10 + 48;
		l /= 10;
		++i;
	}
	(negative == 1) ? (buf[19 - i] = '-') : --i;
	return (ft_strdup(buf + 19 - i));
}

void		print_d(t_flag *flag, int *r)
{
	char	*arr;
	int		i;
	int		nb;
	int		negative;
	int		in;

	i = 0;
	nb = 0;
	in = va_arg(flag->arg, int);
	arr = ft_ltoa(in);
	negative = (arr[0] == '-') ? 1 : 0;
	if (flag->width > flag->precision)
	{
		nb = (flag->precision > (int)ft_strlen(arr))
		? (int)(flag->width - ft_strlen(arr) - flag->precision + ft_strlen(arr))
		: (int)(flag->width - ft_strlen(arr));
		(in < 0 && flag->precision > (int)ft_strlen(arr)) ? --nb : 0;
		nb += (flag->p_given && !flag->precision && !in) ? ft_strlen(arr) : 0;
	}
	(flag->flag[' '] && !flag->flag['+'] && !flag->flag['-'] && in > 0
		&& !flag->width && !flag->precision && ++*r) ? ft_putchar(' ') : 0;
	if (flag->flag[' '] && in == 0)
	{
		ft_putchar(' ');
		++*r;
		--nb;
	}
	(flag->flag['+'] == 1 && in >= 0) ? --nb : 0;
	(flag->flag['-'] == 0 && (!flag->flag['0'] || flag->precision)
		&& flag->width - negative > flag->precision) ? print_width(nb, r) : 0;
	(flag->flag['+'] == 1 && in >= 0 && ++*r) ? ft_putchar('+') : 0;
	if (flag->precision >= (int)ft_strlen(arr))
	{
		(negative == 1 && ++*r) ? ft_putchar('-') : 0;
		(flag->flag['-'] == 0 && flag->flag['0'] && !flag->precision)
			? print_width_z(nb, r) : 0;
		while (i < flag->precision - (int)ft_strlen(arr) + negative)
		{
			ft_putchar('0');
			++*r;
			++i;
		}
		ft_putstr(arr + negative);
		*r += ft_strlen(arr + negative);
	}
	else
	{
		negative = (arr[0] == '-') ? 1 : 0;
		(negative == 1 && ++*r) ? ft_putchar('-') : 0;
		(flag->flag['-'] == 0 && flag->flag['0'] && !flag->precision)
			? print_width_z(nb, r) : 0;
		(flag->p_given && !flag->precision && !in)
			? 0 : ft_putstr(arr + negative);
		*r += (flag->p_given && !flag->precision && !in)
			? 0 : ft_strlen(arr + negative);
	}
	(flag->flag['-'] == 1) ? print_width(nb, r) : 0;
}
