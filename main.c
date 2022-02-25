/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vess <vess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:38:31 by vess              #+#    #+#             */
/*   Updated: 2022/02/25 23:44:41 by vess             ###   ########.fr       */
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

void exec_cmd()
{




}

void	redirection(char *path)
{
	int fd[2];
	pid_t	pid;
	int	status;

	if (pipe(fd) == -1)
		error("Pipe: ");
	pid = fork();
	if (pid < 0 )
		error("Fork : ");
	// parent process car > 0
	if (pid > 0)
	{

		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid, &status, 0);
		execlp("ping", "ping", "-c", "5", "google.com", NULL);
	}
	// child process car = 0
	else
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid, &status, 0);
		execlp("ping", "ping", "-c", "5", "google.com", NULL);
	}


}

int	main(int ac, char **av)
{
	int	fd[2];

	if (ac == 5)
	{
		fd[0] = open_file(av[1], O_RDONLY);
		fd[1] = open_file(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC);

	}
	return (0);
}
