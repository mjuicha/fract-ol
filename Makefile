PRINTF = ft_printf/libftprintf.a
HEADERPRINTF = ft_printf/ft_printf.h

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

all: $(PRINTF) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(PRINTF) $(OBJ) $(MLXFLAGS) -o $@

$(PRINTF): $(HEADERPRINTF) ft_printf/*.c
	@$(MAKE) -C ft_printf

clean:
	rm -f $(OBJ)
	@$(MAKE) clean -C ft_printf

fclean: clean
	rm -f $(NAME)
	@$(MAKE) fclean -C ft_printf

re: fclean all

.PHONY: all clean fclean re