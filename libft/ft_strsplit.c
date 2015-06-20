/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 01:36:12 by jchenaf           #+#    #+#             */
/*   Updated: 2015/03/23 13:59:50 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t		ft_strlenws(char const *s, char c)
{
	size_t	result;

	result = 0;
	while (*s != c && *s)
	{
		result++;
		s++;
	}
	return (result);
}

static char			**ft_spliting(char const *s, char **newt, char c)
{
	unsigned int	i;
	int				x;

	i = 0;
	x = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			newt[x++] = ft_strsub(s, i, ft_strlenws(&s[i], c));
			i = i + ft_strlenws(&s[i], c);
		}
		else
			i++;
	}
	return (newt);
}

char				**ft_strsplit(char const *s, char c)
{
	int		i;
	int		t;
	char	**newtab;

	i = 0;
	t = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && ((i != 0 && s[i - 1] == c) || i == 0))
			t++;
		i++;
	}
	newtab = (char**)(malloc(sizeof(newtab) * (t + 1)));
	if (newtab == NULL)
		return (NULL);
	while (t != -1)
		newtab[t--] = NULL;
	newtab = ft_spliting(s, newtab, c);
	return (newtab);
}
