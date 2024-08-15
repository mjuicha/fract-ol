CC = cc

CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

HEADER = so_long.h

SRC = check_file.c   errors.c   map_check_list.c      move.c check_element.c \
data_info.c gaaaaaa.c  get_next_line.c       get_next_line_utils.c map_check.c    so_long.c  utils.c \
	
OBJ = $(SRC:.c=.o)

NAME = so_long

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re