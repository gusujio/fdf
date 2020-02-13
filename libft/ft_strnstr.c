/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:44:04 by tnichell          #+#    #+#             */
/*   Updated: 2019/09/24 21:38:09 by tnichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t len)
{
	size_t	pos;
	size_t	i;

	if (ft_strlen(tofind) == 0)
		return ((char *)str);
	pos = 0;
	while (str[pos] != '\0' && pos < len)
	{
		if (str[pos] == tofind[0])
		{
			i = 1;
			while (str[pos + i] == tofind[i]
				&& (pos + i) < len && tofind[i] != '\0')
				i++;
			if (tofind[i] == '\0')
				return ((char *)str + pos);
		}
		pos++;
	}
	return (0);
}
