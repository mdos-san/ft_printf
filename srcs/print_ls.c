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

void	print_ls(void *s, t_flag flag)
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
	if (flag.width > flag.precision)
	{
		nb = flag.width - int_arr_len(arr) * 3;	
		while (i < nb)
		{
			ft_putchar(' ');
			++i;
		}
	}
	ft_putwstr(arr);
	if (flag.precision > 0)
		arr[flag.precision / 3] = tmp;
	(arr) ? free(arr) : 0;
}
