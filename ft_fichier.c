/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fichier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 14:33:50 by ibouhiri          #+#    #+#             */
/*   Updated: 2020/01/21 20:08:16 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

char	*ft_map_strdup(const char *s1)
{
	char	*p;
	size_t	i;
	size_t	x;

	x = 0;
	i = ft_map_strlen(s1);
	if (!(p = (char*)malloc((i + 1) * sizeof(char))))
		return (0);
	i = 0;
	while (s1[i])
	{
		if (s1[i] != ' ')
			p[x++] = s1[i];
		i++;
	}
	p[x] = '\0';
	return (p);
}

void	ft_check_map(t_win *ptr)
{
	int		fd;
	char	*line;
	int		i;

	if ((fd = open(*ptr->file, O_RDONLY)) < 0)
		ft_error(ptr, 3);
	while ((i = get_next_line(fd, &line)) != -1)
	{
		if (line[0] == 'F' || line[0] == 'C')
			ft_rgb(ptr, line);
		ft_map_help(ptr, line);
		if (i == 0)
			fd = open("abcd", O_RDONLY);
	}
}

void	ft_resulotion(t_win *ptr, char *line)
{
	int i;

	i = 3;
	ptr->size_map_x = 0;
	ptr->size_map_y = 0;
	ptr->size_map_x = ft_atoi(line);
	line++;
	line++;
	while (*line != ' ' && *line != '\0')
		line++;
	ptr->size_map_y = ft_atoi(line);
	if (ptr->size_map_x <= 0 || ptr->size_map_y <= 0)
		ft_error(ptr, 4);
	if (ptr->size_map_x > 2560)
		ptr->size_map_x = 2560;
	if (ptr->size_map_y > 1440)
		ptr->size_map_y = 1440;
}

void	ft_help_player(t_win *ptr, int *mapx, int *mapy)
{
	if (ptr->map[0][*mapx] != '1' || ptr->map[ptr->size_y - 1][*mapx] != '1' ||
	ptr->map[*mapy][0] != '1' || ptr->map[*mapy][ptr->size_x - 1] != '1')
	{
		ft_clean(ptr);
		ft_error(ptr, 2);
	}
	if (ptr->map[*mapy][*mapx] == 'N' || ptr->map[*mapy][*mapx] == 'S' ||
	ptr->map[*mapy][*mapx] == 'E' || ptr->map[*mapy][*mapx] == 'W')
	{
		ptr->x_origine = ptr->x + ptr->size_square / 2;
		ptr->y_origine = ptr->y + ptr->size_square / 2;
		if (ptr->map[*mapy][*mapx] == 'N')
			ptr->angle = 270;
		if (ptr->map[*mapy][*mapx] == 'S')
			ptr->angle = 90;
		if (ptr->map[*mapy][*mapx] == 'W')
			ptr->angle = 0;
		if (ptr->map[*mapy][*mapx] == 'E')
			ptr->angle = 180;
		ptr->count++;
	}
	ft_what(ptr, mapx, mapy);
}

void	ft_swap_ds(void)
{
	float	a;
	float	b;
	t_list	*sp1;

	g_tmp = g_head;
	while (g_tmp)
	{
		a = g_tmp->ds_sprit;
		sp1 = g_tmp->next;
		while (sp1)
		{
			if (sp1->ds_sprit > a)
			{
				ft_swap(&sp1->ds_sprit, &g_tmp->ds_sprit);
				ft_swap(&sp1->y_sprit, &g_tmp->y_sprit);
				ft_swap(&sp1->x_sprit, &g_tmp->x_sprit);
			}
			sp1 = sp1->next;
		}
		g_tmp = g_tmp->next;
	}
}
