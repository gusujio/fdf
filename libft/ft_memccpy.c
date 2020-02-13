/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:14:51 by tnichell          #+#    #+#             */
/*   Updated: 2019/09/22 20:00:24 by tnichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*src1;
	unsigned char	*dst1;
	size_t			i;

	src1 = (unsigned char *)src;
	dst1 = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		dst1[i] = src1[i];
		if (src1[i++] == (unsigned char)c)
			return ((void*)(dst1 + i));
	}
	return (NULL);
}
