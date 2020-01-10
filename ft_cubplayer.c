/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cubplayer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 09:38:40 by ibouhiri          #+#    #+#             */
/*   Updated: 2020/01/04 14:38:57 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

float	ft_normalizangle(float angle)
{
	angle = fmod(angle, 360);
	if (angle < 0)
		angle = 360 + angle;
	return (angle);
}

void	ft_vuangle(t_win *ptr)
{
	ptr->down = 0;
	ptr->up = 0;
	ptr->left = 0;
	ptr->right = 0;
	if (ptr->norangle >= 0 && ptr->norangle < 180)
		ptr->down = 1;
	if (ptr->norangle >= 180 && ptr->norangle <= 360)
		ptr->up = 1;
	if ((ptr->norangle >= 0 && ptr->norangle <= 90) ||
	(ptr->norangle >= 270 && ptr->norangle <= 360))
		ptr->right = 1;
	if (ptr->norangle > 90 && ptr->norangle < 270)
		ptr->left = 1;
}

void	ft_herozontal(t_win *ptr)
{
	ptr->wall = '0';
	ft_vuangle(ptr);
	ptr->yintercept = floor(ptr->y_origine / ptr->size_square)
	* ptr->size_square;
	ptr->yintercept += (ptr->down == 1) ? ptr->size_square : 0;
	ptr->alpha = ptr->norangle * M_PI / 180;
	ptr->xintercept = ptr->x_origine + (ptr->yintercept - ptr->y_origine)
	/ tan(ptr->alpha);
	ft_herocalcul(ptr);
	ptr->yintercept += (ptr->up == 1) ? -1 : 1;
	while (ptr->wall != '1' && ptr->wall != '3')
	{
		ptr->wall = ft_wallstop(ptr, ptr->xintercept, ptr->yintercept);
		if (ptr->wall != '3' && ptr->wall != '1')
		{
			ptr->xintercept += ptr->xstep;
			ptr->yintercept += ptr->ystep;
		}
	}
	ptr->yintercept -= (ptr->up == 1) ? -1 : 1;
	ptr->xherowall = ptr->xintercept;
	ptr->yherowall = ptr->yintercept;
}

void	ft_herocalcul(t_win *ptr)
{
	ptr->ystep = ptr->size_square;
	if (ptr->up == 1)
		ptr->ystep *= -1;
	ptr->xstep = ptr->size_square / tan(ptr->alpha);
	if (ptr->left == 1 && ptr->xstep > 0)
		ptr->xstep *= -1;
	if (ptr->right == 1 && ptr->xstep < 0)
		ptr->xstep *= -1;
}

void	ft_vertical(t_win *ptr)
{
	ptr->wall = '0';
	ptr->xintercept = floor(ptr->x_origine / ptr->size_square) *
	ptr->size_square;
	if (ptr->right == 1)
		ptr->xintercept += ptr->size_square;
	ptr->alpha = ptr->norangle * M_PI / 180;
	ptr->yintercept = ptr->y_origine + (ptr->xintercept - ptr->x_origine) *
	tan(ptr->alpha);
	ft_vertcalcul(ptr);
	ptr->xintercept += (ptr->left == 1) ? -1 : 1;
	while (ptr->wall != '1' && ptr->wall != '3')
	{
		ptr->wall = ft_wallstop(ptr, ptr->xintercept, ptr->yintercept);
		if (ptr->wall != '3' && ptr->wall != '1')
		{
			ptr->xintercept += ptr->xstep;
			ptr->yintercept += ptr->ystep;
		}
	}
	ptr->xintercept -= (ptr->left == 1) ? -1 : 1;
	ft_chosethepoint(ptr);
}
