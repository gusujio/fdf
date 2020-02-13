/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:56:14 by tnichell          #+#    #+#             */
/*   Updated: 2019/09/22 20:39:09 by tnichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *destination, const char *source, size_t size)
{
	size_t lendest;
	size_t lensour;
	size_t i;
	size_t k;

	i = 0;
	lendest = 0;
	while (destination[lendest] != '\0' && lendest < size)
		lendest++;
	lensour = ft_strlen(source);
	if (size <= lendest)
		return (lensour + size);
	k = lendest;
	while (source[i] != '\0' && i + k < size - 1)
	{
		destination[lendest] = source[i];
		i++;
		lendest++;
	}
	destination[lendest] = '\0';
	return (k + lensour);
}
