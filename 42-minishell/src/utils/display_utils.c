/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:27:33 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/08 10:43:04 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_list(t_list	*list)
{
	t_list	*local_list;

	local_list = list;
	if (!local_list)
		printf("\033[0;91mAUCUN\033[0m\n");
	else
	{
		while (local_list)
		{
			printf("\033[0;92m{%s} \033[0m", (char *)local_list->content);
			local_list = local_list->next;
		}
		printf("\n");
	}
}

void	print_list_redir(t_list	*list)
{
	t_list	*local_list;
	t_redir	*redir;

	local_list = list;
	if (!local_list)
		printf("\033[0;91mAUCUN\033[0m\n");
	else
	{
		while (local_list)
		{
			redir = (t_redir *)local_list->content;
			if (redir->type == REDIR_IN)
				printf("\033[0;95m{< ");
			else if (redir->type == REDIR_OUT)
				printf("\033[0;96m{> ");
			else if (redir->type == APPEND)
				printf("\033[0;94m{>> ");
			else if (redir->type == DELIMITER)
				printf("\033[0;93m{<< ");
			printf("%s} \033[0m", redir->value);
			local_list = local_list->next;
		}
		printf("\n");
	}
}

void	print_listenv(t_list	*list)
{
	t_list	*local_list;
	t_env	*node;

	local_list = list;
	if (!local_list)
		printf("\033[0;91mAUCUN\033[0m\n");
	else
	{
		while (local_list)
		{
			node = local_list->content;
			printf("\033[0;92m%s=%s\n\033[0m", node->name, node->value);
			local_list = local_list->next;
		}
		printf("\n");
	}
}

void	print_tab(char **char_tab)
{
	int	i;

	if (!char_tab)
	{
		printf("\033[0;91mtab is NULL\033[0m\n");
		return ;
	}
	i = 0;
	while (char_tab[i])
	{
		printf("\033[0;92m{%s}\033[0m", char_tab[i]);
		i++;
	}
	if (char_tab[i] == NULL)
		printf("\033[0;94m{null term}\n\033[0m");
}

void	print_link(enum e_type type)
{
	if (!type)
		printf("\033[0;93mNONE\033[0m\n");
	else if (type == PIPE)
		printf("\033[0;92mPIPE\033[0m\n");
	else if (type == OR)
		printf("\033[0;92mOR\033[0m\n");
	else if (type == AND)
		printf("\033[0;92mAND\033[0m\n");
	else if (type == AR_PLAN)
		printf("\033[0;92mAR_PLAN\033[0m\n");
}
