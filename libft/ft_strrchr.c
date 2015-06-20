/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 10:19:00 by jchenaf           #+#    #+#             */
/*   Updated: 2015/03/18 22:41:23 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c1;
	int		i;
	int		t;

	i = 0;
	t = 0;
	c1 = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == c1)
			t = i;
		i++;
	}
	if (c == 0)
		return (char*)(&s[i]);
	if ((t == 0 && s[t] == c1) || t > 0)
		return (char*)(&s[t]);
	else
		return (NULL);
}
