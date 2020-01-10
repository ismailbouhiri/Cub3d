/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:54:18 by ibouhiri          #+#    #+#             */
/*   Updated: 2020/01/10 11:15:37 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_chosethepoint(t_win *ptr)
{
	float	distanceh;
	float	distancev;

	ptr->true_v = 0;
	ptr->true_h = 0;
	distanceh = sqrt((ptr->xherowall - ptr->x_origine) * (ptr->xherowall -
	ptr->x_origine) + (ptr->yherowall - ptr->y_origine) * (ptr->yherowall -
	ptr->y_origine));
	distancev = sqrt((ptr->xintercept - ptr->x_origine) * (ptr->xintercept -
	ptr->x_origine) + (ptr->yintercept - ptr->y_origine) * (ptr->yintercept -
	ptr->y_origine));
	if (distanceh > distancev)
	{
		ptr->true_v = 1;
		ptr->offs_x = fmod(ptr->yintercept, ptr->size_square);
		ptr->rayon = distancev;
	}
	else if (distanceh <= distancev)
	{
		ptr->rayon = distanceh;
		ptr->offs_x = fmod(ptr->xherowall, ptr->size_square);
		ptr->true_h = 1;
	}
}

void	ft_vertcalcul(t_win *ptr)
{
	ptr->xstep = ptr->size_square;
	if (ptr->left == 1)
		ptr->xstep *= -1;
	ptr->ystep = ptr->size_square * tan(ptr->alpha);
	if (ptr->up == 1 && ptr->ystep > 0)
		ptr->ystep *= -1;
	if (ptr->down == 1 && ptr->ystep < 0)
		ptr->ystep *= -1;
}

void	ft_readmap(t_win *ptr)
{
	int		fd;
	int		y;
	int		i;
	char	*line;

	y = 0;
	i = 0;
	ft_check_map(ptr);
	ptr->map = malloc(sizeof(char**) * ptr->size_y + 1);
	fd = open(*ptr->file, O_RDONLY);
	while ((i = get_next_line(fd, &line)) != -1)
	{
		ft_colotex(ptr, line);
		if (line[0] == '0' || line[0] == '1')
			ptr->map[y++] = ft_map_strdup(line);
		if (i == 0)
			fd = open("asc.as", O_RDONLY);
	}
	ptr->map[y] = ft_strdup("\0");
	if (ptr->size_map_x == 0 || ptr->size_map_y == 0)
		ft_error(2);
	if (ptr->size_map_x > 2560)
		ptr->size_map_x = 2560;
	if (ptr->size_map_y > 1440)
		ptr->size_map_y = 1440;
}