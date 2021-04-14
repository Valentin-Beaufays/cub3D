CC=				gcc

CFLAGS=			-Wall -Wextra -Werror

BUFFER_SIZE=	10

NAME=			cub3D

INCLUDES=		-I ./includes/ -I ./libft/ -I ./get_next_line/ -I ./mlx/

FILES=			error/error.c\
				structures/struct.c\
				structures/data_struct.c\
				structures/free_struct.c\
				structures/free_data_struct.c\
				parser/parser.c\
				parser/textures_parser.c\
				parser/fc_parser.c\
				parser/map_parser.c\
				parser/get_data.c\
				parser/get_textures.c\
				parser/get_map.c\
				parser/get_pos.c\
				parser/check_valid_map.c\
				render/print_column.c\
				render/find_intersection.c\
				render/check_hit.c\
				render/render.c\
				sprite/sprite.c\
				sprite/print_sprite.c\
				sprite/find_sprite_col.c\
				game/game_loop.c\
				utils/check_path.c\
				utils/rgb_to_int.c\
				utils/rad_utils.c\
				utils/mlx_utils.c\
				utils/mlx_img_utils.c\
				utils/resize_image.c\
				utils/ft_abs.c\
				utils/sprite_utils.c\
				get_next_line/get_next_line.c\
				get_next_line/get_next_line_utils.c\
				main.c

LIB=			libft/libft.a mlx/libmlx.a -lm -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	$(CC) -o $(NAME) $(INCLUDES) -D BUFFER_SIZE=$(BUFFER_SIZE) $(FILES) $(LIB)

clean:
	@rm -rf $(NAME)

fclean: clean

re: fclean $(NAME)

install:
	git clone https://github.com/Valentin-Beaufays/libft.git libft
	make -C ./libft
	git clone https://github.com/Valentin-Beaufays/get_next_line.git get_next_line