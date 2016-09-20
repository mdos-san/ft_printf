#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_flag
{
	int			precision;
	int			width;
	char		flag[256];
	char		*mod;
}				t_flag;

typedef struct	s_ftpf
{
	char		*input;
	int			nbr_param;
	char		**params;
	void		(*fct[256])(void *arg, t_flag flag);
	char		c;
	char		*tmp;
	t_flag		flag;
}				t_ftpf;	

int		ft_printf(char *str, ...);
t_ftpf	*ftpf_init(char *input);
void	ftpf_del(t_ftpf **addr);
void	ft_putwchar(int c);
void	ft_putwstr(int *wstr);
void	ft_putptn(unsigned long int pnt);
char	ft_str_last_char(char *s);
void	useless(void *param, t_flag flag);
void	print_c(void *c, t_flag flag);
void	print_lc(void *c, t_flag flag);
void	print_s(void *s, t_flag flag);
void	print_ls(void *s, t_flag flag);
void	print_d(void *i, t_flag flag);
void	print_ld(void *arg, t_flag flag);
void	print_p(void *p, t_flag flag);
void	print_o(void *o, t_flag flag);
void	print_lo(void *o, t_flag flag);
void	print_x(void *arg, t_flag flag);


#endif
