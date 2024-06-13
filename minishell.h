/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:45:30 by pramos            #+#    #+#             */
/*   Updated: 2024/06/11 15:08:00 by marvin           ###   ########.fr       */
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


typedef struct	s_expansions
{
	char			*new_arg;
	int				i;
	int				j;
}	t_expansions;


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
int			redirecctions_extend(t_mini *mini, char **env);
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

//joseph
t_env     *getminienv();
int				ft_cd(char **args, t_env *env);
int		ft_export2(char *args, t_env *env);
int     main(int arc, char **argc, char **envp);
t_token *prev_token(t_token *token, int skip);
t_token *next_node_token(t_token *token, int skip);
void parse_token(t_mini *mini);
void	execute(char *str, char **envp);
t_token *get_tokens(char *line);
void    ft_jump_space(const char *str, int *i);
void	error(void);
int is_types(t_token *token, char *types);
void type_token(t_token *token, int separator);
t_token *next_exe(t_token *token, int skip);
int is_type(t_token *token, int arguments);
char	*find_path(char *cmd, char **envp);
void	ft_clean(int i, char **paths);
void type_exe(t_mini *mini,t_token *token);
int    get_env(t_mini *minishell, char **envp);
void    increment_shlv(t_env *env);
t_token *next_token(char *line, int *i);
char	**cmd_tab(t_token *start);
char		*get_env_name(char *dest, const char *src);
int next_alloc(char *line, int *i);
char			*expansions(char *arg, t_env *env, int ret);
int		has_pipe(t_token *token);
void	mini_exit(t_mini *mini, char **cmd);
int		is_builtin(char *command);
int		exec_builtin(char **args, t_mini *mini);
char	**cmd_tab(t_token *start);
void	free_tab(char **tab);

int		get_var_len(const char *arg, int pos, t_env *env, int ret);
int		arg_alloc_len(const char *arg, t_env *env, int ret);
void		insert_var(t_expansions *ex, char *arg, t_env *env, int ret);
char	*get_var_value(const char *arg, int pos, t_env *env, int ret);
int		is_env_char(int c);
char	*get_env_value(char *arg, t_env *env);
void ft_close(int fd);
void	free_token(t_token *start);
char	*space_alloc(char *line);

int				ft_echo(char **args);
int		ft_pwd(void);
int		ft_env(t_env *env);
int		ft_export(char **args, t_env *env);
int	ft_unset(char **args, t_mini *mini);
int	cmd_bin(char **cmd, t_env *env, t_mini *mini);
int	in_env(t_env *env, char *arg);
int	add_env(const char *arg, t_env *env);
int		quotes(char *line, int index);
int		is_sep(char *line, int i);

#endif
