#include "libftprintf.h"

static int count_params(char *s)
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

static void init_params(char *s, char ***arr)
{
	int	i1;
	int	i2;
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
			tmp = s[++i2];
			s[i2] = '\0';
			str_array_add(arr, s + i1);
			s[i2] = tmp;
			i1 = i2 - 1;
		}
		++i1;
	}
	str_array_add(arr, s + i2 + 1);
}

static void get_mod(t_ftpf *ftpf)
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

t_ftpf	*ftpf_init(char *input)
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
		new->z[i] = useless;
		new->j[i] = useless;
	}
	new->fct['c'] = print_c;
	new->fct['C'] = print_lc;
	new->fct['s'] = print_s;
	new->fct['S'] = print_ls;
	new->fct['d'] = print_d;
	new->fct['D'] = print_ld;
	new->z['d'] = print_lu;
	new->j['d'] = print_jd;
	new->h['d'] = print_hd;
	new->hh['d'] = print_hhd;
	new->z['i'] = print_zi;
	new->fct['i'] = print_d;
	new->fct['I'] = print_ld;
	new->h['o'] = print_ho;
	new->hh['o'] = print_hho;
	new->fct['o'] = print_o;
	new->fct['O'] = print_lo;
	new->fct['p'] = print_p;
	new->fct['P'] = print_p;
	new->hh['X'] = print_hhx;
	new->h['x'] = print_hx;
	new->fct['x'] = print_x;
	new->fct['X'] = print_x;
	new->j['x'] = print_jx;
	new->fct['Y'] = print_lx;
	new->h['u'] = print_hu;
	new->h['U'] = print_hu;
	new->fct['u'] = print_u;
	new->j['u'] = print_ju;
	new->hh['u'] = print_hhu;
	new->fct['U'] = print_lu;
	new->fct['%'] = print_percent;
	return (new);
}
