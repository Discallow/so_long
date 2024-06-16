NAME = so_long
BONUS = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext
SRC_DIR = src/
BONUS_DIR = bonus_src/
OBJ_DIR = obj/
B_OBJ_DIR = bonus_obj/
SRCS =	$(SRC_DIR)check_map.c \
	$(SRC_DIR)check_map_2.c \
	$(SRC_DIR)exit_functions.c \
	$(SRC_DIR)flood_fill.c \
	$(SRC_DIR)get_next_line.c \
	$(SRC_DIR)libft_utils.c \
	$(SRC_DIR)libft_utils_2.c \
	$(SRC_DIR)split.c \
	$(SRC_DIR)events.c \
	$(SRC_DIR)player_moves.c \
	$(SRC_DIR)textures_utils.c \
	$(SRC_DIR)utils.c \
	$(SRC_DIR)main.c
BONUS_SRCS= $(BONUS_DIR)check_map.c \
	$(BONUS_DIR)check_map_2.c \
	$(BONUS_DIR)exit_functions.c \
	$(BONUS_DIR)flood_fill.c \
	$(BONUS_DIR)get_next_line.c \
	$(BONUS_DIR)libft_utils.c \
	$(BONUS_DIR)libft_utils_2.c \
	$(BONUS_DIR)split.c \
	$(BONUS_DIR)events.c \
	$(BONUS_DIR)player_moves.c \
	$(BONUS_DIR)textures_utils.c \
	$(BONUS_DIR)utils.c \
	$(BONUS_DIR)enemy_sprite.c \
	$(BONUS_DIR)main.c
OBJS = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o, $(SRCS))
BONUS_OBJS = $(patsubst $(BONUS_DIR)%.c,$(B_OBJ_DIR)%.o, $(BONUS_SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@ $(MLX_FLAGS)

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS)
	$(CC) $(BONUS_OBJS) -o $@ $(MLX_FLAGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(MLX_FLAGS)

$(B_OBJ_DIR):
	mkdir -p $(B_OBJ_DIR)
	
$(B_OBJ_DIR)%.o: $(BONUS_DIR)%.c | $(B_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(MLX_FLAGS)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(B_OBJ_DIR)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BONUS)
re: fclean all
