#include "libftprintf.h"
#include "stdio.h"
#include <locale.h>
#include <wchar.h>
#include "unistd.h"

static void	test(char *s, void *param, char type)
{
	setlocale(LC_ALL, "");
	ft_putendl("#######################");
	ft_putstr("TEST with '");
	ft_putstr(s);
	ft_putendl("'");
	ft_putendl("=====FT_PRINTF=====");
	if (type == 0)
		ft_printf(s);
	if (type == 1)
		ft_printf(s, *(char*)param);
	if (type == 2)
		ft_printf(s, *(int*)param);
	if (type == 3)
		ft_printf(s, (char*)param);
	if (type == 4)
		ft_printf(s, *(int*)param);
	ft_putendl("\n=======PRINTF======");
	if (type == 0)
		printf((char *)s);
	if (type == 1)
		printf(s, *(char*)param);
	if (type == 2)
		printf(s, *(int*)param);
	if (type == 3)
		printf(s, (char*)param);
	if (type == 4)
		printf(s, *(int*)param);
	fflush(stdout);
	ft_putendl("\n===================\n\n");
}


int		main()
{
	int i;
	char  c;
	wchar_t w;

	w = L'\x03b1';
	test("", NULL, 0);
	test("Basic output", NULL, 0);
	c = 'a';
	test("char test: %c", (void*)&c, 1);
	i = 65599;
	test("wchar test: %C", (void*)&i, 2);
	i = -42;
	test("s test: %s", (void*)"coucou", 3);
	test("d test: %d", (void*)&i, 4);
	return (0);
}
