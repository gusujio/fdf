/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:38:55 by gusujio           #+#    #+#             */
/*   Updated: 2020/02/12 20:41:14 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				color2(t_fdf **data)
{
	double		x;
	double		z;
	double		z2;
	static int	mas[11] = {0x800000, 0xff0000, 0xff6600, 0xff66cc,
		0xcc66ff, 0x6666ff, 0x0033cc, 0x00cc99,
		0x33cc33, 0x99ff66, 0xffff66};

	x = (int)(((*data)->max - (*data)->min) / 11.0);
	if (x == 0)
		x = 1;
	z = (*data)->z_matrix[(int)(*data)->y][(int)(*data)->x].number;
	z2 = (*data)->z_matrix[(int)(*data)->y1][(int)(*data)->x1].number;
	z = z > z2 ? z : z2;
	z = (z - (*data)->min) / x;
	return (mas[(int)z]);
}
