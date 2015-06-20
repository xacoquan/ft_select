/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 22:52:26 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/18 22:39:50 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	exec_select(t_data *data, t_list *liste)
{
	char buf[4];

	ft_strclr(buf);
	while (42)
	{
		tputs(data->cl_str, 1, tputs_putchar);
		if (print_list(data, liste))
			return (0);
		buf[1] = 0;
		buf[2] = 0;
		read(0, buf, 3);
		if (buf[0] == 27 && buf[1] == 0 && buf[2] == 0)
			return (0);
		if (buf[0] == 10 && buf[1] == 0 && buf[2] == 0)
			return (1);
		list(buf, data, liste);
	}
	return (0);
}

static void	print_result(t_list *list)
{
	t_file	*tmp;
	int		result;

	result = 0;
	tmp = list->first;
	while (tmp)
	{
		if (tmp->selected == 1)
		{
			if (result > 0)
				ft_putchar(' ');
			ft_putstr(tmp->name);
			result++;
		}
		tmp = tmp->next;
	}
	if (result != 0)
		ft_putchar('\n');
}

static void	ft_select2(t_data *d, t_list *l, struct termios t, struct termios o)
{
	checksignal();
	tputs(tgetstr("ti", NULL), 1, tputs_putchar);
	exec_select(d, l);
	tputs(tgetstr("te", NULL), 1, tputs_putchar);
	print_result(l);
	select_close_term(&t, &o);
}

static void	ft_select(char **argv)
{
	t_list				*liste;
	t_data				*data;
	int					i;
	struct termios		term;
	struct termios		oldterm;

	i = 1;
	liste = ft_list_init();
	select_init_term(&term, &oldterm);
	while (argv[i])
	{
		add_to_list(liste, argv, i);
		i++;
	}
	data = ft_init_data(liste);
	singleton_liste(liste);
	singleton_data(data);
	ft_select2(data, liste, term, oldterm);
}

int			main(int argc, char **argv)
{
	if (argc > 1)
		ft_select(argv);
	else
		ft_error("ft_select choix1 choix2 choix3 choix4");
	return (0);
}
