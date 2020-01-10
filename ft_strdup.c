/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 11:30:07 by ibouhiri          #+#    #+#             */
/*   Updated: 2020/01/10 11:07:24 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	i;
	size_t	x;

	x = 0;
	i = ft_strlen(s1);
	if (!(p = (char*)malloc(i * sizeof(char) + 1)))
		return (0);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

void	ft_wall3d(t_win *ptr)
{
	ptr->x = 0;
	ptr->origine_angle = ptr->angle;
	ptr->angle -= 30;
	while (ptr->x < ptr->size_map_x)
	{
		ptr->y = 0;
		ptr->off_y = 0;
		ft_calcul_wall(ptr);
		ft_draw_line(ptr);
		ptr->x++;
		ptr->angle += ptr->size_square / ptr->size_map_x;
	}
	ptr->angle = ptr->origine_angle;
}

void	ft_playerposition(t_win *ptr)
{
	int mapx;
	int mapy;

	ptr->x = 0;
	ptr->y = 0;
	mapx = 0;
	mapy = 0;
	ptr->count = 0;
	while (ptr->map[mapy][mapx] != '\0')
	{
		ft_help_player(ptr, &mapx, &mapy);
		ptr->x += ptr->size_square;
		if (mapx == ptr->size_x - 1)
		{
			ptr->y += ptr->size_square;
			ptr->x = 0;
			mapx = -1;
			mapy += 1;
		}
		mapx++;
	}
}

void	ft_draw_line(t_win *ptr)
{
	int count;

	count = ptr->y_start;
	while (ptr->y < ptr->size_map_y)
	{
		if (ptr->y < ptr->y_start)
		{
			ptr->color = 0x00FFF6;
			img_put(ptr->x, ptr->y, ptr);
		}
		else if (ptr->y >= ptr->y_end)
		{
			ptr->color = 0xFF7300;
			img_put(ptr->x, ptr->y, ptr);
		}
		else if (count >= ptr->y_start && count < ptr->y_end)
		{
			ft_color(ptr);
			img_put(ptr->x, count, ptr);
			ptr->off_y += ptr->offs_y;
			ptr->y = count++;
		}
		ptr->y++;
	}
}

void	ft_calcul_wall(t_win *ptr)
{
	ptr->norangle = ft_normalizangle(ptr->angle);
	ft_herozontal(ptr);
	ft_vertical(ptr);
	ptr->rayon *= cos((ptr->angle - ptr->origine_angle) * M_PI / 180);
	ptr->distancepplane = (ptr->size_map_x / 2) / tan(fov_angle / 2);
	ptr->wallstriph = (ptr->size_square / ptr->rayon) * ptr->distancepplane;
	ptr->y_start = (ptr->size_map_y / 2) - (ptr->wallstriph / 2);
	ptr->y_end = (ptr->size_map_y / 2) + (ptr->wallstriph / 2);
}
