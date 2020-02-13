/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:57:50 by tnichell          #+#    #+#             */
/*   Updated: 2019/09/24 14:57:56 by tnichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_ll_check(int neg, long long n, char c)
{
	if (neg == -1 && n == 922337203685477580 && c == '9')
		return (1);
	if (neg == 1 && n == 922337203685477580 && (c == '8' || c == '9'))
		return (1);
	if (n > 922337203685477580 && c >= '0' && c <= '9')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int			i;
	int			neg;
	long long	rez;

	rez = 0;
	i = 0;
	neg = 1;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\n' ||
	str[i] == '\t' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
	{
		i++;
	}
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		rez = rez * 10 + (str[i] - 48);
		if (ft_ll_check(neg, rez, str[i + 1]))
			return (-1 * (neg == 1));
		i++;
	}
	return ((int)(rez * neg));
}
