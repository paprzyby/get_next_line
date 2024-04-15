/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:51:44 by paprzyby          #+#    #+#             */
/*   Updated: 2024/04/15 14:25:44 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_the_rest(char *str)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	rest = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
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
	while (ft_strchr(buffer, '\n') == NULL)
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
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = find_next_line(fd, str);
	if (!str)
		return (NULL);
	line = create_next_line(str);
	str = get_the_rest(str);
	return (line);
}

int main()
{
	char	*str;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file\n");
		return (1);
	}
	str = get_next_line(fd);
	printf("%s", str);
	//while ((str = get_next_line(fd)) != NULL)
	//	printf("%s", str);
	free(str);
	close(fd);
	return (0);
}