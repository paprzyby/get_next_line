/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:37:41 by paprzyby          #+#    #+#             */
/*   Updated: 2024/04/15 14:10:24 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*if_str_empty(char *str)
{
	str = (char *)malloc(1 * sizeof(char));
	str[0] = '\0';
	if (!str)
		return (NULL);
	return (str);
}

void	*ft_calloc(size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc(size * sizeof(char));
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *buffer, char c)
{
	unsigned int	i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] != c && buffer[i] != '\0')
		i++;
	if (buffer[i] == c)
		return (buffer + i);
	return (NULL);
}

char	*ft_strjoin(char *str, char *buffer)
{
	char			*new;
	unsigned int	i;
	unsigned int	j;

	i = -1;
	j = 0;
	if (!str)
		str = if_str_empty(str);
	if (!str || !buffer)
		return (NULL);
	new = malloc(sizeof(char) * ((ft_strlen(str) + ft_strlen(buffer)) + 1));
	if (!new)
		return (NULL);
	if (str)
		while (str[++i] != '\0')
			new[i] = str[i];
	while (buffer[j] != '\0')
		new[i++] = buffer[j++];
	new[ft_strlen(str) + ft_strlen(buffer)] = '\0';
	free(str);
	return (new);
}
