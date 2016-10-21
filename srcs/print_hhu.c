/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hhu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:32:54 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/21 22:52:41 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_ltoa(unsigned char l)
{
	char			buf[21];
	int				i;
	unsigned char	mod;

	i = 0;
	ft_bzero(buf, 21);
	if (l == 0)
		return (ft_strdup("0"));
	while (l != 0)
	{
		mod = l % 10;
		buf[19 - i] = mod + 48;
		l /= 10;
		++i;
	}
	--i;
	return (ft_strdup(buf + 19 - i));
}

void		print_hhu(t_flag *flag, int *r)
{
	char			*arr;
	int				i;
	int				nb;
	int				negative;
	unsigned char	uc;

	i = 0;
	nb = 0;
	uc = (unsigned char)va_arg(flag->arg, int);
	arr = ft_ltoa(uc);
	if (flag->width > flag->precision)
	{
		nb = (flag->precision > (int)ft_strlen(arr))
		? (int)(flag->width - ft_strlen(arr) - flag->precision + ft_strlen(arr))
		: (int)(flag->width - ft_strlen(arr));
		(flag->precision > (int)ft_strlen(arr)) ? --nb : 0;
	}
	(flag->flag[' '] && !flag->flag['+'] && !flag->flag['-'] && uc > 0
		&& !flag->width && !flag->precision && ++*r) ? ft_putchar(' ') : 0;
	(flag->flag['+'] == 1 && uc > 0) ? --nb : 0;
	(flag->flag['-'] == 0 && (!flag->flag['0'] || flag->precision))
		? print_width(nb, r) : 0;
	(flag->flag['+'] == 1 && ++*r) ? ft_putchar('+') : 0;
	if (flag->precision > (int)ft_strlen(arr))
	{
		negative = (arr[0] == '-') ? 1 : 0;
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
		ft_putstr(arr + negative);
		*r += ft_strlen(arr + negative);
	}
	(flag->flag['-'] == 1) ? print_width(nb, r) : 0;
}
