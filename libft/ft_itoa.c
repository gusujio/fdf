/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:42:19 by tnichell          #+#    #+#             */
/*   Updated: 2019/09/24 14:50:31 by tnichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*b;
	int		i;
	char	minus;

	i = ft_lennbr(n);
	if (!(b = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	b[i] = '\0';
	i--;
	minus = n < 0;
	if (n < 0)
	{
		b[i] = n % 10 * -1 + '0';
		i--;
		n = n / 10 * -1;
	}
	while (i >= 0)
	{
		b[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	if (minus)
		b[0] = '-';
	return (b);
}
