NAME =	pipex

CC =	gcc
CFLAGS =	-g -Wall -Wextra -Werror -MMD
RM =	rm -rf

SRC =   check.c	\
		pipex.c	\
		utils.c	\
		main.c	\


INC = 	-I libft/libft.h 	\
		-I pipex.h	\

OBJS =	$(SRC:.c=.o)
DEP =	$(SRC:.c=.d)

OBJS_B =	$(SRC_B:.c=.o)
DEP_B =		$(SRC_B:.c=.d)

LD_FLAGS =	-L libft

.PHONY :	all clean re fclean

.c.o :		
		${CC} ${CFLAGS} ${INC} -c $< -o ${<:.c=.o}


$(NAME):	$(OBJS)
			make -C ./libft/
			${CC} ${CFLAGS} ${LD_FLAGS} ${OBJS} ./libft/libft.a -o ${NAME}


all: 		$(NAME)

clean:
			$(RM) $(OBJS) $(DEP) $(OBJS_B) $(DEP_B)
			make clean -C libft/

fclean: 	clean
			$(RM) $(NAME)
			make fclean -C libft/

re: 		fclean all

-include $(DEP)
-include $(DEP_B)