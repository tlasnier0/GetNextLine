/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlasnier <tlasnier@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:44:22 by tlasnier          #+#    #+#             */
/*   Updated: 2026/11/09 16:45:00 by tlasnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != (char)c)
		i++;
	if (str[i] == (char)c)
		return (&str[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	len;

	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	len = ft_strlen(s1);
	res = malloc(sizeof(char) * (len + ft_strlen(s2) + 1));
	if (!res)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(res, s1, len + 1);
	ft_strlcpy(&res[len], s2, ft_strlen(s2) + 1);
	free(s1);
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		res = malloc(sizeof(char) * 1);
		if (!res)
			return (NULL);
		res[0] = 0;
		return (res);
	}
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, &s[start], len + 1);
	return (res);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t length)
{
	size_t	i;

	if (length == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < length - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (i);
}
