/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:28:54 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/08 12:32:37 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	ft_lstiter_rev(t_list *lst, void (*f)(void *))
{
	t_list	*local;

	local = ft_lstlast(lst);
	while (local && f)
	{
		(*f)(local->content);
		local = local->prev;
	}
}
