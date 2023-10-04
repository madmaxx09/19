NAME = push_swap

SRCS = ./src/main.c\
		./src/algo.c\
		./src/argscheck.c\
		./src/listops.c\
		./src/operations.c\
		./src/radix.c\
		./src/sort.c\
		./src/utils.c
	
	
OBJS = ${SRCS:.c=.o}

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

GCC = gcc

%.o : %.c
	@${GCC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	@${GCC} $(CFLAGS) $(OBJS) -o ${NAME}

all:	${NAME}

clean:
	@${RM} ${OBJS}

fclean : clean
	@${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re