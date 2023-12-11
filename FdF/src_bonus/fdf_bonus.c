/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facetint <facetint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:27:19 by facetint          #+#    #+#             */
/*   Updated: 2023/12/07 16:54:31 by facetint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"
#include "../ft_printf/ft_printf.h"
#include <fcntl.h>
#include <stdlib.h>
#include "../minilibx/mlx.h"

t_map	*map_init(int fd)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
	{
		close(fd);
		exit(ft_printf("Memory Allocation Error!\n"));
	}
	map->coords_arr = NULL;
	map->colors_arr = NULL;
	map->height = 0;
	map->width = 0;
	return (map);
}

t_data	*fdf_init(t_coord_value **stack, t_map *map, int fd)
{
	t_data	*fdf;

	fdf = (t_data *)malloc(sizeof(t_data));
	if (!fdf)
	{
		close(fd);
		free(map);
		exit(1);
	}
	fdf->mlx_ptr = mlx_init();
	if (!fdf->mlx_ptr)
		free_map_coords(fdf, 1);
	fdf_init_(fdf);
	fdf->mouse = (t_mouse *)malloc(sizeof(t_mouse));
	fdf->camera = 0;
	if (!fdf->mouse)
	{
		close(fd);
		free_map_coords(fdf, 1);
	}
	fdf->coords = *stack;
	return (fdf);
}

void	fdf_init_(t_data *fdf)
{
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "Facetint_FDF");
	if (!fdf->win_ptr)
		free_map_coords(fdf, 1);
	fdf->img = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
	if (!fdf->img)
		free_map_coords(fdf, 1);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &fdf->bits_per_pixel,
			&fdf->size_line, &fdf->endian);
}

t_camera	*camera_init(t_data *fdf)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		free_map_coords(fdf, 1);
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->projection = 0;
	camera->x_offset = 0;
	camera->y_offset = 0;
	camera->z_height = 1;
	camera->zoom = HEIGHT / fdf->map->height / 2;
	return (camera);
}

int	main(int ac, char **av)
{
	int				fd;
	t_coord_value	*coords;
	t_data			*fdf;
	t_map			*map;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd <= 0)
			exit(ft_printf("Incorrect Map File!\n"));
		coords = 0;
		map = map_init(fd);
		fdf = fdf_init(&coords, map, fd);
		fdf->map = map;
		read_map(fd, &coords, fdf);
		convert(&coords, fdf);
		fdf->camera = camera_init(fdf);
		draw(fdf);
		ft_hook_controls(fdf);
		mlx_loop(fdf->mlx_ptr);
	}
	else
		ft_printf("Incorrect Argument Number!\n");
	return (0);
}
