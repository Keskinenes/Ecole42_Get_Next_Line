/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkeskin < enkeskin@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:37:07 by enkeskin          #+#    #+#             */
/*   Updated: 2022/08/22 14:37:34 by enkeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line_bonus(int fd);
char	*ft_read_and_create(int fd, char *str);
char	*ft_create(char *str);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *str);
size_t	ft_strlcpy(char	*dst, const char *src, size_t	dstsize);
void	*ft_free(void *str);

#endif
