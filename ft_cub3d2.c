/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 20:35:17 by ibouhiri          #+#    #+#             */
/*   Updated: 2020/01/10 11:08:37 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_keybord(int key, t_win *ptr)
{
	clock_t b;
	clock_t e;

	b = clock();
	if (ptr->angle == 360 || ptr->angle == -360)
		ptr->angle = 0;
	if (key == 53)
		exit(0);
	if (key == 0 || key == 13 || key == 1 || key == 2)
	{
		ft_keypress(key, ptr);
		mlx_destroy_image(ptr->mlx_ptr, ptr->img);
		ft_gestion(ptr);
	}
	e = clock();
	printf("fps: %d\n", (int)(1 / ((double)(e - b) / CLOCKS_PER_SEC)));
	return (1);
}

void	ft_keypress(int key, t_win *ptr)
{
	float speed;

	speed = 15;
	if (key == 2)
		ptr->angle += 5;
	if (key == 0)
		ptr->angle -= 5;
	ptr->wall = ft_wallstop(ptr, 3 * cos(ptr->angle * M_PI / 180) * speed
	+ ptr->x_origine, 3 * sin(ptr->angle * M_PI / 180) * speed +
	ptr->y_origine);
	if (key == 13 && ptr->wall != '1')
	{
		ptr->x_origine = cos(ptr->angle * M_PI / 180) * speed + ptr->x_origine;
		ptr->y_origine = sin(ptr->angle * M_PI / 180) * speed + ptr->y_origine;
	}
	ptr->wall = ft_wallstop(ptr, 3 * -cos(ptr->angle * M_PI / 180) * speed +
	ptr->x_origine, 3 * -sin(ptr->angle * M_PI / 180) * speed + ptr->y_origine);
	if (key == 1 && ptr->wall != '1')
	{
		ptr->x_origine = -cos(ptr->angle * M_PI / 180) * speed + ptr->x_origine;
		ptr->y_origine = -sin(ptr->angle * M_PI / 180) * speed + ptr->y_origine;
	}
}

char	ft_wallstop(t_win *ptr, float x, float y)
{
	int x_position;
	int y_position;

	x_position = (int)(x / ptr->size_square);
	y_position = (int)(y / ptr->size_square);
	if (x_position < ptr->size_x && y_position < ptr->size_y && y_position >= 0
	&& x_position >= 0)
		return (ptr->map[y_position][x_position]);
	return ('3');
}
