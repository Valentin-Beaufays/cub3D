CC=				gcc

CFLAGS=			-Wall -Wextra -Werror

BUFFER_SIZE=	10

NAME=			cub3D

FILES=			error/error.c\
				parser/parser.c\
				parser/textures_parser.c\
				get_next_line/get_next_line.c\
				get_next_line/get_next_line_utils.c\
				parser/fc_parser.c\
				parser/map_parser.c\
				main.c

LIB=			libft/libft.a

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) -D BUFFER_SIZE=$(BUFFER_SIZE) $(FILES) $(LIB)

clean:
	@rm -rf $(NAME)

fclean: clean

re: fclean $(NAME)