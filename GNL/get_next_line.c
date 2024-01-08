/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:21:02 by sbouabid          #+#    #+#             */
/*   Updated: 2024/01/08 17:50:35 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buffer(int fd, char *tmp)
{
	int		read_counter;
	char	*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_counter = 1;
	while (read_counter && !ft_strchr(tmp, '\n'))
	{
		read_counter = read(fd, buffer, BUFFER_SIZE);
		if (read_counter <= 0)
			break ;
		buffer[read_counter] = '\0';
		tmp = ft_strjoin(tmp, buffer);
	}
	return (free(buffer), tmp);
}

char	*read_line(char *tmp)
{
	char	*line;
	int		len;

	len = 0;
	if (!tmp || !*tmp)
		return (NULL);
	while (tmp[len] && tmp[len] != '\n')
		len++;
	line = ft_substr(tmp, len);
	return (line);
}

char	*next_line(char	*tmp)
{
	char	*buffer;
	int		i;

	if (!tmp || !*tmp)
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (!tmp[i])
		buffer = ft_strdup(tmp + i);
	else
		buffer = ft_strdup(tmp + (i + 1));
	return (free(tmp), tmp = NULL, buffer);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0
		|| BUFFER_SIZE >= 2147483647)
		return (free(tmp), tmp = NULL, NULL);
	tmp = read_buffer(fd, tmp);
	line = read_line(tmp);
	if (!line)
		return (free(tmp), tmp = NULL, NULL);
	tmp = next_line(tmp);
	return (line);
}
