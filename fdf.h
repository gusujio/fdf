/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:43:18 by gusujio           #+#    #+#             */
/*   Updated: 2020/02/12 21:16:29 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

# include <math.h>
# include <stdio.h>

# include <fcntl.h>

typedef struct			s_ili
{
	int					number;
	int					color;
}						t_ili;

typedef struct			s_fdf
{
	int					max;
	int					min;
	int					width;
	int					height;
	t_ili				**z_matrix;
	int					zoom;
	float				zoomz;
	int					color;
	int					shift_x;
	int					shift_y;
	float				tettax;
	float				tettay;
	float				tettaz;
	void				*mlx_ptr;
	void				*win_ptr;
	float				x;
	float				y;
	float				x1;
	float				y1;
}						t_fdf;

void					isometricz(float *x, float *y, float z, float tetta);
void					isometricy(float *x, float y, float *z, float tetta);
void					isometricx(float x, float *y, float *z, float tetta);
float					mod(float i);
void					read_file(char *data, t_fdf **data2);
void					bresenham(t_fdf *data);
void					draw(t_fdf *data);
void					read_file(char *file_name, t_fdf **data);
void					fill_matrix(t_ili *z_line, char *line, t_fdf **data);
void					stop(char *s2, t_ili *z_line);
void					error(void);
int						ft_isnumber(const char *s);
int						perevod(char *s);
int						get_height(char *file_name);
int						get_width(char *file_name);
unsigned long long int	ft_degree(unsigned
long long int x, unsigned long long int n);
int						color2(t_fdf **data);

#endif
