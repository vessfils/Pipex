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

static char	**ft_panic(char **arr, int len)
{
	while (--len >= 0)
	{
		free(arr[len]);
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
				return (ft_panic(arr, i - 1));
			while (*s && *s != c)
				s++;
		}
	}
	arr[i] = 0;
	return (arr);
}

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