/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:26:34 by mdos-san          #+#    #+#             */
/*   Updated: 2016/10/21 20:21:33 by mdos-san         ###   ########.fr       */
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
	int		i1;
	int		i2;
	char	tmp;

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
			tmp = s[i2];
			s[i2] = '\0';
			str_array_add(arr, s + i1);
			s[i2] = tmp;
			i1 = i2 - 1;
		}
		++i1;
	}
	str_array_add(arr, s + i2 + 1);
}

static void	get_mod(t_ftpf *ftpf)
{
	if (ft_strchr(ftpf->input, 'l'))
		ftpf->flag.mod = ft_strdup("l");
	if (ft_strstr(ftpf->input, "ll"))
		ftpf->flag.mod = ft_strdup("ll");
	if (ft_strchr(ftpf->input, 'h'))
		ftpf->flag.mod = ft_strdup("h");
	if (ft_strstr(ftpf->input, "hh"))
		ftpf->flag.mod = ft_strdup("hh");
}

t_ftpf		*ftpf_init(char *input)
{
	t_ftpf	*new;
	char	*str;
	int		i;

	i = -1;
	new = (t_ftpf*)malloc(sizeof(t_ftpf));
	if (!new)
		return (NULL);
	new->input = ft_strdup(input);
	str = ft_strdup(new->input);
	new->nbr_param = count_params(input);
	new->params = str_array_new();
	new->r = 0;
	init_params(str, &new->params);
	ft_strdel(&str);
	get_mod(new);
	while (++i < 256)
	{
		new->hh[i] = useless;
		new->h[i] = useless;
		new->fct[i] = useless;
		new->l[i] = useless;
		new->z[i] = useless;
		new->j[i] = useless;
	}
	new->hh['s'] = print_ls;
	new->hh['S'] = print_ls;
	new->hh['c'] = print_lc;
	new->hh['C'] = print_lc;
	new->hh['d'] = print_hhd;
	new->hh['D'] = print_hu;
	new->hh['i'] = print_hhd;
	new->hh['o'] = print_hho;
	new->hh['O'] = print_ho;
	new->hh['x'] = print_hhx;
	new->hh['X'] = print_hhx;
	new->hh['u'] = print_hhu;
	new->hh['U'] = print_hu;
	new->h['d'] = print_hd;
	new->h['D'] = print_hud;
	new->h['i'] = print_hd;
	new->h['I'] = print_hd;
	new->h['o'] = print_ho;
	new->h['O'] = print_ho;
	new->h['x'] = print_hx;
	new->h['X'] = print_hx;
	new->h['u'] = print_hu;
	new->h['U'] = print_huu;
	new->j['d'] = print_jd;
	new->j['D'] = print_jd;
	new->j['i'] = print_jd;
	new->j['x'] = print_jx;
	new->j['X'] = print_jx;
	new->j['u'] = print_ju;
	new->j['U'] = print_ju;
	new->j['o'] = print_jo;
	new->j['O'] = print_jo;
	new->l['d'] = print_ld;
	new->l['D'] = print_ld;
	new->l['i'] = print_ld;
	new->l['I'] = print_ld;
	new->l['c'] = print_lc;
	new->l['C'] = print_lc;
	new->l['s'] = print_ls;
	new->l['S'] = print_ls;
	new->l['o'] = print_lo;
	new->l['O'] = print_lo;
	new->l['x'] = print_lx;
	new->l['X'] = print_lx;
	new->l['u'] = print_lu;
	new->l['U'] = print_lu;
	new->l['p'] = print_p;
	new->l['P'] = print_p;
	new->fct['D'] = print_ld;
	new->fct['I'] = print_ld;
	new->fct['C'] = print_lc;
	new->fct['S'] = print_ls;
	new->fct['O'] = print_lo;
	new->fct['U'] = print_lu;
	new->fct['c'] = print_c;
	new->fct['s'] = print_s;
	new->fct['d'] = print_d;
	new->fct['i'] = print_d;
	new->fct['o'] = print_o;
	new->fct['p'] = print_p;
	new->fct['P'] = print_p;
	new->fct['x'] = print_x;
	new->fct['X'] = print_x;
	new->fct['u'] = print_u;
	new->z['d'] = print_zi;
	new->z['D'] = print_zi;
	new->z['i'] = print_zi;
	new->z['u'] = print_zu;
	new->z['U'] = print_zu;
	new->z['o'] = print_zo;
	new->z['O'] = print_zo;
	new->z['x'] = print_zx;
	new->z['X'] = print_zx;

	new->fct['%'] = print_percent;
	return (new);
}
