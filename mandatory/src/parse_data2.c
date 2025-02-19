/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboussad <tboussad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:18:59 by aragragu          #+#    #+#             */
/*   Updated: 2025/02/19 12:57:19 by tboussad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	map_first_line_index(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (is_map_line(str[i]))
			return (i);
		i++;
	}
	return (0);
}

int	file_lenght(char *str)
{
	int		i;
	int		line;

	i = 0;
	line = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i + 1] == '\0')
			line++;
		i++;
	}
	return (line);
}

void	get_file_lines(char *str, t_parsing *info)
{
	int		i;
	int		len;
	int		start;
	int		count;

	i = 0;
	len = 0;
	start = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i + 1] == '\0')
		{
			if (str[i] == '\n')
				len = i - start;
			else
				len = i - start + 1;
			info->file_lines[count] = ft_substr(str, start, len);
			start = i + 1;
			count++;
		}
		i++;
	}
	info->file_lines[count] = NULL;
}

void	check_player_surending(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || \
				map[i][j] == 'W' || map[i][j] == 'E')
			{
				if (!check_surrending(map, i, j))
					my_perror(1, "Error\n player is not \
						surrounded by walls\n");
			}
			j++;
		}
		i++;
	}
}
