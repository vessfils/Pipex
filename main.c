/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <vess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:51:06 by vess              #+#    #+#             */
/*   Updated: 2022/03/04 21:56:50 by vess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *file, int flag)
{
	int	fd;

	fd = open(file, flag, 0644);
	if (fd < 0)
	{
		perror("Error Open: ");
		exit(1);
	}
	return (fd);
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
	if (!env[i])
		ft_error("Env does not exist");
	path = env[i] + 5;
	while (*path && (ft_strichr(path, ':') > -1))
	{
		dir = ft_strndup(path, ft_strichr(path, ':'));
		file = ft_joinpath(dir, cmd);
		free(dir);
		if (access(file, F_OK) == 0)
			return (file);
		free(file);
		path += ft_strichr(path, ':') + 1;
	}
	return (NULL);
}

void	exec_cmd(char *cmd, char **env)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (ft_strichr(args[0], '/') > -1 || *args[0] == '.' || *args[0] == '~')
		path = args[0];
	else
		path = get_path(args[0], env);
	if (path != NULL)
		execve(path, args, env);
	ft_panic(args);
	free(path);
	write(STDERR, "Command not found.\n", 20);
	exit(1);
}

void	redirection(char *cmd, char **env)
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
		if (WEXITSTATUS(status) == EXIT_FAILURE)
			exit(EXIT_FAILURE);
	}
	else
	{
		close(fdpipe[0]);
		dup2(fdpipe[1], STDOUT_FILENO);
		close(fdpipe[1]);
		exec_cmd(cmd, env);
	}
}

int	main(int ac, char **av, char **env)
{
	int		fdfile[2];
	int		i;

	i = 1;
	if (!*env)
		ft_error("Env does not exist");
	if (ac >= 5)
	{
		fdfile[0] = open_file(av[1], O_RDONLY);
		fdfile[1] = open_file(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC);
		dup2(fdfile[0], STDIN_FILENO);
		while (++i < ac - 2)
			redirection(av[i], env);
		dup2(fdfile[1], STDOUT_FILENO);
		exec_cmd(av[i], env);
		close(fdfile[0]);
		close(fdfile[1]);
	}
	write(STDERR, "Invalid number of arguments.\n", 29);
	return (EXIT_FAILURE);
}
