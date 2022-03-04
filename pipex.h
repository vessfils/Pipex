/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <vess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:55:22 by vess              #+#    #+#             */
/*   Updated: 2022/03/04 18:05:06 by vess             ###   ########.fr       */
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

# define INPUT 0
# define OUTPUT 1
# define READ_END 0
# define WRITE_END 1
# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define INFILE 0
# define OUTFILE 1

int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strichr(char *str, char c);
char	*ft_strchr(const char *str, int c);
char	*ft_strndup(const char *str, unsigned int n);
char	*ft_joinpath(char const *s1, char const *s2);
void	ft_error(const char *msg);
char	**ft_panic(char **arr);
#endif