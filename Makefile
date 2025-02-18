NAME = cub3D
NAME_BONUS = cub3D_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast
RM = rm -rf

FRMW = -lmlx -framework OpenGL -framework AppKit -O3

SRC = mandatory/src/ceil_and_floor.c mandatory/src/ft_split.c mandatory/src/movements2.c mandatory/src/render_utils.c \
      mandatory/src/checking_map.c mandatory/src/get_next_libe_utils.c mandatory/src/movements.c mandatory/src/utils1.c \
      mandatory/src/data.c mandatory/src/get_next_line.c mandatory/src/parse_data2.c mandatory/src/utils2.c  \
      mandatory/src/keys.c mandatory/src/parse_data.c mandatory/src/utils3.c mandatory/src/data_utils.c mandatory/src/data_utils2.c mandatory/src/load_texture.c \
      mandatory/src/parsing.c mandatory/src/utils4.c mandatory/src/main.c mandatory/src/raycasting.c \
      mandatory/src/utils.c mandatory/src/draw_walls.c mandatory/src/map_parsing.c mandatory/src/raycasting_utils.c \
      mandatory/src/fill_data.c mandatory/src/render.c mandatory/src/ft_malloc.c \

OBJ = $(SRC:%.c=%.o)

SRC_BONUS = bonus/src/ceil_and_floor.c bonus/src/data_utils.c bonus/src/main.c bonus/src/movements2.c bonus/src/render.c \
			bonus/src/data.c bonus/src/ft_malloc.c bonus/src/minimap2.c bonus/src/movements.c bonus/src/render_utils2.c \
			bonus/src/data_utils2.c bonus/src/keys2.c bonus/src/minimap.c bonus/src/raycasting.c bonus/src/render_utils.c \
			bonus/src/data_utils3.c bonus/src/keys.c bonus/src/mouse.c bonus/src/raycasting_utils.c bonus/src/utils.c \
			bonus/src/checking_map.c bonus/src/get_next_libe_utils.c bonus/src/map_parsing.c bonus/src/utils1.c \
			bonus/src/draw_walls.c bonus/src/get_next_line.c bonus/src/parse_data2.c bonus/src/utils2.c bonus/src/fill_data.c \
			bonus/src/gun.c bonus/src/parse_data.c bonus/src/utils3.c bonus/src/ft_split.c bonus/src/load_texture.c \
			bonus/src/parsing.c bonus/src/utils4.c


OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

all: $(NAME)

$(NAME): $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(FRMW) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ): mandatory/cub3d.h

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(MLX) $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(FRMW) -o $(NAME_BONUS)

$(OBJ_BONUS): bonus/cub3d_bonus.h

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all