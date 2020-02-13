/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:08:42 by tnichell          #+#    #+#             */
/*   Updated: 2019/09/22 20:26:19 by tnichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *destination, const char *append)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (destination[i] != '\0')
	{
		i++;
	}
	while (append[j] != '\0')
	{
		destination[i] = append[j];
		i++;
		j++;
	}
	destination[i] = '\0';
	return (destination);
}
