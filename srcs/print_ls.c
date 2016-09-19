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

void	print_ls(void *s, int precision)
{
	int		tmp;
	int		*arr;

	arr = int_arr_dup((int*)s);
	if (precision > 0)
	{
		tmp = arr[precision / 3];
		arr[precision / 3] = 0;
	}
	ft_putwstr(arr);
	if (precision > 0)
		arr[precision / 3] = tmp;
	(arr) ? free(arr) : 0;
}
