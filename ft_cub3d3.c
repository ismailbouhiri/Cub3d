/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:28:19 by ibouhiri          #+#    #+#             */
/*   Updated: 2020/01/23 14:49:10 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		if (res > 2147483648 && sign == -1)
			return (0);
		if (res > 2147483647 && sign == 1)
			return (-1);
		i++;
	}
	return (res * sign);
}

char	*ft_memcpy(char *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*s2;
	char		*s1;

	i = 0;
	s1 = dst;
	s2 = src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dst);
}

int		ft_check_arg2(int argc, char *dst)
{
	char	*str;
	int		j;
	int		i;

	i = 0;
	j = 0;
	str = ".cub\0";
	while (dst[i] && str[j])
	{
		if (dst[i] == str[j])
			j++;
		i++;
	}
	if (j != 4 || dst[i] != '\0')
		return (1);
	return (0);
}

int		ft_check_arg(int argc, char *dst, int a)
{
	int		i;
	char	*str;
	int		j;

	i = 0;
	j = 0;
	if (a == 1)
	{
		str = "--save";
		if (argc == 3)
			while (str[i])
			{
				if (dst[i] != str[i])
					return (1);
				i++;
			}
	}
	else
		return (ft_check_arg2(argc, dst));
	return (0);
}

void	ft_move(t_win *ptr)
{
	float speed;
	float me;

	speed = 5;
	me = ptr->angle;
	me -= 90;
	ptr->wall = ft_wallstop(ptr, 2 * cos(me * M_PI / 180) * speed
	+ ptr->x_origine, 2 * sin(me * M_PI / 180) * speed + ptr->y_origine);
	if (go.left == 1 && ptr->wall != '2' && ptr->wall != '1')
	{
		ptr->x_origine = cos(me * M_PI / 180) * speed + ptr->x_origine;
		ptr->y_origine = sin(me * M_PI / 180) * speed + ptr->y_origine;
	}
	ptr->wall = ft_wallstop(ptr, 2 * -cos(me * M_PI / 180) * speed
	+ ptr->x_origine, 2 * -sin(me * M_PI / 180) * speed + ptr->y_origine);
	if (go.right == 1 && ptr->wall != '2' && ptr->wall != '1')
	{
		ptr->x_origine = -cos(me * M_PI / 180) * speed + ptr->x_origine;
		ptr->y_origine = -sin(me * M_PI / 180) * speed + ptr->y_origine;
	}
	if (go.cam_right == 1)
		ptr->origine_angle += 5;
	if (go.cam_left == 1)
		ptr->origine_angle -= 5;
}
