/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:39:09 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/21 20:36:43 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	*int_arr_dup(int *arr, int pre)
{
	int	i;
	int	nbr;
	int	bla;
	int	to_go;
	int	*ret;

	i = 0;
	nbr = 0;
	to_go = 0;
	while (arr[nbr])
	{
		++to_go;
		to_go += (arr[nbr] > 127) ? 1 : 0;
		to_go += (arr[nbr] > 2047) ? 1 : 0;
		to_go += (arr[nbr] > 65535) ? 1 : 0;
		++nbr;
	}
	ret = (int*)malloc(sizeof(int) * (nbr + 1));
	ft_bzero(ret, sizeof(int) * (nbr + 1));
	pre = (pre <= 0) ? to_go : pre;
	bla = 0;
	while (bla < pre)
	{
		++bla;
		bla += (arr[i] > 127) ? 1 : 0;
		bla += (arr[i] > 2047) ? 1 : 0;
		bla += (arr[i] > 65535) ? 1 : 0;
		if (bla > pre)
		{
			ret[i] = 0;
			break ;
		}
		ret[i] = arr[i];
		++i;
	}
	return (ret);
}

static int	int_arr_len(int *arr)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (arr[i])
	{
		ret++;
		ret += (arr[i] > 127) ? 1 : 0;
		ret += (arr[i] > 2047) ? 1 : 0;
		ret += (arr[i] > 65535) ? 1 : 0;
		++i;
	}
	return (ret);
}

void		print_ls(void *s, t_flag flag, int *r)
{
	int		*arr;
	int		nb;
	int		*st;

	nb = 0;
	st = va_arg(flag.arg, int *);
	if (st == NULL && flag.width == 0)
	{
		ft_putstr("(null)");
		*r += 6;
	}
	else
	{
		arr = int_arr_dup(st, flag.precision);
		nb = (flag.width > flag.precision) ? flag.width - int_arr_len(arr) : 0;
		(flag.flag['-'] == 0 && !flag.flag['0']) ? print_width(nb, r) : 0;
		(flag.flag['-'] == 0 && flag.flag['0']) ? print_width_z(nb, r) : 0;
		if (!(flag.p_given && !flag.precision))
		{
			*r += ft_putwstr(arr);
			(flag.flag['-'] == 1) ? print_width(nb, r) : 0;
		}
		else
		{
			(flag.flag['-'] == 0 && flag.flag['0'])
				? print_width_z(flag.width, r) : 0;
			(flag.flag['-'] == 0 && !flag.flag['0'])
				? print_width(flag.width, r) : 0;
		}
		(flag.flag['-'] && flag.flag['0']) ? print_width_z(nb, r) : 0;
		(arr) ? free(arr) : 0;
	}
	(void)s;
}
