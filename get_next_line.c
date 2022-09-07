/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkeskin < enkeskin@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:19:18 by enkeskin          #+#    #+#             */
/*   Updated: 2022/08/04 21:49:54 by enkeskin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_read(int fd, char *str)
{
	int		rd;
	char	*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rd = 1;
	while (!ft_n(str) && rd != 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		buff[rd] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}
char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	str = ft_update_str(str);
	return (line);
}

#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int		fd;
	char	*buff;
	fd = open("test.txt", O_CREAT | O_RDWR, 0777);
	buff = get_next_line(fd);
	while (buff)
	{
		printf("%s", buff);
		free(buff);
		buff = get_next_line(fd);
	}
}

/*
int main()
{
	char dizi[] = "selamnaber\nselam\nnaber\n\0";
	selamnaber\0
	selam\0
	naber\0
	selam
	selam
	naber
	\0
	
	// selamnaber selam naber\0
	printf("%s", dizi);

}*/
/*
#include <fcntl.h>
#include <stdio.h>
int main()
{
	int		fd;
	int		i = 0;
	char	*buff;
	fd = open("test.txt", O_CREAT | O_RDWR, 0777);

	buff = ft_calloc(sizeof(char), 42);
	int b;
	b = ft_strlen(buff);
	printf("%d", b);
	read(fd, buff, BUFFER_SIZE);
	printf("%s", buff);
	printf("\n");
	while (*(buff + i))
	{
		printf("%d", i);
		write(1, buff + i, 1);
		i++;
		printf("\n");
	}
	
	buff[b - 1] = '\0';
	printf("%s", buff);

}
*/