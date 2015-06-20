/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 22:50:25 by jchenaf           #+#    #+#             */
/*   Updated: 2015/03/18 22:41:20 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s, size_t n)
{
	char	*s2;
	size_t	i;

	i = -1;
	if (s == NULL)
		return (NULL);
	if ((s2 = (char *)(malloc(sizeof(*s2) * (n + 1)))) == NULL)
		return (NULL);
	while (++i < n)
		s2[i] = s[i];
	s2[i] = '\0';
	return (s2);
}
