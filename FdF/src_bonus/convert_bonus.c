/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:36:42 by facetint          #+#    #+#             */
/*   Updated: 2023/12/02 19:34:25 by facetint         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"
#include <stdlib.h>

void	convert(t_coord_value **coords_stack, t_data *fdf)
{
	t_coord_value	*coords;
	int				i;
	int				size;

	size = fdf->map->width * fdf->map->height * sizeof(int);
	fdf->map->coords_arr = (int *)malloc(size);
	fdf->map->colors_arr = (int *)malloc(size);
	if (!fdf->map->coords_arr || !fdf->map->colors_arr)
		free_map_coords(fdf, 1);
	i = fdf->map->width * fdf->map->height - 1;
	while (1)
	{
		if (!(*coords_stack))
			break ;
		coords = ft_arr_last(coords_stack);
		fdf->map->coords_arr[i] = coords->z;
		fdf->map->colors_arr[i] = coords->color;
		if (coords->z > fdf->map->z_max)
			fdf->map->z_max = coords->z;
		if (coords->z < fdf->map->z_min)
			fdf->map->z_min = coords->z;
		i--;
		free(coords);
	}
}
