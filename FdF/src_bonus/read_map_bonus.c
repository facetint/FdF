/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:38:51 by facetint          #+#    #+#             */
/*   Updated: 2023/12/07 15:29:29 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"
#include <stdlib.h>
#include "../get_next_line/get_next_line.h"
#include <unistd.h>

t_coord_value	*new_coord(char *coords_arr, t_data *fdf)
{
	t_coord_value	*coords;
	char			**line;

	coords = (t_coord_value *)malloc(sizeof(t_coord_value));
	if (!coords)
		free_map_coords(fdf, 1);
	line = ft_split(coords_arr, ',');
	if (!line)
	{
		free(coords);
		free_map_coords(fdf, 1);
	}
	coords->z = ft_atoi(line[0]);
	if (line[1])
		coords->color = ft_atoi_hex(line[1]);
	else
		coords->color = -1;
	coords->next = NULL;
	free_double(line);
	return (coords);
}

void	get_width(t_coord_value **coords, t_data *fdf, char **coords_arr)
{
	int				width;

	width = 0;
	while (*coords_arr)
	{
		ft_add_front(coords, new_coord(*(coords_arr++), fdf));
		width++;
	}
	if (fdf->map->height == 0 || fdf->map->width != width)
		fdf->map->width = width;
	else if (fdf->map->width != width)
		free_map_coords(fdf, 1);
}

void	read_map(int fd, t_coord_value **coords, t_data *fdf)
{
	char	*line;
	char	**coords_arr;

	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		free_map_coords(fdf, 0);
	}
	while (line != NULL)
	{
		coords_arr = ft_split(line, ' ');
		if (!coords_arr)
		{
			close(fd);
			free_map_coords(fdf, 1);
		}
		get_width(coords, fdf, coords_arr);
		fdf->map->height++;
		free_double(coords_arr);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
