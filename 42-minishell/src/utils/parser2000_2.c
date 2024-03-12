/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2000_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:43:31 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/08 14:48:52 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

enum e_type	get_type(char *str)
{
	if (!ft_strncmp(str, "<", 2))
		return (REDIR_IN);
	else if (!ft_strncmp(str, "<<", 3))
		return (DELIMITER);
	else if (!ft_strncmp(str, ">", 2))
		return (REDIR_OUT);
	else if (!ft_strncmp(str, ">>", 3))
		return (APPEND);
	else if (!ft_strncmp(str, "|", 2))
		return (PIPE);
	else if (!ft_strncmp(str, "||", 3))
		return (OR);
	else if (!ft_strncmp(str, "&", 2))
		return (AR_PLAN);
	else if (!ft_strncmp(str, "&&", 3))
		return (AND);
	else if (!ft_strncmp(str, ";", 2))
		return (SEMI_COLON);
	else
		return (STRING);
}

char	**args_list_maker(t_cmd *cmd)
{
	t_list	*begin;
	int		i;
	int		count;
	char	**ret;

	i = 1;
	count = 0;
	begin = cmd->lst_param;
	while (cmd->lst_param)
	{
		count++;
		cmd->lst_param = cmd->lst_param->next;
	}
	cmd->lst_param = begin;
	ret = ft_calloc(sizeof(char *), (count + 2));
	if (!ret)
		return (NULL);
	ret[0] = cmd->cmd;
	while (i <= count)
	{
		ret[i++] = (char *)cmd->lst_param->content;
		cmd->lst_param = cmd->lst_param->next;
	}
	cmd->lst_param = begin;
	return (ret);
}

void	make_pipe(t_list *list)
{
	t_pipe	*pipe_ret;
	t_list	*begin;

	begin = list;
	while (list)
	{
		if (list->prev && ((t_cmd *)(list->prev->content))->link_type == PIPE)
		{
			pipe_ret = ft_calloc(sizeof(t_pipe), 1);
			pipe(*pipe_ret);
			((t_cmd *)(list->prev->content))->pipe_out = pipe_ret;
			((t_cmd *)(list->content))->pipe_in = pipe_ret;
		}
		list = list->next;
	}
	list = begin;
}

int	lexer(t_list **lexer_lst, char	**str_tab)
{
	t_token	*token;
	int		cmd_not_found;
	int		was_redir;

	token = NULL;
	while (*str_tab)
	{
		token = ft_calloc(sizeof(t_token), 1);
		if (!token)
			return (EXIT_FAILURE);
		token->type = get_type(*str_tab);
		token->str = ft_strdup(*str_tab);
		ft_lstadd_back(lexer_lst, ft_lstnew(token));
		str_tab++;
	}
	return (EXIT_SUCCESS);
}

int	make_node(t_list **cmd_lst, t_cmd **cmd, int *new_node, t_data *data)
{
	*new_node = FALSE;
	*cmd = ft_calloc(sizeof(t_cmd), 1);
	if (!(*cmd))
		return (EXIT_FAILURE);
	(*cmd)->data = data;
	(*cmd)->pid = -2;
	(*cmd)->pipe_in = NULL;
	(*cmd)->pipe_out = NULL;
	ft_lstadd_back(cmd_lst, ft_lstnew(*cmd));
	return (EXIT_SUCCESS);
}
