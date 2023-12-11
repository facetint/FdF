/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:43:31 by facetint          #+#    #+#             */
/*   Updated: 2023/12/04 15:29:22 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	ft_abs(float n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_r_int(float n)
{
	return ((int)n);
}

float	ft_float(float n)
{
	if (n > 0.f)
		return (n - ft_r_int(n));
	return (n - (ft_r_int(n) + 1.f));
}

float	color_smoothing(float n)
{
	return (1.f - ft_float(n));
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
