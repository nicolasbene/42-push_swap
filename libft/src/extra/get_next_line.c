/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:47:47 by nibenoit          #+#    #+#             */
/*   Updated: 2023/02/10 11:52:15 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	copy_until_end(char *src, char *dst)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

static void	*free_strings(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (NULL);
}

static char	*extract_line_and_save(char **line, char *save, int size)
{
	char	*tmp_save;

	if (size < 0)
		size = ft_strlen(save);
	if (size == 0)
		return (free_strings(save, NULL));
	tmp_save = malloc(ft_strlen(save + size) + 1);
	if (!tmp_save)
		return (free_strings(save, NULL));
	copy_until_end(save + size, tmp_save);
	*line = malloc(size + 1);
	if (*line != NULL)
	{
		save[size] = 0;
		copy_until_end(save, *line);
	}
	free(save);
	return (tmp_save);
}

static char	*read_line(int fd, char **line, char *save)
{
	int		ret;
	char	*tmp;
	char	*buff;

	ret = BUFFER_SIZE;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	tmp = ft_strchr(save, '\n');
	while (tmp == NULL && ret == BUFFER_SIZE)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
			return (free_strings(save, buff));
		buff[ret] = 0;
		tmp = ft_strjoin(save, buff);
		free(save);
		save = tmp;
		tmp = ft_strchr(save, '\n');
	}
	if (ret != BUFFER_SIZE && tmp == NULL)
		tmp = save + ft_strlen(save) - 1;
	free(buff);
	return (extract_line_and_save(line, save, (tmp - save) + 1));
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save[OPEN_MAX] = {0};

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	if (!save[fd])
		save[fd] = ft_strdup("");
	save[fd] = read_line(fd, &line, save[fd]);
	return (line);
}
