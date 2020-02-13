/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eberta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:33:52 by eberta            #+#    #+#             */
/*   Updated: 2019/09/12 18:31:40 by eberta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strchr(const char *string, int symbol)
{
	int		i;

	i = 0;
	while (string[i])
	{
		if (string[i] == symbol)
			return ((char*)(string + i));
		i++;
	}
	if (symbol == 0)
		return ((char*)(string + i));
	else
		return (NULL);
}
