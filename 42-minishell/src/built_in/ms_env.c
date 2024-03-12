/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:59:41 by glamazer          #+#    #+#             */
/*   Updated: 2023/03/23 09:30:20 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	display_node(void *content)
{
	t_env	*node;

	node = content;
	if (node->display_env)
	{
		putstr_fd_wq(node->name, 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd(node->value, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	ms_env(t_cmd *cmd)
{
	cmd->data->state = EXIT_SUCCESS;
	ft_lstiter(cmd->data->list_env, &display_node);
}
