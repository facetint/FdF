/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:36 by facetint          #+#    #+#             */
/*   Updated: 2023/12/02 19:34:14 by facetint         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"
#include "../includes/key_bonus.h"
#include "../minilibx/mlx.h"

int	key_press(int keycode, void *param)
{
	t_data	*fdf;

	fdf = (t_data *)param;
	if (keycode == MAIN_PAD_ESC)
		free_map_coords(fdf, 0);
	if (keycode == MAIN_PAD_PLUS || keycode == MAIN_PAD_MINUS)
		zoom(keycode, fdf);
	else if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT
		|| keycode == ARROW_UP || keycode == ARROW_DOWN)
		ft_translate(keycode, fdf);
	else if (keycode == MAIN_PAD_2 || keycode == MAIN_PAD_3
		|| keycode == MAIN_PAD_4 || keycode == MAIN_PAD_6
		|| keycode == MAIN_PAD_7 || keycode == MAIN_PAD_8)
		rotate(keycode, fdf);
	else if (keycode == MAIN_PAD_LESS || keycode == MAIN_PAD_MORE)
		pit(keycode, fdf);
	else if (keycode == MAIN_PAD_P || keycode == MAIN_PAD_I)
		toggle_projection(keycode, fdf);
	return (0);
}

void	ft_hook_controls(t_data *fdf)
{
	mlx_hook(fdf->win_ptr, 2, 0, key_press, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, ft_close_win, fdf);
	mlx_hook(fdf->win_ptr, 4, 0, mouse_press, fdf);
	mlx_hook(fdf->win_ptr, 5, 0, mouse_release, fdf);
	mlx_hook(fdf->win_ptr, 6, 0, mouse_move, fdf);
}
