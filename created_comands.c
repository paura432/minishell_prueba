/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   created_comands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:02:34 by marvin            #+#    #+#             */
/*   Updated: 2024/04/02 22:02:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

int	created_comands(char *input, t_mini *mini, char **env)
{
	int	i;
	int	bol;

	i = 0;
	bol = 0;
	mini->info = ft_split(input, ' ');
	mini->comand = mini->info[0];
	while ((input[i] > 8 && input[i] < 13) || input[i] == 32)
		i++;
	if (!ft_strncmp("echo", input + i, 4))
		bol = echo_comand(input + i + 4, mini);
	if (!ft_strncmp("cd", input + i, 2))
		bol = cd_comand(input + i + 2, mini);
	else if (!ft_strncmp("pwd", input + i, 3))
		bol = pwd_comand(input + i + 3, mini);
	else if (!ft_strncmp("export", input + i, 6))
		bol = export_comand(input + i + 6, mini);
	else if (!ft_strncmp("unset", input + i, 5))
		bol = unset_comand(input + i + 5, mini);
	else if (!ft_strncmp("env", input + i, 3))
		bol = env_comand(input + i + 3, mini);
	free_split(mini->info);
	return (bol);
}

int	cd_comand(char *input, t_mini *mini)
{
	int	i;

	i = 0;
	if (mini->info[2] != 0)
		return (mini->error = 5, check_errors(mini, mini->info[2]), 0);
	while ((input[i] > 8 && input[i] < 13) || input[i] == 32)
		i++;
	if (input[i] == 0)
		return (1);
	if ((chdir(input + i)))
		return (mini->error = 7, check_errors(mini, input + i), 0);
	return (1);
}

int	echo_comand(char *input, t_mini *mini)
{
	if (input[0] == ' ' || input[0] == 0)
		return (1);
	return (0);
}

int	export_comand(char *input, t_mini *mini)
{
	int	i;
	int	j;

	i = 0;
	while ((input[i] > 8 && input[i] < 13) || input[i] == 32)
		i++;
	if (input[i] == '$')
	{
		i = dolar_parse_export(input, mini);
		if (i == 0)
			return (0);
		else if (i == 1)
			return (1);
		i--;
	}
	else
		i = 0;
	while (mini->info[++i] != 0)
	{
		j = -1;
		while (mini->info[i][++j] != 0)
		{
			if (!((mini->info[i][j] >= 'a' && mini->info[i][j] <= 'z') || (mini->info[i][j] >= 'A' &&
				mini->info[i][j] <= 'Z') || (mini->info[i][j] >= '0' && mini->info[i][j] <= '9') ||
				mini->info[i][j] == '_') || (mini->info[i][0] >= '0' && mini->info[i][0] <= '9'))
				return (mini->error = 2, check_errors(mini, mini->info[i]), 0);
		}
	}
	i = 0;
	while ((input[i] > 8 && input[i] < 13) || input[i] == 32)
		i++;
	if (input[i] == '-')
		return (mini->error = 10, check_errors(mini, input + i), 0);
	if (input[i] >= '0' && input[i] <= '9')
		return (mini->error = 2, check_errors(mini, input + i), 0);
	if (input[0] == ' ' || input[0] == 0)
		return (1);
	return (0);
}

int	unset_comand(char *input, t_mini *mini)
{
	int	i;

	i = 0;
	while ((input[i] > 8 && input[i] < 13) || input[i] == 32)
		i++;
	if (input[0] == ' ' || input[0] == 0)
		return (1);
	return (0);
}

int	pwd_comand(char *input, t_mini *mini)
{
	int	i;

	i = 0;
	while ((input[i] > 8 && input[i] < 13) || input[i] == 32)
		i++;
	if (input[0] == ' ' || input[0] == 0)
		return (1);
	return (0);
}

int	env_comand(char *input, t_mini *mini)
{
	int	i;

	i = 0;
	if (input[0] != ' ' && input[0] != 0)
		return (mini->error = 1, check_errors(mini, 0), 0);
	while ((input[i] > 8 && input[i] < 13) || input[i] == 32)
		i++;
	if (input[i] == '*')
		return (mini->error = 9, check_errors(mini, 0), 0);
	if (input[i] == '$')
		return (dolar_parse_env(input, mini));
	if (input[i] == 0)
		return (1);
	if (access(input + i, F_OK) == -1)
		return (mini->error = 7, check_errors(mini, input + i), 0);
	else
		return (mini->error = 4, check_errors(mini, input + i), 0);
	return (0);
}

int	dolar_parse_env(char *input, t_mini *mini)
{
	int	i;
	int	j;

	i = 1;
	while (mini->info[i] != 0)
	{
		j = 0;
		if (mini->info[i][0] == '$')
		{
			if ((mini->info[i][1] >= '0' && mini->info[i][1] <= '9')
				&& (mini->info[i][2] >= '0' && mini->info[i][2] <= '9'))
				return (mini->error = 8, check_errors(mini, mini->info[i] + 2), 0);
			while (mini->info[i][++j] != 0)
			{
				if (!((mini->info[i][j] >= 'a' && mini->info[i][j] <= 'z')
					|| (mini->info[i][j] >= 'A' &&
					mini->info[i][j] <= 'Z') || (mini->info[i][j] >= '0'
					&& mini->info[i][j] <= '9') || mini->info[i][j] == '_'))
						return (mini->error = 8, check_errors(mini, mini->info[i] + j), 0);
			}
			i++;
		}
		else if(mini->info[i] != 0)
		{
			if (access(mini->info[i], F_OK) == -1)
				return (mini->error = 7, check_errors(mini, mini->info[i]), 0);
			else
				return (mini->error = 4, check_errors(mini, mini->info[i]), 0);
		}
	}
	return (1);
}

int	dolar_parse_export(char *input, t_mini *mini)
{
	int	i;
	int	j;

	i = 1;
	while (mini->info[i] != 0)
	{
		j = 0;
		if (mini->info[i][j++] == '$')
		{
			if ((mini->info[i][1] >= '0' && mini->info[i][1] <= '9') && (mini->info[i][2] >= '0' && mini->info[i][2] <= '9'))
				return (mini->error = 3, check_errors(mini, mini->info[i] + 2), 0);
			while (mini->info[i][++j] != 0)
			{
				if (!((mini->info[i][j] >= 'a' && mini->info[i][j] <= 'z') || (mini->info[i][j] >= 'A' &&
					mini->info[i][j] <= 'Z') || (mini->info[i][j] >= '0' && mini->info[i][j] <= '9') ||
					mini->info[i][j] == '_'))
						return (mini->error = 3, check_errors(mini, mini->info[i] + j), 0);
			}
		}
		else
			return (i);
		i++;
	}
	return (1);
}
