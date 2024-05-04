NAME = so_long
SRCS = srcs/allocation/allocation_mat.c srcs/allocation/creation.c  srcs/get_next_line/get_next_line.c srcs/mylib/mylib_utile1.c \
       srcs/mylib/mylibft_utile2.c srcs/mylib/mylibft_utile3.c  srcs/parsing/flood_fill.c\
		srcs/parsing/parsing.c srcs/parsing/read_file.c srcs/allocation/initialization.c srcs/mylib/mylib_utile4.c \
	   srcs/main.c  srcs/free/ft_free.c  srcs/free/ft_exit.c srcs/parsing/valide.c\
		algo_mlx/mlx_general.c algo_mlx/draw_window.c  algo_mlx/point_to_imags.c algo_mlx/enemy.c algo_mlx/hook_mlx.c

OBJS = $(SRCS:.c=.o)
CFLAGS 	=   -Wall -Wextra -Werror
RM 		= @rm -f
all : $(NAME)

$(NAME):$(OBJS)
	$(CC) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS)
%.o : %.c includes/get_next_line.h includes/headers.h includes/structs.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
fclean : clean
	$(RM) $(NAME)
re:fclean all

.PHONY: clean