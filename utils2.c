/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcampagn <jcampagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:11:48 by jcampagn          #+#    #+#             */
/*   Updated: 2022/03/03 14:14:40 by jcampagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	c = (unsigned char)c;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *) str + i);
		i++;
	}
	if (!c)
		return ((char *) str + i);
	return (0);
}

int	ft_strichr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}

char	*ft_joinpath(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	size_t	len;

	str = 0;
	str = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 2);
	if (!str)
		return (NULL);
	len = 0;
	while (s1 && s1[len])
	{
		str[len] = s1[len];
		len++;
	}
	str[len] = '/';
	len++;
	i = -1;
	while ((char *)s2 && s2[++i])
		str[len++] = s2[i];
	str[len] = '\0';
	return (str);
}
