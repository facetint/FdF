/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:38:03 by facetint          #+#    #+#             */
/*   Updated: 2023/12/04 15:11:58 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"
#include "../includes/color_bonus.h"
#include "../minilibx/mlx.h"

void	menu_background(t_data *fdf)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fdf->mlx_ptr;
	win = fdf->win_ptr;
	mlx_string_put(mlx, win, 80, y += 20, TEXT_COLOR, "Controls\n\n");
	mlx_string_put(mlx, win, 15, y += 40, TEXT_COLOR, "Zoom: Scroll or */- \n");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Move: Arrows\n\n\n\n");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Elevation: K Keys\n\n");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Pit: L Keys\n\n\n\n");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Projection: \n\n\n\n");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "ISO: I Key\n\n\n");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Parallel: P Key\n\n\n");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate with Keyboard:");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "X-Axis - 2/8");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Y-Axis - 4/6");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Z-Axis - 3/7 \n\n\n\n");
	mlx_string_put(mlx, win, 30, y += 39, TEXT_COLOR, "Rotate with Mouse: \n");
	mlx_string_put(mlx, win, 57, y += 30, TEXT_COLOR, "Press & Move \n\n\n");
	mlx_string_put(mlx, win, 90, y += 40, TEXT_COLOR, "!!FDF!!");
}
