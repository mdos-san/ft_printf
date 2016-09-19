#include "libftprintf.h"

static int count_params(char *s)
{
	int	i;
	int	nbr;
	
	i = 0;
	nbr = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != '%')
			++nbr;
		++i;
	}
	return (nbr);
}

static int	is_flag(char c)
{
	if (
			c == 'c' ||
			c == 'C' ||
			c == 's' ||
			c == 'S' ||
			c == 'd' ||
			c == 'p'
			)
			return (1);
	return (0);
}

static void init_params(char *s, char ***arr)
{
	int	i1;
	int	i2;

	i1 = 0;
	i2 = 0;
	while (s[i1])
	{
		if (s[i1] == '%')
		{
			i2 = i1;
			while (!is_flag(s[i2]))
			{
				++i2;
			}
			s[++i2] = '\0';
			str_array_add(arr, s + i1);
			i1 = i2;
		}
		++i1;
	}
	str_array_add(arr, s + i2 + 1);
	int i;

	i = 0;
	ft_putendl("==========params==============");
	while ((*arr)[i])
	{
		ft_putstr("param ");
		ft_putnbr(i);
		ft_putstr(":");
		ft_putendl((*arr)[i]);
		++i;
	}
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
	init_params(str, &new->params);
	ft_strdel(&str);
	while (++i < 256)
		new->fct[i] = useless;
	new->fct['c'] = print_c;
	new->fct['C'] = ft_putwchar;
	new->fct['s'] = print_s;
	new->fct['S'] = ft_putwstr;
	return (new);
}
