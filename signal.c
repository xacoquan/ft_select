/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 07:41:13 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/18 22:43:36 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		sigkill(void)
{
	struct termios		*old;
	struct termios		*term;

	term = singleton_newterm(NULL);
	old = singleton_oldterm(NULL);
	tputs(tgetstr("te", NULL), 1, tputs_putchar);
	tputs(tgetstr("ve", NULL), 1, tputs_putchar);
	term->c_lflag |= ICANON;
	term->c_lflag |= ECHO;
	tcsetattr(0, 0, old);
	exit(0);
}

static void		sigcont(void)
{
	t_list			*liste;
	t_data			*data;
	struct termios	*news;

	liste = singleton_liste(NULL);
	data = singleton_data(NULL);
	news = singleton_newterm(NULL);
	tcsetattr(0, 0, news);
	tputs(tgetstr("vi", NULL), 1, tputs_putchar);
	tputs(tgetstr("ti", NULL), 1, tputs_putchar);
	print_list(data, liste);
	signal(SIGTSTP, treat_signal);
}

static void		sigstp(void)
{
	char			sim[2];
	struct termios	*old;
	struct termios	*news;

	old = singleton_oldterm(NULL);
	news = singleton_newterm(NULL);
	sim[0] = news->c_cc[VSUSP];
	sim[1] = 0;
	tputs(tgetstr("ve", NULL), 1, tputs_putchar);
	tputs(tgetstr("te", NULL), 1, tputs_putchar);
	tcsetattr(0, 0, old);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, sim);
}

static void		sigredim(void)
{
	struct winsize		win;
	t_list				*liste;
	t_data				*data;

	liste = singleton_liste(NULL);
	data = singleton_data(NULL);
	ioctl(0, TIOCGWINSZ, &win);
	data->row = (int)win.ws_row;
	data->col = (int)win.ws_col;
	tputs(data->cl_str, 1, tputs_putchar);
	print_list(data, liste);
}

void			treat_signal(int sig)
{
	if (sig == SIGWINCH)
		sigredim();
	if (sig == SIGTSTP)
		sigstp();
	if (sig == SIGCONT)
		sigcont();
	if (sig == SIGINT || sig == SIGTERM || sig == SIGTTIN)
		sigkill();
}
