/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:57:00 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/23 09:28:41 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

enum	e_error
{
	NONE,
	TOKEN_ERROR,
	NOT_FOUND_ERROR,
	QUOTES_OPENED_ERROR
};

enum	e_type
{
	UNSET,
	PARAM,
	REDIR_IN,
	REDIR_OUT,
	DELIMITER,
	APPEND,
	PIPE,
	OR,
	AND,
	AR_PLAN,
	SEMI_COLON,
	STRING,
};

enum	e_cmdtype
{
	NO_ONE,
	OTHER,
	B_ECHO,
	B_CD,
	B_PWD,
	B_EXPORT,
	B_UNSET,
	B_ENV,
	B_EXIT,
	UNKNOWN
};

enum	e_quote
{
	CLOSED,
	OPEN
};

typedef int	t_pipe[2];

typedef struct s_token
{
	char		*str;
	enum e_type	type;
}				t_token;

typedef struct s_env
{
	char	*value;
	char	*name;
	int		display_env;
}			t_env;

typedef struct s_launch
{
	int		save_fd_stdout;
	int		save_fd_stdin;
	int		run;
	int		heredoc_killed;
}			t_launch;

typedef struct s_redir
{
	char		*value;
	enum e_type	type;
}			t_redir;

typedef struct s_data
{
	t_list				*list_cmd;
	char				**prompt_tab;
	int					request_quit;
	enum e_quote		quotes;
	enum e_quote		s_quotes;
	enum e_quote		d_quotes;
	int					main_argc;
	char				**main_argv;
	t_list				*list_env;
	int					state;
	int					debug;
	int					d_env;
	enum e_error		error;
	struct sigaction	sa;
	struct sigaction	old_sa;
}				t_data;

typedef struct s_cmd
{
	char			**args;
	t_list			*lst_param;
	t_list			*lst_redir_in;
	t_list			*lst_redir_out;
	char			*cmd;
	enum e_type		link_type;
	enum e_cmdtype	cmd_type;
	t_list			*lst_begin;
	struct s_data	*data;
	pid_t			pid;
	t_pipe			*pipe_in;
	t_pipe			*pipe_out;
}			t_cmd;

#endif
