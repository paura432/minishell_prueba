/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:45:30 by pramos            #+#    #+#             */
/*   Updated: 2024/04/16 09:47:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "Libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <dirent.h>

# define EMPTY 0
# define CMD 1
# define ARG 2
# define TRUNC 3
# define APPEND 4
# define INPUT 5
# define PIPE 6
# define END 7
# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define SKIP 1
# define NOSKIP 0
# define EXPANSION 36
# define UNKNOWN_COMMAND 127
# define ERROR 1
# define SUCCESS 0
# define ERROR_1 "has taken a fork"

typedef struct s_env
{
	char			*value;
	struct s_env	*next;
}				t_env;

typedef struct s_token
{
	int				i;
	struct s_token	*prev;
	struct s_token	*next;
	char			*str;
	int				type;
}				t_token;

typedef struct s_mini
{
	int				signin;
	int				signout;
	int				compound;
	char			**info;
	char			*input;
	char			*comand;
	int				error;
	int				pipes_errors;
	int				info_y_comand;
	int				info_x_comand;
	int				info_y_created;
	struct s_env	*env;
	struct s_token	*token;
}				t_mini;

typedef struct mini_parse
{
	char			**content;
	char			*index;
}				t_mini_parse;

//minishell.c
void		handle_signal(int sign);
void		signal_detecter(void);
int			invalid_input(t_mini *mini, char *input, char **env, int i);
void		free_token(t_token *start);
void		*ft_memdel(void *ptr);

//invalid_input.c
void		free_split(char **inf);
int			change_path(char *paths, char *cmd);
int			no_comands(char *input);

//go_comands
int			go_comands(t_mini *mini, char **env);
int			simple_comand(t_mini *mini, char **env);
int			compound_comand(t_mini *mini, char **env);
int			pipe_comand(t_mini *mini, char **env);
int			parse(t_mini *mini);
int			operators_comand(t_mini *mini, char **env);
int			redirecctions_extend(t_mini *mini, int *i);
int			redirecctions_comand(t_mini *mini, char **env);

//mini_utils.c
int			execute_cmd_mini(char **cmd, char **envp);
char		*find_path_mini(char **envp);
char		*change_paths_mini(char *paths, char *cmd);

//created_comands
int			created_comands(char *input, t_mini *mini, char **env);
int			cd_comand(char *input, t_mini *mini);
int			echo_comand(char *input, t_mini *mini);
int			export_comand(char *input, t_mini *mini);
int			unset_comand(char *input, t_mini *mini);
int			pwd_comand(char *input, t_mini *mini);
int			env_comand(char *input, t_mini *mini);
int			dolar_parse_export(char *input, t_mini *mini);
int			dolar_parse_env(char *input, t_mini *mini);

//check_errors
void		check_errors(t_mini *mini, char *input);
void		copy_comand(t_mini *mini, char *input);

//token.c
t_token		*get_tokens(char *line);
void		ft_jump_space(const char *str, int *i);
static int	ignore_sep(char *line, int i);
t_token		*next_token(char *line, int *i);
t_token		*get_tokens(char *line);
void		ft_jump_space(const char *str, int *i);
static int	ignore_sep(char *line, int i);
t_token		*next_token(char *line, int *i);
void		type_token(t_token *token, int separator);
int			next_alloc(char *line, int *i);
int 		ft_separator(char c);
int			ft_is_space(char *line);

#endif
