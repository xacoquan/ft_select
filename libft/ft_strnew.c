/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 10:18:34 by jchenaf           #+#    #+#             */
/*   Updated: 2015/03/18 22:41:21 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*newstr;
	size_t	i;

	i = 0;
	newstr = (char *)malloc(sizeof(newstr) * size + 1);
	if (newstr == NULL)
		return (NULL);
	while (i <= size)
	{
		newstr[i] = '\0';
		i++;
	}
	newstr[size] = '\0';
	return (newstr);
}
