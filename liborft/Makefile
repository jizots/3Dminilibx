NAME	=	liborft.a
CC 		=	cc
CFLAGS	=	-Wall -Wextra -Werror
SCRS	=	get_next_line.c	get_next_line_utils.c ft_strlen.c\
	ft_atoi.c ft_split_multichar.c ft_strlcpy.c ft_atoi_base.c\
	ft_count_word.c ft_strchr.c get_first_line.c ft_atoi_base_util.c\
	ft_memset.c ft_bzero.c\

OBJS	=	$(SCRS:%.c=%.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $@ $^

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all