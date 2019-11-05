DOSS	=	./srcs/

SRCS	=	${DOSS}ft_putchar.c ${DOSS}ft_swap.c ${DOSS}ft_putstr.c ${DOSS}ft_strlen.c ${DOSS}ft_strcmp.c

OBJS	=	${SRCS:.c=.o}

CFLAGS	=	-Wall -Wextra -Werror

CC		=	gcc

RM		=	rm -f

NAME	=	libft.a

PATH	=	./includes

HEADER	=	${PATH}

.c.o	:
			${CC} ${CFLAGS} -I ${HEADER} -c $< -o ${<:.c=.o}


all		:	${NAME}

clean	:
			${RM} ${OBJS}

fclean	:	clean
			${RM} ${NAME}

${NAME} :	${OBJS}
			ar rc ${NAME} ${OBJS}

re		:	fclean all

.PHONY	:	all clean fclean re libft.a
