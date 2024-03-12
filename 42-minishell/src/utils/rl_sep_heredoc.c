/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_sep_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:30:46 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/08 14:30:25 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_simple_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			return (1);
		i++;
	}
	return (0);
}

static void	env_parser(char **strs, t_data *data)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!strs)
		return ;
	while (strs[i])
	{
		if (!is_simple_quote(strs[i]))
		{
			tmp = strs[i];
			strs[i] = clean_arg(strs[i], data);
			free(tmp);
		}
		i++;
	}
}

static void	child(char *buff)
{
	int		fd;

	signal(SIGINT, SIG_DFL);
	while (1)
	{
		buff = readline(">");
		if (buff && !buff[0])
		{
			free(buff);
			continue ;
		}
		else
			break ;
	}
	fd = open(".tmp2", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd, buff, ft_strlen(buff));
	free(buff);
	close(fd);
	exit (EXIT_SUCCESS);
}

static char	**father(struct termios *term, char *buff, int *run, t_data *data)
{
	char	**read_strs;
	int		fd;

	tcsetattr(STDIN_FILENO, TCSANOW, term);
	rl_replace_line("", 1);
	fd = open(".tmp2", O_RDONLY);
	if (fd < 0)
	{
		printf("\n");
		*run = FALSE;
	}
	buff = get_next_line(fd);
	close(fd);
	unlink(".tmp2");
	if (!buff)
		return (NULL);
	add_history(buff);
	buff = string_cleaner(buff, *data);
	if (!buff)
		return (NULL);
	read_strs = ms_split(buff, data, 0);
	env_parser(read_strs, data);
	free(buff);
	return (read_strs);
}

char	**rl_sep_heredoc(t_data *data, int *run)
{
	char			*buff;
	char			**read_strs;
	pid_t			pid;
	struct termios	term;

	buff = NULL;
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag |= ECHO;
	pid = fork();
	if (pid == 0)
	{
		child(buff);
		return (NULL);
	}
	else
	{
		waitpid(pid, NULL, 0);
		read_strs = father(&term, buff, run, data);
		if (!read_strs)
			return (NULL);
		return (read_strs);
	}
}
