/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 10:17:14 by jchenaf           #+#    #+#             */
/*   Updated: 2015/03/18 22:41:16 by xacoquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	int	resultat;

	if (str == NULL)
		return (0);
	resultat = 0;
	while (*str != '\0')
	{
		resultat++;
		str++;
	}
	return (resultat);
}
