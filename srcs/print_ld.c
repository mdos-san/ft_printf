/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:38:23 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/13 12:38:34 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_ltoa(long l)
{
	char	buf[21];
	int		i;
	char	negative;
	char	mod;
	
	i = 0;
	ft_bzero(buf, 21);
	negative = (l < 0) ? 1 : 0;
	if (l == 0)
		return (ft_strdup("0"));
	while (l != 0)
	{
		mod = l % 10;
		mod *= (negative) ? -1 : 1;
		buf[19 - i] = mod + 48;
		l /= 10;
		++i;
	}
	(negative == 1) ? (buf[19 - i] = '-') : --i;
	return (ft_strdup(buf + 19 - i));
}

void		print_ld(void *arg, t_flag flag, int *r)
{
	char	*arr;
	int		i;
	int		nb;
	int		negative;
	long	l;

	i = 0;
	nb = 0;
	l = va_arg(flag.arg, long);
	arr = ft_ltoa(l);
	if (flag.width > flag.precision)
	{
		nb = (flag.precision > (int)ft_strlen(arr))
			? (int)(flag.width - ft_strlen(arr)  - flag.precision + ft_strlen(arr))
			: (int)(flag.width - ft_strlen(arr));
		(l < 0 && flag.precision > (int)ft_strlen(arr)) ? --nb : 0;
	}
	(flag.flag['+'] == 1 && l > 0) ? --nb : 0;
	(flag.flag['-'] == 0) ? print_width(nb, r) : 0;
	(flag.flag['+'] == 1 && l > 0 && ++*r) ? ft_putchar('+') : 0;
	if (flag.precision > (int)ft_strlen(arr))
	{
		negative = (arr[0] == '-') ? 1 : 0;
		(negative == 1 && ++*r) ? ft_putchar('-') : 0;
		while (i < flag.precision - (int)ft_strlen(arr) + negative)
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
		ft_putstr(arr);
		*r += ft_strlen(arr);
	}
	(flag.flag['-'] == 1) ? print_width(nb, r) : 0;
	(void)arg;
}
