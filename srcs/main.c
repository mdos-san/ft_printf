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
		ft_printf(s, (int*)param);
	if (type == 5)
		ft_printf(s, *(int*)param);
	if (type == 7)
		ft_printf(s, (unsigned long int*)param);
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
		printf(s, (int*)param);
	if (type == 5)
		printf(s, *(int*)param);
	if (type == 7)
		printf(s, (unsigned long int*)param);
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
	test("char test: |%.5c|", (void*)&c, 1);
	i = 65599;
	test("wchar test: |%10.5C|", (void*)&i, 2);
	test("s test: |%14.9s|", (void*)"Hello World!", 3);
	test("S test: |%14.9S|", (void*)L"我是一只猫。", 4);
	i = 42;
	test("d test: |%10.5d|", (void*)&i, 5);
	i = -42;
	test("d test: |%10.5d|", (void*)&i, 5);
	test("p test: |%.24p|", (void*)&i, 7);
	return (0);
}
