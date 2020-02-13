/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:25:17 by tnichell          #+#    #+#             */
/*   Updated: 2019/09/22 20:46:10 by tnichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		p[i] = f(i, s[i]);
	}
	return (p);
}
