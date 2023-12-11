/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:36:25 by facetint          #+#    #+#             */
/*   Updated: 2023/12/02 19:33:09 by facetint         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"
#include "../includes/key_bonus.h"

void	rotate(int keycode, t_data *fdf)
{
	if (keycode == MAIN_PAD_2)
		fdf->camera->alpha += 0.1;
	else if (keycode == MAIN_PAD_8)
		fdf->camera->alpha -= 0.1;
	else if (keycode == MAIN_PAD_4)
		fdf->camera->beta -= 0.1;
	else if (keycode == MAIN_PAD_6)
		fdf->camera->beta += 0.1;
	else if (keycode == MAIN_PAD_3)
		fdf->camera->gamma += 0.1;
	else if (keycode == MAIN_PAD_7)
		fdf->camera->gamma -= 0.1;
	draw(fdf);
}

void	pit(int keycode, t_data *fdf)
{
	if (keycode == MAIN_PAD_LESS)
		fdf->camera->z_height -= 0.1;
	else if (keycode == MAIN_PAD_MORE)
		fdf->camera->z_height += 0.1;
	if (fdf->camera->z_height < 0.1)
		fdf->camera->z_height = 0.1;
	draw(fdf);
}

void	toggle_projection(int keycode, t_data *fdf)
{
	fdf->camera->alpha = 0;
	fdf->camera->beta = 0;
	fdf->camera->gamma = 0;
	if (keycode == MAIN_PAD_I)
		fdf->camera->projection = ISO;
	else if (keycode == MAIN_PAD_P)
		fdf->camera->projection = PARALLEL;
	draw(fdf);
}

void	ft_translate(int keycode, t_data *fdf)
{
	if (keycode == ARROW_LEFT)
		fdf->camera->x_offset += 10;
	else if (keycode == ARROW_RIGHT)
		fdf->camera->x_offset -= 10;
	else if (keycode == ARROW_UP)
		fdf->camera->y_offset += 10;
	else
		fdf->camera->y_offset -= 10;
	draw(fdf);
}
