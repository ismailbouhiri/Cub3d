/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cubtext.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 14:34:02 by ibouhiri          #+#    #+#             */
/*   Updated: 2020/01/06 16:55:52 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_error(int a)
{
	if (a == 1)
		perror("error\n(player)");
	if (a == 2)
		perror("error\n(Map)");
	if (a == 3)
		perror("error\n(fille)");
	if (a == 4)
		perror("error\n(resolution)");
	exit(0);
}

void	ft_colotex(t_win *ptr, char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		ptr->texture_n = ft_map_strdup(line + 2);
	if (line[0] == 'S' && line[1] == 'O')
		ptr->texture_s = ft_map_strdup(line + 2);
	if (line[0] == 'W' && line[1] == 'E')
		ptr->texture_w = ft_map_strdup(line + 2);
	if (line[0] == 'E' && line[1] == 'A')
		ptr->texture_e = ft_map_strdup(line + 2);
	if (line[0] == 'R')
		ft_resulotion(ptr, line + 2);
}

