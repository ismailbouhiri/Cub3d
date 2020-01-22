/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 20:35:17 by ibouhiri          #+#    #+#             */
/*   Updated: 2020/01/22 18:28:30 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_keybord(t_win *ptr)
{
	if (ptr->angle == 360 || ptr->angle == -360)
		ptr->angle = 0;
	if (go.esc == 1)
		exit(0);
	if (go.back == 1 || go.cam_left == 1 || go.cam_right == 1
	|| go.front == 1 || go.left == 1 || go.right == 1)
	{
		ft_keypress(ptr);
		mlx_destroy_image(ptr->mlx_ptr, ptr->img);
		ft_gestion(ptr);
	}
	return (1);
}

void	ft_keypress(t_win *ptr)
{
	float speed;

	speed = 7;
	ptr->origine_angle = ptr->angle;
	ft_move(ptr);
	ptr->wall = ft_wallstop(ptr, 4 * cos(ptr->angle * M_PI / 180) * speed
	+ ptr->x_origine, 4 * sin(ptr->angle * M_PI / 180) * speed +
	ptr->y_origine);
	if (go.front == 1 && ptr->wall != '1' && ptr->wall != '2')
	{
		ptr->x_origine = cos(ptr->angle * M_PI / 180) * speed + ptr->x_origine;
		ptr->y_origine = sin(ptr->angle * M_PI / 180) * speed + ptr->y_origine;
	}
	ptr->wall = ft_wallstop(ptr, 4 * -cos(ptr->angle * M_PI / 180) * speed +
	ptr->x_origine, 4 * -sin(ptr->angle * M_PI / 180) * speed + ptr->y_origine);
	if (go.back == 1 && ptr->wall != '1' && ptr->wall != '2')
	{
		ptr->x_origine = -cos(ptr->angle * M_PI / 180) * speed + ptr->x_origine;
		ptr->y_origine = -sin(ptr->angle * M_PI / 180) * speed + ptr->y_origine;
	}
	ptr->angle = ptr->origine_angle;
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

void	ft_cal_ds(t_win *ptr)
{
	float a;

	ptr->sp_dr = atan2(g_head->y_sprit - ptr->y_origine,
	g_head->x_sprit - ptr->x_origine);
	while (ptr->sp_dr - ptr->angle * (M_PI / 180) > M_PI)
		ptr->sp_dr -= 2 * M_PI;
	while (ptr->sp_dr - ptr->angle * (M_PI / 180) < -M_PI)
		ptr->sp_dr += 2 * M_PI;
	if (ptr->size_map_x > ptr->size_map_y)
		ptr->spt_size = (ptr->size_map_x / g_head->ds_sprit) * ptr->size_square;
	else
		ptr->spt_size = (ptr->size_map_y / g_head->ds_sprit) * ptr->size_square;
	ptr->y_sp = (ptr->size_map_y / 2) - (ptr->spt_size / 2);
	a = ptr->sp_dr - ptr->angle;
	ptr->x_sp = (ptr->sp_dr - ptr->angle * (M_PI / 180)) / g_fov_angle *
	ptr->size_map_x + (ptr->size_map_x / 2 - ptr->spt_size / 2);
	ft_draw_sprit(ptr);
}

void	ft_draw_sprit(t_win *ptr)
{
	int j;
	int *add;
	int a;

	ptr->y = 0;
	j = 0;
	add = (int*)mlx_get_data_addr(ptr->img_xpm_sprit, &a, &a, &a);
	while (ptr->y++ < ptr->spt_size - 1)
	{
		if (ptr->x_sp + ptr->y < 0 || ptr->x_sp + ptr->y > ptr->size_map_x)
			continue;
		if (g_head->ds_sprit >= g_sprit[ptr->x_sp + ((int)ptr->y)] &&
		(g_head->ds_sprit - g_sprit[ptr->x_sp + ((int)ptr->y)]) > 40)
			continue;
		j = 0;
		while (j++ < ptr->spt_size - 1)
		{
			if (ptr->y_sp + j < 0 || ptr->y_sp + j > ptr->size_map_y)
				continue;
			ptr->color = add[(ptr->s_x * (j * ptr->s_y / ptr->spt_size))
			+ (((int)ptr->y) * ptr->s_x / ptr->spt_size)];
			if (ptr->color != add[0])
				img_put((ptr->x_sp + ((int)ptr->y)), ptr->y_sp + j, ptr);
		}
	}
}
