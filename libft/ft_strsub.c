/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:15:18 by tnichell          #+#    #+#             */
/*   Updated: 2019/09/22 20:59:28 by tnichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (s == NULL || len + 1 == 0L)
		return (NULL);
	sub = ft_strnew(len);
	if (sub == NULL)
		return (NULL);
	s = s + start;
	i = 0;
	while (i < len)
	{
		sub[i] = s[i];
		i++;
	}
	return (sub);
}
