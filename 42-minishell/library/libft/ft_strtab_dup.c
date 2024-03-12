/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:03:45 by tdechand          #+#    #+#             */
/*   Updated: 2023/02/16 10:46:14 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_tab(char **str_tab)
{
	while (str_tab)
	{
		free(*str_tab);
		str_tab++;
	}
	return (NULL);
}

char	**ft_strtab_dup(char **str_tab)
{
	int		i;
	char	**tab_ret;

	i = 0;
	tab_ret = ft_calloc(sizeof(char *), (ft_strtab_len(str_tab) + 1));
	if (!tab_ret)
		return (NULL);
	while (i < ft_strtab_len(str_tab))
	{
		tab_ret[i] = ft_strdup(str_tab[i]);
		if (!(tab_ret[i]))
			return (free_tab(tab_ret));
		i++;
	}
	return (tab_ret);
}
