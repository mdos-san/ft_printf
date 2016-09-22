#include "libftprintf.h"

static int	*int_arr_dup(int *arr)
{
	int	i;
	int	nbr;
	int	*ret;

	i = 0;
	nbr = 0;
	while (arr[nbr])
		++nbr;
	ret = (int*)malloc(sizeof(int) * (nbr + 1));
	ret[nbr] = 0;
	while (arr[i])
	{
		ret[i] = arr[i];
		++i;
	}
	return (ret);
}

static int	int_arr_len(int *arr)
{
	int	i;

	i = 0;
	while (arr[i])
		++i;
	return (i);
}

void	print_ls(void *s, t_flag flag, int *r)
{
	int		tmp;
	int		*arr;
	int		nb;
	int		i;

	i = 0;
	nb = 0;
	arr = int_arr_dup((int*)s);
	if (flag.precision > 0)
	{
		tmp = arr[flag.precision / 3];
		arr[flag.precision / 3] = 0;
	}
	nb = (flag.width > flag.precision) ? flag.width - int_arr_len(arr) * 3 : 0;
	(flag.flag['-'] == 0) ? print_width(nb, r) : 0;
	ft_putwstr(arr);
	*r += int_arr_len(arr);
	(flag.flag['-'] == 1) ? print_width(nb, r) : 0;
	(flag.precision > 0) ? (arr[flag.precision / 3] = tmp) : 0;
	(arr) ? free(arr) : 0;
}
