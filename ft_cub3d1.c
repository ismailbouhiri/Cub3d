/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:59:51 by ibouhiri          #+#    #+#             */
/*   Updated: 2020/01/06 16:53:42 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_initionsation(t_win *ptr)
{
	ptr->wallstriph = 0;
	ptr->distancepplane = 0;
	ptr->color = 0;
	ptr->xherowall = 0;
	ptr->norangle = 0;
	ptr->rayon = 0;
	ptr->yherowall = 0;
	ptr->angle = 0;
	ptr->x_origine = 0;
	ptr->y_origine = 0;
	ptr->start = 1;
	ptr->mlx_ptr = 0;
	ptr->mlx_win = 0;
	ptr->img = 0;
	ptr->size_map_x = 0;
	ptr->size_map_y = 0;
	ptr->xintercept = 0;
	ptr->yintercept = 0;
	ptr->ystep = 0;
	ptr->xstep = 0;
	ptr->alpha = 0;
	ptr->size_y = 0;
	ptr->size_x = 0;
	ptr->size_square = 60;
	ft_initionsation1(ptr);
}

void	img_put(int x, int y, t_win *ptr)
{
	int		*addr;
	int		a;
	int		dst;

	addr = (int *)mlx_get_data_addr(ptr->img, &a, &a, &a);
	if (x >= 0 && x < ptr->size_map_x && y >= 0 && y < ptr->size_map_y)
		*(addr + (y * (ptr->size_map_x) + x)) = ptr->color;
}

void	ft_gestion(t_win *ptr)
{
	ptr->img = mlx_new_image(ptr->mlx_ptr, ptr->size_map_x, ptr->size_map_y);
	if (ptr->start == 1)
	{
		ft_texture(ptr);
		ft_playerposition(ptr);
		if (ptr->count != 1)
			ft_error(1);
	}
	ptr->start = 0;
	ft_wall3d(ptr);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->mlx_win, ptr->img, 0, 0);
}

void	ft_map_help(t_win *ptr, char *line)
{
	int save;

	save = 0;
	if (line[0] >= '0' && line[0] < '3')
	{
		ptr->size_y++;
		save = ft_map_strlen(line);
	}
	if (line[0] != '0' && line[0] != '1' && ptr->size_y > 0)
		ft_error(2);
	if (ptr->count == 0 && line[0] >= '0' && line[0] < '3')
	{
		ptr->size_x = ft_map_strlen(line);
		ptr->count = 1;
	}
	if (save != ptr->size_x)
		ft_error(2);
}
