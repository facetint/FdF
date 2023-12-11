/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_controls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:36 by facetint          #+#    #+#             */
/*   Updated: 2023/11/27 18:41:02 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/key.h"
#include <math.h>
#include "../minilibx/mlx.h"

int	key_press(int keycode, void *param)
{
	t_data	*fdf;

	fdf = (t_data *)param;
	if (keycode == MAIN_PAD_ESC)
		free_map_coords(fdf, 0);
	return (0);
}

void	ft_hook_controls(t_data *fdf)
{
	mlx_hook(fdf->win_ptr, 2, 0, key_press, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, ft_close_win, fdf);
}

void	isometric(int *x, int *y, int z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);
	*y = -z + (prev_x + prev_y) * sin(0.523599);
}
