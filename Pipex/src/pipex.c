/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:38:53 by mdor              #+#    #+#             */
/*   Updated: 2023/10/09 18:40:19 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void    child_process(char **argv, int *p_fd, char **env)
{
    int fd;
	
	fd = open(argv[1], O_RDONLY, 0777);
	if (fd == -1)
		exit (EXIT_FAILURE);
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);	
	execute_cmd(argv[2], env);
}

void    parent_process(char **argv, int *p_fd, char **env)
{
    int fd;

	
    fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		exit (EXIT_FAILURE);
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	execute_cmd(argv[3], env);	
}

void	execute_cmd(char *cmd, char **env)
{
	char	*path;
	char	**cmd_args;
	
	cmd_args = ft_split(cmd, ' ');
	path = path_finding(cmd_args[0], env);
	if (execve(path, cmd_args, env) == -1);
	{
		 
	}
}

int main(int argc, char **argv, char **env)
{
    int     p_fd[2];
    pid_t   pid;


    if (argc != 5)
        return (0);
    if (pipe(p_fd) == -1)
        exit (EXIT_FAILURE);
    pid = fork();
    if (pid == -1)
        exit (EXIT_FAILURE);
    if(!pid)
        child_process(argv, p_fd, env);
    parent_process(argv, p_fd, env);
    exit (EXIT_SUCCESS);
}