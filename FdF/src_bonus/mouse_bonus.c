/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:38:11 by facetint          #+#    #+#             */
/*   Updated: 2023/12/07 16:41:21 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"
#include "../includes/key_bonus.h"
#include <stdbool.h>

void	zoom(int key, t_data *fdf)
{
	if (key == MAIN_PAD_PLUS || key == MOUSE_SCROLL_DOWN)
		fdf->camera->zoom++;
	else if (key == MAIN_PAD_MINUS || key == MOUSE_SCROLL_UP)
		fdf->camera->zoom--;
	if (fdf->camera->zoom < 1)
		fdf->camera->zoom = 1;
	draw(fdf);
}

int	mouse_press(int button, int x, int y, void *param)
{
	t_data	*fdf;

	(void)x;
	(void)y;
	fdf = (t_data *)param;
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		zoom(button, fdf);
	else if (button == MOUSE_LEFT_BUTTON)
		fdf->mouse->is_pressed = true;
	return (0);
}

int	mouse_release(int button, int x, int y, void *param)
{
	t_data	*fdf;

	(void)x;
	(void)y;
	(void)button;
	fdf = (t_data *)param;
	fdf->mouse->is_pressed = false;
	return (0);
}

int	mouse_move(int x, int y, void *param)
{
	t_data	*fdf;

	fdf = (t_data *)param;
	fdf->mouse->prev_x = fdf->mouse->x;
	fdf->mouse->prev_y = fdf->mouse->y;
	fdf->mouse->x = x;
	fdf->mouse->y = y;
	if (fdf->mouse->is_pressed)
	{
		fdf->camera->beta += (x - fdf->mouse->prev_x) * 0.0025;
		fdf->camera->alpha += (y - fdf->mouse->prev_y) * 0.0025;
		draw(fdf);
	}
	return (0);
}
