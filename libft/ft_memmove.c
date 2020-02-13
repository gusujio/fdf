/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:59:20 by tnichell          #+#    #+#             */
/*   Updated: 2019/09/22 20:12:48 by tnichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*buf;

	if (dst != src)
	{
		buf = (char *)malloc(len);
		if (buf)
		{
			ft_memcpy(buf, src, len);
			ft_memcpy(dst, buf, len);
			free(buf);
		}
	}
	return (dst);
}
