/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:26:34 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/22 06:16:34 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	count_params(char *s)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			++nbr;
			++i;
		}
		++i;
	}
	return (nbr);
}

static int	is_flag(char c)
{
	if (c == 'c' || c == 'C' ||
		c == 's' || c == 'S' ||
		c == 'd' || c == 'D' ||
		c == 'i' || c == 'I' ||
		c == 'o' || c == 'O' ||
		c == 'x' || c == 'X' ||
		c == 'u' || c == 'U' ||
		c == '%' ||
		c == 'p')
		return (1);
	return (0);
}

static void	init_params(char *s, char ***arr)
{
	unsigned int	i1;
	unsigned int	i2;
	char			cpy[1024];

	i1 = 0;
	i2 = 0;
	while (s[i1])
	{
		if (s[i1] == '%')
		{
			i2 = i1;
			++i2;
			while (!is_flag(s[i2]) && s[i2 + 1] != '\0')
				++i2;
			i2++;
			ft_bzero(cpy, 1024);
			ft_strncpy(cpy, s + i1, i2 - i1);
			str_array_add(arr, cpy);
			i1 = i2 - 1;
		}
		++i1;
	}
}

static void	get_mod(t_ftpf *ftpf)
{
	if (ft_strchr(ftpf->input, 'l'))
		ftpf->flag.mod = ft_strdup("l");
	else if (ft_strstr(ftpf->input, "ll"))
		ftpf->flag.mod = ft_strdup("ll");
	else if (ft_strchr(ftpf->input, 'h'))
		ftpf->flag.mod = ft_strdup("h");
	else if (ft_strstr(ftpf->input, "hh"))
		ftpf->flag.mod = ft_strdup("hh");
}

t_ftpf		*ftpf_init(char *input)
{
	t_ftpf	*new;

	new = (t_ftpf*)malloc(sizeof(t_ftpf));
	if (!new)
		return (NULL);
	new->input = input;
	new->nbr_param = count_params(input);
	if (new->nbr_param == 0)
	{
		ft_putstr(input);
		free(new);
		return (NULL);
	}
	new->params = str_array_new();
	new->r = 0;
	init_params(input, &new->params);
	get_mod(new);
	init_useless(new);
	init_hhhl(new);
	init_lj(new);
	init_fct(new);
	init_pz(new);
	return (new);
}
