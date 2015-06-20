/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 22:53:00 by xacoquan          #+#    #+#             */
/*   Updated: 2015/05/24 17:05:20 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_file		*init_node(char **argv, int i)
{
	t_file	*news;

	if ((news = (t_file *)malloc(sizeof(*news))) == NULL)
		return (NULL);
	news->name = ft_strdup(argv[i]);
	news->id = i;
	news->selected = 0;
	news->next = NULL;
	news->prev = NULL;
	return (news);
}

t_list				*ft_list_init(void)
{
	t_list		*new;

	if ((new = (t_list *)malloc(sizeof(*new))) == NULL)
		exit(0);
	new->first = NULL;
	new->last = NULL;
	return (new);
}

void				add_to_list(t_list *list, char **argv, int i)
{
	t_file	*node;

	node = init_node(argv, i);
	if (list->first == NULL)
	{
		list->first = node;
		list->last = node;
	}
	else
	{
		node->prev = list->last;
		list->last->next = node;
		list->last = node;
		node->next = NULL;
	}
}

static int			get_len(t_list *liste)
{
	t_file	*elem;
	int		len;

	len = 0;
	elem = liste->first;
	while (elem)
	{
		if (len < ft_strlen(elem->name))
			len = ft_strlen(elem->name);
		elem = elem->next;
	}
	return (len);
}

t_data				*ft_init_data(t_list *liste)
{
	t_data				*news;
	struct winsize		win;

	ioctl(0, TIOCGWINSZ, &win);
	if ((news = (t_data *)malloc(sizeof(*news))) == NULL)
		return (NULL);
	news->row = (int)win.ws_row;
	news->col = (int)win.ws_col;
	news->size = 0;
	news->len = get_len(liste);
	news->current = 0;
	news->cl_str = tgetstr("cl", NULL);
	news->us_str = tgetstr("us", NULL);
	news->so_str = tgetstr("so", NULL);
	news->ue_str = tgetstr("ue", NULL);
	news->se_str = tgetstr("se", NULL);
	news->cm_str = tgetstr("cm", NULL);
	news->vb_str = tgetstr("vb", NULL);
	return (news);
}
