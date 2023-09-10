NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I ./inc
CFLAGS += -I/path/to/minilibx_macos -I/path/to/liborft
COPTIONS = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
SRCS = main.c\
	ft_get_map.c\
	ft_get_map2.c\
	ft_print_error.c\
	ft_free_allocate.c\
	ft_map_initi_locate.c\
	ft_map_relocate.c\
	ft_length_utils.c\
	ft_mlx_func.c\
	ft_mlx_inside_win.c\
	ft_puts_dot.c\
	ft_color_get.c\
	ft_color_gradation.c\

SRCS_DIR = src/
OBJS_DIR = objs/

OBJS = ${addprefix ${OBJS_DIR}, ${SRCS:%.c=%.o}}

LIBORFT_DIR = liborft
LIBORFT_MAKEFILE = $(LIBORFT_DIR)/Makefile
LIBORFT_STATIC = $(LIBORFT_DIR)/liborft.a

MLX_DIR = minilibx_macos
MLX_MAKEFILE = $(MLX_DIR)/Makefile
MLX_STATIC = $(MLX_DIR)/libmlx.a

.PHONY: all bonus clean fclean re

all: ${OBJS_DIR} ${NAME}

${OBJS_DIR}:
	mkdir -p ${OBJS_DIR}

${OBJS_DIR}%.o: ${SRCS_DIR}%.c | ${OBJS_DIR}
	${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJS) $(LIBORFT_STATIC) $(MLX_STATIC)
	$(CC) $(CFLAGS1) $(CFLAGS2) -o $(NAME) $(OBJS) -L$(LIBORFT_DIR) -lorft -L$(MLX_DIR) -lmlx $(COPTIONS)

$(LIBORFT_STATIC):
	$(MAKE) -C $(LIBORFT_DIR)

$(MLX_STATIC):
	$(MAKE) -C $(MLX_DIR)

bonus:
	${MAKE} WITH_BONUS=1 all

clean:
	$(MAKE) -C $(LIBORFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS)
	rmdir ${OBJS_DIR} 2>/dev/null || true

fclean: clean
	$(MAKE) -C $(LIBORFT_DIR) fclean
	rm -f $(NAME)

re: fclean all
