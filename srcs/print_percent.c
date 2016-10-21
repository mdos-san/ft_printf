/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:41:57 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/21 20:40:07 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_percent(void *arg, t_flag flag, int *ret)
{
	(!flag.flag['-'] && !flag.flag['0'])
		? print_width(flag.width - 1, ret) : 0;
	(!flag.flag['-'] && flag.flag['0'])
		? print_width_z(flag.width - 1, ret) : 0;
	ft_putchar('%');
	++*ret;
	(flag.flag['-'] == 1) ? print_width(flag.width - 1, ret) : 0;
	(void)arg;
	(void)flag;
}
