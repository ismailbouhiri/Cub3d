/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:28:19 by ibouhiri          #+#    #+#             */
/*   Updated: 2020/01/22 12:22:32 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_initionsation1(t_win *ptr)
{
	ptr->off_y = 0;
	ptr->offs_x = 0;
	ptr->offs_y = 0;
	ptr->count = 0;
	ptr->s_y = 0;
	ptr->s_x = 0;
	g_head = NULL;
	g_new = NULL;
	ptr->x_sp = 0;
	ptr->y_sp = 0;
	ptr->sp_dr = 0;
	ptr->argc = 0;
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
	ptr->img_xpm_sprit = mlx_xpm_file_to_image(ptr->mlx_ptr, ptr->sprit,
	&ptr->s_x, &ptr->s_y);
	if (ptr->img_xpm_x1_s == NULL || ptr->img_xpm_x2_e == NULL ||
	ptr->img_xpm_x3_w == NULL || ptr->img_xpm_x_n == NULL ||
	ptr->img_xpm_sprit == NULL)
	{
		ft_clean(ptr);
		perror("error\n(aucun texture)");
		exit(0);
	}
	free(ptr->texture_n);
	free(ptr->texture_s);
	free(ptr->sprit);
	free(ptr->texture_e);
	free(ptr->texture_w);
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
	g_tmp = g_head;
	while (g_tmp)
	{
		g_tmp->ds_sprit = sqrt((g_tmp->x_sprit - ptr->x_origine) *
		(g_tmp->x_sprit - ptr->x_origine) + (g_tmp->y_sprit - ptr->y_origine)
		* (g_tmp->y_sprit - ptr->y_origine));
		g_tmp = g_tmp->next;
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
