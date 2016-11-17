/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 08:17:06 by mdos-san          #+#    #+#             */
/*   Updated: 2016/11/17 08:22:05 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	norm(t_ftpf *ftpf, int *i, int *nb, va_list *ap)
{
	if (ftpf->input[*i] != '%')
	{
		ftpf->buffer[ftpf->buf_i] = ftpf->input[*i];
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
		exec_ftpf(ftpf, ap, nb, i);
	}
	++*i;
}
