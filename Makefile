NAME		=	libftprintf.a

TMP_C		=\
				ft_printf.c\
				ftpf_init.c\
				ftpf_del.c\
				ft_putwchar.c\
				ft_putwstr.c\
				ft_putptn.c\
				ft_str_last_char.c\
				useless.c\
				print_c.c\
				print_lc.c\
				print_s.c\
				print_ls.c\
				print_d.c\
				print_ld.c\
				print_p.c
SRC_C		=	$(TMP_C:%=srcs/%)
SRC_O		=	$(TMP_C:.c=.o)

FLAG		=	-Wall -Wextra -Werror

all: libftprintf.a 

libftprintf.a: includes/libft.h libft.a
	gcc -c $(SRC_C) -I./includes $(FLAG)
	ar -rc $(NAME) $(SRC_O)

includes/libft.h:
	cp libft/includes/libft.h includes

libft.a:
	make -C libft
	cp libft/libft.a .
	make fclean -C libft

clean:
	rm -rf $(SRC_O)

fclean: clean
	rm -rf $(NAME) libft.a

re: fclean all

test: all
	gcc -I./includes -o test srcs/main.c libftprintf.a libft.a 

retest: fclean all test
