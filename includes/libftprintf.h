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
	char		uppercase;
	char		p_given;
}				t_flag;

typedef struct	s_ftpf
{
	char		*input;
	int			nbr_param;
	char		**params;
	void		(*fct[256])(void *arg, t_flag flag, int *ret);
	void		(*h[256])(void *arg, t_flag flag, int *ret);
	void		(*hh[256])(void *arg, t_flag flag, int *ret);
	void		(*j[256])(void *arg, t_flag flag, int *ret);
	void		(*z[256])(void *arg, t_flag flag, int *ret);
	unsigned char	c;
	char		*tmp;
	t_flag		flag;
	int			r;
}				t_ftpf;	

int		ft_printf(char *str, ...);
t_ftpf	*ftpf_init(char *input);
void	ftpf_del(t_ftpf **addr);
void	ft_putwchar(int c);
void	ft_putwstr(int *wstr);
void	ft_putptn(unsigned long int pnt);
char	ft_str_last_char(char *s);
void	useless(void *param, t_flag flag, int *ret);
void	print_c(void *c, t_flag flag, int *ret);
void	print_lc(void *c, t_flag flag, int *ret);
void	print_s(void *s, t_flag flag, int *ret);
void	print_ls(void *s, t_flag flag, int *ret);
void	print_hhd(void *arg, t_flag flag, int *ret);
void	print_hd(void *arg, t_flag flag, int *ret);
void	print_d(void *i, t_flag flag, int *ret);
void	print_jd(void *i, t_flag flag, int *ret);
void	print_ld(void *arg, t_flag flag, int *ret);
void	print_p(void *p, t_flag flag, int *ret);
void	print_o(void *o, t_flag flag, int *ret);
void	print_lo(void *o, t_flag flag, int *ret);
void	print_hhx(void *arg, t_flag flag, int *ret);
void	print_hx(void *arg, t_flag flag, int *ret);
void	print_x(void *arg, t_flag flag, int *ret);
void	print_lx(void *arg, t_flag flag, int *ret);
void	print_jx(void *arg, t_flag flag, int *ret);
void	print_u(void *ui, t_flag flag, int *r);
void	print_lu(void *ui, t_flag flag, int *r);
void	print_ju(void *ui, t_flag flag, int *r);
void	print_percent(void *arg, t_flag flag, int *ret);
void	print_width(int nbr, int *ret);
void	print_width_z(int nb, int *r);


#endif
