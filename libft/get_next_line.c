/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnichell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 18:30:37 by tnichell          #+#    #+#             */
/*   Updated: 2019/10/29 22:36:18 by tnichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*check_reminder(char *reminder, char **line)
{
	char	*p_n;

	p_n = NULL;
	if (reminder)
	{
		if ((p_n = ft_strchr(reminder, '\n')))
		{
			*p_n = '\0';
			*line = ft_strdup(reminder);
			ft_strcpy(reminder, ++p_n);
		}
		else
		{
			*line = ft_strdup(reminder);
			ft_strclr(reminder);
		}
	}
	else
		*line = ft_strnew(1);
	return (p_n);
}

int		get_line(int fd, char **line, char **reminder)
{
	char	buf[BUFF_SIZE + 1];
	int		byte_was_read;
	char	*p_n;
	char	*tmp;

	byte_was_read = 1;
	p_n = check_reminder(*reminder, line);
	while (!p_n && (byte_was_read = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[byte_was_read] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			p_n++;
			free(*reminder);
			*reminder = ft_strdup(p_n);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buf)) || byte_was_read < 0)
			return (-1);
		free(tmp);
	}
	if (byte_was_read < 0)
		return (-1);
	return (byte_was_read || ft_strlen(*line)) ? 1 : 0;
}

t_gnl	*new_linked_list_el(int fd)
{
	t_gnl	*new;

	new = (t_gnl *)malloc(sizeof(t_gnl));
	new->fd = fd;
	new->reminder = NULL;
	new->next = NULL;
	return (new);
}

int		get_next_line(int fd, char **line)
{
	static t_gnl	*head;
	t_gnl			*tmp;

	if (fd < 0 || !line || fd > 10240 || BUFF_SIZE < 0)
		return (-1);
	if (head == NULL)
		head = new_linked_list_el(fd);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = new_linked_list_el(fd);
		tmp = tmp->next;
	}
	return (get_line(tmp->fd, line, &tmp->reminder));
}
