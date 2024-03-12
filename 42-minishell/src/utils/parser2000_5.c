/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2000_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:43:31 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/10 10:26:38 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	args_tab_maker(t_list *cmd_lst)
{
	t_list	*local;
	t_cmd	*cmd;

	local = cmd_lst;
	while (local)
	{
		cmd = (t_cmd *)local->content;
		cmd->args = args_list_maker(cmd);
		local = local->next;
	}
	return (EXIT_SUCCESS);
}

void	free_lex(void *arg)
{
	t_token	*token;

	token = (t_token *)arg;
	free(token->str);
	free(token);
}

int	error_redir(t_list **lexer_lst)
{
	ft_putstr_fd("minishell: syntax error near unexpected token 'newline'\n",
		STDERR_FILENO);
	ft_lstclear(lexer_lst, &free_lex);
	return (1);
}

int	error_sep(t_list **lexer_lst, char *str, t_data *data)
{
	ft_putstr_fd("minishell: syntax error near unexpected token '",
		STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("'\n", STDERR_FILENO);
	ft_lstclear(lexer_lst, &free_lex);
	data->state = 258;
	return (1);
}

int	token_error(t_list **lexer_lst, t_data *data)
{
	t_list		*local;
	enum e_type	t_t;
	enum e_type	nt_t;
	char		*t_str;

	local = *lexer_lst;
	while (local)
	{
		t_t = ((t_token *)local->content)->type;
		t_str = ((t_token *)local->content)->str;
		if (local->next)
			nt_t = ((t_token *)local->next->content)->type;
		else
			nt_t = 0;
		if ((t_t == REDIR_IN || t_t == REDIR_OUT || t_t == DELIMITER
				|| t_t == APPEND) && (!nt_t || nt_t == PIPE || nt_t == OR
				|| nt_t == AND || nt_t == AR_PLAN))
			return (error_redir(lexer_lst));
		else if ((t_t == PIPE || t_t == OR || t_t == AND || t_t == AR_PLAN)
			&& ((!local->prev) || (nt_t && (nt_t == PIPE || nt_t == OR
						|| nt_t == AND || nt_t == AR_PLAN))))
			return (error_sep(lexer_lst, t_str, data));
		local = local->next;
	}
	return (0);
}
