/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_delete_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 07:31:19 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/18 22:40:34 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		delelete_node(t_data *data, t_list *list, t_file *node)
{
	if (node == list->first)
	{
		if (node->next != NULL)
		{
			list->first = node->next;
			node->next->prev = NULL;
		}
		else
		{
			list->first = NULL;
			return ;
		}
	}
	else if (node != list->last)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	else
	{
		list->last = node->prev;
		node->prev->next = NULL;
		data->current = data->current - 1;
	}
}

static void		free_node(t_file *node)
{
	free(node->name);
	free(node);
}

void			checkdel(char *buf, t_data *data, t_list *list)
{
	t_file	*tmp;
	t_file	*save;
	int		check;

	check = 0;
	save = NULL;
	tmp = list->first;
	if ((buf[0] == 126 || buf[0] == 127) && buf[1] == 0 && buf[2] == 0)
	{
		while (tmp)
		{
			if (tmp->id == data->current)
			{
				delelete_node(data, list, tmp);
				data->size = data->size - 1;
				save = tmp;
				check = 1;
			}
			if (check == 1)
				tmp->id = (tmp->id) - 1;
			tmp = tmp->next;
		}
		if (save)
			free_node(save);
	}
}
