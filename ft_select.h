/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 08:16:32 by xacoquan          #+#    #+#             */
/*   Updated: 2015/03/18 22:40:30 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <libft.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <termios.h>
# include <sys/fcntl.h>
# include <term.h>
# include <curses.h>
# include <termcap.h>
# include <sys/ioctl.h>
# include <signal.h>

typedef struct termios	t_termios;

typedef struct		s_file
{
	char			*name;
	int				id;
	int				selected;
	struct s_file	*next;
	struct s_file	*prev;
}					t_file;

typedef struct		s_list
{
	t_file			*first;
	t_file			*last;
}					t_list;

typedef struct		s_data
{
	int				row;
	int				col;
	int				size;
	int				len;
	int				current;
	char			*cl_str;
	char			*us_str;
	char			*so_str;
	char			*ue_str;
	char			*se_str;
	char			*cm_str;
	char			*vb_str;
}					t_data;

t_list				*ft_list_init(void);
void				add_to_list(t_list *list, char **argv, int i);
t_data				*ft_init_data(t_list *liste);
void				treat_signal(int sig);
void				ft_error(const char *name);
int					tputs_putchar(int c);
int					get_fd_tty(void);
t_termios			*singleton_oldterm(t_termios *term);
t_termios			*singleton_newterm(t_termios *term);
t_list				*singleton_liste(t_list *new);
t_data				*singleton_data(t_data *new);
void				select_close_term(t_termios *term, t_termios *old);
void				select_init_term(t_termios *term, t_termios *oldterm);
int					get_pos(char *buf, t_data *data, t_list *list);
void				list(char *buf, t_data *data, t_list *liste);
void				checksignal(void);
void				treat_signal(int sig);
int					print_list(t_data *data, t_list *liste);
void				checkdel(char *buf, t_data *data, t_list *list);

#endif
