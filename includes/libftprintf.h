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
	void		(*fct[256])(void *arg, int precision);
	int			precision;
	char		c;
	char		*tmp;
}				t_ftpf;	

int		ft_printf(char *str, ...);
t_ftpf	*ftpf_init(char *input);
void	ftpf_del(t_ftpf **addr);
void	ft_putwchar(int c);
void	ft_putwstr(int *wstr);
void	ft_putptn(unsigned long int pnt);
char	ft_str_last_char(char *s);
void	useless(void *param, int precision);
void	print_c(void *c, int precision);
void	print_lc(void *c, int precision);
void	print_s(void *s, int precision);
void	print_ls(void *s, int precision);
void	print_d(void *i, int precision);

#endif
