/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cubtext.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 14:34:02 by ibouhiri          #+#    #+#             */
/*   Updated: 2020/01/21 20:05:19 by ibouhiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_error(t_win *ptr, int a)
{
	if (a == 1)
		perror("error\n(player)");
	if (a == 2)
		perror("error\n(Map)");
	if (a == 3)
		perror("error\n(fille)");
	if (a == 4)
		perror("error\n(resolution)");
	if (a == 5)
		perror("error\n(color)");
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
	if (line[0] == 'S')
		ptr->sprit = ft_map_strdup(line + 1);
	if (line[0] == 'R')
		ft_resulotion(ptr, line + 2);
}

t_list	*ft_lstnew(float x, float y, float ds)
{
	t_list *tmp;

	if (!(tmp = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	tmp->x_sprit = x;
	tmp->y_sprit = y;
	tmp->ds_sprit = ds;
	tmp->next = NULL;
	return (tmp);
}

void	ft_lstadd_back(t_list **head, t_list *new)
{
	t_list *str;

	if (*head == NULL)
	{
		*head = new;
		new->next = NULL;
	}
	else
	{
		str = *head;
		while (str->next != NULL)
			str = str->next;
		str->next = new;
		new->next = NULL;
	}
}

void	ft_sprit_corr(t_win *ptr)
{
	g_new = ft_lstnew(ptr->x + (ptr->size_square / 2), ptr->y +
	(ptr->size_square / 2), 0);
	ft_lstadd_back(&g_head, g_new);
}
