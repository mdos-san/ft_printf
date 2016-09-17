#include "libftprintf.h"
#include "stdio.h"
#include "unistd.h"

static	test(char *s)
{
	ft_putendl("#######################");
	ft_putstr("TEST with '");
	ft_putstr(s);
	ft_putendl("'");
	ft_putendl("=====FT_PRINTF=====");
	ft_printf(s);
	ft_putendl("\n=======PRINTF======");
	printf(s);
	fflush(stdout);
	ft_putendl("\n===================\n\n");
}


int		main(int ac, char **av)
{
	test("toto");
	test("tata");
	return (0);
}
