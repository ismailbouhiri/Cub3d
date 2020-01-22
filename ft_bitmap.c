/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:55:39 by ibouhiri          #+#    #+#             */
/*   Updated: 2020/01/22 15:50:35 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void		ft_bmp_file(t_win *ptr)
{
	t_str bmp;

	ft_ini_bmp(ptr, &bmp);
	bmp.header = (char *)ft_calloc(54, sizeof(unsigned char));
	ft_memcpy(bmp.header, "BM", 2);
	ft_memcpy(bmp.header + 2, &bmp.filesize, 4);
	ft_memcpy(bmp.header + 10, &bmp.ffbits, 4);
	ft_memcpy(bmp.header + 14, &bmp.bisize, 4);
	ft_memcpy(bmp.header + 18, &bmp.width, 4);
	ft_memcpy(bmp.header + 22, &bmp.height, 4);
	ft_memcpy(bmp.header + 26, &bmp.biplanes, 2);
	ft_memcpy(bmp.header + 28, &bmp.bitcount, 2);
	ft_memcpy(bmp.header + 34, &bmp.imagesize, 4);
	ft_bmp_next(ptr, &bmp);
}

void		ft_bmp_next(t_win *ptr, t_str *bmp)
{
	unsigned char	*buf;
	int				row;
	int				col;
	long long		a;
	int				i;

	buf = malloc(bmp->imagesize);
	row = bmp->height - 1;
	i = 0;
	while (row >= 0)
	{
		col = 0;
		while ((unsigned int)col < bmp->width)
		{
			a = ft_get_img_pix(ptr, col, i);
			buf[row * bmp->width_in_bytes + col * 3 + 0] = fmod(a, 256);
			buf[row * bmp->width_in_bytes + col * 3 + 1] = fmod((a / 256), 256);
			buf[row * bmp->width_in_bytes + col * 3 + 2] = fmod(a / 256 / 256
			, 256);
			col++;
		}
		row--;
		i++;
	}
	ft_bmp_last(bmp, buf);
}

void		ft_bmp_last(t_str *bmp, unsigned char *buf)
{
	int fd;

	fd = open("Cub3D.bmp", O_WRONLY | O_CREAT, 500);
	write(fd, bmp->header, 54);
	write(fd, buf, bmp->imagesize);
	free(buf);
}

long long	ft_get_img_pix(t_win *ptr, int x, int y)
{
	int a;
	int *add;

	add = (int *)mlx_get_data_addr(ptr->img, &a, &a, &a);
	return (add[y * ptr->size_map_x + x]);
}
