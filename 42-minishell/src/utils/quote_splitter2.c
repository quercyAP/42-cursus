/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_splitter2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:09:00 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/15 15:08:13 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**init_tab2(t_list *list)
{
	t_list	*local;
	int		i;
	char	**ret;

	i = 0;
	local = list;
	while (list)
	{
		i++;
		list = list->next;
	}
	ret = ft_calloc(sizeof(char *), i + 1);
	if (!ret)
		return (NULL);
	return (ret);
}
