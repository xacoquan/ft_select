/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 07:16:41 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/18 22:40:09 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		right(t_data *data)
{
	if ((data->current + (data->row)) <= data->size)
		data->current = data->current + (data->row - 1);
}

static void		left(t_data *data)
{
	if ((data->current - (data->row)) >= 0)
		data->current = (data->current - data->row) + 1;
}

static void		up(t_data *data, t_list *list)
{
	if (data->current == 0)
		data->current = list->last->id;
	else
		data->current = data->current - 1;
}

static void		down(t_data *data, t_list *list)
{
	if (data->current == list->last->id)
		data->current = 0;
	else
		data->current = data->current + 1;
}

int				get_pos(char *buf, t_data *data, t_list *list)
{
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 65)
		up(data, list);
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 66)
		down(data, list);
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 67)
		right(data);
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 68)
		left(data);
	return (0);
}
