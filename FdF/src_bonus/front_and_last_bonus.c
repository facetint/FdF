/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   front_and_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:38:22 by facetint          #+#    #+#             */
/*   Updated: 2023/12/02 19:32:36 by facetint         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

void	ft_add_front(t_coord_value **stack, t_coord_value *new)
{
	if (!new || !stack)
		return ;
	new->next = *stack;
	*stack = new;
}

t_coord_value	*ft_arr_last(t_coord_value **stack)
{
	t_coord_value	*ret_val;

	ret_val = 0;
	if (*stack)
	{
		ret_val = *stack;
		*stack = (*stack)->next;
	}
	return (ret_val);
}
