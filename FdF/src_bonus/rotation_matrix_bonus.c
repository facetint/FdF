/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:38:29 by facetint          #+#    #+#             */
/*   Updated: 2023/12/02 19:36:22 by facetint         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

void	rotate_x(int *y, int *z, double x_angle)
{
	int	prev_y;
	int	prev_z;

	prev_y = *y;
	prev_z = *z;
	*y = prev_y * cos(x_angle) + prev_z * sin(x_angle);
	*z = -prev_y * sin(x_angle) + prev_z * cos(x_angle);
}

void	rotate_y(int *x, int *z, double y_angle)
{
	int	prev_x;
	int	prev_z;

	prev_x = *x;
	prev_z = *z;
	*x = prev_x * cos(y_angle) + prev_z * sin(y_angle);
	*z = -prev_x * sin(y_angle) + prev_z * cos(y_angle);
}

void	rotate_z(int *x, int *y, double z_angle)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(z_angle) - prev_y * sin(z_angle);
	*y = prev_x * sin(z_angle) + prev_y * cos(z_angle);
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
