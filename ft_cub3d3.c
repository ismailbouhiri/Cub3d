/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:28:19 by ibouhiri          #+#    #+#             */
/*   Updated: 2020/01/22 15:33:38 by ibouhiri         ###   ########.fr       */
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

int		ft_check_arg(int argc, char *dst)
{
	int		i;
	char	*str;

	str = "--save";
	i = 0;
	if (argc == 3)
	{
		while (str[i])
		{
			if (dst[i] != str[i])
				return (1);
			i++;
		}
	}
	return (0);
}
