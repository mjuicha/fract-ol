CC = cc

CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

HEADER = so_long.h

SRC = so_long.c move.c get_next_line.c get_next_line_utils.c check_map.c game_map.c \
	
OBJ = $(SRC:.c=.o)

NAME = so_long

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(MLXFLAGS) -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re