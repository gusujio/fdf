/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:43:01 by tnichell          #+#    #+#             */
/*   Updated: 2019/09/22 20:48:11 by tnichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *destination, const char *append, size_t n)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	if (n == 0)
		return (destination);
	while (destination[i] != '\0')
	{
		i++;
	}
	while (append[j] != '\0' && j < n)
	{
		destination[i] = append[j];
		i++;
		j++;
	}
	destination[i] = '\0';
	return (destination);
}
