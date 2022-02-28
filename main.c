/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <vess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:51:06 by vess              #+#    #+#             */
/*   Updated: 2022/02/28 23:20:37 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *file, int flag)
{
	int	fd;

	fd = open(file, flag, 0644);
	if (fd == -1)
	{
		perror("Error Open: ");
		exit(1);
	}
	return (fd);
}

void	error(const char *msg)
{
	perror(msg);
	exit(1);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	*path;
	char	*dir;
	char	*file;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	path = env[i] + 5;
	while (*path && (ft_strichr(path, ':') > -1))
	{
		dir = ft_strndup(path, ft_strichr(path, ':'));
		file = ft_joinpath(dir, cmd);
		free(dir);
		if (access(file, X_OK) == 0)
			return (file);
		free(file);
		path += ft_strichr(path, ':') + 1;
	}
	return (cmd);
}

void	exec_cmd(char *cmd, char **env)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (ft_strichr(args[0], '/') > -1)
		path = args[0];
	else
		path = get_path(cmd, env);
	execve(path, args, env);
}

void	redirection(char **av,char **env)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (pipe(fd) == -1)
		error("Pipe : ");
	pid1 = fork();
	if (pid1 < 0)
		error("Fork : ");
	if (pid1 == 0)
	{	
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		exec_cmd(av[2], env);
	}
	pid2 = fork();
	if (pid2 < 0)
		error("Fork : ");
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		exec_cmd(av[3], env);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
}

int	main(int ac, char **av, char **env)
{
	int	fd[2];
	int	i;

	i = 1;

	if (ac == 4)
	{
		fd[0] = open_file(av[1], O_RDONLY);
		fd[1] = open_file(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC);
		redirection(av, env);
	}
	return (0);
}
