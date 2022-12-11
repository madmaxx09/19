# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 18:35:29 by mdor              #+#    #+#              #
#    Updated: 2022/12/11 12:17:10 by mdor             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memmove.c ft_memset.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c 

OBJS = ${SRCS:.c=.o}


.c.o: gcc -Wall -Wextra -Werror -c -l./includes  $< -o ${<:.c=.o}

${NAME}: ${OBJS} ar rc ${NAME} ${OBJS}

all: ${NAME}

clean: rm -f ${OBJS}

fclean: clean rm -f ${NAME}

re: fclean all 