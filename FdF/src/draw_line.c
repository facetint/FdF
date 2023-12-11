/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:07 by facetint          #+#    #+#             */
/*   Updated: 2023/12/04 15:56:00 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"
#include "../minilibx/mlx.h"
#include <math.h>
#include <stdlib.h>

void	ft_put_pixel(t_data *fdf, int x, int y, int color)
{
	int		i;

	if (x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * fdf->bits_per_pixel / 8) + (y * fdf->size_line);
		fdf->data_addr[i] = color;
		fdf->data_addr[++i] = color >> 8;
		fdf->data_addr[++i] = color >> 16;
	}
}

void	ft_draw_line_loop(t_point s, t_point e, float g, t_data *fdf)
{
	float	inter_y;
	int		x;

	inter_y = (float)s.y;
	x = s.x;
	while (x <= e.x)
	{
		if (fdf->steep)
		{
			ft_put_pixel(fdf, ft_r_int(inter_y), x,
				ft_get_color(x, s, e, color_smoothing(inter_y)));
			ft_put_pixel(fdf, ft_r_int(inter_y) + 1, x,
				ft_get_color(x, s, e, ft_float(inter_y)));
		}
		else
		{
			ft_put_pixel(fdf, x, ft_r_int(inter_y),
				ft_get_color(x, s, e, color_smoothing(inter_y)));
			ft_put_pixel(fdf, x, ft_r_int(inter_y) + 1,
				ft_get_color(x, s, e, ft_float(inter_y)));
		}
		inter_y += g;
		x++;
	}
}

void	ft_draw_line(t_point point1, t_point point2, t_data *fdf)
{
	float	dy;
	float	dx;
	float	ratio;

	fdf->steep = ft_abs(point2.y - point1.y) > ft_abs(point2.x - point1.x);
	if (fdf->steep)
	{
		ft_swap(&point1.x, &point1.y);
		ft_swap(&point2.x, &point2.y);
	}
	if (point1.x > point2.x)
	{
		ft_swap(&point1.color, &point2.color);
		ft_swap(&point1.x, &point2.x);
		ft_swap(&point1.y, &point2.y);
	}
	dx = (float)(point2.x - point1.x);
	dy = (float)(point2.y - point1.y);
	ratio = dy / dx;
	if (dx == 0.0f)
		ratio = 1.f;
	ft_draw_line_loop(point1, point2, ratio, fdf);
}

void	draw(t_data *fdf)
{
	int	x;
	int	y;

	draw_background(fdf);
	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (x != fdf->map->width - 1)
				ft_draw_line(project(new_point(x, y, fdf->map), fdf),
					project(new_point(x + 1, y, fdf->map), fdf), fdf);
			if (y != fdf->map->height - 1)
				ft_draw_line(project(new_point(x, y, fdf->map), fdf),
					project(new_point(x, y + 1, fdf->map), fdf), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img, 0, 0);
}
