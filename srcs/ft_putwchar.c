#include "libftprintf.h"
#define MASK_1 0 
#define MASK_2 49280
#define MASK_3 14712960
#define MASK_4 4034953344


static	char *print_bit(int c)
{
	int		i;
	char	buf[33];

	i = 0;
	ft_bzero(buf, 32);
	buf[32] = '\0';
	while (i < 32)
	{
		buf[31 - i] = (c % 2 == 1) ? '1' : '0';
		c = c / 2;
		++i;
	}
//	ft_putendl("====PRINT_BIT====");
//	write(1, buf, 8);
//	ft_putchar(' ');
//	write(1, buf + 8, 8);
//	ft_putchar(' ');
//	write(1, buf + 16, 8);
//	ft_putchar(' ');
//	write(1, buf + 24, 8);
//	ft_putchar('\n');
	return (ft_strdup(buf));
}

static void	mask_init(char *m, char nbr)
{
	int i;

	i = 0;
	if (nbr == 2)
	{
		while (i < 6)
		{
			m[31 - i] = '#';
			++i;
		}
		i += 2;
		while (i < 13)
		{
			m[31 - i] = '#';
			++i;
		}
	}
}

static void	mask_fill(char *m, char *n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 32)
	{
		if (m[31 - i] == '#')
		{
			m[31 - i] = n[31 - j];
			++j;
		}
		++i;
	}
}

static int bin_to_int(char *bin)
{
	int	i;
	int ret;
	double pow;

	i = 0;
	ret = 0;
	pow = 1;
	while (i < 32)
	{
		if (bin[31 - i] == '1')
			ret += pow;
		pow *= 2;
		++i;
	}
	return (ret);
}

void	ft_putwchar(int c)
{
	char	*mask;
	char	*nbr;
	int		result;

	mask = print_bit(MASK_2);
	nbr = print_bit(c);
	mask_init(mask, 2);
	mask_fill(mask, nbr);
	result = bin_to_int(mask);
	free(nbr);
	nbr = (char*)&result;
	write(1, nbr + 3, 1);
	write(1, nbr + 2, 1);
	write(1, nbr + 1, 1);
	write(1, nbr + 0, 1);
}
