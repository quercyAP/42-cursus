/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:12:17 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/08 10:40:15 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	pnode_utils(t_cmd *cmd)
{
	printf("------------------\n");
	printf("\033[0;94mCommande = %s\033[0m\n", cmd->cmd);
	printf("Cmd Type = ");
	print_cmdtype(cmd->cmd_type);
	printf("Quotes are ");
	print_quote((*(cmd->data)).quotes);
	printf("Param = ");
	print_list(cmd->lst_param);
	printf("Args (Char **) = ");
	print_tab(cmd->args);
	if ((*(cmd->data)).d_env)
	{
		printf("Env (Char **) = ");
		print_listenv((*(cmd->data)).list_env);
	}
	printf("Redir In= ");
	print_list_redir(cmd->lst_redir_in);
	printf("Redir Out= ");
	print_list_redir(cmd->lst_redir_out);
	printf("Link is = ");
	print_link(cmd->link_type);
	print_pipe(cmd);
	printf("------------------\n");
}

void	print_lexer(t_list *lexer_lst)
{
	t_list	*local;
	t_token	*token;

	local = lexer_lst;
	printf("Lexer Out\n");
	while (local)
	{
		token = (t_token *)local->content;
		plexer_utils(token);
		local = local->next;
	}
	printf("\n");
}

static void	print_node(void *node)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)node;
	if (cmd->data->debug)
		pnode_utils(cmd);
	else
		printf("");
}

void	display_list(t_list	*list)
{
	ft_lstiter(list, &print_node);
}
