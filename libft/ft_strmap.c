/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:25:17 by tnichell          #+#    #+#             */
/*   Updated: 2019/09/22 20:44:09 by tnichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*p;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	if (!(p = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	p[i] = '\0';
	while (i > 0)
	{
		i--;
		p[i] = f(s[i]);
	}
	return (p);
}
