/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:47:14 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/15 10:34:25 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_args(t_list	*list, int ln, int fd)
{
	t_list	*local_list;

	local_list = list;
	if (!local_list && ln)
		ft_putstr_fd("\n", fd);
	else
	{
		while (local_list)
		{
			if (local_list == list)
				ft_putstr_fd((char *)local_list->content, fd);
			else
			{
				ft_putchar_fd(' ', fd);
				ft_putstr_fd((char *)local_list->content, fd);
			}
			local_list = local_list->next;
		}
		if (ln)
			printf("\n");
	}
}

int	bn_check(char *str)
{
	char	*local;

	local = str;
	if (*local != '-')
		return (0);
	local++;
	while (*local)
	{
		if (*local != 'n')
			return (0);
		local++;
	}
	return (1);
}

void	ms_echo(t_cmd *cmd)
{
	int		ln;
	int		fd;
	t_list	*lst_param;

	lst_param = cmd->lst_param;
	fd = 1;
	ln = TRUE;
	while (lst_param && bn_check((char *)(lst_param->content)))
	{
		ln = FALSE;
		lst_param = lst_param->next;
	}
	print_args(lst_param, ln, fd);
	(*(cmd->data)).state = EXIT_SUCCESS;
}
