/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:53:18 by discallow         #+#    #+#             */
/*   Updated: 2024/06/16 06:18:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

// before moving the player or changing the exit, this is going to be the first path to the xpm files
void	get_path(t_game *game)
{
	game->collectable.path = "textures/pokeball.xpm";
	game->wall.path = "textures/SLIMBRICKS.xpm";
	game->floor.path = "textures/grass.xpm";
	game->player.path = "textures/ash_down.xpm";
	game->exit.path = "textures/grass.xpm";
}
/* This function is checking all the images,
to make sure that they're valid and no error occurs while converting them from xpm to image*/
void	*check_image(t_game *game, void *image, char *path)
{
	int	width;
	int	height;

	image = mlx_xpm_file_to_image(game->connection, path, &width, &height);
	if (!image)
	{
		write(2, "Error in image\n", 15);
		free_map(game->map);
		mlx_destroy_window(game->connection, game->window);
		mlx_destroy_display(game->connection);
		free(game->connection);
		exit(1);
	}
	return (image);
}

void	xpm_to_image(t_game *game)
{
	if (game->collectable.num == 0)
	{
		game->exit.path = "textures/exit_open_01.xpm";
		game->map[game->exit.x][game->exit.y] = 'E';
	}
	game->wall.img = check_image(game, game->wall.img, game->wall.path);
	game->floor.img = check_image(game, game->floor.img, game->floor.path);
	game->player.img = check_image(game, game->player.img, game->player.path);
	game->collectable.img = check_image(game, game->collectable.img,
			game->collectable.path);
	game->exit.img = check_image(game, game->exit.img, game->exit.path);
}

// After checking the images, I'm putting them in the respective x and y of the 2D array map
void	put_images_to_window(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->connection, game->window,
			game->wall.img, (j + 1) * TILE_SIZE, (i + 1) * TILE_SIZE);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->connection, game->window,
			game->floor.img, (j + 1) * TILE_SIZE, (i + 1) * TILE_SIZE);
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->connection, game->window,
			game->player.img, (j + 1) * TILE_SIZE, (i + 1) * TILE_SIZE);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->connection, game->window,
			game->collectable.img, (j + 1) * TILE_SIZE, (i + 1) * TILE_SIZE);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->connection, game->window,
			game->exit.img, (j + 1) * TILE_SIZE, (i + 1) * TILE_SIZE);
}

void	build_map(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	xpm_to_image(game);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			put_images_to_window(game, i, j);
			j++;
		}
		i++;
	}
}
