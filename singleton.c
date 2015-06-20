/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 07:07:10 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/18 22:43:35 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_termios			*singleton_oldterm(t_termios *term)
{
	static struct termios	*old;

	if (term != NULL)
		old = term;
	return (old);
}

t_termios			*singleton_newterm(t_termios *term)
{
	static struct termios	*new;

	if (term != NULL)
		new = term;
	return (new);
}

t_list				*singleton_liste(t_list *new)
{
	static t_list			*liste;

	if (new != NULL)
		liste = new;
	return (liste);
}

t_data				*singleton_data(t_data *new)
{
	static t_data			*data;

	if (new != NULL)
		data = new;
	return (data);
}
