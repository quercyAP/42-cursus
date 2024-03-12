/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2000_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:43:31 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/08 14:59:13 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redir	*make_redir(enum e_type type, char *str)
{
	t_redir	*ret;

	ret = ft_calloc(sizeof(t_redir), 1);
	if (!ret)
		return (NULL);
	ret->type = type;
	ret->value = ft_strdup(str);
	return (ret);
}

void	set_cmd_param_sep(t_token *token, t_cmd *cmd,
	int *cmd_found, int *new_node)
{
	if (token->type == STRING && !(*cmd_found))
	{
		*cmd_found = TRUE;
		cmd->cmd = ft_strdup(token->str);
		check_cmd_path(&cmd);
	}
	else if (token->type == STRING && *cmd_found)
		ft_lstadd_back(&(cmd->lst_param), ft_lstnew(ft_strdup(token->str)));
	else if (token->type == PIPE)
		set_pipe(token, cmd, cmd_found, new_node);
	else if (token->type == OR)
		set_or(token, cmd, cmd_found, new_node);
	else if (token->type == AND)
		set_and(token, cmd, cmd_found, new_node);
	else if (token->type == AR_PLAN)
		set_arplan(token, cmd, cmd_found, new_node);
	else if (token->type == SEMI_COLON)
		set_sc(token, cmd, cmd_found, new_node);
}

void	set_redir_in_ps(t_token *token, t_cmd *cmd, t_list **lexer_lst)
{
	ft_lstadd_back(&(cmd->lst_redir_in), ft_lstnew(make_redir(token->type,
				((t_token *)((*lexer_lst)->next->content))->str)));
			*lexer_lst = (*lexer_lst)->next;
}

void	set_redir_out_ps(t_token *token, t_cmd *cmd, t_list **lexer_lst)
{
	ft_lstadd_back(&(cmd->lst_redir_out), ft_lstnew(make_redir(token->type,
				((t_token *)((*lexer_lst)->next->content))->str)));
			*lexer_lst = (*lexer_lst)->next;
}

int	parsing(t_list **cmd_lst, t_list *lexer_lst, t_data *data)
{
	t_token	*token;
	t_cmd	*cmd;
	int		cmd_found;
	int		new_node;

	cmd_found = FALSE;
	new_node = TRUE;
	while (lexer_lst)
	{
		if (new_node)
			make_node(cmd_lst, &cmd, &new_node, data);
		token = (t_token *)lexer_lst->content;
		set_cmd_param_sep(token, cmd, &cmd_found, &new_node);
		if ((token->type == REDIR_IN || token->type == DELIMITER)
			&& lexer_lst->next)
			set_redir_in_ps(token, cmd, &lexer_lst);
		if ((token->type == REDIR_OUT || token->type == APPEND)
			&& lexer_lst->next)
			set_redir_out_ps(token, cmd, &lexer_lst);
		lexer_lst = lexer_lst->next;
	}
	return (EXIT_SUCCESS);
}
