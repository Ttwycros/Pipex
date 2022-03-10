# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 19:58:17 by ttwycros          #+#    #+#              #
#    Updated: 2021/10/21 13:40:07 by ttwycros         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIST =	ft_atoi.c			ft_isalnum.c		ft_isdigit.c\
		ft_bzero.c			ft_isalpha.c		ft_isprint.c\
		ft_calloc.c			ft_isascii.c		ft_memchr.c\
		ft_memcmp.c			ft_memcpy.c			ft_memcpy.c\
		ft_memmove.c		ft_memset.c			ft_strchr.c\
		ft_strdup.c			ft_strlcat.c		ft_strlcpy.c\
		ft_strlen.c			ft_strncmp.c		ft_strnstr.c\
		ft_strrchr.c		ft_tolower.c		ft_toupper.c\
		ft_itoa.c			ft_putchar_fd.c		ft_putstr_fd.c\
		ft_putendl_fd.c		ft_putnbr_fd.c		ft_strjoin.c\
		ft_substr.c			ft_strmapi.c		ft_strtrim.c\
		ft_split.c			ft_striteri.c


BONUS_LIST =	ft_lstnew.c		ft_lstadd_front.c		ft_lstsize.c\
				ft_lstlast.c	ft_lstadd_back.c

HEADER = libft.h

COMPILER = gcc

FLAGS = -Wall -Wextra -Werror -I$(HEADER)

OBJS = $(patsubst %.c,%.o,$(LIST))

OBJS_BONUS = $(patsubst %.c,%.o,$(BONUS_LIST))

.PHONY : all clean fclean re bonus

all: $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	ar rcs $(NAME) $?
%.o : %.c $(HEADER)
	$(COMPILER) $(FLAGS) -c $< -o $@
bonus :
	@make OBJS="$(OBJS_BONUS) $(OBJS)" all
norm : 
	norminette
clean :
	rm -f $(OBJS) $(OBJS_BONUS)
fclean : clean
	rm -f $(NAME)
re : fclean all
