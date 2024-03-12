/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2000_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:43:31 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/08 14:51:07 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_pipe(t_token *token, t_cmd *cmd, int *cmd_found, int *new_node)
{
	*cmd_found = FALSE;
	*new_node = TRUE;
	cmd->link_type = PIPE;
}

void	set_or(t_token *token, t_cmd *cmd, int *cmd_found, int *new_node)
{
	*cmd_found = FALSE;
	*new_node = TRUE;
	cmd->link_type = OR;
}

void	set_and(t_token *token, t_cmd *cmd, int *cmd_found, int *new_node)
{
	*cmd_found = FALSE;
	*new_node = TRUE;
	cmd->link_type = AND;
}

void	set_arplan(t_token *token, t_cmd *cmd, int *cmd_found, int *new_node)
{
	*cmd_found = FALSE;
	*new_node = TRUE;
	cmd->link_type = AR_PLAN;
}

void	set_sc(t_token *token, t_cmd *cmd, int *cmd_found, int *new_node)
{
	*cmd_found = FALSE;
	*new_node = TRUE;
	cmd->link_type = SEMI_COLON;
}
