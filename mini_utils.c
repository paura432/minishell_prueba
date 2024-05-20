/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:21:38 by pramos            #+#    #+#             */
/*   Updated: 2024/04/02 22:07:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_cmd_mini(char **cmd, char **envp)
{
	char	*true_path;
	char	*path;

	path = find_path_mini(envp);
	true_path = change_paths_mini(path, *cmd);
	execve(true_path, cmd, envp);
	return (1);
}

char	*find_path_mini(char **envp)
{
	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	return (*envp + 5);
}

char	*change_paths_mini(char *paths, char *cmd)
{
	char	**tmp_paths;
	char	*tmp;
	char	*path;

	tmp_paths = ft_split(paths, ':');
	while (*tmp_paths)
	{
		tmp = ft_strjoin(*tmp_paths, "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK & R_OK) == 0)
			return (path);
		free(path);
		tmp_paths++;
	}
	return (NULL);
}
