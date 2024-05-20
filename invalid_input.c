/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:33:32 by marvin            #+#    #+#             */
/*   Updated: 2024/02/05 21:33:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

void	free_split(char **inf)
{
	int	i;

	i = -1;
	while (inf[++i] != 0)
		free(inf[i]);
}

int	change_path(char *paths, char *cmd)
{
	char	**tmp_paths;
	char	*tmp;
	char	*path;

	if (cmd)
	tmp_paths = ft_split(paths, ':');
	while (*tmp_paths)
	{
		tmp = ft_strjoin(*tmp_paths, "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK & R_OK) == 0)
			return (1);
		free(path);
		tmp_paths++;
	}
	return (0);
}

int	no_comands(char *input)
{
	int	i;

	i = 0;
	while ((input[i] > 8 && input[i] < 13) || input[i] == 32)
		i++;
	if (!ft_strncmp("echo", input + i,  4))
		return (1);
	else if (!ft_strncmp("cd", input + i, 2))
		return (1);
	else if (!ft_strncmp("pwd", input + i, 3))
		return (1);
	else if (!ft_strncmp("export", input + i, 6))
		return (1);
	else if (!ft_strncmp("unset", input + i, 5))
		return (1);
	else if (!ft_strncmp("env", input + i, 3))
		return (1);
	else if (!ft_strncmp("exit", input + i, 4))
		return (printf("logout\n"), exit(0), 0);
	else if (!ft_strncmp(">> ", input + i, 2) || !ft_strncmp("<< ", input, 2))
		return (1);
	return (0);
}

int	invalid_input(t_mini *mini, char *input, char **env, int i)
{
	char	*path;
	char	**info;

	info = ft_split(input, ' ');
	path = find_path_mini(env);
	if (!change_path(path, info[0]))
		return (mini->error = 1, check_errors(mini, info[0])
			, free_split(info), 0);
	return (free_split(info), 1);
}
