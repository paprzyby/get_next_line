/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:29:42 by paprzyby          #+#    #+#             */
/*   Updated: 2024/04/18 14:36:54 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(unsigned int size)
{
	unsigned int		i;
	char				*str;

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
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!buffer)
		return (NULL);
	if (!str)
	{
		str = (char *)malloc(1 * sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	new = malloc(sizeof(char) * ((ft_strlen(str) + ft_strlen(buffer)) + 1));
	if (!new)
		return (free(str), NULL);
	if (str)
		while (str[++i] != '\0')
			new[i] = str[i];
	while (buffer[j] != '\0')
		new[i++] = buffer[j++];
	new[ft_strlen(str) + ft_strlen(buffer)] = '\0';
	return (free(str), new);
}
