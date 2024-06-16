/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:32:54 by discallow         #+#    #+#             */
/*   Updated: 2024/06/16 06:18:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_map(t_game *game, char *file)
{
	check_extension(file);
	open_file(game, file);
	read_file(game);
	close(game->fd);
	build_map_read_borders(game, file);
	check_first_last_line(game->map[0], game);
	check_middle_lines(game);
	check_first_last_line(game->map[game->y - 1], game);
	check_map_composition(game);
	flood_fill(game);
}

static void	check_map_composition_2(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'C')
		game->collectable.num++;
	else if (game->map[i][j] == 'E')
	{
		game->exit.x = i;
		game->exit.y = j;
		game->exit.num++;
	}
	else if (game->map[i][j] == 'P')
	{
		game->player.x = i;
		game->player.y = j;
		game->player.num++;
	}
	else if (game->map[i][j] != '1' && game->map[i][j] != '0')
		invalid_map(game);
}

void	check_map_composition(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			check_map_composition_2(game, i, j);
			j++;
		}
		i++;
	}
	if (game->collectable.num < 1 || game->exit.num != 1
		|| game->player.num != 1)
		invalid_map(game);
}

void	open_file(t_game *game, char *file)
{
	game->fd = open(file, O_RDONLY);
	if (game->fd < 0)
	{
		perror("Error opening file");
		exit (1);
	}
}
// 
void	build_map_read_borders(t_game *game, char *file)
{
	char	*line;
	char	*str;
	size_t	total_len;

	total_len = game->x * game->y;
	str = (char *)malloc(sizeof(char) * total_len + 1);
	if (!str)
		return ;
	open_file(game, file);
	line = get_next_line(game->fd);
	if (!line)
		free(line);
	else
	{
		ft_strlcpy(str, line, ft_strlen(line) + 1);
		free(line);
	}
	read_file_again(line, game, str, total_len);
	game->map = ft_split(str, '\n');
	game->copy.map = ft_split(str, '\n');
	game->x = ft_strlen(game->map[0]);
	free(str);
}
