/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:04:55 by tnichell          #+#    #+#             */
/*   Updated: 2019/09/22 20:58:41 by tnichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *tofind)
{
	unsigned int	pos;
	unsigned int	i;

	pos = 0;
	if (tofind[pos] == '\0')
		return ((char *)str);
	while (str[pos] != '\0')
	{
		if (str[pos] == tofind[0])
		{
			i = 1;
			while (str[pos + i] == tofind[i] && tofind[i] != '\0')
			{
				i++;
			}
			if (tofind[i] == '\0')
				return ((char *)str + pos);
		}
		pos++;
	}
	return (0);
}
