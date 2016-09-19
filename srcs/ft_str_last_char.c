#include "libftprintf.h"

char	ft_str_last_char(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	return (s[i - 1]);
}
