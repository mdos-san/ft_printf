#include "libftprintf.h"
#include "stdio.h"
#include "unistd.h"

static void	test(char *s, void *param, char type)
{
	ft_putendl("#######################");
	ft_putstr("TEST with '");
	ft_putstr(s);
	ft_putendl("'");
	ft_putendl("=====FT_PRINTF=====");
	if (type == 0)
		ft_printf(s);
	if (type == 1)
		ft_printf(s, (char*)param);
	ft_putendl("\n=======PRINTF======");
	if (type == 0)
		printf(s);
	if (type == 1)
		printf(s, (char*)param);
	fflush(stdout);
	ft_putendl("\n===================\n\n");
}


int		main()
{
	test("", NULL, 0);
	test("Basic output", NULL, 0);
	test("s test: %s", (void*)"coucou", 1);
	return (0);
}
