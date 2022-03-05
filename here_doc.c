/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcampagn <jcampagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:13:14 by jcampagn          #+#    #+#             */
/*   Updated: 2022/03/05 16:13:12 by jcampagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_putstr_fd(char const *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

static void	read_here_doc(char *av, int fdpipe[2])
{
	char	*line;
	char	*limiter;

	limiter = ft_strjoin(av, "\0");
	close (fdpipe[0]);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (ft_strncmp(line, limiter, ft_strlen(limiter) + 1))
		{
			close(fdpipe[1]);
			free(line);
			free(limiter);
			exit(1);
		}
		ft_putstr_fd(line, fdpipe[1]);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	close(fdpipe[1]);
	free(line);
	free(limiter);
}

void	here_doc(char *av)
{
	int		fdpipe[2];
	pid_t	pid;
	int		status;

	if (pipe(fdpipe) == -1)
		ft_error("Pipe : ");
	pid = fork();
	if (pid < 0)
		ft_error("Fork : ");
	if (pid > 0)
	{
		close(fdpipe[1]);
		dup2(fdpipe[0], STDIN_FILENO);
		close(fdpipe[0]);
		waitpid(pid, &status, 0);
	}
	else
	{
		read_here_doc(av, fdpipe);
	}
}
