# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/25 14:54:15 by ooliinyk          #+#    #+#              #
#    Updated: 2019/07/01 20:00:14 by ooliinyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_strlen.c ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c ft_isalnum.c ft_isdigit.c \
	   ft_isalpha.c ft_strcmp.c ft_strncmp.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
		ft_strncat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_atoi.c ft_strlcat.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
		ft_putchar.c ft_putstr.c ft_putendl.c ft_strclr.c ft_strequ.c ft_strnequ.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_striter.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c \
		ft_striteri.c ft_strmap.c ft_strmapi.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
		ft_putnbr.c ft_putnbr_fd.c ft_itoa.c ft_lstadd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
		ft_lstiter.c ft_lstmap.c ft_wrdcnt.c ft_strndup.c ft_isspace.c ft_swap.c ft_isupper.c \
		ft_islower.c ft_sqrt.c
SRCO = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror -I. -c

all : $(NAME)

$(NAME): $(SRCO)
	@ar rc $(NAME) $(SRCO)
$(SRCO): $(SRCS)
	@gcc $(FLAGS) $(SRCS)
clean:
	@rm -f $(SRCO)
fclean: clean
	@rm -f $(NAME)
re: fclean all
