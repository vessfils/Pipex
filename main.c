/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <vess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:38:31 by vess              #+#    #+#             */
/*   Updated: 2022/02/27 23:31:49 by vess             ###   ########.fr       */
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
	char	**dir;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	path = env[i] + 5;
	dir = ft_split(path, ':');
	i = 0;
	while (dir[i])
	{
		printf("%s\n", dir[i]);
		if (access(dir[i], X_OK))
			return (dir[i]);
		i++;
	}
	return (cmd);
}

/*
void exec_cmd()
{




}

void	redirection(void)
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
		execlp("ls", "ls", NULL);
	}
	pid2 = fork();
	if (pid2 < 0)
		error("Fork : ");
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("grep", "grep", "main", NULL);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
}
*/
int	main(int ac, char **av, char **env)
{
	//int	fd[2];
	char	*binaryPath = "/bin/ls";
	char	*args[] = {binaryPath, "ls", NULL};

/*
	if (ac == 5)
	{
		fd[0] = open_file(av[1], O_RDONLY);
		fd[1] = open_file(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC);

	}
*/
	//execve(binaryPath, args, env);
	//printf("%s\n", get_path(env));
	//redirection();
	get_path("ls", env);
	return (0);
}
