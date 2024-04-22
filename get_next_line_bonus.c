/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:29:25 by paprzyby          #+#    #+#             */
/*   Updated: 2024/04/22 08:11:24 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_the_rest(char *str)
{
	unsigned int		i;
	unsigned int		j;
	char				*rest;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	rest = (char *)malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (str[i] != '\0')
		rest[j++] = str[i++];
	rest[j] = '\0';
	free(str);
	return (rest);
}

char	*create_next_line(char *str)
{
	char			*line;
	unsigned int	i;

	i = 0;
	if (str[i] == '\0')
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[0] == '\n' || str[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (i > 0)
	{
		i--;
		line[i] = str[i];
	}
	return (line);
}

char	*find_next_line(int fd, char *str)
{
	char	*buffer;
	int		size;

	buffer = ft_calloc(BUFFER_SIZE + 1);
	while (ft_strchr(str, '\n') == NULL)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		if (size == 0)
			break ;
		buffer[size] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[256];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = find_next_line(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = create_next_line(str[fd]);
	str[fd] = get_the_rest(str[fd]);
	return (line);
}

//[fd] is used to store a string corresponding to the file descriptor
//This allows the function to maintain separate string buffers
//for different file descriptors