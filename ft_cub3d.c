/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 20:47:17 by ibouhiri          #+#    #+#             */
/*   Updated: 2020/01/22 15:31:31 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_rgb_help(t_win *ptr, char *line)
{
	int r;
	int g;
	int b;
	int i;

	i = 2;
	if (line[0] == 'F' && line[1] == ' ')
	{
		r = ft_atoi(line + i);
		while (line[i] != ',')
			i++;
		i++;
		g = ft_atoi(line + i);
		while (line[i] != ',')
			i++;
		i++;
		b = ft_atoi(line + i);
		while (line[i] <= '9' && line[i] >= '0')
			i++;
		i = ft_strlen(line);
		if (i > 13 || b < 0 || b > 255 || r < 0 || r > 255 || g < 0 || g > 255)
			ft_error(ptr, 5);
		ptr->fcolor = (256 * 256) * r + (256 * g) + b;
	}
}

void	ft_rgb(t_win *ptr, char *line)
{
	int r;
	int g;
	int b;
	int i;

	ft_rgb_help(ptr, line);
	i = 2;
	if (line[0] == 'C' && line[1] == ' ')
	{
		r = ft_atoi(line + i);
		while (line[i] != ',')
			i++;
		i++;
		g = ft_atoi(line + i);
		while (line[i] != ',')
			i++;
		i++;
		b = ft_atoi(line + i);
		i = ft_strlen(line);
		if (i > 13 || b < 0 || b > 255 || r < 0 || r > 255 || g < 0 || g > 255)
			ft_error(ptr, 5);
		ptr->ccolor = (256 * 256) * r + 256 * g + b;
	}
}

void	ft_what(t_win *ptr, int *mapx, int *mapy)
{
	if (ptr->map[*mapy][*mapx] != 'N' && ptr->map[*mapy][*mapx] != 'S' &&
	ptr->map[*mapy][*mapx] != 'E' && ptr->map[*mapy][*mapx] != 'W' &&
	ptr->map[*mapy][*mapx] != '1' && ptr->map[*mapy][*mapx] != '0' &&
	ptr->map[*mapy][*mapx] != '2')
	{
		ft_clean(ptr);
		ft_error(ptr, 2);
	}
}

void	ft_ini_bmp(t_win *ptr, t_str *bmp)
{
	bmp->width = ptr->size_map_x;
	bmp->height = ptr->size_map_y;
	bmp->bitcount = 24;
	bmp->width_in_bytes = ((ptr->size_map_x * bmp->bitcount + 31) / 32) * 4;
	bmp->imagesize = bmp->width_in_bytes * ptr->size_map_y;
	bmp->bisize = 40;
	bmp->ffbits = 54;
	bmp->filesize = 54 + bmp->imagesize;
	bmp->biplanes = 1;
}

int		main(int argc, char **argv)
{
	t_win *ptr;
	if (argc > 3 || ft_check_arg(argc, argv[2]))
	{
		perror("error\n(argument)");
		exit(0);
	}
	ptr = malloc(sizeof(t_win));
	ptr->file = &argv[1];
	ft_initionsation(ptr);
	if (argc == 3)
		ptr->argc = 1;
	ft_readmap(ptr);
	ptr->mlx_ptr = mlx_init();
	ptr->mlx_win = mlx_new_window(ptr->mlx_ptr, ptr->size_map_x,
	ptr->size_map_y, "cub3d");
	ft_gestion(ptr);
	mlx_hook(ptr->mlx_win, 2, 0, ft_keybord, ptr);
	mlx_loop(ptr->mlx_ptr);
	free(ptr);
	return (0);
}
