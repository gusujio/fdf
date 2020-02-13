NAME = fdf

SRC = draw.c			draw2.c		draw3.c		main.c\
	  read_file.c        read_file2.c\

OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME):
	@make -C ./libft re
	@gcc -o $(NAME) -Wall -Wextra -Werror $(SRC) -L ./libft -lft minilibx_macos/libmlx.a -framework OpenGL -framework AppKit

clean:
	@make -C ./libft fclean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C ./libft fclean
	@/bin/rm -f $(NAME)

re: fclean all






