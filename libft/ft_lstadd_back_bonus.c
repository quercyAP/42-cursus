/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42mulhouse.fr   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:44:35 by glamazer          #+#    #+#             */
/*   Updated: 2022/11/24 12:23:49 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newlst)
{
	t_list	*ptr;

	if (lst)
	{
		if (!*lst)
			*lst = newlst;
		else
		{
			ptr = ft_lstlast(*lst);
			ptr->next = newlst;
		}	
	}	
}
