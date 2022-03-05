/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcampagn <jcampagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:03:59 by jcampagn          #+#    #+#             */
/*   Updated: 2022/03/05 17:13:06 by jcampagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*cpy;
	int		len;

	i = 0;
	cpy = 0;
	len = ft_strlen((char *)str);
	cpy = (char *)malloc (sizeof(*cpy) * (len + 1));
	if (!cpy)
		return (NULL);
	while (i < len)
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		j;
	char		*sub;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (((unsigned int)start) >= (unsigned int)ft_strlen((char *)s))
		return (ft_strdup(""));
	sub = 0;
	if (ft_strlen(s) < start + len)
		len = ft_strlen(s) - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
			sub[j++] = s[i];
		i++;
	}
	sub[j] = 0;
	return (sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	size_t	len;

	str = 0;
	str = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!str)
		return (NULL);
	len = 0;
	while (s1 && s1[len])
	{
		str[len] = s1[len];
		len++;
	}
	i = -1;
	while ((char *)s2 && s2[++i])
		str[len++] = s2[i];
	str[len] = '\0';
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
