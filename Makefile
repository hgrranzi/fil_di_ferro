NAME = fil_di_ferro

COMPILE = gcc -c

LINK = gcc -Wall -Wextra -Werror

MLX = -I mlx -L mlx -lmlx -framework OpenGL -framework AppKit

SRCS = main.c init_remove.c check_config.c utils.c

OBJS =	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): fil_di_ferro.h utils.h $(OBJS)
	cd mlx && make
	$(LINK) $(MLX) $(OBJS) mlx/libmlx.a -o $(NAME)

%.o: %.c fil_di_ferro.h utils.h
	$(COMPILE) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	cd mlx && make clean

re: fclean all