#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

typedef struct	s_ftpf
{
	char		*input;
	int			nbr_param;
	char		*param;
}				t_ftpf;	

int		ft_printf(char *str, ...);
t_ftpf	*ftpf_init(char *input);
void	ftpf_del(t_ftpf **addr);

#endif
