NAME = fil_di_ferro

COMPILE = gcc #-Wall -Wextra -Werror

MLX = -Iminilibx-linux -Lminilibx-linux

MLXX = -lmlx -lXext -lX11 ./minilibx-linux/libmlx.a -lm

SRCS = main.c init_remove.c check_config.c utils.c take_line.c draw.c\
		lst.c split_line.c render_image.c vector.c press_key_linux.c render_utils.c

all: $(NAME)

$(NAME): fil_di_ferro.h utils.h vector.h $(SRCS)
	cd minilibx-linux && make
	$(LINK) $(OBJS) -o $(NAME)
	$(COMPILE) $(MLX) $(SRCS) $(MLXX) -o $(NAME)

clean:
	echo "Done"

fclean: clean
	cd minilibx-linux && make clean
	rm -f $(NAME)

re: fclean all
