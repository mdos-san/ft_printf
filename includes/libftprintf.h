#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_ftpf
{
	char		*input;
	int			nbr_param;
	char		**params;
	void		(*fct[256])(void *arg);
	char		c;
}				t_ftpf;	

int		ft_printf(char *str, ...);
t_ftpf	*ftpf_init(char *input);
void	ftpf_del(t_ftpf **addr);
void	ft_putwchar(void *c);
void	ft_putwstr(void *wstr);
void	ft_putptn(unsigned long int pnt);
char	ft_str_last_char(char *s);
void	useless(void *param);
void	print_c(void *c);
void	print_s(void *s);

#endif
