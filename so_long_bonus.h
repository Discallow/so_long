/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 18:59:09 by discallow         #+#    #+#             */
/*   Updated: 2024/06/15 01:15:28 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define TILE_SIZE 32
typedef struct s_map_copy
{
	char	**map;
	int		collectable;
	int		exit;
}		t_map_copy;

typedef struct s_position
{
	int		x;
	int		y;
	int		num;
	int		total;
	void	*img;
	char	*path;
}		t_position;

typedef struct s_game
{
	void		*connection;
	void		*window;
	char		**map;
	int			x;
	int			y;
	int			fd;
	t_map_copy	copy;
	t_position	collectable;
	t_position	player;
	t_position	exit;
	t_position	wall;
	t_position	floor;
	t_position	enemy;
}		t_game;

// LIBFT UTILS
char	*get_next_line(int fd);
int		ft_strcmp2(char *str1, char *str2);
size_t	ft_strlen(char *str);
void	*ft_calloc(size_t n, size_t size);
void	*ft_memset(void *str, int c, size_t n);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
size_t	ft_strlcat(char *dest, char *src, size_t size);
char	**ft_split(char const *s, char c);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_itoa(int n);

// SO_LONG FUNCTIONS
void	init_struct(t_game *game);
void	check_valid_line(char *line, int line_size, t_game *game);
void	check_map(t_game *game, char *file);
void	build_map_read_borders(t_game *game, char *file);
void	check_extension(char *file);
void	open_file(t_game *game, char *file);
void	read_file(t_game *game);
void	read_file_again(char *line, t_game *game, char *str, size_t total_len);
void	free_map(char **str);
void	check_first_last_line(char *line, t_game *game);
void	check_middle_lines(t_game *game);
void	check_map_composition(t_game *game);
void	flood_fill(t_game *game);
void	invalid_map(t_game *game);
void	build_map(t_game *game);
void	destroy_map(t_game *game);
void	end_game(t_game *game);
void	*check_image(t_game *game, void *image, char *path);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_up(t_game *game);
int		key_pressed(int keysim, t_game *game);
int		window_closed(t_game *game);
void	redraw_map(t_game *game, int flag);
void	init_connection(t_game *game);
void	count_movements(t_game *game);
void	get_path(t_game *game);
void	build_map(t_game *game);
void	game_over(t_game *game);
int		enemy_sprite(t_game *game);

#endif
