/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkeskin < enkeskin@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:37:20 by enkeskin          #+#    #+#             */
/*   Updated: 2022/08/22 18:09:28 by enkeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *str)
{
	int		i;
	char	*dizi;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	dizi = malloc(sizeof(char) * (i + 2));
	if (!dizi)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		dizi[i] = str[i];
	if (str[i] == '\n')
	{
		dizi[i] = str[i];
		i++;
	}
	dizi[i] = '\0';
	return (dizi);
}

char	*ft_create(char *str)
{
	int		i;
	int		j;
	char	*dizi;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (ft_free(str));
	dizi = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!dizi)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		dizi[j++] = str[i++];
	dizi[j] = '\0';
	free(str);
	return (dizi);
}

char	*ft_read_and_create(int fd, char *str)
{	
	char	*buff;
	int		rc;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rc = 10;
	while (!ft_strchr(str) && rc != 0)
	{
		rc = read(fd, buff, BUFFER_SIZE);
		if (rc == -1)
			return (ft_free(buff));
		buff[rc] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read_and_create(fd, str);
	if (!str)
		return (0);
	line = ft_get_line(str);
	str = ft_create(str);
	return (line);
}


//--------------------------------------------------------------------------------------------
#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd;
	int fd1;

	char *str;

	fd = open("get_next_line_utils.c", O_CREAT | O_RDWR, 0777);
	fd1 = open("get_next_line_utils.c", O_CREAT | O_RDWR, 0777);
	printf("%d", fd);
	printf("%d", fd1);
	str = get_next_line(fd);
	printf("%s", str);

//	system("leaks a.out");
	
	return(0);
}