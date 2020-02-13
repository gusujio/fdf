/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:36:45 by tnichell          #+#    #+#             */
/*   Updated: 2019/09/22 21:02:14 by tnichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*p;
	size_t	i;
	size_t	j;
	size_t	l;

	if (s == NULL)
		return (NULL);
	i = 0;
	l = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = ft_strlen(s);
	while (j > 0 && (s[j - 1] == ' ' || s[j - 1] == '\n'
		|| s[j - 1] == '\t'))
		j--;
	if (!(p = malloc((j > i ? j - i : 0) + 1)))
		return (0);
	while (i < j)
	{
		p[l] = s[i];
		l++;
		i++;
	}
	p[l] = '\0';
	return (p);
}
