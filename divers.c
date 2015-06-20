/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 07:08:14 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/18 22:39:05 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_error(const char *name)
{
	write(2, name, ft_strlen(name));
	exit(0);
}

int			tputs_putchar(int c)
{
	write(get_fd_tty(), &c, 1);
	return (1);
}

int			get_fd_tty(void)
{
	static int		fd = -1;

	if (fd == -1)
		fd = open("/dev/tty", O_WRONLY);
	return (fd);
}

void		checksignal(void)
{
	signal(SIGWINCH, &treat_signal);
	signal(SIGTSTP, &treat_signal);
	signal(SIGCONT, &treat_signal);
	signal(SIGINT, &treat_signal);
	signal(SIGTERM, &treat_signal);
	signal(SIGTTIN, &treat_signal);
}
