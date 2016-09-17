NAME		=	libftprintf.a

TMP_C		=\
				ft_printf.c
SRC_C		=	$(TMP_C:%=srcs/%)
SRC_O		=	$(TMP_C:.c=.o)

all: libftprintf.a 

libftprintf.a: includes/libft.h libft.a
	gcc -c $(SRC_C) -I./includes
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
