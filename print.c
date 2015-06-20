/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 07:51:16 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/18 22:43:36 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		print_argv(t_data *d, t_list *liste)
{
	int		y;
	int		c;
	t_file	*elem;

	c = 0;
	elem = liste->first;
	while (elem != NULL)
	{
		y = 1;
		while (y < d->row && elem != NULL)
		{
			tputs(tgoto(d->cm_str, (d->len + 2) * c, y), 1, tputs_putchar);
			if (elem->id == d->current)
				tputs(d->us_str, 1, tputs_putchar);
			if (elem->selected == 1)
				tputs(d->so_str, 1, tputs_putchar);
			ft_putstr_fd(elem->name, get_fd_tty());
			tputs(d->ue_str, 1, tputs_putchar);
			tputs(d->se_str, 1, tputs_putchar);
			elem = elem->next;
			y++;
		}
		c++;
	}
}

static int		check_window(t_data *data, t_list *liste)
{
	int		last;

	last = 0;
	last = ((data->len) + 2) * ((liste->last->id) / (data->row));
	if ((last + data->len) > data->col)
	{
		tputs(data->vb_str, 1, tputs_putchar);
		tputs(tgoto(data->cm_str, 0, 1), 1, tputs_putchar);
		ft_putstr_fd("window too small", get_fd_tty());
		return (1);
	}
	return (0);
}

static void		print_header(t_data *data)
{
	int		i;

	i = 0;
	if (data->col > 18)
	{
		tputs(tgoto(data->cm_str, 0, 0), 1, tputs_putchar);
		tputs(data->so_str, 1, tputs_putchar);
		ft_putstr_fd("ft_select", get_fd_tty());
		while (i < (data->col - 9))
		{
			ft_putchar_fd(' ', get_fd_tty());
			i++;
		}
		tputs(data->se_str, 1, tputs_putchar);
	}
}

int				print_list(t_data *data, t_list *liste)
{
	print_header(data);
	if (check_window(data, liste))
		return (0);
	print_argv(data, liste);
	return (0);
}
