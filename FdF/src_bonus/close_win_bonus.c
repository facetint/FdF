/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:36:36 by facetint          #+#    #+#             */
/*   Updated: 2023/12/02 19:32:48 by facetint         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"
#include "../includes/key_bonus.h"
#include <stdlib.h>

int	ft_close_win(void *param)
{
	t_data	*fdf;

	fdf = (t_data *)param;
	free_map_coords(fdf, 0);
	return (0);
}
