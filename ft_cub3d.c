/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 20:47:17 by ibouhiri          #+#    #+#             */
/*   Updated: 2020/01/10 11:14:30 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		main(int argc, char **argv)
{
	t_win *ptr;

	if (argc != 2)
	{
		perror("error\n(argument)");
		exit(0);
	}
	ptr = malloc(sizeof(t_win));
	ptr->file = &argv[1];
	ft_initionsation(ptr);
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
