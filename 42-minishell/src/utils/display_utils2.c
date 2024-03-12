/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:29:22 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/08 10:44:23 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_quote(enum e_quote quote)
{
	if (!quote)
		printf("\033[0;92mCLOSED\033[0m\n");
	else if (quote == OPEN)
		printf("\033[0;93mOPEN\033[0m\n");
}

void	print_state(int state)
{
	if (!state)
		printf("\033[0;92mEXIT_SUCCESS\033[0m\n");
	else
		printf("\033[0;93m(%i)ERROR\033[0m\n", state);
}

void	print_cmdtype(enum e_cmdtype cmdtype)
{
	if (!cmdtype)
		printf("\033[0;93mNONE\033[0m\n");
	else if (cmdtype == UNKNOWN)
		printf("\033[0;95mUNKNOWN\033[0m\n");
	else if (cmdtype == OTHER)
		printf("\033[0;92mOTHER\033[0m\n");
	else if (cmdtype == B_ECHO)
		printf("\033[0;92mB_ECHO\033[0m\n");
	else if (cmdtype == B_CD)
		printf("\033[0;92mB_CD\033[0m\n");
	else if (cmdtype == B_PWD)
		printf("\033[0;92mB_PWD\033[0m\n");
	else if (cmdtype == B_EXPORT)
		printf("\033[0;92mB_EXPORT\033[0m\n");
	else if (cmdtype == B_UNSET)
		printf("\033[0;92mB_UNSET\033[0m\n");
	else if (cmdtype == B_ENV)
		printf("\033[0;92mB_ENV\033[0m\n");
	else if (cmdtype == B_EXIT)
		printf("\033[0;92mB_EXIT\033[0m\n");
}

void	plexer_utils(t_token *token)
{
	printf("\033[0;94m{ ");
	if (!token->type)
		printf("NONE");
	else if (token->type == PIPE)
		printf("PIPE");
	else if (token->type == OR)
		printf("OR");
	else if (token->type == AND)
		printf("AND");
	else if (token->type == AR_PLAN)
		printf("AR_PLAN");
	else if (token->type == SEMI_COLON)
		printf("SEMI_COLON");
	if (token->type == REDIR_IN)
		printf("<");
	else if (token->type == REDIR_OUT)
		printf(">");
	else if (token->type == APPEND)
		printf(">>");
	else if (token->type == DELIMITER)
		printf("<<");
	else if (token->type == STRING)
		printf("\033[0;95m%s", token->str);
	printf("\033[0;94m } \033[0m");
}

void	print_pipe(t_cmd *cmd)
{
	printf("Pipe In = ");
	if (!cmd->pipe_in)
		printf("\033[0;93mNONE\033[0m\n");
	else
	{
		printf("\033[0;92m(%i <-> %i)\033[0m\n",
			(*(cmd->pipe_in))[0], (*(cmd->pipe_in))[1]);
	}
	printf("Pipe Out = ");
	if (!cmd->pipe_out)
		printf("\033[0;93mNONE\033[0m\n");
	else
	{
		printf("\033[0;92m(%i <-> %i)\033[0m\n",
			(*(cmd->pipe_out))[0], (*(cmd->pipe_out))[1]);
	}
}
