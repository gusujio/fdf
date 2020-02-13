/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:01:19 by tnichell          #+#    #+#             */
/*   Updated: 2019/09/24 21:35:45 by tnichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst1;
	unsigned char	*src1;

	if (dst != src)
	{
		i = 0;
		dst1 = (unsigned char*)dst;
		src1 = (unsigned char*)src;
		while (i < n)
		{
			dst1[i] = src1[i];
			i++;
		}
	}
	return (dst);
}
