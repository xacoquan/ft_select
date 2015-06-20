/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 07:34:22 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/18 22:40:28 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		checkmod(char *buf, t_data *data, t_list *list)
{
	t_file	*tmp;

	tmp = list->first;
	if (buf[0] == 32 && buf[1] == 0 && buf[2] == 0)
	{
		while (tmp != NULL)
		{
			if (data->current == tmp->id)
			{
				if (tmp->selected == 1)
					tmp->selected = 0;
				else
				{
					tmp->selected = 1;
					if (data->current != list->last->id)
						data->current = data->current + 1;
				}
				return ;
			}
			tmp = tmp->next;
		}
	}
}

static void		select_all(char *buf, t_list *list)
{
	t_file		*tmp;

	if (buf[0] == 97 && buf[1] == 0 && buf[2] == 0)
	{
		tmp = list->first;
		while (tmp)
		{
			if (tmp->selected == 0)
				tmp->selected = 1;
			tmp = tmp->next;
		}
	}
}

static void		unselect_all(char *buf, t_list *list)
{
	t_file		*tmp;

	if (buf[0] == 115 && buf[1] == 0 && buf[2] == 0)
	{
		tmp = list->first;
		while (tmp)
		{
			if (tmp->selected == 1)
				tmp->selected = 0;
			tmp = tmp->next;
		}
	}
}

static void		inverse(char *buf, t_list *list)
{
	t_file		*tmp;

	if (buf[0] == 105 && buf[1] == 0 && buf[2] == 0)
	{
		tmp = list->first;
		while (tmp)
		{
			if (tmp->selected == 0)
				tmp->selected = 1;
			else if (tmp->selected == 1)
				tmp->selected = 0;
			tmp = tmp->next;
		}
	}
}

void			list(char *buf, t_data *data, t_list *liste)
{
	get_pos(buf, data, liste);
	checkmod(buf, data, liste);
	checkdel(buf, data, liste);
	select_all(buf, liste);
	unselect_all(buf, liste);
	inverse(buf, liste);
}
