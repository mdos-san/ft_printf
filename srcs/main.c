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
	if (type == 6)
		ft_printf(s, *(long*)param);
	if (type == 7)
		ft_printf(s, (unsigned long int*)param);
	if (type == 8)
		ft_printf(s, *(unsigned int*)param);
	if (type == 9)
		ft_printf(s, *(unsigned long int*)param);
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
	if (type == 6)
		printf(s, *(long*)param);
	if (type == 7)
		printf(s, (unsigned long int*)param);
	if (type == 8)
		printf(s, *(unsigned int*)param);
	if (type == 9)
		printf(s, *(unsigned long int*)param);
	fflush(stdout);
	ft_putendl("\n===================\n\n");
}

int		main()
{
	int i;
	unsigned long l;
	unsigned int u;
	unsigned long ul;
	char  c;
	wchar_t w;

	i = 945;
	w = L'\x03b1';
	test("", NULL, 0);
	test("Basic output", NULL, 0);
	c = 'a';
	test("char test: |%-+10.5c|", (void*)&c, 1);
	i = 65539;
	test("wchar test: |%-+10.5lc|", (void*)&i, 2);
	test("wchar test: |%-+10.5C|", (void*)&i, 2);
	test("s test: |%-+10.5s|", (void*)"Hello World!", 3);
	test("S test: |%-+10.5S|", (void*)L"我是一只猫。", 4);
	i = 42;
	test("d test: |%-+10.5ld|", (void*)&i, 5);
	i = -42;
	test("d test: |%-+10.5d|", (void*)&i, 5);
	l = 9223372036854775807;
	test("D test: |%-+42.21lld|", (void*)&l, 6);
	l = 9223372036854775807;
	test("D test: |%-+42.21D|", (void*)&l, 6);
	i = 42;
	test("d test: |%-+10.5li|", (void*)&i, 5);
	i = -42;
	test("d test: |%-+10.5i|", (void*)&i, 5);
	l = 9223372036854775807;
	test("D test: |%-+42.21lli|", (void*)&l, 6);
	l = 9223372036854775807;
	test("D test: |%-+42.21li|", (void*)&l, 6);
	test("p test: |%-+42.20p|", (void*)&l, 7);
	test("p test: |%-+42.20p|", (void*)&l, 7);
	u = 4294967295;
	ul = 9223372036854775807;
	test("o test: |%-+42.20o|", (void*)&u, 8);
	test("O test: |%-+42.42O|", (void*)&ul, 9);
	test("x test: |%-+42.20x|", (void*)&u, 8);
	test("lx test: |%-+42.20lx|", (void*)&ul, 9);
	test("X test: |%-+42.20X|", (void*)&ul, 9);
	ft_putnbrl(sizeof(long long));
	ft_putnbrl(sizeof(long int));
	ft_putnbrl(sizeof(long));
	ft_putnbrl(sizeof(int));
	ft_putnbrl(sizeof(short int));
	ft_putnbrl(sizeof(signed char));
	ft_putnbrl(sizeof(unsigned long));
	ft_printf("%s%s%s%s%s", "this", "is", "a", "multi", "string");
	printf("%s%s%s%s%s", "this", "is", "a", "multi", "string");
	return (0);
}
