/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:49:37 by tnichell          #+#    #+#             */
/*   Updated: 2019/09/26 21:20:05 by tnichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		numberword;
	int		i;
	int		j;
	int		length;

	if (s == NULL)
		return (NULL);
	numberword = wordcount(s, c);
	tab = (char**)malloc(sizeof(char*) * (numberword + 1));
	if (tab == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < numberword)
	{
		while (s[j] != '\0' && s[j] == c)
			j++;
		length = wordlength(s + j, c);
		tab[i] = ft_strsub(s, j, length + 1);
		tab[i][length] = '\0';
		j += length;
	}
	tab[i] = NULL;
	return (tab);
}
