/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_init_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 07:11:01 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/18 22:43:34 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			select_close_term(t_termios *t, t_termios *o)
{
	tputs(tgetstr("ve", NULL), 1, tputs_putchar);
	t->c_lflag |= ICANON;
	t->c_lflag |= ECHO;
	tcsetattr(0, 0, o);
	exit(0);
}

void			select_init_term(t_termios *t, t_termios *o)
{
	char	*tname;

	if ((tname = getenv("TERM")) == NULL)
		ft_error("Error");
	tgetent(NULL, tname);
	tcgetattr(0, o);
	singleton_oldterm(o);
	tcgetattr(0, t);
	t->c_lflag &= ~(ICANON);
	t->c_lflag &= ~(ECHO);
	t->c_cc[VMIN] = 1;
	t->c_cc[VTIME] = 0;
	singleton_newterm(t);
	tcsetattr(0, 0, t);
	tputs(tgetstr("vi", NULL), 1, tputs_putchar);
}
