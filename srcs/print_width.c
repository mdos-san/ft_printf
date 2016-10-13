/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:42:40 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/13 12:42:45 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_width(int	nb, int *r)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		ft_putchar(' ');
		++*r;
		++i;
	}
}

void	print_width_z(int nb, int *r)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		ft_putchar('0');
		++*r;
		++i;
	}
}

