/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkeskin < enkeskin@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:37:17 by enkeskin          #+#    #+#             */
/*   Updated: 2022/08/22 18:26:59 by enkeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strcpy(char	*dst, const char *src, size_t	dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] && i < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		len_s1;
	int		len_s2;


	}
	if (!s2)
		return (NULL);
	len_s1 = (ft_strlen((char *)s1));
	len_s2 = (ft_strlen((char *)s2));
	res = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_strcpy(res, s1, len_s1);
	ft_strcpy(&res[len_s1], s2, len_s2);
	free(s1);
	return (res);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	*ft_free(void *str)
{
	free(str);
	return (NULL);
}
