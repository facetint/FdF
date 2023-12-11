/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:36:16 by facetint          #+#    #+#             */
/*   Updated: 2023/12/04 15:41:19 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/color.h"

double	percent(int start, int end, int cur)
{
	double	placement;
	double	distance;

	placement = cur - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return (placement / distance);
}

int	get_default_color(int z, t_map *map)
{
	double	percentange;

	percentange = percent(map->z_min, map->z_max, z);
	if (percentange < 0.2)
		return (BLUE);
	else if (percentange < 0.4)
		return (DARK_PURPLE);
	else if (percentange < 0.6)
		return (PURPLE);
	else if (percentange < 0.8)
		return (PINK);
	else
		return (PINK);
}

int	ft_lin_intpol(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

int	ft_get_color(int x, t_point p1, t_point p2, float ratio)
{
	int		r;
	int		g;
	int		b;
	float	percent;

	percent = 1 - ft_abs(x - p1.x) / ft_abs(p2.x - p1.x);
	r = ft_lin_intpol((p2.color >> 16) & 0xFF, (p1.color >> 16)
			& 0xFF, percent);
	g = ft_lin_intpol((p2.color >> 8) & 0xFF, (p1.color >> 8)
			& 0xFF, percent);
	b = ft_lin_intpol(p2.color & 0xFF, p1.color & 0xFF, percent);
	r *= ratio;
	g *= ratio;
	b *= ratio;
	return ((r << 16) | (g << 8) | b);
}
