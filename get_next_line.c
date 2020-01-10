/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:09:25 by ibouhiri          #+#    #+#             */
/*   Updated: 2019/12/30 19:54:35 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static	void	ft_allocation(char **stock)
{
	*stock = (char *)malloc(sizeof(char));
	*stock[0] = '\0';
}

static	int		ft_read(char **stock, int fd)
{
	char	*buff;
	int		byte;
	char	*tmp;

	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	buff[0] = '\0';
	if (!*stock)
		ft_allocation(stock);
	while (ft_check(buff) && ft_check(*stock))
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == 0 || byte == -1)
		{
			free(buff);
			return (byte);
		}
		buff[byte] = '\0';
		tmp = *stock;
		if (!(*stock = ft_strjoin(*stock, buff)))
			return (-1);
		free(tmp);
	}
	free(buff);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char	*stock;
	int			res;
	int			p;
	char		*tmp;

	res = ft_read(&stock, fd);
	if (res == -1)
		return (res);
	p = ft_position(stock);
	if (!(*line = (char *)malloc(sizeof(char) * (p + 1))))
		return (-1);
	ft_devision(*line, stock);
	tmp = stock;
	if (!(stock = ft_strdup(stock + (p + 1))))
		return (-1);
	free(tmp);
	if (!res)
	{
		free(stock);
		stock = NULL;
	}
	return (res);
}
