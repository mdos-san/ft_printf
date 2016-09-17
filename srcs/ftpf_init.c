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

static void init_params(char *s, char *tab)
{
	int	i;
	int	j;
	char find;
	
	i = 0;
	j = 0;
	find = 0;
	while (s[i])
	{
		if (s[i] == '%' && find == 0)
			++find;
		else if (find == 1 && ft_isalpha(s[i]) && (s[i + 1] == ' ' || s[i + 1] == '\0'))
		{
			tab[j] = s[i];
			++j;
		}
		else if (find == 1 && (s[i] == ' ' || s[i] == '%'))
			find = 0;
		++i;
	}
}

t_ftpf	*ftpf_init(char *input)
{
	t_ftpf	*new;
	new = (t_ftpf*)malloc(sizeof(t_ftpf));
	if (!new)
		return (NULL);
	new->input = ft_strdup(input);
	new->nbr_param = count_params(input);
	new->param = (char *)malloc(new->nbr_param);
	init_params(input, new->param);
	return (new);
}
