/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasnier <tlasnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 10:24:29 by tlasnier          #+#    #+#             */
/*   Updated: 2026/11/10 08:57:06 by tlasnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*stash_next_line(char *stash, int fd)
{
	int		rreturn;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(stash);
		return (NULL);
	}
	rreturn = BUFFER_SIZE;
	while (rreturn > 0 && !ft_strchr(stash, '\n'))
	{
		rreturn = read(fd, buffer, BUFFER_SIZE);
		if (rreturn < 0)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[rreturn] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*extract_line(char *stash)
{
	int	i;

	if (ft_strchr(stash, '\n'))
		i = ft_strchr(stash, '\n') - stash + 1;
	else
		i = ft_strlen(stash);
	return (ft_substr(stash, 0, i));
}

char	*clean_stash(char *stash)
{
	char	*res;
	char	*tofree;
	int		i;

	tofree = stash;
	if (ft_strchr(stash, '\n'))
		i = ft_strchr(stash, '\n') - stash + 1;
	else
		i = ft_strlen(stash);
	res = ft_substr(stash, i, ft_strlen(stash));
	free(tofree);
	if (!res || res[0] == '\0')
	{
		free(res);
		return (NULL);
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = stash_next_line(stash, fd);
	if (!stash || stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	res = extract_line(stash);
	if (!res)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = clean_stash(stash);
	return (res);
}

/* #include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
} */
