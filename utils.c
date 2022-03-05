/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcampagn <jcampagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:10:25 by jcampagn          #+#    #+#             */
/*   Updated: 2022/03/05 14:54:35 by jcampagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_panic(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
	{
		free(arr[i]);
	}
	free(arr);
	return (NULL);
}

static int	ft_count_words(const char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*malloc_word(const char *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**arr;

	i = 0;
	arr = 0;
	if (!s)
		return (0);
	arr = (char **)malloc(sizeof(char *) *(ft_count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			arr[i] = malloc_word(s, c);
			if (!arr[i++])
				return (ft_panic(arr));
			while (*s && *s != c)
				s++;
		}
	}
	arr[i] = 0;
	return (arr);
}

char	*ft_strndup(const char *str, unsigned int n)
{
	int		i;
	char	*cpy;
	int		len;

	i = 0;
	cpy = 0;
	len = n;
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
