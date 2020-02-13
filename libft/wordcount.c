/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordcount.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:35:15 by tnichell          #+#    #+#             */
/*   Updated: 2019/09/26 21:07:23 by tnichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	wordcount(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (s[0] == '\0')
		return (0);
	if (s[0] != c)
		count++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}
