/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 10:23:28 by ibouhiri          #+#    #+#             */
/*   Updated: 2020/01/03 11:39:33 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		t;
	int		lenofs1;
	int		lenofs2;
	char	*pointeur;

	t = 0;
	lenofs1 = ft_strlen(s1);
	lenofs2 = ft_strlen(s2);
	pointeur = (char*)malloc((lenofs1 + lenofs2) * sizeof(char) + 1);
	if (!pointeur)
		return (0);
	while (lenofs1--)
	{
		pointeur[t] = s1[t];
		t++;
	}
	lenofs1 = 0;
	while (lenofs2--)
		pointeur[t++] = s2[lenofs1++];
	pointeur[t] = '\0';
	return (pointeur);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;
	int		x;

	x = 0;
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		ft_position(char *dst)
{
	int i;

	i = 0;
	if (dst == NULL)
		return (i);
	while (dst[i])
	{
		if (dst[i] == '\n')
		{
			dst[i] = '\0';
			return (i);
		}
		i++;
	}
	return (i);
}

char	*ft_devision(char *dst, char *src)
{
	int i;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int		ft_check(char *dst)
{
	int i;

	i = 0;
	if (dst[i] == '\0')
		return (1);
	while (dst[i])
	{
		if (dst[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}
