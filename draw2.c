/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:38:13 by gusujio           #+#    #+#             */
/*   Updated: 2020/02/12 20:38:42 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		color(t_fdf **data, int x)
{
	int c1;
	int c2;

	c1 = (*data)->z_matrix[(int)(*data)->y][(int)(*data)->x].color;
	c2 = (*data)->z_matrix[(int)(*data)->y1][(int)(*data)->x1].color;
	if (c1 || c2)
		(*data)->color = c1 ? c1 : c2;
	else
		(*data)->color = x ? color2(data) : 0xffffff;
}

void		bresenham2(t_fdf *data)
{
	float	z;
	float	z1;

	z = data->z_matrix[(int)data->y][(int)data->x].number;
	z1 = data->z_matrix[(int)data->y1][(int)data->x1].number;
	color(&data, (z || z1));
	z *= data->zoomz;
	z1 *= data->zoomz;
	data->x *= data->zoom;
	data->y *= data->zoom;
	data->x1 *= data->zoom;
	data->y1 *= data->zoom;
	data->x -= (data->width * data->zoom) / 2;
	data->x1 -= (data->width * data->zoom) / 2;
	data->y -= (data->height * data->zoom) / 2;
	data->y1 -= (data->height * data->zoom) / 2;
	isometricx(data->x, &(data->y), &z, data->tettax);
	isometricy(&(data->x), data->y, &z, data->tettay);
	isometricz(&(data->x), &(data->y), z, data->tettaz);
	isometricx(data->x1, &(data->y1), &z1, data->tettax);
	isometricy(&(data->x1), data->y1, &z1, data->tettay);
	isometricz(&(data->x1), &(data->y1), z1, data->tettaz);
}

void		bresenham(t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;

	bresenham2(data);
	data->x += data->shift_x;
	data->y += data->shift_y;
	data->x1 += data->shift_x;
	data->y1 += data->shift_y;
	x_step = data->x1 - data->x;
	y_step = data->y1 - data->y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(data->x - data->x1)
	|| (int)(data->y - data->y1))
	{
		mlx_pixel_put(data->mlx_ptr,
		data->win_ptr, data->x, data->y, data->color);
		data->x += x_step;
		data->y += y_step;
	}
}

void		draw2(int x, int y, t_fdf *data)
{
	if (x < data->width - 1)
	{
		data->y = y;
		data->x = x;
		data->x1 = data->x + 1;
		data->y1 = data->y;
		bresenham(data);
	}
	if (y < data->height - 1)
	{
		data->y = y;
		data->x = x;
		data->x1 = data->x;
		data->y1 = data->y + 1;
		bresenham(data);
	}
}

void		draw(t_fdf *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			draw2(x, y, data);
			x++;
		}
		y++;
	}
}
