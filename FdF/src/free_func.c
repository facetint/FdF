/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:15 by facetint          #+#    #+#             */
/*   Updated: 2023/12/07 16:40:09 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>
#include "../ft_printf/ft_printf.h"
#include "../minilibx/mlx.h"

void	free_map(t_data *fdf)
{
	if (fdf->map)
	{
		if (fdf->map->coords_arr)
			free(fdf->map->coords_arr);
		if (fdf->map->colors_arr)
			free(fdf->map->colors_arr);
		free(fdf->map);
	}
}

void	free_map_coords(t_data *fdf, int a)
{
	t_coord_value	*tmp;

	if (fdf)
	{
		while (fdf->coords)
		{
			tmp = fdf->coords;
			fdf->coords = (fdf->coords)->next;
			free(tmp);
		}
		if (fdf->map)
			free_map(fdf);
		if (fdf->camera)
			free(fdf->camera);
		if (fdf->win_ptr)
			mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		if (fdf->img)
			mlx_destroy_image(fdf->mlx_ptr, fdf->img);
		free(fdf);
	}
	if (a == 1)
		exit(ft_printf("Map loading error\n"));
	else
		exit(0);
}

void	free_double(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
