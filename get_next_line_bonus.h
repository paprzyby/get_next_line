/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paprzyby <paprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:29:06 by paprzyby          #+#    #+#             */
/*   Updated: 2024/04/19 05:33:04 by paprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(GET_NEXT_LINE_BONUS_H)
# define GET_NEXT_LINE_BONUS_H

# if !defined(BUFFER_SIZE)
#  define BUFFER_SIZE 5
# endif

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
void	*ft_calloc(unsigned int size);

#endif
