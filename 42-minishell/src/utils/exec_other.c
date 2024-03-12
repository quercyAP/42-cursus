/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_other.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:22:07 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/15 15:37:52 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**list_to_tab(t_list *list)
{
	t_env	*node;
	char	**env;
	char	*tmp;
	int		i;

	env = ft_calloc(sizeof(char *), ft_lstsize(list) + 1);
	i = 0;
	while (list)
	{
		node = list->content;
		tmp = ft_strjoin(node->name, "=");
		env[i] = ft_strjoin(tmp, node->value);
		free(tmp);
		list = list->next;
		i++;
	}
	return (env);
}

static void	signaled(t_cmd *cmd)
{
	if (WIFSIGNALED(cmd->data->state))
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		cmd->data->state += 128;
	}
	else
		cmd->data->state %= 255;
}

int	exec_other(t_cmd *cmd)
{
	char	*path;
	pid_t	pid;
	char	**env;

	pid = fork();
	if (pid == 0)
	{
		env = list_to_tab(cmd->data->list_env);
		execve(cmd->cmd, cmd->args, env);
		perror("execve failed");
		exit(1);
	}
	else if (pid == -1)
	{
		perror("execve fork failed");
		return (1);
	}
	else
	{
		waitpid(pid, &(cmd->data->state), 0);
		signaled(cmd);
	}
	return (0);
}
