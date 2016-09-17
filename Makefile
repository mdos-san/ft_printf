NAME		=	libftprintf.a

TMP_C		=\
				ft_printf.c
SRC_C		=	$(TMP_C:%=srcs/%)
SRC_O		=	$(TMP_C:.c=.o)


all:
	gcc -c $(SRC_C) -I./includes
	ar -rc $(NAME) $(SRC_O)

clean:
	rm -rf $(SRC_O)

fclean: clean
	rm -rf $(NAME)

re: fclean all
