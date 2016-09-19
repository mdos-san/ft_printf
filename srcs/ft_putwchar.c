/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 18:21:58 by mdos-san          #+#    #+#             */
/*   Updated: 2016/09/19 12:27:54 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#define MASK_1 "0000000000000000000000000xxxxxxx"
#define MASK_2 "0000000000000000110xxxxx10xxxxxx"
#define MASK_3 "000000001110xxxx10xxxxxx10xxxxxx"
#define MASK_4 "11110xxx10xxxxxx10xxxxxx10xxxxxx"


static	char *print_bit(int c)
{
	int		i;
	char	buf[33];

	i = 0;
	ft_bzero(buf, 32);
	buf[32] = '\0';
	while (i < 32)
	{
		buf[31 - i] = (c % 2 == 1) ? '1' : '0';
		c = c / 2;
		++i;
	}
	return (ft_strdup(buf));
}

static char	*mask_init(char nbr)
{
	int i;

	i = 0;
	if (nbr == 1)
		return (ft_strdup(MASK_1));
	if (nbr == 2)
		return (ft_strdup(MASK_2));
	if (nbr == 3)
		return (ft_strdup(MASK_3));
	if (nbr == 4)
		return (ft_strdup(MASK_4));
	return (NULL);
}

static void	mask_fill(char *m, char *n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 32)
	{
		if (m[31 - i] == 'x')
		{
			m[31 - i] = n[31 - j];
			++j;
		}
		++i;
	}
}

static unsigned int bin_to_int(char *bin)
{
	int	i;
	unsigned int ret;
	double pow;

	i = 0;
	ret = 0;
	pow = 1;
	while (i < 32)
	{
		if (bin[31 - i] == '1')
			ret += pow;
		pow *= 2;
		++i;
	}
	return (ret);
}

void	ft_putwchar(void *r)
{
	int				c;
	char			*mask;
	char			*nbr;
	unsigned int	result;

	c = *(int*)r;
	nbr = print_bit(c);
	if (c <= 127)
		mask = mask_init(1);
	else if (c <= 2047)
		mask = mask_init(2);
	else if (2047 < c && c <= 65535)
		mask = mask_init(3);
	else
		mask = mask_init(4);
	mask_fill(mask, nbr);
	result = bin_to_int(mask);
	free(nbr);
	nbr = (char*)&result;
	(c > 65535) ? write(1, nbr + 3, 1) : 0;
	(c > 2047) ? write(1, nbr + 2, 1) : 0;
	(c > 127) ? write(1, nbr + 1, 1) : 0;
	write(1, nbr + 0, 1);
	free(mask);
}
