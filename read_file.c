/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 20:05:25 by gusujio           #+#    #+#             */
/*   Updated: 2020/02/12 20:15:03 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned long long int	ft_degree(unsigned
						long long int x, unsigned long long int n)
{
	if (n == 0)
		return (1);
	else if (n == 1)
		return (x);
	else if (n % 2 == 0)
		return (ft_degree(x * x, n / 2));
	else
		return (ft_degree(x * x, n / 2) * x);
}

int						ft_isnumber(const char *s)
{
	int					i;

	i = 0;
	if (s[0] == '-')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

void					stop(char *s2, t_ili *z_line)
{
	int					i;

	i = 2;
	s2++;
	if (*s2 != '0' && *(s2 + 1) != 'x' && *(s2 + 9) != 0)
		error();
	while (s2[i])
	{
		if (!((s2[i] >= 'A' && s2[i] <= 'F') || ft_isdigit(s2[i])))
			error();
		i++;
	}
	z_line->color = perevod(s2 + 2);
}

void					fill_matrix(t_ili *z_line, char *line, t_fdf **data)
{
	char				**nums;
	int					i;
	char				*s2;

	nums = ft_strsplit(line, ' ');
	i = 0;
	while (nums[i])
	{
		if ((s2 = ft_strchr(nums[i], ',')))
			stop(s2, z_line + i);
		else
		{
			if (!ft_isnumber(nums[i]))
				error();
			z_line[i].color = 0;
		}
		z_line[i].number = ft_atoi(nums[i]);
		if (z_line[i].number > (*data)->max)
			(*data)->max = z_line[i].number;
		if (z_line[i].number < (*data)->min)
			(*data)->min = z_line[i].number;
		i++;
	}
}

void					read_file(char *file_name, t_fdf **data)
{
	int					fd;
	char				*line;
	int					i;

	(*data)->height = get_height(file_name);
	(*data)->width = get_width(file_name);
	(*data)->z_matrix = (t_ili **)malloc(sizeof(t_ili *)
			* ((*data)->height + 1));
	i = 0;
	while (i <= (*data)->height)
		(*data)->z_matrix[i++] = (t_ili *)malloc(sizeof(t_ili)
				* ((*data)->width + 1));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	(*data)->max = -2147483648;
	(*data)->min = +2147483647;
	while (get_next_line(fd, &line))
	{
		fill_matrix((*data)->z_matrix[i], line, data);
		free(line);
		i++;
	}
	close(fd);
	(*data)->z_matrix[i] = NULL;
}
