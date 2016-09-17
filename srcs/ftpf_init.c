#include "libftprintf.h"

t_ftpf	*ftpf_init(char *input)
{
	t_ftpf	*new;
	new = (t_ftpf*)malloc(sizeof(t_ftpf));
	if (!new)
		return (NULL);
	new->input = ft_strdup(input);
	return (new);
}
