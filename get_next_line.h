/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:49:43 by paprzyby          #+#    #+#             */
/*   Updated: 2024/04/15 14:10:42 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(GET_NEXT_LINE_H)
# define GET_NEXT_LINE_H

//#if !defined BUFFER_SIZE
//# define BUFFER_SIZE 5
//# endif

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *buffer, char c);
int		ft_strlen(char *str);
void	*ft_calloc(size_t size);
//char	*if_str_empty(char *str, char *buffer, char *s);

#endif
