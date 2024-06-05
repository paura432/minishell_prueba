/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:45:10 by pramos            #+#    #+#             */
/*   Updated: 2024/05/11 14:24:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_memdel(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	return (NULL);
}

void	free_token(t_token *start)
{
	while (start && start->next)
	{
		ft_memdel(start->str);
		start = start->next;
		ft_memdel(start->prev);
	}
	if (start)
	{
		ft_memdel(start->str);
		ft_memdel(start);
	}
}

void	handle_signal(int sign)
{
	printf("\nMinishell->");
}

void	signal_detecter(void)
{
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, SIG_IGN);
}

// void	leaks()
// {
// 	system("leaks -q minishell");
// }

int	main(int ac, char **av, char **env)
{
	t_mini	*mini;
	int		i;

	i = 0;
	mini = malloc(sizeof(t_mini));
	if (ac > 2 && av == 0 && env == 0)
		return (0);
	signal_detecter();
	while (1)
	{
		mini->input = readline("Minishell->");
		if (mini->input == 0)
			return (free(mini), printf("logout\n"), 0);
		if (mini->input[0] != '\0')
		{
			mini->token = get_tokens(mini->input);
			add_history(mini->input);
			go_comands(mini, env);
			free_token(mini->token);
		}
	}
	free(mini);
	return (0);
}
