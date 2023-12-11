/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:36:36 by facetint          #+#    #+#             */
/*   Updated: 2023/12/07 16:48:27 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/key.h"
#include <stdlib.h>

int	ft_close_win(void *param)
{
	t_data	*fdf;

	fdf = (t_data *)param;
	free_map_coords(fdf, 0);
	return (0);
}
