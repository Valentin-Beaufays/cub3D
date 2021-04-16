UNAME := $(shell uname -s)

CC=                gcc

CFLAGS=            -Wall -Wextra -Werror

BUFFER_SIZE=    16

NAME=            cub3D

INCLUDES:=        -I ./includes/ -I ./libft/ -I ./get_next_line/ 

FILES=			./srcs/error/error.c\
				./srcs/structures/struct.c\
				./srcs/structures/data_struct.c\
				./srcs/structures/free_struct.c\
				./srcs/structures/free_data_struct.c\
				./srcs/parser/parser.c\
				./srcs/parser/textures_parser.c\
				./srcs/parser/fc_parser.c\
				./srcs/parser/map_parser.c\
				./srcs/parser/get_data.c\
				./srcs/parser/get_textures.c\
				./srcs/parser/get_map.c\
				./srcs/parser/get_pos.c\
				./srcs/parser/check_valid_map.c\
				./srcs/render/print_columnv2.c\
				./srcs/render/find_intersection.c\
				./srcs/render/check_hit.c\
				./srcs/render/render.c\
				./srcs/sprite/sprite.c\
				./srcs/sprite/print_sprite.c\
				./srcs/sprite/find_sprite_col.c\
				./srcs/game/game_loop.c\
				./srcs/utils/check_path.c\
				./srcs/utils/rgb_to_int.c\
				./srcs/utils/rad_utils.c\
				./srcs/utils/mlx_utils.c\
				./srcs/utils/mlx_img_utils.c\
				./srcs/utils/resize_image.c\
				./srcs/utils/ft_abs.c\
				./srcs/utils/sprite_utils.c\
				./srcs/utils/get_dist.c\
				get_next_line/get_next_line.c\
				get_next_line/get_next_line_utils.c\
				main.c

MLX :=


ifeq ($(UNAME), Darwin)
    MLX += libft/libft.a ./minilibX/mlx_mac/libmlx.a -lm -framework OpenGL -framework AppKit
	INCLUDES += -I ./minilibX/mlx_mac/
endif
ifeq ($(UNAME), Linux)
    MLX += libft/libft.a ./minilibX/mlx_linux/libmlx.a -lXext -lX11 -lm 
	INCLUDES += -I ./minilibX/mlx_linux/
endif

$(NAME): 
	$(CC) -o $(NAME) $(INCLUDES) -D BUFFER_SIZE=$(BUFFER_SIZE) $(FILES) $(MLX)

all: $(NAME)

clean: 
	@rm -rf $(NAME)

fclean: clean

re: fclean $(NAME)


install:
	git clone https://github.com/Valentin-Beaufays/libft.git libft 
	make -C ./libft 
	git clone https://github.com/Valentin-Beaufays/get_next_line.git get_next_line
