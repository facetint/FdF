/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:38:38 by facetint          #+#    #+#             */
/*   Updated: 2023/12/02 19:33:37 by facetint         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

int	is_hexa(char c)
{
	if (c == 'a' || c == 'A')
		return (10);
	else if (c == 'b' || c == 'B')
		return (11);
	else if (c == 'c' || c == 'C')
		return (12);
	else if (c == 'd' || c == 'D')
		return (13);
	else if (c == 'e' || c == 'E')
		return (14);
	else if (c == 'f' || c == 'F')
		return (15);
	return (c - 48);
}

int	ft_atoi_hex(char *str)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (str[i] == '0' || str[i] == 'x')
		i++;
	while (str[i])
	{
		result *= 16;
		result = result + is_hexa(str[i]);
		i++;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * sign);
}
