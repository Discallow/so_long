/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 18:56:52 by discallow         #+#    #+#             */
/*   Updated: 2024/06/13 14:26:27 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_valid_line(char *line, int line_size, t_game *game)
{
	if (game->y == 0)
		game->x = ft_strlen(line);
	if (game-> y > 1 || game->x < 6)
	{
		game->x = ft_strlen(line);
		if (line_size != game->x || game->x < 6)
		{
			write(2, "Error: Invalid lines in map\n", 28);
			free(line);
			exit (1);
		}
	}
}

void	read_file(t_game *game)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = get_next_line(game->fd);
		if (!line)
		{
			if (game->x < 6)
				check_valid_line(line, ft_strlen(line), game);
			free(line);
			break ;
		}
		check_valid_line(line, ft_strlen(line), game);
		free(line);
		game->y++;
	}
}

void	read_file_again(char *line, t_game *game, char *str, size_t total_len)
{
	while (1)
	{
		line = get_next_line(game->fd);
		if (!line)
		{
			free (line);
			break ;
		}
		ft_strlcat(str, line, total_len + 1);
		free(line);
	}
}

void	check_first_last_line(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
		{
			write(2, "Error: Check the borders\n", 25);
			free_map(game->map);
			free_map(game->copy.map);
			exit (1);
		}
		i++;
	}
}

void	check_middle_lines(t_game *game)
{
	int	i;
	int	last_index;

	i = 1;
	last_index = game->x - 1;
	while (i < (game->y - 1))
	{
		if (game->map[i][0] != '1' || game->map[i][last_index] != '1')
		{
			write(2, "Error: Check the borders\n", 25);
			free_map(game->map);
			free_map(game->copy.map);
			exit (1);
		}
		i++;
	}
}
