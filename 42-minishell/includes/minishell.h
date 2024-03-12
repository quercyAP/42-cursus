/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/23 09:40:43 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <curses.h>
# include <dirent.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>
# include <signal.h>

# include "struct.h"
# include "exit_main.h"
# include "parser2000.h"
# include "rl_sep_heredoc.h"
# include "readline.h"
# include "free.h"
# include "handle.h"
# include "error.h"
# include "display_list.h"
# include "string_cleaner.h"
# include "ms_exit.h"
# include "ms_echo.h"
# include "exec_other.h"
# include "parser_check.h"
# include "env_utils.h"
# include "launcher.h"
# include "ms_split.h"
# include "putstr_fd_wq.h"
# include "ms_export.h"
# include "ms_cd.h"
# include "ms_pwd.h"
# include "redir.h"
# include "heredoc.h"
# include "quote_splitter.h"
# include "rev.h"

# define FALSE 0
# define TRUE 1
# define WAY_OUT 0
# define WAY_IN 1
# define PROMPT "minishell $> "
# define DIR_BUF 1000

#endif
