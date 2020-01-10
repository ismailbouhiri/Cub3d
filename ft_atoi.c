/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:28:19 by ibouhiri          #+#    #+#             */
/*   Updated: 2020/01/10 11:05:47 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_initionsation1(t_win *ptr)
{
	ptr->off_y = 0;
	ptr->offs_x = 0;
	ptr->offs_y = 0;
	ptr->count = 0;
}

void	ft_color(t_win *ptr)
{
	int *adrr;
	int a;

	if (ptr->up && ptr->true_h)
	{
		adrr = (int *)mlx_get_data_addr(ptr->img_xpm_x_n, &a, &a, &a);
		ptr->offs_y = ptr->y_img_x / (float)(ptr->y_end - ptr->y_start);
		ptr->color = adrr[((int)ptr->offs_x +
		(int)(ptr->off_y) * ptr->y_img_x)];
	}
	else if (ptr->down && ptr->true_h)
	{
		adrr = (int*)mlx_get_data_addr(ptr->img_xpm_x1_s, &a, &a, &a);
		ptr->offs_y = ptr->y_img_x1 / (float)(ptr->y_end - ptr->y_start);
		ptr->color = adrr[((int)ptr->offs_x +
		(int)(ptr->off_y) * ptr->y_img_x1)];
	}
	ft_color2(ptr);
}

void	ft_texture(t_win *ptr)
{
	ptr->img_xpm_x_n = mlx_xpm_file_to_image(ptr->mlx_ptr, ptr->texture_n,
	&ptr->x_img_x, &ptr->y_img_x);
	ptr->img_xpm_x1_s = mlx_xpm_file_to_image(ptr->mlx_ptr, ptr->texture_s,
	&ptr->x_img_x1, &ptr->y_img_x1);
	ptr->img_xpm_x2_e = mlx_xpm_file_to_image(ptr->mlx_ptr, ptr->texture_e,
	&ptr->x_img_x2, &ptr->y_img_x2);
	ptr->img_xpm_x3_w = mlx_xpm_file_to_image(ptr->mlx_ptr, ptr->texture_w,
	&ptr->x_img_x3, &ptr->y_img_x3);
	if (ptr->img_xpm_x1_s == NULL || ptr->img_xpm_x2_e == NULL ||
	ptr->img_xpm_x3_w == NULL || ptr->img_xpm_x_n == NULL)
	{
		perror("error\n(aucun texture)");
		exit(0);
	}
}

void	ft_color2(t_win *ptr)
{
	int *adrr;
	int a;

	if (ptr->true_v && ptr->left)
	{
		adrr = (int *)mlx_get_data_addr(ptr->img_xpm_x3_w, &a, &a, &a);
		ptr->offs_y = ptr->y_img_x2 / (float)(ptr->y_end - ptr->y_start);
		ptr->color = adrr[((int)ptr->offs_x +
		(int)(ptr->off_y) * ptr->y_img_x2)];
	}
	else if (ptr->true_v && ptr->right)
	{
		adrr = (int *)mlx_get_data_addr(ptr->img_xpm_x2_e, &a, &a, &a);
		ptr->offs_y = ptr->y_img_x3 / (float)(ptr->y_end - ptr->y_start);
		ptr->color = adrr[((int)ptr->offs_x + (int)(ptr->off_y)
		* ptr->y_img_x3)];
	}
}

size_t	ft_map_strlen(const char *s)
{
	size_t	i;
	int		x;

	x = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ')
			x++;
		i++;
	}
	return (x);
}
