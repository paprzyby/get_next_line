/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:37:41 by paprzyby          #+#    #+#             */
/*   Updated: 2024/04/15 10:29:00 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strjoin(char *str, char *buffer)
{
	char	*s3;
	int		i;
	int		len1;
	int		len2;
	int		j;

	i = 0;
	j = 0;
	if (!str || !buffer)
		return (NULL);
	len1 = ft_strlen(str);
	len2 = ft_strlen(buffer);
	s3 = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	while (i < len1)
	{
		s3[i] = str[i];
		i++;
	}
	while (j < len2)
		s3[i++] = buffer[j++];
	s3[i] = '\0';
	return (s3);
}

char	*ft_strchr(const char *s, char c)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}
