/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_comands.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:26:08 by pramos            #+#    #+#             */
/*   Updated: 2024/04/20 23:39:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	go_comands(t_mini *mini, char **env)
{
	int	comands;
	int	i;

	i = 0;
	comands = parse(mini);
	while (mini->token->prev != 0)
		mini->token = mini->token->prev;
	if (comands == 0)
		i = simple_comand(mini, env);
	else if (comands == 1)
		i = pipe_comand(mini, env);
	else if (comands == 2)
		i = redirecctions_comand(mini, env);
	return (i);
}

int	parse(t_mini *mini)
{
	int	i;
	int	bol;

	bol = 0;
	while (mini->token->next != 0)
	{
		i = 0;
		if (mini->token->str[0] == '>' || mini->token->str[0] == '<')
			return (2);
		if (mini->token->str[0] == '|')
			bol = 1;
		mini->token = mini->token->next;
	}
	return (bol);
}

int	simple_comand(t_mini *mini, char **env)
{
	if (no_comands(mini->token->str))
	{
		if (created_comands(mini->token->str, mini, env))
			return (1);
		else
			return (0);
	}
	else if (!invalid_input(mini, mini->token->str, env, 0))
		return (0);
	return (1);
}

int	pipe_comand(t_mini *mini, char **env)
{
	int	bol;

	bol = 1;
	while (mini->token != 0)
	{
		if (mini->token->str[0] == '|')
			mini->token = mini->token->next;
		if (no_comands(mini->token->str))
			created_comands(mini->token->str, mini, env);
		else if (!invalid_input(mini, mini->token->str, env, 0))
			bol = 0;
		mini->token = mini->token->next;
	}
	return (bol);
}

int	redirecctions_extend(t_mini *mini, int *i)
{
	*i = 0;
	while (mini->token->str[i] != 0
		&& (mini->token->str[i] != '<' || mini->token->str[i] != '>'))
		i++;
	if (mini->token->str[i] && (mini->token->str[i] != '<'
			|| mini->token->str[i] != '>'))
		created_comands(mini->token->str, mini, env);
}

int	redirecctions_comand(t_mini *mini, char **env)
{
	int	bol;
	int	i;

	bol = 1;
	i = 0;
	while (mini->token != 0)
	{
		while (mini->token->next != 0 && mini->token->str[0] != '|')
			mini->token = mini->token->next;
		else if (mini->token != 0
			&& mini->token->str[0] != '|' && no_comands(mini->token->str))
			redirecctions_extend(mini, i);
		else if (mini->token != 0 && mini->token->str[0] != '|'
			&& !invalid_input(mini, mini->token->str, env, 0))
			bol = 0;
		mini->token = mini->token->next;
	}
	return (bol);
}

//ls | akjjs > hibnj | jnlmk