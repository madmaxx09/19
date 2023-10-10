/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdor <mdor@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:22:38 by mdor              #+#    #+#             */
/*   Updated: 2023/10/09 18:25:53 by mdor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*path_finding(char *cmd, char **env)
{
	char	*executable;
	int		iterate;
	char	**paths;
	char	*potential_path;
	char	*cmd_args;
		
	iterate = -1;
	paths = ft_split(get_env("PATH", env), ';');
	while (paths[++iterate])
	{
		potential_path = ft_strjoin(paths[iterate], "/");
		executable = ft_strjoin(potential_path, cmd);
		if (access(executable, F_OK | X_OK) == 0)
			return (executable);
		free(executable);
	}
	free(paths);
	return (cmd);
}

char	*get_env(char *name, char **env)
{
	char	*path;
	int		i;
	int		j;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		path = ft_substr(env[i], 0, j);
		if (ft_strcmp(path, name) == 0)
		{
			free(path);
			return (env[i] + j + 1);
		}
		free(path);
		i++;
 	}
	return (NULL);
}