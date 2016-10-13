/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useless.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:50:28 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/13 12:50:33 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	useless(void *param, t_flag flag, int *r)
{
	ft_putstr(flag.param + 1);
	*r += ft_strlen(flag.param + 1);
	(void)param;
	(void)flag.precision;
	(void)r;
}
