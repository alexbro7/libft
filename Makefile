# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llefranc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/15 23:22:56 by llefranc          #+#    #+#              #
#    Updated: 2019/11/20 17:51:04 by alebross         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
FLAGS		=	-Wall -Wextra -Werror
SRCS		=	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_isalpha.c \
		ft_isalnum.c \
		ft_isdigit.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_strdup.c \
		ft_calloc.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \

BNS			=	ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c\
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c \

OBJS		=	$(SRCS:.c=.o)
BNSOBJS		=	$(BNS:.c=.o)
PATHINC		=	./

all		: $(NAME)

$(NAME)	:	$(OBJS)
			gcc -c $(FLAGS) $(SRCS) -I $(PATHINC)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

bonus	:	$(BNSOBJS)
			gcc -c $(FLAGS) $(BNS) -I $(PATHINC)
			ar rc $(NAME) $(BNSOBJS)
			ranlib $(NAME)
%.o: %.c
	gcc $(FLAGS) $< -c -o $@

clean	:
			rm -f $(OBJS) $(BNSOBJS)

fclean	:	clean
			rm -f $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
