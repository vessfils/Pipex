/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <vess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:55:22 by vess              #+#    #+#             */
/*   Updated: 2022/02/28 21:54:43 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>

int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strichr(char *str, char c);
char	*ft_strchr(const char *str, int c);
char	*ft_strndup(const char *str, unsigned int n);
char	*ft_joinpath(char const *s1, char const *s2);
#endif