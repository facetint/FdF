/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:36:58 by facetint          #+#    #+#             */
/*   Updated: 2023/12/02 19:35:21 by facetint         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"
#include "../includes/color_bonus.h"

t_point	project(t_point point, t_data *fdf)
{
	point.x *= fdf->camera->zoom;
	point.y *= fdf->camera->zoom;
	point.z *= fdf->camera->zoom / fdf->camera->z_height;
	point.x -= (fdf->map->width * fdf->camera->zoom) / 2;
	point.y -= (fdf->map->height * fdf->camera->zoom) / 2;
	rotate_x(&point.y, &point.z, fdf->camera->alpha);
	rotate_y(&point.x, &point.z, fdf->camera->beta);
	rotate_z(&point.x, &point.y, fdf->camera->gamma);
	if (fdf->camera->projection == ISO)
		isometric(&point.x, &point.y, point.z);
	point.x += (WIDTH - MENU_WIDTH) / 2 + fdf->camera->x_offset + MENU_WIDTH;
	point.y += (HEIGHT + fdf->map->height * fdf->camera->zoom) / 2
		+ fdf->camera->y_offset;
	return (point);
}

void	draw_background(t_data *fdf)
{
	int	*back_ground;
	int	i;

	back_ground = (int *)(fdf->data_addr);
	i = 0;
	while (i < HEIGHT * WIDTH)
	{
		if (i % WIDTH < MENU_WIDTH)
			back_ground[i] = MENU_BACKGROUND;
		else
			back_ground[i] = BACKGROUND;
		i++;
	}
}

int	get_index(int x, int y, int width)
{
	return (y * width + x);
}

t_point	new_point(int x, int y, t_map *map)
{
	t_point	p;
	int		i;

	i = get_index(x, y, map->width);
	p.x = x;
	p.y = y;
	p.z = map->coords_arr[i];
	if (map->colors_arr[i] == -1)
		p.color = get_default_color(p.z, map);
	else
		p.color = map->colors_arr[i];
	return (p);
}
