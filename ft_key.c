/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:38:52 by ibouhiri          #+#    #+#             */
/*   Updated: 2020/01/22 18:32:12 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_rel(int key)
{
	if (key == 13)
		go.front = -1;
	if (key == 1)
		go.back = -1;
	if (key == 0)
		go.left = -1;
	if (key == 2)
		go.right = -1;
	if (key == 123)
		go.cam_left = -1;
	if (key == 124)
		go.cam_right = -1;
	if (key == 53)
		go.esc = -1;
	return (0);
}

int		ft_press(int key)
{
	if (key == 13)
		go.front = 1;
	if (key == 1)
		go.back = 1;
	if (key == 0)
		go.left = 1;
	if (key == 2)
		go.right = 1;
	if (key == 123)
		go.cam_left = 1;
	if (key == 124)
		go.cam_right = 1;
	if (key == 53)
		go.esc = 1;
	return (0);
}

int		ft_x(t_win *ptr)
{
	exit(0);
}

void	ft_hep_spri(t_win *ptr)
{
	g_draw = g_head;
	while (g_head)
	{
		ft_cal_ds(ptr);
		g_head = g_head->next;
	}
	g_head = g_draw;
	if (ptr->argc == 1)
	{
		ft_bmp_file(ptr);
		ft_clean(ptr);
		exit(0);
	}
}
